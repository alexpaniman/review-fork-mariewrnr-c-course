#include "parameters_check.h"
#include <stdio.h>
#include <float.h>

// backend functions | for parameter check
static bool clean_stdin() {
    while (getchar() != '\n') {
        continue;       
    }

    return true;
}

static bool is_float_infinity(float par) { //TODO: проверить стандартную функцию проверки isinf()
    //printf("%f is float max, %f is float min, %f is parameter", FLT_MAX, FLT_MIN, par);
    return par >= FLT_MAX || par <= -FLT_MAX;
}

static bool are_coefficients_infinity (float a, float b, float c) {
//  общая проверка коэффициентов на выход из допустимого диапазона
     // проверка на параметры не пройдена (как минимум один из них является бесконечностью, но возвращается true)
    return is_float_infinity(a) || is_float_infinity(b) || is_float_infinity(c); 
}

static bool are_coefficients_float(float *a, float *b, float *c) { // TODO: эта функция нахрен не сдалась (либо прописать обработку ошибок \\возможно с помощью структур//)
    return scanf("%f %f %f", a, b, c) == 3;
}

void show_coefficients_check(float *a, float *b, float *c) {
     while ((!are_coefficients_float(a, b, c) && clean_stdin()) || are_coefficients_infinity(*a, *b, *c)) { 
        printf("Wrong format. Try again!\n");
    }   
}