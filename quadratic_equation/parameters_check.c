#include "parameters_check.h"
#include <stdio.h>
#include <float.h>
#include <math.h>

// backend functions | for parameter check
static bool clean_stdin() {
    while (getchar() != '\n') {
        continue;       
    }

    return true;
}

static bool are_coefficients_infinity (float a, float b, float c) {
//  общая проверка на бесконечность
    return isinf(a) || isinf(b) || isinf(c); 
}

static bool are_coefficients_float(float *a, float *b, float *c) { // TODO: эта функция нахрен не сдалась (либо прописать обработку ошибок \\возможно с помощью структур//)
    return scanf("%f %f %f", a, b, c) == 3;
}

void show_coefficients_check(float *a, float *b, float *c) {
     while ((!are_coefficients_float(a, b, c) && clean_stdin()) || are_coefficients_infinity(*a, *b, *c)) { 
        printf("Wrong format. Try again!\n");
    }   
}