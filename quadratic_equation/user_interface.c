#include "user_interface.h"
#include "solve_equation.h"
//#include "recording_errors.h"
#include <stdio.h>
#include <string.h>

// UI functions | displaying equation
void display_part_equation(float par, int exp, char sign) { // exp - степень, par - параметр, pos - позиция параметра (в начале не стоит знак "+")
	if (!is_equal(par, 0)) {
		switch(exp) {
			case 0:
				printf("%c%.4f", sign, par); // TODO: %+.4f | уменьшить кол-во printf
				break;
			case 1:
				printf("%c%.4fx", sign, par);
				break;
			case 2:
				printf("%c%.4fx^2", sign, par);
				break;
			default:
				break;
		}
	}
}

void display_equation(float a, float b, float c) {

	display_part_equation(a, 2, ' ');

	if (b > 0 && !is_equal(a, 0)) {
		display_part_equation(b, 1, '+');
	}
	else {
		display_part_equation(b, 1, ' ');
	}

	if (c > 0 && !(is_equal (a, 0) && is_equal(b, 0))) {
		display_part_equation(c, 0, '+');
	}
	else {
		display_part_equation(c, 0, ' ');
	}

	printf(" = 0\n");
	  
}

void output_solutions(int q_solutions, float solutions[], NoSolutionCases solution_case, float a, float b) {
	switch(q_solutions) { // TODO: убрать вложенности (switch in switch)//
		case 0:
			switch (solution_case) {
				case NEGATIVE_DISCRIMINANT:
					printf("%s\n", error_text[NEGATIVE_DISCRIMINANT]);
					break;
				break;
				case NO_COEFFICIENTS:
					printf("%s\n", error_text[NO_COEFFICIENTS]);
					break;
			default:
				break;
			}
		break;

		case 1:
			printf("Single Root is %f.\n", solutions[0]);
			break;

		case 2:
			printf("The equation has two roots: %f and %f.\n", solutions[0], solutions[1]);
		
		default:
		break;

	}
}