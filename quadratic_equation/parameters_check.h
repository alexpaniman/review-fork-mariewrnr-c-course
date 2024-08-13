#ifndef PARAMETERS_CHECK_H
#define PARAMETERS_CHECK_H
#include <stdbool.h>

bool clean_stdin();

bool my_is_inf(float par);

bool check_pars_inf (float a, float b, float c);

bool scan_parameters(float *a, float *b, float *c);

void general_check_parameters(float *a, float *b, float *c);

#endif