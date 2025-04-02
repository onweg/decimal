#include "../s21_tests.h"

START_TEST(test1) {
  s21_decimal d = {26, 0, 0, 0};
  s21_decimal b = {22, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal answer = {572, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test2) {
  s21_decimal d = {0, 0, 0, 0};
  s21_decimal b = {22, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal answer = {0, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test3) {
  s21_decimal d = {26, 0, 0, 0};
  s21_decimal b = {0, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal answer = {0, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test4) {
  s21_decimal d = {0, 0, 0, 0};
  s21_decimal b = {0, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal answer = {0, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test5) {
  s21_decimal d = {1, 0, 0, 0};
  s21_decimal b = {22, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal answer = {22, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test6) {
  s21_decimal d = {26, 0, 0, 0};
  s21_decimal b = {1, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal answer = {26, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test7) {
  s21_decimal d = {26, 0, 0, 0};
  s21_decimal b = {1, 0, 0, 0x80000000};
  s21_decimal res = {0};
  s21_decimal answer = {26, 0, 0, 0x80000000};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test8) {
  s21_decimal d = {1, 0, 0, 0};
  s21_decimal b = {26, 0, 0, 0x80000000};
  s21_decimal res = {0};
  s21_decimal answer = {26, 0, 0, 0x80000000};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test9) {
  s21_decimal d = {26, 0, 0, 0x80000000};
  s21_decimal b = {1, 0, 0, 0x80000000};
  s21_decimal res = {0};
  s21_decimal answer = {26, 0, 0, 0x0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test10) {
  s21_decimal d = {26, 0, 0, 0x80000000};
  s21_decimal b = {5, 0, 0, 0x80010000};
  s21_decimal res = {0};
  s21_decimal answer = {13, 0, 0, 0x0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  // s21_print_decimal(res);
  // printf("\n");
  // s21_print_decimal(answer);
  // printf("\n");
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test11) {
  s21_decimal d = {25, 0, 0, 0x80000000};
  s21_decimal b = {5, 0, 0, 0x80010000};
  s21_decimal res = {0};
  s21_decimal answer = {125, 0, 0, 0x10000};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test12) {
  s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000};
  s21_decimal res = {0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(2, status);
}
END_TEST

START_TEST(test13) {
  s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000};
  s21_decimal res = {0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(1, status);
}
END_TEST

START_TEST(test14) {
  // 1,0000000000000000000000000000 * 1,0000000000000000000000000000

  s21_decimal d = {0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000};
  s21_decimal b = {0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000};
  s21_decimal res = {0};
  s21_decimal answer = {1, 0, 0, 0};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

// START_TEST(test15) {
// 	//  7,9228162514264337593543950335 * 2 =
// 	// 15.845632502852867518708790067
// 	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
// 0x1C0000};
//     s21_decimal b = {2, 0, 0, 0};
//     s21_decimal res = {0};
//     s21_decimal answer = {0x33333333,
//     0x33333333, 0x33333333,
//     0x1B0000}; int status = s21_mul(d, b, &res);
//     ck_assert_int_eq(0, status);
// 	s21_print_decimal(res);
// 	printf("\n");
// 	s21_print_decimal(answer);
// 	printf("\n");
//     ck_assert_int_eq(1, s21_is_equal(res, answer));

// } END_TEST

// START_TEST(test16) {
// 	//  7,9228162514264337593543950335 * 3 =
// 	// 23.768448754279301278063185100
// 	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
// 0x1C0000};
//     s21_decimal b = {2, 0, 0, 0};
//     s21_decimal res = {0};
//     s21_decimal answer = {0xCCCCCCCC,
//     0xCCCCCCCC, 0x4CCCCCCC,
//     0x1B0000}; int status = s21_mul(d, b, &res);
//     ck_assert_int_eq(0, status);
//     ck_assert_int_eq(1, s21_is_equal(res, answer));

// } END_TEST

START_TEST(test17) {
  s21_decimal d = {123, 0, 0, 0x20000};
  s21_decimal b = {123, 0, 0, 0x20000};
  s21_decimal res = {0};
  s21_decimal answer = {15129, 0, 0, 0x40000};
  int status = s21_mul(d, b, &res);
  ck_assert_int_eq(0, status);
  // s21_print_decimal(res);
  // printf("\n");
  // s21_print_decimal(answer);
  // printf("\n");
  ck_assert_int_eq(1, s21_is_equal(res, answer));
}
END_TEST

START_TEST(test18) {
  s21_decimal val_1 = {{0x1c6bec8, 0x0, 0x0, 0x80000000}};  // -29802184
  s21_decimal val_2 = {
      {0xabad5278, 0x9432da5, 0x0, 0x120000}};  // 0.667427359354081912
  s21_decimal answer = {{0x36D7DC0, 0xC2B1439, 0x10740A,
                         0x80120000}};  // -19890792.970104470292495808
  s21_decimal result = {{0}};
  int status = s21_mul(val_1, val_2, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_is_equal(answer, result), 1);
}
END_TEST

START_TEST(test19) {
  s21_decimal val_1 = {{1, 0, 0, 0x001C0000}};
  s21_decimal val_2 = {{1, 0, 0, 0x001C0000}};
  s21_decimal answer = {{0, 0, 0, 0}};
  s21_decimal result = {{0}};
  int status = s21_mul(val_1, val_2, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_is_equal(answer, result), 1);
}
END_TEST

void init_decimal(s21_decimal *decimal, uint32_t bit0, uint32_t bit1,
                  uint32_t bit2, uint32_t bit3) {
  decimal->bits[0] = bit0;
  decimal->bits[1] = bit1;
  decimal->bits[2] = bit2;
  decimal->bits[3] = bit3;
}

START_TEST(test_mul_positive) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 10, 0, 0, 0);
  init_decimal(&value_2, 5, 0, 0, 0);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(result.bits[0], 50);
}
END_TEST

START_TEST(test_mul_negative) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 10, 0, 0, 0x80000000);
  init_decimal(&value_2, 5, 0, 0, 0x80000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(result.bits[0], 50);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_mul_diff_signs) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 10, 0, 0, 0);
  init_decimal(&value_2, 5, 0, 0, 0x80000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(result.bits[0], 50);
  ck_assert_int_eq((result.bits[3] >> 31) & 1, 1);
}
END_TEST

START_TEST(test_mul_diff_scales) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};
  init_decimal(&value_1, 100, 0, 0, 0x00020000);
  init_decimal(&value_2, 5, 0, 0, 0x00010000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 1);
}
END_TEST

START_TEST(test_mul_by_zero) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 10, 0, 0, 0);
  init_decimal(&value_2, 0, 0, 0, 0);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_mul_overflow) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 2, 0, 0, 0x00000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 1);
}
END_TEST

START_TEST(test_mul_loss_of_precision) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 1, 0, 0, 0x00010000);
  init_decimal(&value_2, 3, 0, 0, 0x00010000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 2);
}
END_TEST

START_TEST(test_mul_large_numbers) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 1, 0, 0, 0x00000000);
  s21_decimal answer = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0};

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(test_mul_max_scale) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 1, 0, 0, 0x001C0000);
  init_decimal(&value_2, 1, 0, 0, 0x0000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq((result.bits[3] >> 16) & 0xFF, 28);
}
END_TEST

