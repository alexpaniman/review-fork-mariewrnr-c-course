#include "equation_data.h"
#include "solve_equation.h"
#include "user_interface.h"
#include <stdio.h>

int main () {
    equation equation_data;

    show_coefficients_check(&equation_data);  
    solve_equation(&equation_data);
    output_solution(&equation_data);

    return 0;
}