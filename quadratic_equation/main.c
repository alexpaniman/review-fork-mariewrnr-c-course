#include "solve_equation.h"
#include "user_interface.h"
#include "equation_data.h"
//#include "recording_errors.h"
#include <stdio.h>

int main () {
    equation equation_data;

    show_coefficients_check(&equation_data);  

    solve_equation(&equation_data); // сначала ТОЛЬКО сопутствующие решению уравнения процедуры (определение типа ии последующее решение и запись в структуру)

    output_solution(&equation_data);

    return 0;
}