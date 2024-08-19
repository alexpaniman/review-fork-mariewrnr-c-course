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
    int q_solutions;
    Errors error;
    //char  no_roots[5]; // the reason why the equation has no roots;
    
// User suggests his own coefficents (a, b and c); Позднее поставить как функцию интерфейса??
    printf("Please, enter coefficients a, b and c. Format: a b c;\n");

/* Coef check: only numbers; */
    general_check_parameters(&a, &b, &c);  

// Equation view
	display_equation(a, b, c);    

// Solving the equation
    q_solutions = solve_equation(a, b, c, solutions, &error); // need to display roots (or not to display)

// Output results
    output_solutions(q_solutions, solutions, error, a, b);

    return 0;
}
