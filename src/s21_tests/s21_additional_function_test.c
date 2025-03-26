#include "../s21_tests.h"

START_TEST(test1) {

	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0};
	s21_shift_bits_to_right(&d, 100);
	s21_decimal answer = {0, 0, 0, 0};
	ck_assert_int_eq(1, s21_is_equal(d, answer));
}END_TEST

Suite *s21_additional_function_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_additional_function_test");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test1);

	suite_add_tcase(s, tc_core);
	return s;

}