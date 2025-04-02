#include "../s21_tests.h"

START_TEST(test1) {
  s21_decimal *res = NULL;
  float src = 0;
  int status = s21_from_float_to_decimal(src, res);
  ck_assert_int_eq(status, 1);
}

START_TEST(test2) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {0, 0, 0, 0};
  float src = 0;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test3) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1, 0, 0, 0x00010000};
  float src = 0.1f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  // s21_print_decimal(res);
  // printf("\n");
  // s21_print_decimal(answer);
  // printf("\n");
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test4) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {123, 0, 0, 0};
  float src = 123;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test5) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1, 0, 0, 0x80010000};
  float src = -0.1;
  int status = s21_from_float_to_decimal(src, &res);

  // 	s21_print_decimal(res);
  // printf("\n");
  // s21_print_decimal(answer);
  // printf("\n");
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test6) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {123, 0, 0, 0x80010000};
  float src = -12.3;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test7) {
  s21_decimal res = {0, 0, 0, 0};
  float src = 3.402823e+37;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 1);
}

START_TEST(test8) {
  s21_decimal res = {0, 0, 0, 0};
  float src = 3.402823e+38;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 1);
}

START_TEST(test9) {
  s21_decimal res = {0, 0, 0, 0};
  float src = 1.192093e-07;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
}

START_TEST(test10) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1, 0, 0, 0};
  float src = 1.0f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test11) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1, 0, 0, 0};
  s21_set_sign(&answer, 1);
  float src = -1.0f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test12) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {123456, 0, 0, 0};
  s21_set_exp(&answer, 3);
  float src = 123.456f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test13) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {25, 0, 0, 0};
  s21_set_exp(&answer, 2);
  s21_set_sign(&answer, 1);
  float src = -0.25f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test14) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {123, 0, 0, 0};
  s21_set_exp(&answer, 6);
  float src = 0.000123f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test15) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1000000, 0, 0, 0};
  s21_set_exp(&answer, 0);
  float src = 1000000.0f;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test16) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1234568, 0, 0, 0x00070000};
  float src = 0.123456789;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test17) {
  s21_decimal res = {0, 0, 0, 0};
  s21_decimal answer = {1234568, 0, 0, 0x00020000};
  float src = 12345.6789;
  int status = s21_from_float_to_decimal(src, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

Suite *s21_from_float_to_decimal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_from_float_to_decimal");
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
