#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "recording_errors.h"


void display_part_equation(float par, int exp, char sign);

void display_equation(float a, float b, float c);

void output_solutions(int q_solutions, float solutions[], Errors error, float a, float b);

#endif
