#include "../s21_tests.h"
#include "../s21_decimal.h"

int main() {
    Suite* list_cases[] = { 
                            //
                            // s21_from_int_to_decimal_test(),
                            s21_from_decimal_to_int_test(),
                            // s21_from_float_to_decimal_test(),
                            // s21_from_decimal_to_float_test(),
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
                            // s21_div_test(),
                            NULL };

    for (Suite** current_testcase = list_cases; *current_testcase; current_testcase++) {
        run_testcase(*current_testcase);
    }


    //  s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
    // s21_decimal b = {2, 0, 0, 0};
    // s21_decimal res = {0};
    // s21_decimal answer = {0b00110011001100110011001100110011, 0b00110011001100110011001100110011, 0b00110011001100110011001100110011, 0b00000000000110110000000000000000};
    // int status = s21_mul(d, b, &res);
	// s21_print_decimal(res);
	// printf("\n");
	// s21_print_decimal(answer);
	// printf("\n");

    return 0;
}

void run_testcase(Suite* testcase) {
    SRunner* sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
}