#include "../s21_tests.h"

START_TEST(test1) {
	s21_decimal a = {0, 0, 0, 0};
	int status = s21_truncate(a, &a);
	s21_decimal answer = {0, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(a, answer));
} END_TEST

START_TEST(test2) {
	s21_decimal a = {0, 0, 0, 0};
	int status = s21_truncate(a, NULL);
	ck_assert_int_eq(status, 1);
} END_TEST

START_TEST(test3) {
	s21_decimal a = {5, 0, 0, 0};
	int status = s21_truncate(a, &a);
	s21_decimal answer = {5, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(a, answer));
} END_TEST

START_TEST(test4) {
	s21_decimal a = {5, 0, 0, 0x00010000};
	int status = s21_truncate(a, &a);
	s21_decimal answer = {0, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(a, answer));
} END_TEST

START_TEST(test5) {
	s21_decimal a = {123456789, 0, 0, 0x00050000};
	int status = s21_truncate(a, &a);
	s21_decimal answer = {1234, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(a, answer));
} END_TEST

START_TEST(test6) {
	s21_decimal a = {123456789, 0, 0, 0x00090000};
	int status = s21_truncate(a, &a);
	s21_decimal answer = {0, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(a, answer));
} END_TEST

START_TEST(test7) {
	s21_decimal a = {123456789, 0, 0, 0x00080000};
	int status = s21_truncate(a, &a);
	s21_decimal answer = {1, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(a, answer));
} END_TEST


Suite *s21_truncate_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_truncate");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test1);
	tcase_add_test(tc_core, test2);
	tcase_add_test(tc_core, test3);
	tcase_add_test(tc_core, test4);
	tcase_add_test(tc_core, test5);
	tcase_add_test(tc_core, test6);
	tcase_add_test(tc_core, test7);

	suite_add_tcase(s, tc_core);
	return s;

}