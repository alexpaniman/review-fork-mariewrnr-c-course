#ifndef HELPIN_CHECKS_N_CONSTS_H
#define HELPIN_CHECKS_N_CONSTS_H
#include <stdbool.h>

extern const float epsilon; 

extern bool clean_stdin();

extern bool are_coefficients_infinity (float a, float b, float c);

bool is_equal(float num1, float num2);

void approximate_to_zero(float* num);

#endif