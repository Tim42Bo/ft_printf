#include "myprint.h"

int handle_decimal(va_list args)
{
    int num = va_arg(args, int);
    int len = ft_num_len(num);
    char *buffer = (char *) malloc((len + 1) * sizeof(char));
    if (!buffer)
        return -1;
    ft_int_to_ascii(num, buffer);
    int ret = write(1, buffer, len);
    free(buffer);
    return ret;
}