#include "parameters_check.h"
#include "solve_equation.h"
#include "user_interface.h"
#include "recording_errors.h"
#include <stdio.h>

char* error_text[] = {
    "Discriminant is negative. That equation has no real roots.\n",
    "You probably didn't enter coefficents a and b (a = %f, b = %f). Resulted expression is not an equation.\n"
            
};


int main () {
    float a = 0, b = 0, c = 0;
    float solutions[2] = {0, 0};
    
    NoSolutionCases solution_case;
    
// User suggests his own coefficents (a, b and c); Позднее поставить как функцию интерфейса??
    printf("Please, enter coefficients a, b and c. Format: a b c;\n");

/* Coef check: only numbers; */
    show_coefficients_check(&a, &b, &c);  

// Equation view
	display_equation(a, b, c);    

// Solving the equation
    int q_solutions = solve_equation(a, b, c, solutions, &solution_case); // need to display roots (or not to display)

// Output results
    output_solutions(q_solutions, solutions, solution_case, a, b);

    return 0;
}
