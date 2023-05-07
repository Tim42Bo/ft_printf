#include "myprint.h"

int handle_unsigned_decimal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int len = ft_uint_len(num);
    char *buffer = (char *) malloc((len + 1) * sizeof(char));
    if (!buffer)
        return -1;
    ft_uint_to_ascii(num, buffer);
    int ret = write(1, buffer, len);
    free(buffer);
    return ret;
}