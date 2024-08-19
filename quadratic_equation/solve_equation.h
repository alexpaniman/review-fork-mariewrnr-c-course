#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H
#include "recording_errors.h"
#include <stdbool.h>

bool compare(float num1, float num2);

float linear_solution(float b, float c);

int quadratic_solution(float a, float b, float c, float solutions[], Errors* error);

int solve_equation(float a, float b, float c, float solutions[], Errors* error);

#endif