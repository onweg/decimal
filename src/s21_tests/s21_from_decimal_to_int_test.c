#include "../s21_tests.h"

START_TEST(test1) {
	s21_decimal a = {0, 0, 0, 0};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 0;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test2) {
	s21_decimal a = {1, 0, 0, 0};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 1;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test3) {
	s21_decimal a = {1, 0, 0, 0x80000000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = -1;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test4) {
	s21_decimal a = {1, 0, 0, 0x80010000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 0;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test5) {
	s21_decimal a = {5, 0, 0, 0x80010000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 0;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test6) {
	s21_decimal a = {9, 0, 0, 0x80010000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 0;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test7) {
	s21_decimal a = {90, 0, 0, 0x80010000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = -9;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test8) {
	s21_decimal a = {93, 0, 0, 0x00010000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 9;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test9) {
	s21_decimal a = {2147483647, 0, 0, 0};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 2147483647;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test10) {
	s21_decimal a = {2147483648, 0, 0, 0};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	ck_assert_int_eq(status, 1);
} END_TEST

START_TEST(test11) {
	s21_decimal a = {2147483646, 0, 0, 0};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 2147483646;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test12) {
	s21_decimal a = {2147483650, 0, 0, 0};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 2147483650;
	ck_assert_int_eq(status, 1);
} END_TEST

START_TEST(test13) {
	s21_decimal a = {2147483648, 0, 0, 0x80000000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = -2147483648;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test14) {
	s21_decimal a = {2147483647, 0, 0, 0x80000000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = -2147483647;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test15) {
	s21_decimal a = {2147483649, 0, 0, 0x80000000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	ck_assert_int_eq(status, 1);
} END_TEST

START_TEST(test16) {
	s21_decimal a = {2147483648, 0, 0, 0x00050000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = 21474;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST

START_TEST(test17) {
	s21_decimal a = {2147483647, 0, 0, 0x80050000};
	int res;
	int status = s21_from_decimal_to_int(a, &res);
	int answer = -21474;
	ck_assert_int_eq(status, 0);
	ck_assert_int_eq(res, answer);
} END_TEST


Suite *s21_from_decimal_to_int_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_from_decimal_to_int");
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
	tcase_add_test(tc_core, test10);
	tcase_add_test(tc_core, test11);
	tcase_add_test(tc_core, test12);
	tcase_add_test(tc_core, test13);
	tcase_add_test(tc_core, test14);
	tcase_add_test(tc_core, test15);
	tcase_add_test(tc_core, test16);
	tcase_add_test(tc_core, test17);

	suite_add_tcase(s, tc_core);
	return s;

}