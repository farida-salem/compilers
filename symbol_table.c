#include "symbol_table.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "quadruple.h"

extern Quadruple quadruples[];
extern int quad_count;

#define HASH_SIZE  97 // prime number for hash table size

#define MAX_SYMBOLS 1000  // Maximum symbols to track
#define MAX_SCOPES 100   // Maximum scope depth

static int first_scope_export = 1; // Flag to track if this is the first export

const char *STfilename="symbol_tables.txt";

// With these lines:
static Scope *current_scope = NULL;  // Current active scope
static Scope *global_scope = NULL;   // Global scope (always available)
// ashan lookups saree3a
static unsigned hash(const char *s) {
    unsigned h = 0;
    for (; *s; s++) h = (h<<5) + h + (unsigned)(*s);
    return h % HASH_SIZE;
}

void init_symbol_table(void) {
    // Initialize global scope
    global_scope = malloc(sizeof(Scope));
    if (!global_scope) {
        fprintf(stderr, "Error: Failed to allocate memory for global scope\n");
        exit(1);
    }
    
    for (int i = 0; i < HASH_SIZE; i++) 
        global_scope->symbols[i] = NULL;
        
    global_scope->parent = NULL;
    global_scope->level = 0;
    
    current_scope = global_scope;  // Start in global scope
}

void enter_scope(void) {
    Scope *new_scope = malloc(sizeof(Scope));
    if (!new_scope) {
        fprintf(stderr, "Error: Failed to allocate memory for new scope\n");
        exit(1);
    }
    
    for (int i = 0; i < HASH_SIZE; i++)
        new_scope->symbols[i] = NULL;
        
    new_scope->parent = current_scope;
    new_scope->level = current_scope->level + 1;
    current_scope = new_scope;
}


static void export_scope(Scope *scope, FILE *file) {
    // Print scope header
    fprintf(file, "\n==== Scope Level %d Symbol Table ====\n", scope->level);
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
    fprintf(file, "| Scope | Symbol         | Type   | Initialized | Value   | Is Func    |\n");
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
    
    // Collect all symbols from this scope
    Symbol *scope_symbols[MAX_SYMBOLS];
    int symbol_count = 0;
    
    // Collect symbols from this specific scope
    for (int i = 0; i < HASH_SIZE; i++) {
        for (Symbol *s = scope->symbols[i]; s; s = s->next) {
            if (symbol_count < MAX_SYMBOLS) {
                scope_symbols[symbol_count++] = s;
            } else {
                fprintf(stderr, "Warning: Too many symbols in scope to export\n");
                break;
            }
        }
    }
    
    // Print all symbols in this scope
    for (int i = 0; i < symbol_count; i++) {
        Symbol *sym = scope_symbols[i];
        
        // Get type string
        const char *type_str;
        switch (sym->spec.base) {
            case TYPE_INT: type_str = "int"; break;
            case TYPE_FLOAT: type_str = "float"; break;
            case TYPE_CHAR: type_str = "char"; break;
            case TYPE_STRING: type_str = "string"; break;
            case TYPE_VOID: type_str = "void"; break;
            default: type_str = "unknown"; break;
        }
        
        // Format the value field
        char value_str[64] = "0.00";  // Default value
        
        if (sym->kind == SYM_VAR && sym->has_value) {
            switch (sym->spec.base) {
                case TYPE_INT:
                    sprintf(value_str, "%d.00", sym->value.int_val);
                    break;
                case TYPE_FLOAT:
                    sprintf(value_str, "%.2f", sym->value.float_val);
                    break;
                case TYPE_CHAR:
                    sprintf(value_str, "'%c'", sym->value.char_val);
                    break;
                case TYPE_STRING:
                    if (sym->value.string_val) {
                        if (strlen(sym->value.string_val) > 15) {
                            sprintf(value_str, "\"%.*s...\"", 12, sym->value.string_val);
                        } else {
                            sprintf(value_str, "\"%s\"", sym->value.string_val);
                        }
                    } else {
                        strcpy(value_str, "null");
                    }
                    break;
            }
        }
        
        // Print row with the format requested
        fprintf(file, "| %-5d | %-14s | %-6s | %-11d | %-7s | %-10d |\n", 
                sym->scope_level,
                sym->name, 
                type_str, 
                sym->has_value, 
                value_str,
                sym->kind == SYM_FUNC ? 1 : 0);
    }
    
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
}

