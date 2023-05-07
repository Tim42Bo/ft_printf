#include "myprint.h"


int handle_float(double num, int precision)
{
    if (precision < 0) precision = 6;
    if (precision > 15) precision = 15;

    // handle negative number
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }

    // handle integral part
    int integral = (int)num;
    int num_digits = 0;
    if (integral == 0) {
        write(1, "0", 1);
        num_digits++;
    }
    else {
        char* buffer = (char*)malloc(15 * sizeof(char));
        if (buffer == NULL) return -1;

        // generate integral part string
        while (integral > 0) {
            buffer[num_digits++] = (char)('0' + (integral % 10));
            integral /= 10;
        }
        for (int i = num_digits - 1; i >= 0; i--) {
            write(1, &buffer[i], 1);
        }
        free(buffer);
    }

    // handle decimal part
    write(1, ".", 1);
    num -= (double)integral;
    for (int i = 0; i < precision; i++) {
        num *= 10;
        int digit = (int)num;
        write(1, &"0123456789"[digit], 1);
        num -= (double)digit;
    }

    return num_digits + 1 + precision;
}
