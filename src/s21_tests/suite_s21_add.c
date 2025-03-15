#include "../s21_test.h"

Suite *suite_s21_add(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_add");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test1);

	suite_add_tcase(s, tc_core);


}

START_TEST(test1) {
	ck_assert_int

}