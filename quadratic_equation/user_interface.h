#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "equation_data.h"

// TODO: remove unused headers
#include "solve_equation.h"
#include <math.h>

// TODO: why comment out code?
// extern char* error_text[];

// typedef enum NoSolutionCases {
//          NEGATIVE_DISCRIMINANT,
//          NO_COEFFICIENTS
// } NoSolutionCases;

// extern struct NoSolutions {
//     NoSolutionCases solution_case;
//     char *error_text;
// } no_solution;


void show_coefficients_check(equation *equation_data);

// void output_user_interface(UserOutput phrase);

void output_solution(equation *equation_data);

void display_equation(equation *equation_data);

void output_error();
// void output_solutions(int q_solutions, float solutions[], NoSolutionCases solution_case, float a, float b);

#endif
