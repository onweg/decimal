#pragma once
#include <check.h>

#include "s21_decimal.h"

void run_testcase(Suite *testcase);

Suite *s21_from_int_to_decima_test(void);
Suite *s21_from_decimal_to_int_test(void);
Suite *s21_from_float_to_decimal_test(void);
Suite *s21_from_decimal_to_float_test(void);

Suite *s21_is_less_test(void);
Suite *s21_is_less_or_equal_test(void);
Suite *s21_is_greater_test(void);
Suite *s21_is_greater_or_equal_test(void);
Suite *s21_is_equal_test(void);
Suite *s21_is_not_equal_test(void);

Suite *s21_floor_test(void);
Suite *s21_round_test(void);
Suite *s21_truncate_test(void);
Suite *s21_negate_test(void);

Suite *s21_add_test(void);
Suite *s21_sub_test(void);
Suite *s21_mul_test(void);
Suite *s21_div_test(void);

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check);