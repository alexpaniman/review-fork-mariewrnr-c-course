// TODO: file rename: equation_data.h can be just equation.h it's clear enough

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


// TODO: split this struct into few smaller, more "atomic" ones.
typedef struct { // Все нужные данные об уравнении для вычислительной / описательной части
    float a,b,c;  // TODO: please add spaces after your commas ", "
    equation_type eq_type; // TODO: why add "eq_"?

    float D; // TODO: why solutions and D are part of equation?

    roots existing_roots; // TODO: very different in name then eq_type, but very overall a very similar thing, "roots_type"?
    float solutions[2];

    char equation_view[100]; // TODO: should be separate?

} equation;


#endif
