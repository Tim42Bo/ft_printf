#include "myprint.h"

int ft_uint_len(unsigned int num)
{
    int len = 0;
    do
    {
        len++;
        num /= 10;
    } while (num != 0);

    return len;
}