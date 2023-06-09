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

static t_globalvariable	g_lobal;

int	ft_handle_placeholder_1(const char *fmt, va_list args)
{
	t_globalvariable	g_lobal;

	g_lobal.len = 0;
	if (*fmt == 'c')
		g_lobal.len += ft_handle_char(args);
	else if (*fmt == 's')
		g_lobal.len += ft_handle_string(args);
	else if (*fmt == 'p')
	{
		g_lobal.varg = va_arg(args, void *);
		g_lobal.len += ft_handle_pointer(g_lobal.varg);
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		g_lobal.iarg = va_arg(args, int);
		g_lobal.len += ft_handle_decimal(g_lobal.iarg);
	}
	return (g_lobal.len);
}

int	ft_handle_placeholder_2(const char *fmt, va_list args)
{
	g_lobal.len = 0;
	if (*fmt == 'u')
		g_lobal.len += ft_handle_unsigned_decimal(args);
	else if (*fmt == 'x' || *fmt == 'X')
	{
		g_lobal.uarg = va_arg(args, unsigned int);
		g_lobal.len += ft_handle_hexadecimal(g_lobal.uarg, *fmt);
	}
	else if (*fmt == '%')
		g_lobal.len += ft_handle_percent();
	else
		g_lobal.len += ft_handle_unknown(fmt);
	return (g_lobal.len);
}

int	ft_handle_placeholder(const char *fmt, va_list args)
{
	int	len;

	len = ft_handle_placeholder_1(fmt, args);
	if (len == 0)
		len = ft_handle_placeholder_2(fmt, args);
	return (len);
}
