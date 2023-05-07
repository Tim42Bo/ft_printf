#include "myprint.h"

int specifier_skip(const char *fmt)
{
    int len = 0;
    while (*fmt != '\0') {
        len++;
        if (*fmt == '%') {
            // Found a specifier
            fmt++;
            len++;
            while (*fmt != '\0') {
                len++;
                if (is_specifier_type(*fmt)) {
                    // Found the end of the specifier
                    len++;
                    break;
                }
                fmt++;
            }
            break;
        }
        fmt++;
    }
    return len;
}
