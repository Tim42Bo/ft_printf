/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:54:16 by tbornema          #+#    #+#             */
/*   Updated: 2023/07/05 18:54:16 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		{
			len += ft_handle_placeholder(&format[i + 1], args);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int main() {
   
    int num = -123;
    int num2 = -123;
    char c = 'A';
    char *str = "\"hello\"";
    void *ptr10 = &num;
    void *ptr20 = &num2;
    unsigned int u_num = 456;
    unsigned int hex_num = 0x123;
	void* ptr1 = NULL;
    printf("\noriginal\n\n");
    printf("Pointer 1 is %p\n", ptr1);
    printf("Pointer 2 is %p\n", ptr20);
    printf("Pointer 3 is %p\n", ptr10);
    
    ft_printf("\nmyprintf\n\n");
    ft_printf("Pointer 1 is %p\n", ptr1);
    ft_printf("Pointer 2 is %p\n", ptr20);
    ft_printf("Pointer 3 is %p\n", ptr10);

	printf("\noriginal\n\n");
	printf("Here are some variables: %% %d %s %c %u %x %X %i %p\n", 42, "hello", 'A', 123, 0x123, 0xABC, -42, ptr20);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Here are some variables: %% %d %s %c %u %x %X %i %p\n", 42, "hello", 'A', 123, 0x123, 0xABC, -42, ptr20);
	printf("\noriginal\n\n");
	printf("Signed decimal integer: %d\n", num);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Signed decimal integer: %d\n", num2);
	printf("\noriginal\n\n");
	printf("Signed decimal integer: %% %i\n", num);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Signed decimal integer: %% %i\n", num2);
	printf("\noriginal\n\n");
	printf("Character is %c\n", c);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Character is %c\n", c);
	printf("\noriginal\n\n");
	printf("String is %s\n", str);
	ft_printf("\nmyprintf\n\n");
	ft_printf("String is %s\n", str);
	printf("\noriginal\n\n");
	printf("Pointer is %p\n", ptr10);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Pointer is %p\n", ptr10);
	printf("\noriginal\n\n");
	printf("Unsigned decimal integer: %u\n", u_num);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Unsigned decimal integer: %u\n", u_num);
	printf("\noriginal\n\n");
	printf("Hexadecimal integer (lowercase): %x\n", hex_num);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Hexadecimal integer (lowercase): %x\n", hex_num);
	printf("\noriginal\n\n");
	printf("Hexadecimal integer (uppercase): %X\n", hex_num);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Hexadecimal integer (uppercase): %X\n", hex_num);
	printf("\noriginal\n\n");
	printf("Signed decimal integer: %d\n", -567);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Signed decimal integer: %d\n", -567);
	printf("\noriginal\n\n");
	printf("Signed decimal integer: %% %i\n", -567);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Signed decimal integer:  %% %i\n", -567);
	printf("\noriginal\n\n");
	printf("Character is %c\n", 'Z');
	ft_printf("\nmyprintf\n\n");
	ft_printf("Character is %c\n", 'Z');
	printf("\noriginal\n\n");
	printf("String is %s\n", "test");
	ft_printf("\nmyprintf\n\n");
	ft_printf("String is %s\n", "test");
	printf("\noriginal\n\n");
	printf("Pointer is %p\n", NULL);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Pointer is %p\n", NULL);
	printf("\noriginal\n\n");
	printf("Unsigned decimal integer: %u\n", 987654);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Unsigned decimal integer: %u\n", 987654);
	printf("\noriginal\n\n");
	printf("%x\n", 0);  // Prints hexadecimal value in lowercase: 7b
	printf("%X\n", 0);  // Prints hexadecimal value in uppercase: 7B
	ft_printf("\nmyprintf\n\n");
	ft_printf("%x\n", 0);  // Prints hexadecimal value in lowercase: 7b
	ft_printf("%X\n", 0);  // Prints hexadecimal value in uppercase: 7B
	printf("\noriginal\n\n");
	printf("Hexadecimal integer (lowercase): %x\n", 0xABCDEF);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Hexadecimal integer (lowercase): %x\n", 0xABCDEF);
	printf("\noriginal\n\n");
	printf("Hexadecimal integer (uppercase): %X\n", 0xABCDEF);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Hexadecimal integer (uppercase): %X\n", 0xABCDEF);
	printf("\noriginal\n\n");
	printf("String is %s\n", "This is a longer string for testing purposes");
	ft_printf("\nmyprintf\n\n");
	ft_printf("String is %s\n", "This is a longer string for testing purposes");
	printf("\noriginal\n\n");
	printf("Pointer is %p\n", (void*)-12345);
	ft_printf("\nmyprintf\n\n");
	ft_printf("Pointer is %p\n", (void*)-12345);


    
    
    return 0;
}