START_TEST(test_mul_min_scale) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 123, 0, 0, 0x00000000);
  init_decimal(&value_2, 456, 0, 0, 0x00000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 56088);
  ck_assert_uint_eq(result.bits[3], 0x00000000);
}
END_TEST

START_TEST(test_mul_loss_of_precision_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 1, 0, 0, 0x00010000);
  init_decimal(&value_2, 3, 0, 0, 0x00020000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 3);
  ck_assert_uint_eq((result.bits[3] >> 16) & 0xFF, 3);
}
END_TEST

START_TEST(test_mul_overflow_negative) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 2, 0, 0, 0x80000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 2);
}
END_TEST

START_TEST(test_mul_diff_signs_and_scales) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 12345, 0, 0, 0x00030000);
  init_decimal(&value_2, 6789, 0, 0, 0x80020000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 83810205);
  ck_assert_uint_eq((result.bits[3] >> 31) & 1, 1);
  ck_assert_uint_eq((result.bits[3] >> 16) & 0xFF, 5);
}
END_TEST

START_TEST(test_mul_near_limits) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 2, 0, 0, 0x00000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 1);
}
END_TEST

START_TEST(test_mul_near_limits_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 2, 0, 0, 0x80000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 2);
}
END_TEST

START_TEST(test_mul_diff_signs_large_values) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 2);
}
END_TEST

