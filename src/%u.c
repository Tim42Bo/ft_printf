/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:58:17 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:58:17 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

int	ft_handle_unsigned_decimal(va_list args)
{
	unsigned int	num;
	int				ret;

	num = va_arg(args, unsigned int);
	g_lobal.len = ft_uint_len(num);
	g_lobal.buffer = (char *) malloc((g_lobal.len + 1) * sizeof(char));
	if (!g_lobal.buffer)
		return (-1);
	ft_uint_to_ascii(num, g_lobal.buffer);
	ret = write(1, g_lobal.buffer, g_lobal.len);
	free(g_lobal.buffer);
	return (ret);
}
