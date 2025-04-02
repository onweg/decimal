#include "../s21_tests.h"

START_TEST(test1) {
  s21_decimal a = {0, 0, 0, 0};
  s21_decimal *res = NULL;
  int status = s21_round(a, res);
  ck_assert_int_eq(status, 1);
}

START_TEST(test2) {
  s21_decimal a = {0, 0, 0, 0};
  s21_decimal res;
  s21_decimal answer = {0, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test3) {
  s21_decimal a = {1, 0, 0, 0};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test4) {
  s21_decimal a = {1, 0, 0, 0x80000000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0x80000000};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test5) {
  s21_decimal a = {11, 0, 0, 0x00010000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test6) {
  s21_decimal a = {1199, 0, 0, 0x00030000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test7) {
  s21_decimal a = {19999, 0, 0, 0x00040000};
  s21_decimal res;
  s21_decimal answer = {2, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test8) {
  s21_decimal a = {15999, 0, 0, 0x00040000};
  s21_decimal res;
  s21_decimal answer = {2, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test9) {
  s21_decimal a = {11, 0, 0, 0x80010000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0x80000000};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test10) {
  s21_decimal a = {1199, 0, 0, 0x80030000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0x80000000};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test11) {
  s21_decimal a = {19999, 0, 0, 0x80040000};
  s21_decimal res;
  s21_decimal answer = {2, 0, 0, 0x80000000};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test12) {
  s21_decimal a = {15999, 0, 0, 0x80040000};
  s21_decimal res;
  s21_decimal answer = {2, 0, 0, 0x80000000};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test13) {
  s21_decimal a = {552, 0, 0, 0x00020000};
  s21_decimal res;
  s21_decimal answer = {6, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test14) {
  s21_decimal a = {549, 0, 0, 0x00030000};
  s21_decimal res;
  s21_decimal answer = {1, 0, 0, 0};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

START_TEST(test15) {
  s21_decimal a = {552, 0, 0, 0x80020000};
  s21_decimal res;
  s21_decimal answer = {6, 0, 0, 0x80000000};
  int status = s21_round(a, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}

Suite *s21_round_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_round");
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

  suite_add_tcase(s, tc_core);
  return s;
}
