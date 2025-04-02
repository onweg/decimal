#include "../s21_tests.h"

START_TEST(test1) {
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
		
	}
	{
		s21_decimal a = {0, 0, 0, 0b10000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}	
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b10000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000010000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {0, 0, 0, 0b10000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000010000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b10000000000010000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {0, 0, 0, 0b10000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b10000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
} END_TEST

START_TEST(test2) {
	{
		s21_decimal a = {1, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
		
	}
	{
		s21_decimal a = {1, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000010000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {1, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {1, 0, 0, 0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {1, 0, 0, 0b00000000000010000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {1, 0, 0, 0b00000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
} END_TEST

START_TEST(test3) {
	{
		s21_decimal a = {1000, 0, 0, 0b00000000000000110000000000000000};
		s21_decimal b = {1, 0, 0,    0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {10, 0, 0, 0b00000000000000010000000000000000};
		s21_decimal b = {1, 0, 0, 0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}
	{
		s21_decimal a = {10, 0, 0, 0b00000000000000100000000000000000};
		s21_decimal b = {0, 0, 0, 0b00000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {0, 0, 0, 0b00000000000000000000000000000000};
		s21_decimal b = {1000, 0, 0, 0b00000000000000000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
		s21_decimal b = {1, 0, 0, 0b00000000000010000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);
	}
	{
		s21_decimal a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
		s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 0);
	}

	{
		s21_decimal a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000};
		s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
		ck_assert_int_eq(s21_is_not_equal(a, b), 1);

	}
} END_TEST

Suite *s21_is_not_equal_test(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("s21_is_not_equal");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test1);
	tcase_add_test(tc_core, test2);
	tcase_add_test(tc_core, test3);

	suite_add_tcase(s, tc_core);
	return s;

}