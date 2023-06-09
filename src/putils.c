/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 04:57:49 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/08 11:45:32 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lol;

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
	g_lol.buffer = (char *)malloc(buffer_len);
	if (!g_lol.buffer)
		return (-1);
	else
		return (0);
}

void	ft_write_buffer(const size_t buffer_len)
{
	write(1, g_lol.buffer, buffer_len);
	free(g_lol.buffer);
}

void	ft_handle_null_pointer(void)
{
	write(1, "(nil)\n", 5);
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
	buffer_len = prefix_len + hex_len + 1;
	ft_initialize_buffer(buffer_len);
	g_lol.i = 0;
	g_lol.buffer[0] = '0';
	g_lol.buffer[1] = 'x';
	while (g_lol.i < hex_len)
	{
		g_lol.nibble = ((uintptr_t)addr >> ((hex_len - g_lol.i - 1) * 4) & 0xf);
		g_lol.buffer[g_lol.i + prefix_len] = hexlower[g_lol.nibble];
		g_lol.i++;
	}
	g_lol.buffer[buffer_len - 1] = '\0';
	ft_write_buffer(buffer_len);
	return (buffer_len);
}
