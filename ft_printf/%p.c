#include "myprint.h"

int handle_pointer(void *ptr)
{
    const uintptr_t addr = (uintptr_t) ptr;
    const size_t hex_len = sizeof(uintptr_t) * 2; // hexadecimal length of uintptr_t
    const char hex_digits_lower[] = "0123456789abcdef";
    const size_t prefix_len = 2; // "0x" prefix length
    const size_t buffer_len = prefix_len + hex_len + 1; // add 1 for null-terminator
    char *buffer = (char *) malloc(buffer_len);
    if (!buffer) {
        return -1;
    }

    buffer[0] = '0';
    buffer[1] = 'x';

    for (size_t i = 0; i < hex_len; i++) {
        const uint8_t nibble = (addr >> ((hex_len - i - 1) * 4)) & 0xf;
        buffer[i + prefix_len] = hex_digits_lower[nibble];
    }
    buffer[buffer_len - 1] = '\0';

    const int len = write(1, buffer, buffer_len - 1);
    free(buffer);

    return len;
}

