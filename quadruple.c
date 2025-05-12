#include "quadruple.h"
#include <stdlib.h>
#include <string.h>

#define MAX_QUADRUPLES 10000
#define MAX_TEMP_NAME 16
#define MAX_LABEL_NAME 16

// Array to store all quadruples
Quadruple quadruples[MAX_QUADRUPLES];
int quad_count = 0;

// Counters for generating temporary variables and labels
static int temp_count = 0;
static int label_count = 0;

// Initialize the quadruples system
void init_quadruples(void) {
    quad_count = 0;
    temp_count = 0;
    label_count = 0;
}

// Emit a new quadruple
void emit(QuadOp op, const char *arg1, const char *arg2, const char *result) {
    if (quad_count >= MAX_QUADRUPLES) {
        fprintf(stderr, "Error: Too many quadruples\n");
        exit(1);
    }
    
    // Store the quadruple
    quadruples[quad_count].op = op;
    quadruples[quad_count].arg1 = arg1 ? strdup(arg1) : NULL;
    quadruples[quad_count].arg2 = arg2 ? strdup(arg2) : NULL;
    quadruples[quad_count].result = result ? strdup(result) : NULL;
    
    quad_count++;
}

// Generate a new temporary variable name
char *new_temp(void) {
    char *temp = malloc(MAX_TEMP_NAME);
    if (!temp) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    
    snprintf(temp, MAX_TEMP_NAME, "t%d", temp_count++);
    return temp;
}

// Generate a new label name
char *new_label(void) {
    char *label = malloc(MAX_LABEL_NAME);
    if (!label) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    
    snprintf(label, MAX_LABEL_NAME, "L%d", label_count++);
    return label;
}

// Convert integer to string
char *int_to_string(int value) {
    char *str = malloc(MAX_TEMP_NAME);
    if (!str) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    
    snprintf(str, MAX_TEMP_NAME, "%d", value);
    return str;
}

char *float_to_string(float value) {
    char *str = malloc(32); // Sufficient for most float representations
    if (!str) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    
    // Use %g to show significant digits without unnecessary zeros
    // Or use %.6g to show up to 6 significant digits
    snprintf(str, 32, "%g", value); 
    return str;
}

// Get the string representation of an operation
char *get_op_name(QuadOp op) {
    static const char *op_names[] = {
        "ADD", "SUB", "MUL", "DIV", "MOD","NEG",
        "ASSIGN",
        "LT", "GT", "LE", "GE", "EQ", "NEQ",
        "AND", "OR", "NOT",
        "LABEL", "JUMP", "JUMPZ", "JUMPNZ",
        "PARAM","ARG", "CALL", "RETURN",
        "ASSIGN_CHR",
        // Add new string operations
        "ASSIGN_STR", "CONCAT", "STREQ", "STRNEQ",
        "INT_TO_FLOAT", "CHAR_TO_STRING"
    };
    
    // Update the upper bound check to include the new operations
    if (op < QUAD_ADD || op > QUAD_CHAR_TO_STRING) {
        return "UNKNOWN";
    }
    
    return (char *)op_names[op];
}

// Print all quadruples
void print_quadruples(FILE *out) {
    fprintf(out, "\n=== Generated Quadruples ===\n");
    fprintf(out, "  #  | Operation     | Arg1      | Arg2      | Result\n");
    fprintf(out, "-----|---------------|-----------|-----------|----------\n");
    
    for (int i = 0; i < quad_count; i++) {
        fprintf(out, "%4d | %-13s | %-9s | %-9s | %-9s\n", 
            i,
            get_op_name(quadruples[i].op),
            quadruples[i].arg1 ? quadruples[i].arg1 : "-",
            quadruples[i].arg2 ? quadruples[i].arg2 : "-",
            quadruples[i].result ? quadruples[i].result : "-"
        );
    }
    
    fprintf(out, "=== End of Quadruples ===\n\n");
}

// Get the current quadruple count
int get_quad_count(void) {
    return quad_count;
}

// Add this to quadruple.c
void print_quadruples_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open quadruples output file");
        return;
    }
    
    fprintf(file, "==== QUADRUPLES ====\n");
    fprintf(file, "  #  | Operation     | Arg1      | Arg2      | Result\n");
    fprintf(file, "-----|---------------|-----------|-----------|----------\n");
    
    for (int i = 0; i < quad_count; i++) {
        fprintf(file, "%4d | %-13s | %-9s | %-9s | %-9s\n", 
            i,
            get_op_name(quadruples[i].op),
            quadruples[i].arg1 ? quadruples[i].arg1 : "-",
            quadruples[i].arg2 ? quadruples[i].arg2 : "-",
            quadruples[i].result ? quadruples[i].result : "-"
        );
    }
    
    fclose(file);
}