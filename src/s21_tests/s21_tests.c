#include "../s21_tests.h"
#include "../s21_decimal.h"

int main() {
    Suite* list_cases[] = { 
                            //
                            // s21_from_int_to_decimal_test(),
                            s21_from_decimal_to_int_test(),
                            s21_from_float_to_decimal_test(),
                            s21_from_decimal_to_float_test(),
                            s21_is_less_test(),
                            // s21_is_less_or_equal_test(),
                            s21_is_greater_test(),
                            // s21_is_greater_or_equal_test(),
                            s21_is_equal_test(),
                            // s21_is_not_equal_test(),
                            // s21_floor_test(),
                            // s21_round_test(),
                            s21_truncate_test(),
                            // s21_negate_test(),
                            s21_add_test(),
                            s21_sub_test(),
                            s21_mul_test(),
                            s21_div_test(),
                            s21_additional_function_test(),
                            NULL };

    for (Suite** current_testcase = list_cases; *current_testcase; current_testcase++) {
        run_testcase(*current_testcase);
    }

    // s21_decimal res = {0, 0, 0, 0};
	// s21_decimal answer = {0, 0, 0, 0};
	// float src = 12345.6789;
	// int status = s21_from_float_to_decimal(src, &res);

    return 0;
}

void run_testcase(Suite* testcase) {
    SRunner* sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
}

/*
FLT_MAX:        3.402823e+38
FLT_MIN:        1.175494e-38
FLT_TRUE_MIN:   1.401298e-45
FLT_EPSILON:    1.192093e-07
-FLT_EPSILON:   -1.192093e-07
INFINITY:       inf
-INFINITY:      -inf
NAN:            nan
Largest normal: 3.402823e+38
Smallest normal:-3.402823e+38
*/