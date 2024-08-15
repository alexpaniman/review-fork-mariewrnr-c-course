#include "solve_equation.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

const float epsilon = 1e-6;

// backend functions | for solving equation 
bool compare(float num1, float num2) {
    float res = fabs(num1 - num2);
    return res <= epsilon;
}


float linear_solution(float b, float c) {
    return -c / b;
}

int quadratic_solution(float a, float b, float c, float solutions[], char no_roots[]) {
    float D = (b*b) - (4 * a * c);
    printf("%f D %f D - 0.0\n", D, D - 0.0);
    
    if (D > 0) {
        solutions[0] = (-b + sqrtf(D)) / (2 * a);
        solutions[1] = (-b - sqrtf(D)) / (2 * a);

        if (compare(solutions[0], 0))  {  // to cut off approximate part and "-" sign (like -0.0000000000000001 == 0.0)
            solutions[0] = 0;
        }
        if (compare(solutions[1], 0))  {
            solutions[1] = 0;
        }

        return 2;
    }

    else if (compare(D, 0)) {
        solutions[0] = -b / (2 * a);
        if (compare(solutions[0], 0))  {
            solutions[0] = 0;
        }
        return 1;
    }

    else if (D < 0) {
        strcpy(no_roots, "discr");
        //printf("D = %.2f;\n", D); // перенести в описательную часть
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
