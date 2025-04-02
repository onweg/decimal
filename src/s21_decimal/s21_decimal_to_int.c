#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst){
    if (dst == NULL) { return 1; }
    s21_truncate(src, &src);
    int sign = s21_get_sign(src);

    if (src.bits[1] == 0 && src.bits[2] == 0) {
        unsigned int tmp = src.bits[0];
        if (sign == 0) {
            if (tmp > 2147483647) {
                return 1;
            } else  {
                *dst =  tmp;
            }
        } else {
            if (tmp > 2147483648) {
                return 1;
            } else  {
                *dst = (int)(-1 * (long)(tmp));
            }
        }
    }
    return 0;
}