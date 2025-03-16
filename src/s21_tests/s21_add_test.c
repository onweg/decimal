#include "../s21_tests.h"

START_TEST(add_0) {
  s21_decimal val1 = {{15, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
//   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));

}
END_TEST

START_TEST(add_3) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));

}
END_TEST

START_TEST(add_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_6) {
  s21_decimal val1 = {{8, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_7) {
  s21_decimal val1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_9) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_10) {
  s21_decimal val1 = {{8, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));

}
END_TEST

START_TEST(add_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_14) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_15) {
  s21_decimal val1 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_16) {
  s21_decimal val1 = {{4, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));

}
END_TEST

START_TEST(add_17) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_set_exp(&val1, 5);
  s21_set_exp(&val2, 3);
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_18) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0b10000000000000000000000000000000}};
  s21_set_exp(&val1, 5);
  s21_set_exp(&val2, 3);
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST


START_TEST(add_19) {
  s21_decimal val1 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_20) {
  s21_decimal val1 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_21) {
  s21_decimal val1 = {{123, 0, 0, 0b10000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}

START_TEST(add_22) {
  s21_decimal val1 = {{123, 0, 0, 0b10000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_23) {
  s21_decimal val1 = {{109, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_24) {
  s21_decimal val1 = {{109, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_25) {
  s21_decimal val1 = {{109, 0, 0, 0b10000000000000100000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}

START_TEST(add_26) {
  s21_decimal val1 = {{109, 0, 0, 0b10000000000000010000000000000000}};
  s21_decimal val2 = {{123, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_27) {
  s21_decimal val1 = {{999999, 0, 0, 0b00000000000010000000000000000000}};
  s21_decimal val2 = {{1, 0, 0,      0b00000000000010000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_28) {
  s21_decimal val1 = {{999999, 0, 0, 0b10000000000001000000000000000000}};
  s21_decimal val2 = {{1, 0, 0,      0b10000000000001000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_29) {
  s21_decimal val1 = {{100000, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal val2 = {{100, 0, 0,    0b00000000000000010000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}

START_TEST(add_30) {
  s21_decimal val1 = {{100000, 0, 0, 0b00000000000001010000000000000000}};
  s21_decimal val2 = {{100, 0, 0,    0b00000000000000100000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_31) {
  s21_decimal val1 = {{100000, 0, 0, 0b00000000000001010000000000000000}};
  s21_decimal val2 = {{100, 0, 0,    0b00000000000000100000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  //   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

START_TEST(add_32) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  s21_decimal val2 = {{1, 0, 0,                            0b00000000000111000000000000000000}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
//   s21_print_decimal(val1);
//   printf("\n");
//   s21_print_decimal(val2);
//   printf("\n");
//   s21_print_decimal(res);
//   printf("\n\n");
}
END_TEST

Suite *s21_add_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_add");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, add_0);
	tcase_add_test(tc_core, add_1);
	tcase_add_test(tc_core, add_2);
	tcase_add_test(tc_core, add_3);
	tcase_add_test(tc_core, add_4);
	tcase_add_test(tc_core, add_5);
	tcase_add_test(tc_core, add_6);
	tcase_add_test(tc_core, add_7);
	tcase_add_test(tc_core, add_8);
	tcase_add_test(tc_core, add_9);
	tcase_add_test(tc_core, add_10);
	tcase_add_test(tc_core, add_11);
	tcase_add_test(tc_core, add_12);
	tcase_add_test(tc_core, add_13);
	tcase_add_test(tc_core, add_14);
	tcase_add_test(tc_core, add_15);
	tcase_add_test(tc_core, add_16);
	tcase_add_test(tc_core, add_17);
	tcase_add_test(tc_core, add_18);
	tcase_add_test(tc_core, add_19);
	tcase_add_test(tc_core, add_20);
	tcase_add_test(tc_core, add_21);
	tcase_add_test(tc_core, add_22);
	tcase_add_test(tc_core, add_23);
	tcase_add_test(tc_core, add_24);
	tcase_add_test(tc_core, add_25);
	tcase_add_test(tc_core, add_26);
	tcase_add_test(tc_core, add_27);
	tcase_add_test(tc_core, add_28);
	tcase_add_test(tc_core, add_29);
	tcase_add_test(tc_core, add_30);
	tcase_add_test(tc_core, add_31);
	tcase_add_test(tc_core, add_32);

	suite_add_tcase(s, tc_core);
	return s;

}