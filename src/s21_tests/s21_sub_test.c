#include "../s21_tests.h"

START_TEST(sub_0) {
  s21_decimal val1 = {{15, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000010001,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000011110,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));

}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));

}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000000110,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000000110,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = {{8, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000001010,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000001010,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000001100,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{8, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000001000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111011,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));

}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111011,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_14) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b00000000000000000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111011,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_15) {
  s21_decimal val1 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111011,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_16) {
  s21_decimal val1 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b00000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));

}
END_TEST

START_TEST(sub_17) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_set_exp(&val1, 5);
  s21_set_exp(&val2, 3);
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b00000000000000000000000000000000}};
  s21_set_exp(&val1, 5);
  s21_set_exp(&val2, 3);
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST


START_TEST(sub_19) {
  s21_decimal val1 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010001010011,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_20) {
  s21_decimal val1 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010001010011,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_21) {
  s21_decimal val1 = {{123, 0, 0, 0b10000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010101001001,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

START_TEST(sub_22) {
  s21_decimal val1 = {{123, 0, 0, 0b10000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010101001001,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_23) {
  s21_decimal val1 = {{109, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010001100001,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_24) {
  s21_decimal val1 = {{109, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000001111000111,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_25) {
  s21_decimal val1 = {{109, 0, 0, 0b10000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010100111011,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

START_TEST(sub_26) {
  s21_decimal val1 = {{109, 0, 0, 0b10000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000010010111101,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000100000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_27) {
  s21_decimal val1 = {{999999, 0, 0, 0b00000000000010000000000000000000}};
  s21_decimal val2 = {{1, 0, 0,      0b00000000000010000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000011110100001000111110,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000010000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_28) {
  s21_decimal val1 = {{999999, 0, 0, 0b10000000000001000000000000000000}};
  s21_decimal val2 = {{1, 0, 0,      0b00000000000001000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000001100100,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1, s21_is_equal(res, answer));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_29) {
  s21_decimal val1 = {{100000, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal val2 = {{100, 0, 0,    0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000010011100000110,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

START_TEST(sub_30) {
  s21_decimal val1 = {{100000, 0, 0, 0b00000000000001010000000000000000}};
  s21_decimal val2 = {{100, 0, 0,    0b00000000000000100000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b10000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_31) {
  s21_decimal val1 = {{100000, 0, 0, 0b10000000000010100000000000000000}};
  s21_decimal val2 = {{100, 0, 0,    0b10000000000000100000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000011000011010011111,
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b00000000000001010000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_32) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{1, 0, 0,                            0b00000000000111000000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_33) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{5, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111110,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_34) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{5, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111110,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111110,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_35) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{6, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111110,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_36) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{6, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111110,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111110,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_37) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_38) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111110,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_39) {
  //  +79,228,162,514,264,337,593,543,950,335.
  // -0.5
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{5, 0, 0,                            0b10000000000000010000000000000000}};
  s21_decimal res;
  int status = s21_sub(val1, val2, &res);
  ck_assert_int_eq(1, status);
  
}
END_TEST

START_TEST(sub_40) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{5, 0, 0,                            0b10000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

START_TEST(sub_41) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{6, 0, 0,                            0b10000000000000010000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_42) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{6, 0, 0,                            0b10000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b00000000000000000000000000000000,
    0b00000000000000000000000000000000,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

START_TEST(sub_43) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0,                            0b10000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}
END_TEST

START_TEST(sub_44) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0,                            0b10000000000000010000000000000000}};
  s21_decimal res;
  s21_decimal answer = {
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111111,
    0b11111111111111111111111111111110,
    0b00000000000000000000000000000000
};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

START_TEST(sub_45) {
  s21_decimal val1 = {{5, 0, 0,                            0b00000000000000010000000000000000}};
  s21_decimal val2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0b00000000000000000000000000000000}};
  
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
  // s21_print_decimal(val1);
  // printf("\n");
  // s21_print_decimal(val2);
  // printf("\n");
  // s21_print_decimal(res);
  // printf("\n\n");
}

END_TEST

Suite *s21_sub_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_sub");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, sub_0);
	tcase_add_test(tc_core, sub_1);
	tcase_add_test(tc_core, sub_2);
	tcase_add_test(tc_core, sub_3);
	tcase_add_test(tc_core, sub_4);
	tcase_add_test(tc_core, sub_5);
	tcase_add_test(tc_core, sub_6);
	tcase_add_test(tc_core, sub_7);
	tcase_add_test(tc_core, sub_8);
	tcase_add_test(tc_core, sub_9);
	tcase_add_test(tc_core, sub_10);
	tcase_add_test(tc_core, sub_11);
	tcase_add_test(tc_core, sub_12);
	tcase_add_test(tc_core, sub_13);
	tcase_add_test(tc_core, sub_14);
	tcase_add_test(tc_core, sub_15);
	tcase_add_test(tc_core, sub_16);
	tcase_add_test(tc_core, sub_17);
	tcase_add_test(tc_core, sub_18);
	tcase_add_test(tc_core, sub_19);
	tcase_add_test(tc_core, sub_20);
	tcase_add_test(tc_core, sub_21);
	tcase_add_test(tc_core, sub_22);
	tcase_add_test(tc_core, sub_23);
	tcase_add_test(tc_core, sub_24);
	tcase_add_test(tc_core, sub_25);
	tcase_add_test(tc_core, sub_26);
	tcase_add_test(tc_core, sub_27);
	tcase_add_test(tc_core, sub_28);
	tcase_add_test(tc_core, sub_29);
	tcase_add_test(tc_core, sub_30);
	tcase_add_test(tc_core, sub_31);
	tcase_add_test(tc_core, sub_32);
	tcase_add_test(tc_core, sub_33);
	tcase_add_test(tc_core, sub_34);
	tcase_add_test(tc_core, sub_35);
	tcase_add_test(tc_core, sub_36);
	tcase_add_test(tc_core, sub_37);
	tcase_add_test(tc_core, sub_38);
	tcase_add_test(tc_core, sub_39);
	tcase_add_test(tc_core, sub_40);
	tcase_add_test(tc_core, sub_41);
	tcase_add_test(tc_core, sub_42);
	tcase_add_test(tc_core, sub_43);
	tcase_add_test(tc_core, sub_44);
	tcase_add_test(tc_core, sub_45);

	suite_add_tcase(s, tc_core);
	return s;

}