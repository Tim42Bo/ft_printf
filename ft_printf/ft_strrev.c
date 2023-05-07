#include "myprint.h"


void ft_strrev(char *str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}
