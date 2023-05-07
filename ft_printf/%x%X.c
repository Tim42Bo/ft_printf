#include "myprint.h"

int handle_hexadecimal(unsigned int num, int uppercase)
{
    const char* hex_digits_lower = "0123456789abcdef";
    const char* hex_digits_upper = "0123456789ABCDEF";
    const char* hex_digits = (uppercase ? hex_digits_upper : hex_digits_lower);

    // calculate number of digits needed for the hex representation
    unsigned int tmp = num;
    int num_digits = 0;
    while (tmp > 0) {
        tmp /= 16;
        num_digits++;
    }
    if (num == 0) num_digits = 1;

    // allocate buffer for hex string representation
    char* buffer = (char*)malloc((num_digits + 1) * sizeof(char));
    if (buffer == NULL) return -1;

    // generate hex string representation
    buffer[num_digits] = '\0';
    for (int i = num_digits - 1; i >= 0; i--) {
        buffer[i] = hex_digits[num % 16];
        num /= 16;
    }

    // write hex string to stdout and free buffer
    int len = write(1, buffer, num_digits);
    free(buffer);
    return len;
}
