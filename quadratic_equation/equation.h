#ifndef EQUATION_H
#define EQUATION_H


typedef enum roots_type {
    ONE_LINEAR_ROOT,
    ONE_QUADRATIC_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
    NO_REAL_ROOTS,
    NO_ANY_ROOTS
} roots_type;

typedef enum equation_type {
    LINEAR_EQUATION,
    QUADRATIC_EQUATION,
    NO_EQUATION_TYPE
} equation_type;


typedef struct {
    float D; 

    roots_type type;
    float roots[2];

} equation_solution;

typedef struct { 
    float a, b, c;
    equation_type type;
} equation;


#endif
