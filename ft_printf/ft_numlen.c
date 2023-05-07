#include "myprint.h"

size_t ft_numlen(long long num)
{
    size_t len = 0;
    if (num == 0)
        return 1;
    if (num < 0)
        len++; // for the '-' sign
    while (num)
    {
        num /= 10;
        len++;
    }
    return len;
}