/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:17:04 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/05 11:17:04 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_placeholder_1(const char *fmt, va_list args)
{
	int		len;
	int		iarg;
	void	*varg;

	len = 0;
	if (*fmt == 'c')
		len += ft_handle_char(args);
	else if (*fmt == 's')
		len += ft_handle_string(args);
	else if (*fmt == 'p')
	{
		varg = va_arg(args, void *);
		len += ft_handle_pointer(varg);
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		iarg = va_arg(args, int);
		len += ft_handle_decimal(iarg);
	}
	return (len);
}

int	ft_handle_placeholder_2(const char *fmt, va_list args)
{
	int	len;
	int	uarg;

	len = 0;
	if (*fmt == 'u')
		len += ft_handle_unsigned_decimal(args);
	else if (*fmt == 'x' || *fmt == 'X')
	{
		uarg = va_arg(args, unsigned int);
		len += ft_handle_hexadecimal(uarg, *fmt);
	}
	else if (*fmt == '%')
		len += ft_handle_percent();
	 else
	 	len += ft_handle_unknown(fmt);
	return (len);
}

int	ft_handle_placeholder(const char *fmt, va_list args)
{
	int	len;
	if (*fmt == 's' || *fmt == 'c' || *fmt == 'p' || *fmt == 'd' || *fmt == 'i')
		len = ft_handle_placeholder_1(fmt, args);
	else
		len = ft_handle_placeholder_2(fmt, args);
	return (len);
}