void export_global_scope(void) {
    FILE *file = fopen(STfilename, first_scope_export ? "w" : "a");
    if (file) {
        fprintf(file, "\n==== Global Scope Symbol Table ====\n");
        export_scope(global_scope, file);
        fclose(file);
        first_scope_export = 0;
    } else {
        perror("Failed to open scope log file for global scope");
    }
}

void exit_scope(void) {
    if (current_scope == global_scope) {
        fprintf(stderr, "Warning: Cannot exit global scope\n");
        return;
    }
    
    // Export the current scope's symbol table before exiting
    FILE *file = fopen(STfilename, first_scope_export ? "w" : "a");
    if (file) {
        export_scope(current_scope, file);
        fclose(file);
        first_scope_export = 0; // Next call will append
    } else {
        perror("Failed to open scope log file");
    }
    
    // Just move to parent scope without freeing anything
    current_scope = current_scope->parent;
}

int add_variable(const char *name, TypeImmut immutability) {
    unsigned idx = hash(name);
    
    // Check only in current scope for redeclaration
    for (Symbol *s = current_scope->symbols[idx]; s; s = s->next) {
        if (strcmp(s->name, name) == 0) {
            fprintf(stderr, "Semantic error: redeclaration of '%s'\n", name);
            return 0;
        }
    }
    
    Symbol *sym = malloc(sizeof *sym);
    if (!sym) {
        fprintf(stderr, "Error: Failed to allocate memory for symbol\n");
        return 0;
    }
    
    sym->name        = strdup(name);
    sym->kind        = SYM_VAR;
    sym->spec        = immutability;
    sym->param_count = 0;
    sym->scope_level = current_scope->level;  // Keep track of level for printing

    sym->has_value = 0;  // Mark as uninitialized
    sym->is_used = 0;    // Mark as unused
    
    switch (immutability.base) {
        case TYPE_INT:   sym->value.int_val = 0; break;
        case TYPE_FLOAT: sym->value.float_val = 0.0f; break;
        case TYPE_CHAR:  sym->value.char_val = '\0'; break;
        case TYPE_STRING: sym->value.string_val = NULL; break;
        default: break;
    }
    
    // Add to current scope's hash table (head insertion)
    sym->next = current_scope->symbols[idx];
    current_scope->symbols[idx] = sym;

    return 1;
}

int add_function(const char *name, TypeImmut return_immutability, int param_count, Param *params) {
    unsigned idx = hash(name);
    
    /* Functions can only be declared in global scope */
    if (current_scope != global_scope) {
        fprintf(stderr, "Semantic error: functions can only be declared in global scope\n");
        return 0;
    }
    
    // Check for redefinition
    for (Symbol *s = global_scope->symbols[idx]; s; s = s->next) {
        if (strcmp(s->name, name) == 0 && s->kind == SYM_FUNC) {
            fprintf(stderr, "Semantic error: function '%s' redefined\n", name);
            return 0;
        }
    }
    
    Symbol *sym = malloc(sizeof *sym);
    if (!sym) {
        fprintf(stderr, "Error: Failed to allocate memory for function symbol\n");
        return 0;
    }
    
    sym->name        = strdup(name);
    sym->kind        = SYM_FUNC;
    sym->spec        = return_immutability;
    sym->param_count = param_count;
    sym->scope_level = 0;  // Functions are always at global scope
    sym->has_value = 0;  // Mark as uninitialized
    sym->is_used = 0;    // Mark as unused
    
    for (int i = 0; i < param_count; i++)
        sym->params[i] = params[i];
    
    // Add to global scope
    sym->next = global_scope->symbols[idx];
    global_scope->symbols[idx] = sym;

    return 1;
}

Symbol* lookup_symbol(const char *name) {
    unsigned idx = hash(name);
    
    // Search in current scope first, then parent scopes
    for (Scope *scope = current_scope; scope; scope = scope->parent) {
        for (Symbol *s = scope->symbols[idx]; s; s = s->next) {
            if (strcmp(s->name, name) == 0) {
                return s;
            }
        }
    }
    
    return NULL;
}

