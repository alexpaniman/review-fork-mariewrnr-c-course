#include "solve_equation.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

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
