#include "symbol_table.h"
#include <stdio.h>

#define HASH_SIZE  97 // prime number for hash table size

static Symbol *table[HASH_SIZE];
static int     current_scope = 0; //nested 0 global 1 gowa function 2 gowa gowa etc

// ashan lookups saree3a
static unsigned hash(const char *s) {
    unsigned h = 0;
    for (; *s; s++) h = (h<<5) + h + (unsigned)(*s);
    return h % HASH_SIZE;
}

void init_symbol_table(void) {
    for (int i = 0; i < HASH_SIZE; i++) table[i] = NULL;
    current_scope = 0;
}

void enter_scope(void) {
    current_scope++;
}

void exit_scope(void) {
    
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol **entryPtr = &table[i];
        while (*entryPtr) {
            Symbol *currentSymbol = *entryPtr;

            if (currentSymbol->scope_level == current_scope) {
                *entryPtr = currentSymbol->next;
                free(currentSymbol->name);
                free(currentSymbol);
            } else {
                entryPtr = &currentSymbol->next;
            }
        }
    }
    current_scope--;
}

int add_variable(const char *name, TypeImmut immutability) {
    unsigned idx = hash(name);
    
    for (Symbol *s = table[idx]; s; s = s->next) {
        if (strcmp(s->name, name)==0 && s->scope_level==current_scope) {
            fprintf(stderr, "Semantic error: redeclaration of '%s'\n", name);
            return 0;
        }
    }
    Symbol *sym = malloc(sizeof *sym);
    sym->name        = strdup(name);
    sym->kind        = SYM_VAR;
    sym->spec        = immutability;
    sym->param_count = 0;
    sym->scope_level = current_scope;
    //head insertion
    sym->next        = table[idx];
    table[idx]       = sym;
    return 1;
}

int add_function(const char *name, TypeImmut return_immutability, int param_count, Param *params) {
    unsigned idx = hash(name);
    /* only global functions */
    for (Symbol *s = table[idx]; s; s = s->next) {
        if (strcmp(s->name, name)==0 && s->kind==SYM_FUNC) {
            fprintf(stderr, "Semantic error: function '%s' redefined\n", name);
            return 0;
        }
    }
    Symbol *sym = malloc(sizeof *sym);
    sym->name        = strdup(name);
    sym->kind        = SYM_FUNC;
    sym->spec        = return_immutability;
    sym->param_count = param_count;
    for (int i = 0; i < param_count; i++)
        sym->params[i] = params[i];
    sym->scope_level = 0;
    sym->next        = table[idx];
    table[idx]       = sym;
    return 1;
}

Symbol* lookup_symbol(const char *name) {
    unsigned idx = hash(name);
    for (Symbol *s = table[idx]; s; s = s->next) {
        if (strcmp(s->name, name) == 0 && s->scope_level <= current_scope) {
            return s; 
        }
    }
    return NULL; 
}

const char* type_to_string(Type t) {
    switch(t){
      case TYPE_INT:   return "int";
      case TYPE_FLOAT: return "float";
      case TYPE_CHAR:  return "char";
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
