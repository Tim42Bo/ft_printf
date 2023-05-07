#include "myprint.h"

int handle_decimal(int arg)
{
    int len = ft_numlen(arg);
    char *buffer = (char *) malloc((len + 1) * sizeof(char));
    if (!buffer)
        return -1;
    ft_int_to_ascii(arg, buffer);
    int ret = write(1, buffer, len);
    free(buffer);
    return ret;
}