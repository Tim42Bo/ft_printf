#include "myprint.h"

int	ft_printf(const char *format, ...)
{
    int		i;
    int		len;
    va_list	args;

    i = 0;
    len = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
            len += handle_placeholder(&format[i], args);
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return (len);
}

int main()
{
    ft_printf("first test of %d", 3);
    return (0);
}