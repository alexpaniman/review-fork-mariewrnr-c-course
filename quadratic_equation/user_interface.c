#include "user_interface.h"
#include <stdio.h>
#include <string.h>

// UI functions | displaying equation
void display_part_equation(float par, int exp) { // exp - степень, par - параметр | доработать
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
                printf("You probably didn't enter coefficents a and b (a = %f, b = %f). Resulted expression is not an equation.\n", a, b);
            }
            break;

        case 1:
            printf("Single Root is %f.\n", solutions[0]);
            break;

        case 2:
            printf("The equation has two roots: %f and %f.\n", solutions[0], solutions[1]);

    }
}