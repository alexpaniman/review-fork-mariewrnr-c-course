#include "user_interface.h"
#include "helpin_checks_n_consts.h"
#include "solve_equation.h"
#include <stdio.h>
#include <string.h>

// UI functions | displaying equation

void display_equation_type(equation *equation_data) {
	switch(equation_data->eq_type) {
		case LINEAR_EQUATION:
			printf("This equation is linear!\n");
			break;
		case QUADRATIC_EQUATION:
			printf("This equation is quadratic!\n");
			break;
		case NO_EQUATION_TYPE:
			printf("The equation type is not set\n");
			break;
		default:
		 	printf("Unknown equation type.\n");
			break;
	}
}

void display_D(equation *equation_data) {
	printf("D = %.3f^2 - 4 * (%+.3f) * (%+.3f)\n", equation_data->b, equation_data->a, equation_data->c);
	printf("D = %.3f\n", equation_data->D);
	
}

void display_roots(equation *equation_data) {
	switch(equation_data->existing_roots) {
		case TWO_ROOTS:
			display_D(equation_data);
			printf("The equation has two roots:\n");
			printf("x1 = %.3f, x2 = %.3f\n", equation_data->solutions[0], equation_data->solutions[1]);
			break;

		case ONE_QUADRATIC_ROOT:
			display_D(equation_data);
			printf("The equation has one root\n");
			printf("x = %.3f\n", equation_data->solutions[0]);
			break;

		case ONE_LINEAR_ROOT:
			printf("The equation has one root:\n");
            printf("x = %.3f\n", equation_data->solutions[0]);
			break;

		case INFINITE_ROOTS:
			printf("That equation has infinite number of roots!\n");
			break;

		case NO_REAL_ROOTS:
			display_D(equation_data);
			printf("Discriminant is negative. The equation has no real roots\n");
			break;

		case NO_ANY_ROOTS:
			printf("That equation has no roots at all.\n");
			break;
		
		default:
		  	printf("Unknown root type.\n");
			break;
	}
}

void output_solution(equation *equation_data) {
	display_equation(equation_data);
	display_equation_type(equation_data);
	display_roots(equation_data);
	printf("Thank you for your attention!\n");
}


void show_coefficients_check(equation *equation_data) {
	printf("Please, enter coefficients a, b and c. Format: a b c;\n");
    while ((!(scanf("%f %f %f", &equation_data->a, &equation_data->b, &equation_data->c) == 3) && clean_stdin())
	|| are_coefficients_infinity(equation_data->a, equation_data->b, equation_data->c)) { 
		printf("Wrong format. Try again!\n");

    }   
}

void store_equation_part(float coef, char* exp, char* equation_buf) { // exp - степень;
	if (!is_equal(coef, 0)) {

		sprintf(equation_buf, "%s%+f%s", equation_buf, coef, exp); // записывает число в строковый буфер (по пути преобразовывая его)
		//printf("%s\n", equation_buf);
	}
	// return *part_buf;
}

void display_equation(equation *equation_data) {
	equation_data->equation_view[0] = '\0';
	store_equation_part(equation_data->a, "x^2", equation_data->equation_view);
	store_equation_part(equation_data->b, "x", equation_data->equation_view);
	store_equation_part(equation_data->c, "", equation_data->equation_view);
	

	printf("%s=0\n", equation_data->equation_view);
	  
}
