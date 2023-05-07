#ifndef MYPRINT_H
# define MYPRINT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int handle_char(va_list args);
int handle_string(va_list args);
int handle_pointer(void *ptr);
int handle_decimal(int arg);
int handle_unsigned_decimal(va_list args);
int handle_hexadecimal(unsigned int num, int uppercase);
int handle_percent();

int handle_placeholder(const char *format, va_list args);

size_t ft_numlen(long long num);
int ft_uint_len(unsigned int num);
void ft_int_to_ascii(long long num, char *str);
void ft_uint_to_ascii(unsigned long long num, char *buffer);
char *ft_ulltoa(unsigned long long n);
void ft_strrev(char *str);
int is_specifier_type(char c);
int specifier_length(const char *format);
char get_specifier(const char *fmt);
int specifier_skip(const char *fmt);


int ft_printf(const char *format, ...);

#endif
