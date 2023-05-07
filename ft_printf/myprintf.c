#include "myprint.h"

int ft_printf(const char *format, ...)
{
    int i = 0;
    int len = 0;
    va_list args;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            len += handle_placeholder(&format[i+1], args);
            i++;
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return len;
}

int main() {
   
    int num = -123;
    int num2 = -123;
    char c = 'A';
    char *str = "\"hello\"";
    void *ptr = &num;
    void *ptr2 = &num2;
    unsigned int u_num = 456;
    unsigned int hex_num = 0x123;

    printf("\noriginal\n\n");
    printf("Here are some variables: %% %d %s %c %u %x %X %i %p\n", 42, "hello", 'A', 123, 0x123, 0xABC, -42, ptr);
    printf("Signed decimal integer: %d\n", num);
    printf("Signed decimal integer: %% %i\n", num);
    printf("Character is %c\n", c);
    printf("String is %s\n", str);
    printf("Pointer is %p\n", ptr);
    printf("Unsigned decimal integer: %u\n", u_num);
    printf("Hexadecimal integer (lowercase): %x\n", hex_num);
    printf("Hexadecimal integer (uppercase): %X\n", hex_num);

    ft_printf("\nmyprintf\n\n");
    ft_printf("Here are some variables: %% %d %s %c %u %x %X %i %p\n", 42, "hello", 'A', 123, 0x123, 0xABC, -42, ptr2);
    ft_printf("Signed decimal integer: %d\n", num2);
    ft_printf("Signed decimal integer: %% %i\n", num2);
    ft_printf("Character is %c\n", c);
    ft_printf("String is %s\n", str);
    ft_printf("Pointer is %p\n", ptr2);
    ft_printf("Unsigned decimal integer: %u\n", u_num);
    ft_printf("Hexadecimal integer (lowercase): %x\n", hex_num);
    ft_printf("Hexadecimal integer (uppercase): %X\n", hex_num);

    
    
    return 0;
}