const char* type_to_string(Type t) {
    switch(t){
      case TYPE_INT:   return "int";
      case TYPE_FLOAT: return "float";
      case TYPE_CHAR:  return "char";
      case TYPE_STRING: return "string";
      case TYPE_VOID:  return "void";
      default:         return "error"; //revisit
    }
}

const char* spec_to_string(TypeImmut immutability) {
    static char buf[32];
    snprintf(buf, sizeof buf, "%s%s",
      (immutability.is_const ? "const " : ""),
      type_to_string(immutability.base));
    return buf;
}


void set_int_value(const char *name, int value) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR) {
        fprintf(stderr, "Error: Cannot set value for non-variable %s\n", name);
        return;
    }
    if (s->spec.base != TYPE_INT) {
        fprintf(stderr, "Error: Type mismatch assigning to %s\n", name);
        return;
    }
    s->value.int_val = value;
    s->has_value = 1;
}

void set_float_value(const char *name, float value) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR) {
        fprintf(stderr, "Error: Cannot set value for non-variable %s\n", name);
        return;
    }
    if (s->spec.base != TYPE_FLOAT) {
        fprintf(stderr, "Error: Type mismatch assigning to %s\n", name);
        return;
    }
    s->value.float_val = value;
    s->has_value = 1;
}

void set_char_value(const char *name, char value) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR) {
        fprintf(stderr, "Error: Cannot set value for non-variable %s\n", name);
        return;
    }
    if (s->spec.base != TYPE_CHAR) {
        fprintf(stderr, "Error: Type mismatch assigning to %s\n", name);
        return;
    }
    s->value.char_val = value;
    s->has_value = 1;
}

// Add a new function to set string values
void set_string_value(const char *name, const char *value) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR) {
        fprintf(stderr, "Error: Cannot set value for non-variable %s\n", name);
        return;
    }
    if (s->spec.base != TYPE_STRING) {
        fprintf(stderr, "Error: Type mismatch assigning to %s\n", name);
        return;
    }
    
    // Free the previous string value if it exists
    if (s->has_value && s->value.string_val) {
        free(s->value.string_val);
    }
    
    // Set the new string value
    s->value.string_val = value ? strdup(value) : NULL;
    s->has_value = 1;
}

int get_int_value(const char *name) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR || s->spec.base != TYPE_INT) {
        fprintf(stderr, "Error: Cannot get int value from %s\n", name);
        return 0;
    }
    if (!s->has_value) {
        fprintf(stderr, "Warning: Using uninitialized variable %s\n", name);
        return 0;
    }
    return s->value.int_val;
}

float get_float_value(const char *name) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR || s->spec.base != TYPE_FLOAT) {
        fprintf(stderr, "Error: Cannot get float value from %s\n", name);
        return 0.0;
    }
    if (!s->has_value) {
        fprintf(stderr, "Warning: Using uninitialized variable %s\n", name);
        return 0.0;
    }
    return s->value.float_val;
}

char get_char_value(const char *name) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR || s->spec.base != TYPE_CHAR) {
        fprintf(stderr, "Error: Cannot get char value from %s\n", name);
        return '\0';
    }
    if (!s->has_value) {
        fprintf(stderr, "Warning: Using uninitialized variable %s\n", name);
        return '\0';
    }
    return s->value.char_val;
}

// Add a new function to get string values
const char* get_string_value(const char *name) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->kind != SYM_VAR || s->spec.base != TYPE_STRING) {
        fprintf(stderr, "Error: Cannot get string value from %s\n", name);
        return NULL;
    }
    if (!s->has_value || !s->value.string_val) {
        fprintf(stderr, "Warning: Using uninitialized string variable %s\n", name);
        return "";
    }
    return s->value.string_val;
}

// Function to check symbols in a scope
int check_scope(Scope *scope,int found_unused) {  // Missing semicolon after this line
    for (int i = 0; i < HASH_SIZE; i++) {
        for (Symbol *s = scope->symbols[i]; s; s = s->next) {
            if (s->kind == SYM_VAR && !s->is_used) {
                fprintf(stderr, "Warning: Variable '%s' at scope level %d is declared but never used\n", 
                        s->name, s->scope_level);
                found_unused = 1;
            }
        }
    }
    return found_unused;
}

