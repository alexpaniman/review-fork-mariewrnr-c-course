#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <float.h>

// backend functions | for parameter check
bool clean_stdin() { 
    while (getchar() != '\n') {
        continue;       
    }
    return true;
}

bool my_is_inf(float par) {
    if (par != FLT_MAX && par != -FLT_MAX && par < FLT_MAX && par > -FLT_MAX ) { // параметры не выходят за рамки - не являются бесконечностью    
        return false;
    }
    //printf("%f is float max, %f is float min, %f is parameter", FLT_MAX, FLT_MIN, par);
    return true;
}

bool check_pars_inf (float a, float b, float c) {
    if (my_is_inf(a) || my_is_inf(b) || my_is_inf(c)) { // проверка на параметры не пройдена (как минимум один из них является бесконечностью, но возвращается true)
        return true; 
    }
    return false;
}

bool scan_parameters(float *a, float *b, float *c) {
    if (scanf("%f %f %f", a, b, c) == 3) {
        return true;
    }
    return false;
}

void general_check_parameters(float *a, float *b, float *c) {
     while ((!scan_parameters(a, b, c) && clean_stdin()) || check_pars_inf(*a, *b, *c)) { 
        printf("Wrong format. Try again!\n");

    }   
}

// backend functions | for solving equation 
float linear_solution(float b, float c) {
    return -c / b;
}

int quadratic_solution(float a, float b, float c, float solutions[], char no_roots[]) {
    float D = (b*b) - (4 * a * c);
    
    if (D > 0) {
        solutions[0] = (-b + sqrtf(D)) / (2 * a);
        solutions[1] = (-b - sqrtf(D)) / (2 * a);
        return 2;
    }

    else if (D == 0) {
        solutions[0] = -b / (2 * a);
        return 1;
    }

    else {
        strcpy(no_roots, "discr");
        printf("D = %.2f;\n", D); // перенести в описательную часть
        return 0;
    }
}

int solve_equation(float a, float b, float c, float solutions[], char no_roots[]) {

    if (a == 0) { 
        if (b == 0) { // two "if" is enough to make a conclusion that equation has no roots
            strcpy(no_roots, "coef");
            return 0;
        }

        printf("That equation is linear!\n"); // вынести в описательную часть
        solutions[0] = linear_solution(b, c);

        return 1;
    }
    
    return quadratic_solution(a, b, c, solutions, no_roots);
}

// UI functions | displaying equation
void display_part_equation(float par, unsigned int exp) { // exp - степень, par - параметр | доработать
    if (par > 0) {
        if (exp == 1 || exp == 0) {
            printf("+%.2f", par);
        }
        else {
            printf("%.2f", par);
        }
    }
    if (par < 0) {
        printf("%.2f", par);
    }

    switch(exp) {
        case 1:
            if (par != 0) {
            printf("x");
            }
            break;
        case 2:
            if (par != 0) {
                printf("x^2");
            }
            break;
        default:
            break;
    }


}

void display_equation(float a, float b, float c) {

    display_part_equation(a, 2);
    display_part_equation(b, 1);
    display_part_equation(c, 0);

    printf(" = 0\n");
      
}

void output_solutions(int q_solutions, float solutions[], char no_roots[], float a, float b) {
    switch(q_solutions) {
        case 0:
            if (strcmp(no_roots, "discr") == 0) {
                printf("Discriminant is negative. That equation has no real roots.\n");
                break;
            }
            
            else if (strcmp(no_roots, "coef") == 0) {
                printf("You probably didn't enter coefficents a and b (a = %.2f, b = %.2f). Resulted expression is not an equation.", a, b);
            }
            break;

        case 1:
            printf("Single Root is %.2f.", solutions[0]);
            break;

        case 2:
            printf("The equation has two roots: %.2f and %.2f.", solutions[0], solutions[1]);

    }
}

int main () {
    float a = 0, b = 0, c = 0;
    float solutions[2] = {0, 0};
    int q_solutions;
    char  no_roots[5]; // the reason why the equation has no roots;
    
// User suggests his own coefficents (a, b and c);
    printf("Please, enter coefficients a, b and c. Format: a b c;\n");

/* Coef check: only numbers; */
    general_check_parameters(&a, &b, &c);  

// Equation view
	display_equation(a, b, c);    

// Solving the equation
    q_solutions = solve_equation(a, b, c, solutions, no_roots); // need to display roots (or not to display)

// Output results
    output_solutions(q_solutions, solutions, no_roots, a, b);

    return 0;
}
