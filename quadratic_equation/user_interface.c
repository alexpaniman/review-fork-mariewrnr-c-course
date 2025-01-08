#include "user_interface.h"
#include "solve_equation.h"
//#include "recording_errors.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// UI functions | displaying equation

// void output_user_interface(UserOutput phrase) {
// 	switch(phrase) {
// 		case ENTER_COEFFICIENTS:
// 			printf("Please, enter coefficients a, b and c. Format: a b c;\n");
// 			break;
// 		case ERROR_INPUT:
// 			printf("Wrong format. Try again!\n");
// 			break;
// 		default:
// 			break;
// 	}
// }

static bool clean_stdin() {
    while (getchar() != '\n') {
        continue;       
    }

    return true;
}

static bool are_coefficients_infinity (float a, float b, float c) {
//  общая проверка на бесконечность
    return isinf(a) || isinf(b) || isinf(c); 
}

void show_coefficients_check(equation *equation_data) {
	// output_user_interface(ENTER_COEFFICIENTS);
	printf("Please, enter coefficients a, b and c. Format: a b c;\n");
    while ((!(scanf("%f %f %f", &equation_data->a, &equation_data->b, &equation_data->c) == 3) && clean_stdin()) || 
            are_coefficients_infinity(equation_data->a, equation_data->b, equation_data->c)) { 
				printf("Wrong format. Try again!\n");
			// output_user_interface(ERROR_INPUT);
			
    }   
}

void output_solution(equation *equation_data) {
	display_equation(equation_data);
	// выписать все остальное сюда
}

void store_equation_part(float coef, char* exp, char* equation_buf) { // exp - степень; TODO: пополнение строки должно производиться через буфер
	if (!is_equal(coef, 0)) {

		sprintf(equation_buf, "%s%+f%s", equation_buf, coef, exp); // записывает число в строковый буфер (по пути преобразовывая его)
		//printf("%s\n", equation_buf);
	}
	// return *part_buf;
}

void display_equation(equation *equation_data) {
	equation_data->equation_view[0] = '\0';
    //equation_data->equation_view = (char*)malloc(100*sizeof(char)); TODO: спросить у Саши (в целом про alloc и почему это не всегда нужно)
	store_equation_part(equation_data->a, "x^2", equation_data->equation_view);
	store_equation_part(equation_data->b, "x", equation_data->equation_view);
	store_equation_part(equation_data->c, " ", equation_data->equation_view);
	

	printf("%s", equation_data->equation_view);
	  
}

// void output_solutions(int q_solutions, float solutions[], float a, float b) {
// 	switch(q_solutions) { // TODO: убрать вложенности (switch in switch)//
// 		case 0:
// 			switch (solution_case) {
// 				case NEGATIVE_DISCRIMINANT:
// 					printf("%s\n", error_text[NEGATIVE_DISCRIMINANT]);
// 					break;
// 				break;
// 				case NO_COEFFICIENTS:
// 					printf("%s\n", error_text[NO_COEFFICIENTS]);
// 					break;
// 			default:
// 				break;
// 			}
// 		break;

// 		case 1:
// 			printf("Single Root is %f.\n", solutions[0]);
// 			break;

// 		case 2:
// 			printf("The equation has two roots: %f and %f.\n", solutions[0], solutions[1]);
		
// 		default:
// 		break;

// 	}
// }