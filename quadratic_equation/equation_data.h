#ifndef EQUATION_DATA_H
#define EQUATION_DATA_H

//typedef enum UserOutput { // опять же, не уверена, что оно вообще должно быть тут; UPD: нахуя оно здесь?
//    ENTER_COEFFICIENTS,
//    ERROR_INPUT
//} UserOutput;

typedef enum equation_type {
    LINEAR_EQUATION,
    QUADRATIC_EQUATION
} equation_type;


typedef struct { // Все нужные данные об уравнении для вычислительной / описательной части
// по факту эта структура может использоваться вообще во всех файлах, поэтому вполне возможно ее стоит использовать отдельно от всего остального
    float a,b,c; // коэффициент
    float D; // discriminant
    equation_type eq_type;
    char equation_view[100]; //
    char no_solution_text[1000];
    float solutions[2];
} equation;


#endif