#include "myprint.h"

int handle_placeholder(const char *fmt, va_list args)
{
    
    int len = 0;
        // Handle %c specifier
        if (*fmt == 'c') {
            len += handle_char(args);
        }
        // Handle %s specifier
        if (*fmt == 's') {
            len += handle_string(args);
        }
        // Handle %p specifier
        if (*fmt == 'p') {
            void* arg = va_arg(args, void*);
            len += handle_pointer(arg);
        }
        // Handle %d and %i specifiers
        if (*fmt == 'd' || *fmt == 'i') {
            int arg = va_arg(args, int);
            len += handle_decimal(arg);
        }
        // Handle %u specifier
        if (*fmt == 'u') {
            len += handle_unsigned_decimal(args);
        }
        // Handle %x and %X specifiers
        if (*fmt == 'x' || *fmt == 'X') {
            unsigned int arg = va_arg(args, unsigned int);
            len += handle_hexadecimal(arg, (*fmt == 'X'));
        }
        // Handle %% specifier
        if (*fmt == '%') {
            len += handle_percent();
        }
        // Handle unknown specifier
        /*else {
            len += handle_unknown(fmt);
        }*/
    return len;
}
