#include "../s21_tests.h"

void s21_init_decimal(s21_decimal *decimal, uint32_t bit0, uint32_t bit1,
                      uint32_t bit2, uint32_t bit3) {
  decimal->bits[0] = bit0;
  decimal->bits[1] = bit1;
  decimal->bits[2] = bit2;
  decimal->bits[3] = bit3;
};

START_TEST(test1) {
	s21_decimal d = {0, 0, 0, 0};
    s21_decimal b = {0, 0, 0, 0};
    s21_decimal res = {0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(3, status);
} END_TEST

START_TEST(test2) {
	s21_decimal d = {100, 0, 0, 0};
    s21_decimal b = {0, 0, 0, 0};
    s21_decimal res = {0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(3, status);
} END_TEST

START_TEST(test3) {
	s21_decimal d = {100, 0, 0, 0x80000000};
    s21_decimal b = {0, 0, 0, 0};
    s21_decimal res = {0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(3, status);
} END_TEST

START_TEST(test4) {
	s21_decimal d = {4, 0, 0, 0x80000000};
    s21_decimal b = {2, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {2, 0, 0, 0x80000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test5) {
	s21_decimal d = {4, 0, 0, 0};
    s21_decimal b = {2, 0, 0, 0x80000000};
    s21_decimal res = {0};
	s21_decimal answer = {2, 0, 0, 0x80000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test6) {
	s21_decimal d = {4, 0, 0, 0x80000000};
    s21_decimal b = {2, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {2, 0, 0, 0x80000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test7) {
	s21_decimal d = {4, 0, 0, 0x80010000};
    s21_decimal b = {2, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {2, 0, 0, 0x80010000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test8) {
	s21_decimal d = {4, 0, 0, 0x00010000};
    s21_decimal b = {2, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {2, 0, 0, 0x00010000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test9) {
	s21_decimal d = {4, 0, 0, 0};
    s21_decimal b = {2, 0, 0, 0x00010000};
    s21_decimal res = {0};
	s21_decimal answer = {20, 0, 0, 0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test10) {
	s21_decimal d = {4, 0, 0, 0};
    s21_decimal b = {4, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {1, 0, 0, 0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST


START_TEST(test11) {
	s21_decimal d = {4, 0, 0, 0x00010000};
    s21_decimal b = {4, 0, 0, 0x00010000};
    s21_decimal res = {0};
	s21_decimal answer = {1, 0, 0, 0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test12) {
	s21_decimal d = {4, 0, 0, 0x00010000};
    s21_decimal b = {4, 0, 0, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {1, 0, 0, 0x00010000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test13) {
	s21_decimal d = {4, 0, 0, 0x00000000};
    s21_decimal b = {4, 0, 0, 0x00010000};
    s21_decimal res = {0};
	s21_decimal answer = {10, 0, 0, 0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test14) {
	s21_decimal d = {5, 0, 0, 0x00000000};
    s21_decimal b = {2, 0, 0, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {25, 0, 0, 0x00010000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test15) {
	s21_decimal d = {45, 0, 0, 0x00010000};
    s21_decimal b = {4, 0, 0, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {1125, 0, 0, 0x00030000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test16) {
	s21_decimal d = {45, 0, 0, 0x00000000};
    s21_decimal b = {40, 0, 0, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {1125, 0, 0, 0x00030000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test17) {
	s21_decimal d = {10, 0, 0, 0x00000000};
    s21_decimal b = {3, 0, 0, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {0b00110101010101010101010101010101, 0b11001111001001100000011111101110, 0b01101011101101001010111111100100, 0b00000000000111000000000000000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test18) {
  // 10 / 6 = 1.6666666666666666666666666667
	s21_decimal d = {10, 0, 0, 0x00000000};
    s21_decimal b = {6, 0, 0, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {0b00011010101010101010101010101011, 0b01100111100100110000001111110111, 0b00110101110110100101011111110010, 0b00000000000111000000000000000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test19) {
	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0x00000000};
    s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
    s21_decimal res = {0};
       
	s21_decimal answer = {0b01001000001011110111111111000011, 0b10011100100101010101001000000000, 0b00000011001110110010111000111100, 0b00000000000110110000000000000000}; // проверить
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test20) {
	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
    s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {0x00000001, 0, 0, 0};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test21) {
  // 792281625142643375935 / 782281625142643375931 = 1.0127831201431793474528374993
	s21_decimal d = {0b00011000011100111011111100111111, 0b11110011000111011100010001100001, 0b00000000000000000000000000101010, 0x00000000};
    s21_decimal b = {0b10001110100010111011111100111011, 0b01101000010101101010000101011100, 0b00000000000000000000000000101010, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {0b10011111011111000111000011010001, 0b10001110110101010011111010000000, 0b00100000101110011000101110101101, 0b00000000000111000000000000000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));
} END_TEST

START_TEST(test22) {
  // 79228162514264337593543950335 / 782281625142643375931 = 101278312.01431793474533993217
	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
    s21_decimal b = {0b10001110100010111011111100111011, 0b01101000010101101010000101011100, 0b00000000000000000000000000101010, 0x00000000};
    s21_decimal res = {0};
	s21_decimal answer = {0b10011111110100100010101100000001, 0b10001110110101010011111010000000, 0b00100000101110011000101110101101, 0b00000000000101000000000000000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));
  
} END_TEST

START_TEST(test23) {
     // 5 / 0.9 = 5.5555555555555555555555555556
	s21_decimal d =   {5, 0, 0, 0};
    s21_decimal b = {9, 0, 0, 0x00010000};
    s21_decimal res = {0};
	s21_decimal answer =  {0b00000011100011100011100011100100, 0b01011001001111110110001010001101, 0b10110011100000100111101001111101, 0b00000000000111000000000000000000};
    int status = s21_div(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test_div_by_zero) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 10, 0, 0, 0);
  s21_init_decimal(&divisor, 0, 0, 0, 0);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 3);
}
END_TEST

START_TEST(test_div_positive) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0);
  s21_init_decimal(&divisor, 5, 0, 0, 0);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 20);
}
END_TEST

START_TEST(test_div_negative) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0x80000000);
  s21_init_decimal(&divisor, 5, 0, 0, 0x80000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 20);
  ck_assert_int_eq((result.bits[3] >> 31) & 1, 0);
}
END_TEST

START_TEST(test_div_diff_signs) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0);
  s21_init_decimal(&divisor, 5, 0, 0, 0x80000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 20);
  ck_assert_int_eq((result.bits[3] >> 31) & 1, 1);
}
END_TEST

START_TEST(test_div_diff_scales) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0x00020000);
  s21_init_decimal(&divisor, 5, 0, 0, 0x00010000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 2);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 0);
}
END_TEST

START_TEST(test_div_overflow) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  s21_init_decimal(&divisor, 1, 0, 0, 0x00010000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 1);
}
END_TEST

START_TEST(test_div_zero_by_number) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 0, 0, 0, 0);
  s21_init_decimal(&divisor, 5, 0, 0, 0);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_div_large_by_small) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  s21_init_decimal(&divisor, 1, 0, 0, 0x00000000);

  int div_result = s21_div(dividend, divisor, &result);
  s21_decimal answer = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(1, s21_is_equal(result, answer));
}
END_TEST

START_TEST(test_div_by_self) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 123456, 0, 0, 0x00010000);
  s21_init_decimal(&divisor, 123456, 0, 0, 0x00010000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[3], 0x00000000);
}
END_TEST

START_TEST(test_div_by_self_1) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 123456, 0, 0, 0x00000000);
  s21_init_decimal(&divisor, 123456, 0, 0, 0x00000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[3], 0x00000000);
}
END_TEST

START_TEST(test_div_diff_scales_2) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 123456, 0, 0, 0x00020000);
  s21_init_decimal(&divisor, 123456, 0, 0, 0x00030000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 10);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 0);
}
END_TEST

START_TEST(test_div_negative_result) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0x80000000);
  s21_init_decimal(&divisor, 5, 0, 0, 0x00000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 20);
  ck_assert_int_eq((result.bits[3] >> 31) & 1, 1);
}
END_TEST

START_TEST(test_div_by_one) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 123456, 0, 0, 0x00020000);
  s21_init_decimal(&divisor, 1, 0, 0, 0x00000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 123456);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 2);
}
END_TEST

