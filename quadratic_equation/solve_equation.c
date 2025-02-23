#include "solve_equation.h"
#include "helpin_checks_n_consts.h"
#include "equation_data.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// backend functions | for solving equation 

static equation_type define_equation_type(float a, float b) { // Define type of equation and save it at equation_data
    bool is_a_zero = is_equal(a, 0);
    bool is_b_zero = is_equal(b, 0);

	if (is_a_zero) {
        return is_b_zero ? NO_EQUATION_TYPE : LINEAR_EQUATION;
    }
    return QUADRATIC_EQUATION;
}

float calculate_discriminant(float a, float b, float c) { 
    return b * b - 4 * a * c;
}

float solve_linear_equation(float b, float c) {
    return -c / b;
}

void solve_quadratic_equation(equation *equation_data) {
    float a = equation_data->a;
    float b = equation_data->b;
    float c = equation_data->c;

    equation_data->D = calculate_discriminant(a, b, c);
   
    if (equation_data->D > 0) { // Case, when D > 0
        float sqrtf_D = sqrtf(equation_data->D);
        equation_data->solutions[0] = (-b + sqrtf_D) / (2 * a); 
        equation_data->solutions[1] = (-b - sqrtf_D) / (2 * a);
        equation_data->existing_roots = TWO_ROOTS;
    }

    else if (is_equal(equation_data->D, 0)) { // D = 0
        equation_data->solutions[0] = -b / (2 * a);
        equation_data->existing_roots = ONE_QUADRATIC_ROOT;
    }

    else { // D < 0
        equation_data->existing_roots = NO_REAL_ROOTS;
    }

}

void solve_equation(equation *equation_data) {

    equation_data->eq_type = define_equation_type(equation_data->a, equation_data->b); // Saving equation type

    switch(equation_data->eq_type) { // Choosing how to solve the equation
        case LINEAR_EQUATION:
            equation_data->solutions[0] = solve_linear_equation(equation_data->b, equation_data->c);
            approximate_to_zero(&equation_data->solutions[0]); // to cut off approximate part and "-" sign (like -0.0000000000000001 ~= 0.0)
            equation_data->existing_roots = ONE_LINEAR_ROOT;
            break;

        case QUADRATIC_EQUATION:
            solve_quadratic_equation(equation_data);
            if (equation_data->D >= 0) { // Only when the equation has at least one root!
                approximate_to_zero(&equation_data->solutions[0]); // to cut off approximate part and "-" sign (like -0.0000000000000001 ~= 0.0)
                approximate_to_zero(&equation_data->solutions[1]);
            }
            break;

        case NO_EQUATION_TYPE:
            bool is_c_zero = is_equal(equation_data->c, 0);

            if (is_c_zero) {
                equation_data->existing_roots = INFINITE_ROOTS;
            }
            else equation_data->existing_roots = NO_ANY_ROOTS;

            break;

        default:
            break;
    } 
}
