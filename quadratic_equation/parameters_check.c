#include "parameters_check.h"
#include <stdio.h>
#include <float.h>

// backend functions | for parameter check
bool clean_stdin() { 
    while (getchar() != '\n') {
        continue;       
    }

    return true;
}

bool my_is_inf(float par) {
    if (par < FLT_MAX && par > -FLT_MAX ) { // параметры не выходят за рамки - не являются бесконечностью    
        return false;
    }
    //printf("%f is float max, %f is float min, %f is parameter", FLT_MAX, FLT_MIN, par);
    return true;
}

bool check_pars_inf (float a, float b, float c) {
    if (my_is_inf(a) || my_is_inf(b) || my_is_inf(c)) { // проверка на параметры не пройдена (как минимум один из них является бесконечностью, но возвращается true)
        return true; 
    }
    return false;
}

bool scan_parameters(float *a, float *b, float *c) {
    if (scanf("%f %f %f", a, b, c) == 3) {
        return true;
    }
    return false;
}

void general_check_parameters(float *a, float *b, float *c) {
     while ((!scan_parameters(a, b, c) && clean_stdin()) || check_pars_inf(*a, *b, *c)) { 
        printf("Wrong format. Try again!\n");
    }   
}