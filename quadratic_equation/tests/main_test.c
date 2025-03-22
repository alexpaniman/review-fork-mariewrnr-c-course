#include "test_arithmetic.c"
//#include "../floating_arithmetic.h"
// работа с аргументами переменной длины (когда их количество меняется)
#include <stdarg.h>
// for working with NULL Objects
#include <stddef.h>
// exception handling
#include <setjmp.h>
#include <cmocka.h>


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_are_coefficients_infinity),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}