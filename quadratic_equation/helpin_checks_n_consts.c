// TODO: rename and separate: you have here tools for floating arithmetic AND thing to read lines. Why are they together?
// TODO: read about IEEE754 standard for representing floating point numbers


#include "helpin_checks_n_consts.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const float epsilon = 1e-6; 

// TODO: naming, why clean_stdin? skip_line? skip_to_line_end read_line_end?
bool clean_stdin() {
    while (getchar() != '\n') {
        continue;       
    }

    return true; // TODO: why? It never fails.
}

bool are_coefficients_infinity (float a, float b, float c) {
    //  общая проверка на бесконечность
    return isinf(a) || isinf(b) || isinf(c); 
}

bool is_equal(float num1, float num2) {
    float res = fabs(num1 - num2);
    return res <= epsilon;
}

void approximate_to_zero(float* num) {
    if (is_equal(*num, 0))  {  // to cut off approximate part and "-" sign (like -0.0000000000000001 ~= 0.0)
        *num = 0;
    }
}
