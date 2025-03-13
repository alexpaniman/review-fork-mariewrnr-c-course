#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "equation.h"

void read_coefficients(equation *data);

void print_solution(equation *data, equation_solution *solve_equation);

#endif
