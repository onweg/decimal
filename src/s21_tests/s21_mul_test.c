#include "../s21_tests.h"

START_TEST(test1) {
	s21_decimal d = {26, 0, 0, 0};
    s21_decimal b = {22, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {572, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test2) {
	s21_decimal d = {0, 0, 0, 0};
    s21_decimal b = {22, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {0, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test3) {
	s21_decimal d = {26, 0, 0, 0};
    s21_decimal b = {0, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {0, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test4) {
	s21_decimal d = {0, 0, 0, 0};
    s21_decimal b = {0, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {0, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test5) {
	s21_decimal d = {1, 0, 0, 0};
    s21_decimal b = {22, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {22, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test6) {
	s21_decimal d = {26, 0, 0, 0};
    s21_decimal b = {1, 0, 0, 0};
    s21_decimal res = {0};
	s21_decimal answer = {26, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test7) {
	s21_decimal d = {26, 0, 0, 0};
    s21_decimal b = {1, 0, 0, 0b10000000000000000000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {26, 0, 0, 0b10000000000000000000000000000000};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test8) {
	s21_decimal d = {1, 0, 0, 0};
    s21_decimal b = {26, 0, 0, 0b10000000000000000000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {26, 0, 0, 0b10000000000000000000000000000000};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test9) {
	s21_decimal d = {26, 0, 0, 0b10000000000000000000000000000000};
    s21_decimal b = {1, 0, 0, 0b10000000000000000000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {26, 0, 0, 0b00000000000000000000000000000000};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test10) {
	s21_decimal d = {26, 0, 0, 0b10000000000000000000000000000000};
    s21_decimal b = {5, 0, 0, 0b10000000000000010000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {13, 0, 0, 0b00000000000000000000000000000000};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
	// s21_print_decimal(res);
	// printf("\n");
	// s21_print_decimal(answer);
	// printf("\n");
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test11) {
	s21_decimal d = {25, 0, 0, 0b10000000000000000000000000000000};
    s21_decimal b = {5, 0, 0, 0b10000000000000010000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {125, 0, 0, 0b00000000000000010000000000000000};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

START_TEST(test12) {
	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000};
    s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000010000000000000000};
    s21_decimal res = {0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(2, status);

} END_TEST

START_TEST(test13) {
	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000};
    s21_decimal b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000010000000000000000};
    s21_decimal res = {0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(1, status);

} END_TEST

START_TEST(test14) {
	// 1,0000000000000000000000000000 * 1,0000000000000000000000000000

	s21_decimal d = {0b00010000000000000000000000000000, 0b00111110001001010000001001100001, 0b00100000010011111100111001011110, 0b10000000000111000000000000000000};
    s21_decimal b = {0b00010000000000000000000000000000, 0b00111110001001010000001001100001, 0b00100000010011111100111001011110, 0b10000000000111000000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {1, 0, 0, 0};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST

// START_TEST(test15) {
// 	//  7,9228162514264337593543950335 * 2 = 
// 	// 15.845632502852867518708790067
// 	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
//     s21_decimal b = {2, 0, 0, 0};
//     s21_decimal res = {0};
//     s21_decimal answer = {0b00110011001100110011001100110011, 0b00110011001100110011001100110011, 0b00110011001100110011001100110011, 0b00000000000110110000000000000000};
//     int status = s21_mul(d, b, &res);
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
// 	s21_decimal d = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000};
//     s21_decimal b = {2, 0, 0, 0};
//     s21_decimal res = {0};
//     s21_decimal answer = {0b11001100110011001100110011001100, 0b11001100110011001100110011001100, 0b01001100110011001100110011001100, 0b00000000000110110000000000000000};
//     int status = s21_mul(d, b, &res);
//     ck_assert_int_eq(0, status);
//     ck_assert_int_eq(1, s21_is_equal(res, answer));

// } END_TEST

START_TEST(test17) {
	s21_decimal d =        {123, 0, 0, 0b00000000000000100000000000000000};
    s21_decimal b =        {123, 0, 0, 0b00000000000000100000000000000000};
    s21_decimal res = {0};
	s21_decimal answer = {15129, 0, 0, 0b00000000000001000000000000000000};
    int status = s21_mul(d, b, &res);
    ck_assert_int_eq(0, status);
	// s21_print_decimal(res);
	// printf("\n");
	// s21_print_decimal(answer);
	// printf("\n");
    ck_assert_int_eq(1, s21_is_equal(res, answer));

} END_TEST



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

	suite_add_tcase(s, tc_core);
	return s;

}