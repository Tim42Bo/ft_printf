/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %c.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:47:54 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:47:54 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

int	ft_handle_char(va_list args)
{
	g_lobal.c = (char) va_arg(args, int);
	g_lobal.buffer = ((char *) malloc(2 * sizeof(char)));
	if (!g_lobal.buffer)
		return (-1);
	g_lobal.buffer[0] = g_lobal.c;
	g_lobal.buffer[1] = '\0';
	g_lobal.len = write(1, g_lobal.buffer, 1);
	free(g_lobal.buffer);
	return (g_lobal.len);
}
