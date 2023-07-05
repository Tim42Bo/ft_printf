#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *test = NULL;

    int len1 = ft_printf("%jwea\n");
    printf("%d\n", len1);
    int len2 = printf("%jwea\n");
    printf("%d\n", len2);
}