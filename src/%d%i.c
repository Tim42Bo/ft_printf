/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %d%i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:53:32 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:53:32 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

int	ft_handle_decimal(int arg)
{
	int		ret;
	int		neg;

	neg = 0;
	if (arg < 0)
	{
		neg = 1;
		arg = -arg;
	}
	g_lobal.len = ft_numlen(arg) + neg;
	g_lobal.buffer = (char *) malloc((g_lobal.len + 1) * sizeof(char));
	if (!g_lobal.buffer)
		return (-1);
	if (neg)
		g_lobal.buffer[0] = '-';
	ft_int_to_ascii(arg, g_lobal.buffer + neg);
	ret = write(1, g_lobal.buffer, g_lobal.len);
	free(g_lobal.buffer);
	return (ret);
}
