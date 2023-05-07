#include "myprint.h"

void ft_uint_to_ascii(unsigned int num, char* buffer)
{
    int len = ft_uint_len(num);
    int i = len - 1;

    do
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    } while (num != 0);
    buffer[len] = '\0';
}