START_TEST(test_mul_min_scale_large_values) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  init_decimal(&value_2, 1, 0, 0, 0x80000000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq((unsigned int)result.bits[0], (unsigned int)0xFFFFFFFF);
  ck_assert_uint_eq((unsigned int)result.bits[1], (unsigned int)0xFFFFFFFF);
  ck_assert_uint_eq((unsigned int)result.bits[2], (unsigned int)0xFFFFFFFF);
  ck_assert_uint_eq((unsigned int)result.bits[3], (unsigned int)0x80000000);
}
END_TEST

START_TEST(test_mul_diff_signs_and_scales_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 12345, 0, 0, 0x80030000);
  init_decimal(&value_2, 6789, 0, 0, 0x00020000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 83810205);
  ck_assert_uint_eq((result.bits[3] >> 31) & 1, 1);
  ck_assert_uint_eq((result.bits[3] >> 16) & 0xFF, 5);
}
END_TEST

START_TEST(test_mul_diff_signs_and_scales_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 12345, 0, 0, 0x00030000);
  init_decimal(&value_2, 6789, 0, 0, 0x80020000);
  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 83810205);
  ck_assert_uint_eq((result.bits[3] >> 31) & 1, 1);
  ck_assert_uint_eq((result.bits[3] >> 16) & 0xFF, 5);
}
END_TEST

START_TEST(test_mul_diff_signs_and_scales_4) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};

  init_decimal(&value_1, 12345, 0, 0, 0x80030000);
  init_decimal(&value_2, 6789, 0, 0, 0x80020000);

  int mul_result = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(mul_result, 0);
  ck_assert_uint_eq(result.bits[0], 83810205);
  ck_assert_uint_eq((result.bits[3] >> 31) & 1, 0);
  ck_assert_uint_eq((result.bits[3] >> 16) & 0xFF, 5);
}
END_TEST

Suite *s21_mul_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_mul");
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
  // tcase_add_test(tc_core, test15);
  // tcase_add_test(tc_core, test16);
  tcase_add_test(tc_core, test17);
  tcase_add_test(tc_core, test18);
  tcase_add_test(tc_core, test19);
  tcase_add_test(tc_core, test_mul_positive);
  tcase_add_test(tc_core, test_mul_negative);
  tcase_add_test(tc_core, test_mul_diff_signs);
  tcase_add_test(tc_core, test_mul_diff_scales);
  tcase_add_test(tc_core, test_mul_by_zero);
  tcase_add_test(tc_core, test_mul_overflow);
  tcase_add_test(tc_core, test_mul_loss_of_precision);
  tcase_add_test(tc_core, test_mul_large_numbers);
  tcase_add_test(tc_core, test_mul_max_scale);
  tcase_add_test(tc_core, test_mul_min_scale);
  tcase_add_test(tc_core, test_mul_loss_of_precision_2);
  tcase_add_test(tc_core, test_mul_overflow_negative);
  tcase_add_test(tc_core, test_mul_diff_signs_and_scales);
  tcase_add_test(tc_core, test_mul_near_limits);
  tcase_add_test(tc_core, test_mul_near_limits_2);
  tcase_add_test(tc_core, test_mul_diff_signs_large_values);
  tcase_add_test(tc_core, test_mul_min_scale_large_values);
  tcase_add_test(tc_core, test_mul_diff_signs_and_scales_2);
  tcase_add_test(tc_core, test_mul_diff_signs_and_scales_3);
  tcase_add_test(tc_core, test_mul_diff_signs_and_scales_4);

  suite_add_tcase(s, tc_core);
  return s;
}
