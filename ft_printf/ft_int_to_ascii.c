#include "myprint.h"

void ft_int_to_ascii(int num, char *str)
{
    int i = 0;
    int is_negative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';
        num = num / 10;
    }

    if (is_negative)
        str[i++] = '-';

    str[i] = '\0';

    ft_strrev(str);
}
