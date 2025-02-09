#include "helpin_checks_n_consts.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const float epsilon = 1e-6; 

bool clean_stdin() {
    while (getchar() != '\n') {
        continue;       
    }

    return true;
}

bool are_coefficients_infinity (float a, float b, float c) { // TODO: убедиться в нужности static и что это вообще (как и extern)
//  общая проверка на бесконечность
    return isinf(a) || isinf(b) || isinf(c); 
}

bool is_equal(float num1, float num2) { // TODO: в отдельный файл
    float res = fabs(num1 - num2);
    return res <= epsilon;
}