START_TEST(test_div_small_by_large) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 1, 0, 0, 0x00010000);
  s21_init_decimal(&divisor, 100, 0, 0, 0x00000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 3);
}
END_TEST

START_TEST(test_div_overflow_2) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);
  s21_init_decimal(&divisor, 0x00000001, 0x00000000, 0x00000000, 0x00010000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 1);
}
END_TEST

START_TEST(test_div_negative_dividend) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0x80000000);
  s21_init_decimal(&divisor, 5, 0, 0, 0x00000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 20);
  ck_assert_int_eq((result.bits[3] >> 31) & 1, 1);
}
END_TEST

START_TEST(test_div_negative_divisor) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 100, 0, 0, 0x00000000);
  s21_init_decimal(&divisor, 5, 0, 0, 0x80000000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 20);
  ck_assert_int_eq((result.bits[3] >> 31) & 1, 1);
}
END_TEST

START_TEST(test_div_overflow_minus) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000);
  s21_init_decimal(&divisor, 1, 0, 0, 0x00010000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 2);
}
END_TEST

START_TEST(test_div_large_scale) {
  s21_decimal dividend = {{0}};
  s21_decimal divisor = {{0}};
  s21_decimal result = {{0}};

  s21_init_decimal(&dividend, 123456789, 0, 0, 0x00070000);
  s21_init_decimal(&divisor, 123456789, 0, 0, 0x00070000);

  int div_result = s21_div(dividend, divisor, &result);

  ck_assert_int_eq(div_result, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq((result.bits[3] >> 16) & 0xFF, 0);
}
END_TEST


Suite *s21_div_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_div");
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
	tcase_add_test(tc_core, test18);
	tcase_add_test(tc_core, test19);
	tcase_add_test(tc_core, test20);
	tcase_add_test(tc_core, test21);
	tcase_add_test(tc_core, test22);
	tcase_add_test(tc_core, test23);
  tcase_add_test(tc_core, test_div_by_zero);
  tcase_add_test(tc_core, test_div_positive);
  tcase_add_test(tc_core, test_div_negative);
  tcase_add_test(tc_core, test_div_diff_signs);
  tcase_add_test(tc_core, test_div_diff_scales);
  tcase_add_test(tc_core, test_div_overflow);
  tcase_add_test(tc_core, test_div_zero_by_number);
  tcase_add_test(tc_core, test_div_large_by_small);
  tcase_add_test(tc_core, test_div_by_self);
  tcase_add_test(tc_core, test_div_by_self_1);
  tcase_add_test(tc_core, test_div_diff_scales_2);
  tcase_add_test(tc_core, test_div_negative_result);
  tcase_add_test(tc_core, test_div_by_one);
  tcase_add_test(tc_core, test_div_small_by_large);
  tcase_add_test(tc_core, test_div_overflow_2);
  tcase_add_test(tc_core, test_div_negative_dividend);
  tcase_add_test(tc_core, test_div_negative_divisor);
  tcase_add_test(tc_core, test_div_large_scale);
  tcase_add_test(tc_core, test_div_overflow_minus);
	

	suite_add_tcase(s, tc_core);
	return s;
}