#include <check.h>

#include "../s21_decimal.h"

START_TEST(test_s21_is_less_1) {
  s21_decimal num1 = {{12345, 0, 0, 0x00020000}};
  s21_decimal num2 = {{67890, 0, 0, 0x00050000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(test_s21_is_less_2) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_3) {
  s21_decimal num1 = {{2, 0, 0, 0x80000000}};
  s21_decimal num2 = {{1, 0, 0, 0x80000000}};

  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_4) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};

  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_5) {
  s21_decimal num1 = {{1, 0, 0, 0x00010000}};
  s21_decimal num2 = {{1, 0, 0, 0}};

  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_6) {
  s21_decimal num1 = {{1, 0, 0, 0x80000000}};
  s21_decimal num2 = {{1, 0, 0, 0}};

  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_7) {
  s21_decimal num1 = {{1, 0, 0, 0x80000000}};
  s21_decimal num2 = {{1, 0, 0, 0}};

  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(test_s21_is_less_8) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_9) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(test_s21_is_less_10) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_11) {
  s21_decimal num1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(test_s21_is_less_12) {
  s21_decimal num1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_13) {
  s21_decimal num1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal num2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_14) {
  s21_decimal num1 = {{0xA, 0x0, 0x0, 0x10000}};
  s21_decimal num2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_15) {
  s21_decimal num1 = {{0xA, 0x0, 0x0, 0x10000}};
  s21_decimal num2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_16) {
  s21_decimal num1 = {{0xA, 0x0, 0x0, 0x10000}};
  s21_decimal num2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_17) {
  s21_decimal num1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  s21_decimal num2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_18) {
  s21_decimal num1 = {{0x0, 0x0, 0x0, 0x0}};  // 0
  s21_decimal num2 = {
      {0xA, 0x0, 0x0, 0x0010000}};  // 0.0000000000000000000000000001
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_19) {
  s21_decimal num2 = {{0xA, 0x0, 0x0, 0x10000}};
  s21_decimal num1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_20) {
  s21_decimal num1 = {{0xC8340001, 0x8881186E, 0x4A03CE6,
                       0x120000}};  //  // 1431655765.000000000000000001
  s21_decimal num2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};  // 1431655765.00000
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_21) {
  s21_decimal num2 = {{0xC8340001, 0x8881186E, 0x4A03CE6,
                       0x120000}};  // 1431655765.000000000000000001
  s21_decimal num1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};  // 1431655765.00000
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_22) {
  s21_decimal num1 = {{0xC8340001, 0x8881186E, 0x4A03CE6,
                       0x80120000}};  // 1431655765.000000000000000001
  s21_decimal num2 = {
      {0x5554D320, 0x8235, 0x0, 0x80050000}};  // -1431655765.00000
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_23) {
  s21_decimal num2 = {{0xC8340001, 0x8881186E, 0x4A03CE6,
                       0x80120000}};  // 1431655765.000000000000000001
  s21_decimal num1 = {
      {0x5554D320, 0x8235, 0x0, 0x80050000}};  // 1431655765.00000
  int result = s21_is_less(num1, num2);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(test_s21_is_less_24) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_25) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_26) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_27) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_28) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_29) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_30) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_31) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(test_s21_is_less_32) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x80170000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_33) {
  // -58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x80170000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_34) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_35) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_36) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 5596930204637261591.6377658369
  s21_decimal decimal2 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0xA0000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_37) {
  // 5596930204637261591.6377658369
  s21_decimal decimal1 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0xA0000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_38) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -5596930204637261591.6377658369
  s21_decimal decimal2 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0x800A0000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_39) {
  // -5596930204637261591.6377658369
  s21_decimal decimal1 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0x800A0000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(test_s21_is_less_40) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 47209772988309285293.155713691
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_41) {
  // 47209772988309285293.155713691
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_42) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -47209772988309285293.155713691
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x80090000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_is_less_43) {
  // -47209772988309285293.155713691
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x80090000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_is_less_44) {
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int result = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *s21_is_less_test(void) {
  Suite *s = suite_create("s21_is_less Tests");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_is_less_1);
  tcase_add_test(tc_core, test_s21_is_less_2);
  tcase_add_test(tc_core, test_s21_is_less_3);
  tcase_add_test(tc_core, test_s21_is_less_4);
  tcase_add_test(tc_core, test_s21_is_less_5);
  tcase_add_test(tc_core, test_s21_is_less_6);
  tcase_add_test(tc_core, test_s21_is_less_7);
  tcase_add_test(tc_core, test_s21_is_less_8);
  tcase_add_test(tc_core, test_s21_is_less_9);
  tcase_add_test(tc_core, test_s21_is_less_10);
  tcase_add_test(tc_core, test_s21_is_less_11);
  tcase_add_test(tc_core, test_s21_is_less_12);
  tcase_add_test(tc_core, test_s21_is_less_13);
  tcase_add_test(tc_core, test_s21_is_less_14);
  tcase_add_test(tc_core, test_s21_is_less_15);
  tcase_add_test(tc_core, test_s21_is_less_16);
  tcase_add_test(tc_core, test_s21_is_less_17);
  tcase_add_test(tc_core, test_s21_is_less_18);
  tcase_add_test(tc_core, test_s21_is_less_19);
  tcase_add_test(tc_core, test_s21_is_less_20);
  tcase_add_test(tc_core, test_s21_is_less_21);
  tcase_add_test(tc_core, test_s21_is_less_22);
  tcase_add_test(tc_core, test_s21_is_less_23);
  tcase_add_test(tc_core, test_s21_is_less_24);
  tcase_add_test(tc_core, test_s21_is_less_25);
  tcase_add_test(tc_core, test_s21_is_less_26);
  tcase_add_test(tc_core, test_s21_is_less_27);
  tcase_add_test(tc_core, test_s21_is_less_28);
  tcase_add_test(tc_core, test_s21_is_less_29);
  tcase_add_test(tc_core, test_s21_is_less_30);
  tcase_add_test(tc_core, test_s21_is_less_31);
  tcase_add_test(tc_core, test_s21_is_less_32);
  tcase_add_test(tc_core, test_s21_is_less_33);
  tcase_add_test(tc_core, test_s21_is_less_34);
  tcase_add_test(tc_core, test_s21_is_less_35);
  tcase_add_test(tc_core, test_s21_is_less_36);
  tcase_add_test(tc_core, test_s21_is_less_37);
  tcase_add_test(tc_core, test_s21_is_less_38);
  tcase_add_test(tc_core, test_s21_is_less_39);
  tcase_add_test(tc_core, test_s21_is_less_40);
  tcase_add_test(tc_core, test_s21_is_less_41);
  tcase_add_test(tc_core, test_s21_is_less_42);
  tcase_add_test(tc_core, test_s21_is_less_43);
  tcase_add_test(tc_core, test_s21_is_less_44);

  suite_add_tcase(s, tc_core);
  return s;
}
