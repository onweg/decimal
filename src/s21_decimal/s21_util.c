// #include "../s21_decimal.h"
// #include <math.h>
// #include <stdio.h>

// void s21_dec_print(s21_decimal value) {
//     char result[50] = {0};
//     char temp[50] = {0};
//     char *cur_temp = temp;

//     uint32_t exponent = (value.bits[3] & S21_DEC_EXP_MASK) >> S21_DEC_EXP_SHIFT;
//     uint32_t sign = value.bits[3] & S21_DEC_SIGN_MASK;

//     uint32_t num_len = 0;
//     do {
//         uint32_t rem = 0;
//         for (int i = 2; i >= 0; i-- ) {
//             uint64_t current = ((uint64_t)rem << 32) | (uint64_t)value.bits[i];
//             value.bits[i] = (uint32_t) (current / 10);
//             rem = (uint32_t)(current % 10);
//         }
//         *cur_temp = rem + '0';
//         cur_temp++;
//         num_len++;

//     } while (value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0);


//     char *cur_char = result+48;
//     cur_temp = temp;
//     for (int i = 0; *cur_temp || i <= exponent ; i++) {
//         if (i == exponent) {
//             *cur_char-- = '.';
//         }
//         if (*cur_temp){
//             *cur_char-- = *cur_temp++;
//         } else {
//             *cur_char-- = '0';
//         }
//     }

//     printf("%s\n", cur_char+1);
// }


// int main() {
//     s21_decimal num = (s21_decimal){{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
//     for (int i = 0; i <= 28; i++) {
//         num.bits[3] = i << S21_DEC_EXP_SHIFT;
//         s21_dec_print(num);
//     }
// }