void check_unused_variables() {
    int found_unused = 0;
    
  // Add this semicolon here!
    
    // Start with current scope and go up the chain
    for (Scope *scope = current_scope; scope; scope = scope->parent) {
        found_unused=check_scope(scope,found_unused);
    }
    
    if (found_unused) {
        fprintf(stderr, "\n");
    }
}
// Helper function for collecting symbols (moved outside)
static void collect_symbols_from_scope(Symbol *all_symbols[], int *symbol_count_ptr, Scope *scope) {
    for (int i = 0; i < HASH_SIZE; i++) {
        for (Symbol *s = scope->symbols[i]; s; s = s->next) {
            if (*symbol_count_ptr < MAX_SYMBOLS * MAX_SCOPES) {
                all_symbols[(*symbol_count_ptr)++] = s;
            } else {
                fprintf(stderr, "Warning: Too many symbols to print\n");
                return;
            }
        }
    }
}

void print_symbol_table_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open symbol table output file");
        return;
    }
    
    // Print header with the desired format
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
    fprintf(file, "| Scope | Symbol         | Type   | Initialized | Value   | Is Func    |\n");
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
    
    // Collect all symbols from all scopes
    Symbol *all_symbols[MAX_SYMBOLS * MAX_SCOPES];
    int symbol_count = 0;
    

    
    // Start with global scope
    collect_symbols_from_scope(all_symbols, &symbol_count, global_scope);
    
    // If we're in a nested scope, collect symbols from all parent scopes
    if (current_scope != global_scope) {
        // Create an array to store scopes in order
        Scope *scope_stack[MAX_SCOPES];
        int scope_count = 0;
        
        // Add all scopes from current up to (but not including) global
        for (Scope *scope = current_scope; scope && scope != global_scope; scope = scope->parent) {
            if (scope_count < MAX_SCOPES) {
                scope_stack[scope_count++] = scope;
            }
        }
        
        // Process scopes in reverse order (innermost to outermost)
        for (int i = 0; i < scope_count; i++) {
            collect_symbols_from_scope(all_symbols, &symbol_count, scope_stack[i]);
        }
    }
    
    // // Sort symbols by scope level (optional)
    // // This ensures symbols appear grouped by scope in the output
    // for (int i = 0; i < symbol_count - 1; i++) {
    //     for (int j = 0; j < symbol_count - i - 1; j++) {
    //         if (all_symbols[j]->scope_level > all_symbols[j+1]->scope_level) {
    //             Symbol *temp = all_symbols[j];
    //             all_symbols[j] = all_symbols[j+1];
    //             all_symbols[j+1] = temp;
    //         }
    //     }
    // }
    
    // Print all symbols
    for (int i = 0; i < symbol_count; i++) {
        Symbol *sym = all_symbols[i];
        
        // Get type string
        const char *type_str;
        switch (sym->spec.base) {
            case TYPE_INT: type_str = "int"; break;
            case TYPE_FLOAT: type_str = "float"; break;
            case TYPE_CHAR: type_str = "char"; break;
            case TYPE_STRING: type_str = "string"; break;
            case TYPE_VOID: type_str = "void"; break;
            default: type_str = "unknown"; break;
        }
        
        // Format the value field
        char value_str[64] = "0.00";  // Default value, increase buffer for strings
        
        if (sym->kind == SYM_VAR) {
            // First try to find the value from quadruples
            int value_found = 0;
            
            // Look for assignments to this variable in the quadruples
            for (int j = quad_count - 1; j >= 0; j--) {
                // Check for regular assignments
                if ((quadruples[j].op == QUAD_ASSIGN || 
                     quadruples[j].op == QUAD_ASSIGN_STR ||
                     quadruples[j].op == QUAD_ASSIGN_CHAR) && 
                    strcmp(quadruples[j].result, sym->name) == 0 &&
                    quadruples[j].arg1 != NULL) {
                    
                    // Handle string assignment differently
                    if (quadruples[j].op == QUAD_ASSIGN_STR) {
                        // For strings, just show the first part with quotes and ellipses
                        if (strlen(quadruples[j].arg1) > 15) {
                            sprintf(value_str, "\"%.*s...\"", 12, quadruples[j].arg1);
                        } else {
                            sprintf(value_str, "\"%s\"", quadruples[j].arg1);
                        }
                        
                        // Also update the symbol table value
                        if (sym->spec.base == TYPE_STRING) {
                            if (sym->has_value && sym->value.string_val) {
                                free(sym->value.string_val);
                            }
                            sym->value.string_val = strdup(quadruples[j].arg1);
                            sym->has_value = 1;
                        }
                        value_found = 1;
                        break;
                    }
                    // Handle character assignment
                    else if (quadruples[j].op == QUAD_ASSIGN_CHAR) {
                        strcpy(value_str, quadruples[j].arg1); // Copy character literal as-is
                        
                        // Also update the symbol table value if possible
                        if (sym->spec.base == TYPE_CHAR && strlen(quadruples[j].arg1) >= 3) {
                            sym->value.char_val = quadruples[j].arg1[1]; // Get the middle char: 'a'
                            sym->has_value = 1;
                        }
                        value_found = 1;
                        break;
                    }
                    // Handle regular numeric assignments
                    else if (isdigit(quadruples[j].arg1[0]) || 
                        (quadruples[j].arg1[0] == '-' && isdigit(quadruples[j].arg1[1]))) {
                        // It's a direct numeric assignment
                        if (sym->spec.base == TYPE_INT) {
                            int val = atoi(quadruples[j].arg1);
                            sprintf(value_str, "%d.00", val);
                            
                            // Also update the symbol table value
                            sym->value.int_val = val;
                            sym->has_value = 1;
                        } 
                        else if (sym->spec.base == TYPE_FLOAT) {
                            float val = atof(quadruples[j].arg1);
                            sprintf(value_str, "%.2f", val);
                            
                            // Also update the symbol table value
                            sym->value.float_val = val;
                            sym->has_value = 1;
                        }
                        value_found = 1;
                    } 
                    else {
                        // It's a variable or expression result
                        strcpy(value_str, quadruples[j].arg1);
                        value_found = 1;
                    }
                    break;
                }
            }
            
            // If we didn't find a value in quadruples, use the stored value
            if (!value_found && sym->has_value) {
                switch (sym->spec.base) {
                    case TYPE_INT:
                        sprintf(value_str, "%d.00", sym->value.int_val);
                        break;
                    case TYPE_FLOAT:
                        sprintf(value_str, "%.2f", sym->value.float_val);
                        break;
                    case TYPE_CHAR:
                        sprintf(value_str, "'%c'", sym->value.char_val);
                        break;
                    case TYPE_STRING:
                        if (sym->value.string_val) {
                            if (strlen(sym->value.string_val) > 15) {
                                sprintf(value_str, "\"%.*s...\"", 12, sym->value.string_val);
                            } else {
                                sprintf(value_str, "\"%s\"", sym->value.string_val);
                            }
                        } else {
                            strcpy(value_str, "null");
                        }
                        break;
                }
            }
        }
        
        // Print row with the format requested
        fprintf(file, "| %-5d | %-14s | %-6s | %-11d | %-7s | %-10d |\n", 
                sym->scope_level,
                sym->name, 
                type_str, 
                sym->has_value, 
                value_str,
                sym->kind == SYM_FUNC ? 1 : 0);
    }
    
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
    
    fclose(file);
}

// Helper function for cleaning up a single scope (moved outside)
static void cleanup_scope(Scope *scope) {
    if (!scope) return;
    
    // Free all symbols in this scope
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol *curr = scope->symbols[i];
        while (curr) {
            Symbol *next = curr->next;
            
            // Free the symbol's name
            free(curr->name);
            
            // Free string values if any
            if (curr->kind == SYM_VAR && 
                curr->spec.base == TYPE_STRING && 
                curr->has_value && 
                curr->value.string_val) {
                free(curr->value.string_val);
            }
            
            // Free the symbol itself
            free(curr);
            curr = next;
        }
    }
    
    // Free the scope structure
    free(scope);
}

void cleanup_symbol_table(void) {
    // Clean up all non-global scopes first
    Scope *scope = current_scope;
    while (scope && scope != global_scope) {
        Scope *parent = scope->parent;
        cleanup_scope(scope);
        scope = parent;
    }
    
    // Finally clean up global scope
    cleanup_scope(global_scope);
    
    // Reset pointers
    current_scope = NULL;
    global_scope = NULL;
}