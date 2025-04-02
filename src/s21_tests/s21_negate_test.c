#include "../s21_tests.h"

START_TEST(test1) {
  s21_decimal a = {0, 0, 0, 0};
  s21_decimal *res = NULL;
  int status = s21_negate(a, res);
  ck_assert_int_eq(status, 1);
}

START_TEST(test2) {
  s21_decimal a = {0, 0, 0, 0};
  s21_decimal res;
  s21_decimal answer = {0, 0, 0, 0};
  int status = s21_negate(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test3) {
  s21_decimal a = {1, 0, 0, 0};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0x80000000};
  int status = s21_negate(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
START_TEST(test4) {
  s21_decimal a = {1, 0, 0, 0x80000000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0};
  int status = s21_negate(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

Suite *s21_negate_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_negate");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test1);
  tcase_add_test(tc_core, test2);
  tcase_add_test(tc_core, test3);
  tcase_add_test(tc_core, test4);

  suite_add_tcase(s, tc_core);
  return s;
}
