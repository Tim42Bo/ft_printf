/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:56:50 by tbornema          #+#    #+#             */
/*   Updated: 2023/07/05 18:56:50 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int			ft_handle_char(va_list args);
int			ft_handle_string(va_list args);
int			ft_handle_pointer(void *ptr);
int			ft_handle_decimal(int arg);
int			ft_handle_unsigned_decimal(va_list args);
int			ft_handle_hexadecimal(unsigned int num, int uppercase);
int			ft_handle_percent(void);
int			ft_handle_unknown(const char *fmt);
int			ft_handle_placeholder(const char *format, va_list args);
int			ft_uint_len(unsigned int num);
int			ft_is_specifier_type(char c);
int			ft_specifier_length(const char *format);
int			ft_specifier_skip(const char *fmt);
int			ft_printf(const char *format, ...);
void		ft_int_to_ascii(long long num, char *str);
void		ft_uint_to_ascii(unsigned long long num, char *buffer);
char		*ft_ulltoa(unsigned long long n);
void		ft_strrev(char *str);
char		ft_get_specifier(const char *fmt);
void		ft_write_integral_part(int integral, int *num_digits);
void		ft_write_fractional_part(double num, int precision);
size_t		ft_numlen(long long num);
int			ft_ptrlen(uintptr_t num);
int			ft_initialize_buffer(const size_t buffer_len);
void		ft_write_buffer(const size_t buffer_len);
void		ft_handle_null_pointer(void);
size_t		ft_handle_non_null_pointer(void *ptr);
const char	*ft_case(int alphacase);
void		ft_printhex(unsigned int num, const char *hexdig, int numdig);
char		*ft_strncpy(char *dest, const char *src, size_t n);
size_t		ft_strlen(const char *str);

#endif
