#include "equation_data.h"
#include "solve_equation.h"
#include "user_interface.h"
#include <stdio.h>

// TODO: try to write docs using Doxygen
// TODO: try to write automatic tests (you can do it fully on your own or you can use googletest)

int main () {
    equation equation_data; // TODO: good defensive practice: zero everything with = {}

    show_coefficients_check(&equation_data);  
    solve_equation(&equation_data);
    output_solution(&equation_data);

    // TODO: you can have explicit data flow:
    // quadratic_equation equation = read_equation(); 
    // quadratic_equation_solution solution = solve_equation(&equation); 
    // print_quadratic_solution(&solution);

    return 0;
}
