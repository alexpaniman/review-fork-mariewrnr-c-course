#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

float linear_solution(float b, float c);

int quadratic_solution(float a, float b, float c, float solutions[], char no_roots[]);

int solve_equation(float a, float b, float c, float solutions[], char no_roots[]);

#endif