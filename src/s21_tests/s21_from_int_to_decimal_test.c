#include "../s21_tests.h"

START_TEST(test1) {
	int a = 0;
	s21_decimal *res = NULL;
	int status = s21_from_int_to_decimal(a, res);
	ck_assert_int_eq(status, 1);
} END_TEST

START_TEST(test2) {
	int a = 1;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {1, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test3) {
	int a = -1;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {1, 0, 0, 0x80000000};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test4) {
	int a = 0;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {0, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test5) {
	int a = 2;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {2, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test6) {
	int a = 9;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {9, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test7) {
	int a = -9;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {9, 0, 0, 0x80000000};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test8) {
	int a =  2147483647;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {2147483647, 0, 0, 0};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test9) {
	int a = -2147483648;
	s21_decimal res;
	int status = s21_from_int_to_decimal(a, &res);
	s21_decimal answer = {2147483648, 0, 0, 0x80000000};
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST
Suite *s21_from_int_to_decimal_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_from_int_to_decimal");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test1);
	tcase_add_test(tc_core, test2);
	tcase_add_test(tc_core, test3);
	tcase_add_test(tc_core, test4);
	tcase_add_test(tc_core, test5);
	tcase_add_test(tc_core, test6);
	tcase_add_test(tc_core, test7);
	tcase_add_test(tc_core, test8);
	tcase_add_test(tc_core, test9);

	suite_add_tcase(s, tc_core);
	return s;

}