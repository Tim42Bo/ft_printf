/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:06:00 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/05 08:06:00 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	handle_pointer(void *ptr)
{
	if (ptr == NULL)
	{
		write(1,"(nil)\n",5);
		return (5);
	}
	else
	{
		const uintptr_t	addr = (uintptr_t) ptr;
		const size_t	hex_len = ft_ptrlen(addr);
		const char		hexlower[] = "0123456789abcdef";
		const size_t	prefix_len = 2;
		const size_t	buffer_len = prefix_len + hex_len + 1;
		unsigned int	nibble;

		g_lobal.buffer = (char *) malloc(buffer_len);
		if (!g_lobal.buffer)
		{
			return (-1);
		}
		g_lobal.buffer[0] = '0';
		g_lobal.buffer[1] = 'x';
		g_lobal.i = 0;
		while (g_lobal.i < hex_len)
		{
			nibble = (addr >> ((hex_len - g_lobal.i - 1) * 4) & 0xf);
			g_lobal.buffer[g_lobal.i + prefix_len] = hexlower[nibble];
			g_lobal.i++;
		}
		g_lobal.buffer[buffer_len - 1] = '\0';
		g_lobal.len = 0;
		g_lobal.len = write(1, g_lobal.buffer, buffer_len - 1);
		free(g_lobal.buffer);
		return (g_lobal.len);
	}
}*/

#include "ft_printf.h"

int	ft_handle_pointer(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
	{
		ft_handle_null_pointer();
		return (5);
	}
	else
	{
		len = ft_handle_non_null_pointer(ptr);
		return (len);
	}
}
