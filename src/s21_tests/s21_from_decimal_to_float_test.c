#include "../s21_tests.h"

START_TEST(test1) {
	s21_decimal src = {0, 0, 0, 0};
	float *res = NULL;
	int status = s21_from_decimal_to_float(src, res);
	ck_assert_int_eq(status, 1);
}

START_TEST(test2) {
	s21_decimal src = {0, 0, 0, 0};
	float answer = 0;
	float res = 0;
	int status = s21_from_decimal_to_float(src, &res);
	ck_assert_int_eq(status, 0);
	ck_assert_float_eq(res, answer);
}

START_TEST(test3) {
	s21_decimal src = {1, 0, 0, 0x00010000};
	float answer = 0.1f;
	float res;
	int status = s21_from_decimal_to_float(src, &res);
	ck_assert_int_eq(status, 0);
	// s21_print_decimal(res);
	// printf("\n");
	// s21_print_decimal(answer);
	// printf("\n");
	ck_assert_float_eq(res, answer);
}

START_TEST(test4) {
	s21_decimal src = {123, 0, 0, 0};
	float answer = 123;
	float res;
	int status = s21_from_decimal_to_float(src, &res);
	ck_assert_int_eq(status, 0);
	ck_assert_float_eq(res, answer);
}


START_TEST(test5) {
	s21_decimal src = {1, 0, 0, 0x80010000};
	float answer = -0.1f;
	float res;
	int status = s21_from_decimal_to_float(src, &res);

	// 	s21_print_decimal(res);
	// printf("\n");
	// s21_print_decimal(answer);
	// printf("\n");
	ck_assert_int_eq(status, 0);
	ck_assert_float_eq(res, answer);
}

START_TEST(test6) {
	s21_decimal src = {123, 0, 0, 0x80010000};
	float answer = -12.3;
	float res;
	int status = s21_from_decimal_to_float(src, &res);
	ck_assert_int_eq(status, 0);
	ck_assert_float_eq(res, answer);
}

START_TEST(test7) {
    s21_decimal src = {0x470DE710, 0, 0, 0x00090000};
    float answer = 1.192093;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
	ck_assert_float_eq(res, answer);
}

START_TEST(test8) {
    s21_decimal src = {1, 0, 0, 0};
    float answer = 1.0f;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test9) {
    s21_decimal src =  {1, 0, 0, 0x80000100};
    float answer = -1.0f;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test10) {
    s21_decimal src = {123456, 0, 0, 0x00030000};
    float answer = 123.456f;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test11) {
    s21_decimal src = {25, 0, 0, 0x80020000};
    float answer = -0.25f;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test12) {
    s21_decimal src = {123, 0, 0, 0x00060000};
    float answer = 0.000123f;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test13) {
    s21_decimal src = {1000000, 0, 0, 0}; 
    float answer = 1000000.0f;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test14) {
    s21_decimal src = {123456789, 0, 0, 0x00090000};
    float answer =  0.1234568;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test15) {
    s21_decimal src = {123456789, 0, 0, 0x00040000}; 
    float answer = 12345.68;
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 0);
    ck_assert_float_eq(res, answer);
}

START_TEST(test16) {
    s21_decimal src = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}; 
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 1);
}
START_TEST(test17) {
    s21_decimal src = {1, 0, 0, 0x001D0000}; 
    float res;
    int status = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(status, 1);
}




Suite *s21_from_decimal_to_float_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_from_decimal_to_float");
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