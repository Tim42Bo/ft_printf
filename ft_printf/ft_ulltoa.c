#include "myprint.h"

char *ft_ulltoa(unsigned long long n)
{
    char *str = NULL;
    unsigned long long num = n;
    int len = 0;

    // Determine length of the resulting string
    do {
        len++;
        num /= 10;
    } while (num > 0);

    // Allocate memory for the resulting string
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return NULL;

    // Convert the number to a string in reverse order
    str[len] = '\0';
    do {
        len--;
        str[len] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    return str;
}