#include "myprint.h"


int is_specifier_type(char c)
{
    return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%');
}



int specifier_length(const char *specifier)
{
    int len = 0;

    // Count characters until a specifier type is found
    while (*specifier && !is_specifier_type(*specifier))
    {
        len++;
        specifier++;
    }

    // Include specifier type character in length count
    if (is_specifier_type(*specifier))
    {
        len++;
    }

    return len;
}


