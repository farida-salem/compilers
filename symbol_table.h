#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_ERROR
} Type;

typedef struct {
    Type base;
    int  is_const;
} TypeImmut;

typedef enum {
    SYM_VAR,
    SYM_FUNC
} SymbolKind;


#define MAX_PARAMS 16
typedef struct {
    char*    name;
    TypeImmut spec;
} Param;

typedef struct Symbol {
    char       *name;
    SymbolKind     kind;
    TypeImmut    spec;              
    
    int         param_count;
    Param       params[MAX_PARAMS];

    int         scope_level;       
    struct Symbol *next;    
} Symbol;

void    init_symbol_table(void);
void    enter_scope(void);
void    exit_scope(void);

int     add_variable(const char *name, TypeImmut immutability);
int     add_function(const char *name, TypeImmut return_immutability, int param_count, Param *params);

Symbol* lookup_symbol(const char *name);

const char* type_to_string(Type t);
const char* spec_to_string(TypeImmut s);

#endif // SYMBOL_TABLE_H
