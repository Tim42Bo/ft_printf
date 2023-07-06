/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 04:57:49 by tbornema          #+#    #+#             */
/*   Updated: 2023/07/06 11:13:08 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_lobal
{
	char			*buffer;
	int				len;
	int				i;
	unsigned int	nibble;
} g_bal;

int	ft_ptrlen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_initialize_buffer(const size_t buffer_len)
{
	g_bal.buffer = (char *)malloc(buffer_len);
	if (!g_bal.buffer)
		return (-1);
	else
		return (0);
}

void	ft_write_buffer(const size_t buffer_len)
{
	write(1, g_bal.buffer, buffer_len);
	free(g_bal.buffer);
}

void	ft_handle_null_pointer(void)
{
	write(1, "(nil)", 5);
}

size_t	ft_handle_non_null_pointer(void *ptr)
{
	uintptr_t	addr;
	int			hex_len;
	char		*hexlower;
	size_t		prefix_len;
	size_t		buffer_len;

	addr = (uintptr_t) ptr;
	hex_len = ft_ptrlen(addr);
	hexlower = "0123456789abcdef";
	prefix_len = 2;
	buffer_len = prefix_len + hex_len;
	ft_initialize_buffer(buffer_len);
	g_bal.i = 0;
	g_bal.buffer[0] = '0';
	g_bal.buffer[1] = 'x';
	while (g_bal.i < hex_len)
	{
		g_bal.nibble = ((uintptr_t)addr >> ((hex_len - g_bal.i - 1) * 4) & 0xf);
		g_bal.buffer[g_bal.i + prefix_len] = hexlower[g_bal.nibble];
		g_bal.i++;
	}
	ft_write_buffer(buffer_len);
	return (buffer_len);
}
