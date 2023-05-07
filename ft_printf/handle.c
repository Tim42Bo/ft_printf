#include "myprint.h"

int handle_placeholder(const char *fmt, va_list args)
{
    int len = 0;

    // Handle %c specifier
    if (*fmt == 'c')
        len += handle_char(va_arg(args, int));

    // Handle %s specifier
    else if (*fmt == 's')
        len += handle_string(va_arg(args, char *));

    // Handle %p specifier
    else if (*fmt == 'p')
        len += handle_pointer(va_arg(args, void *));

    // Handle %d and %i specifiers
    else if (*fmt == 'd' || *fmt == 'i')
        len += handle_decimal(va_arg(args, int));

    // Handle %u specifier
    else if (*fmt == 'u')
        len += handle_unsigned_decimal(va_arg(args, unsigned int));

    // Handle %x and %X specifiers
    else if (*fmt == 'x' || *fmt == 'X')
        len += handle_hexadecimal(va_arg(args, unsigned int), (*fmt == 'X'));

    // Handle %% specifier
    else if (*fmt == '%')
        len += handle_percent();

    // Handle unknown specifier
    else
        len += handle_unknown(fmt);

    return (len);
}
