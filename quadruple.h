#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <stdio.h>

// Define quadruple operations
typedef enum {
    QUAD_ADD,      // Addition: +
    QUAD_SUB,      // Subtraction: -
    QUAD_MUL,      // Multiplication: *
    QUAD_DIV,      // Division: /
    QUAD_MOD,      // Modulo: %
    QUAD_NEG,      // Unary negation: -x
    
    
    QUAD_ASSIGN,   // Assignment: =
    
    QUAD_LT,       // Less than: <
    QUAD_GT,       // Greater than: >
    QUAD_LE,       // Less than or equal: <=
    QUAD_GE,       // Greater than or equal: >=
    QUAD_EQ,       // Equal: ==
    QUAD_NEQ,      // Not equal: !=
    
    QUAD_AND,      // Logical AND: &&
    QUAD_OR,       // Logical OR: ||
    QUAD_NOT,      // Logical NOT: !
    

    
    QUAD_LABEL,    // Label for jumps
    QUAD_JUMP,     // Unconditional jump
    QUAD_JUMPZ,    // Jump if zero/false
    QUAD_JUMPNZ,   // Jump if not zero/true
    
    QUAD_PARAM,    // Function parameter
    QUAD_ARG,
    QUAD_CALL,     // Function call
    QUAD_RETURN,   // Return from function
    QUAD_ASSIGN_CHAR,
    QUAD_ASSIGN_STR,    // For string assignment
    QUAD_CONCAT,        // For string concatenation
    QUAD_STREQ,         // For string equality comparison
    QUAD_STRNEQ,
    QUAD_INT_TO_FLOAT,  // Convert int to float
    QUAD_CHAR_TO_STRING,

} QuadOp;

// Define quadruple structure
typedef struct {
    QuadOp op;     // Operation
    char *arg1;    // First argument
    char *arg2;    // Second argument
    char *result;  // Result
} Quadruple;

extern Quadruple quadruples[];
extern int quad_count;

// Function declarations
void init_quadruples(void);
void emit(QuadOp op, const char *arg1, const char *arg2, const char *result);
char *new_temp(void);
char *new_label(void);
void print_quadruples(FILE *out);
int get_quad_count(void);

// Helper functions for converting values to strings
char *int_to_string(int value);

char *float_to_string(float value);

char *get_op_name(QuadOp op);

void print_quadruples_to_file(const char *filename);


#endif // QUADRUPLE_H