#ifndef EQUATION_DATA_H
#define EQUATION_DATA_H


typedef enum roots {
    ONE_LINEAR_ROOT,
    ONE_QUADRATIC_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
    NO_REAL_ROOTS,
    NO_ANY_ROOTS
} roots;

typedef enum equation_type {
    LINEAR_EQUATION,
    QUADRATIC_EQUATION,
    NO_EQUATION_TYPE
} equation_type;


typedef struct { // Все нужные данные об уравнении для вычислительной / описательной части
    float a,b,c; 
    float D;
    float solutions[2];

    equation_type eq_type;
    roots existing_roots;

    char equation_view[100];

} equation;


#endif