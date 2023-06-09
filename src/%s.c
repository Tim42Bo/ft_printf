/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %s.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:55:53 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:55:53 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

int	ft_handle_string(va_list args)
{
	char	*arg;
	size_t	len;
	int		returnlen;

	returnlen = 0;
	arg = va_arg(args, char *);
	len = ft_strlen(arg);
	g_lobal.buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!g_lobal.buffer)
		return (-1);
	ft_strncpy(g_lobal.buffer, arg, len);
	g_lobal.buffer[len] = '\0';
	returnlen = write(1, g_lobal.buffer, len);
	free(g_lobal.buffer);
	return (returnlen);
}
