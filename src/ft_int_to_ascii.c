/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:12:21 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/05 08:12:21 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

void	ft_int_to_ascii(long long num, char *str)
{
	int		is_negative;
	size_t	i;

	i = 0;
	is_negative = 0;
	if (num == 0)
	{
		str[i++] = '\0';
		return ;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num != 0)
	{
		g_lobal.rem = num % 10;
		str[i++] = g_lobal.rem + '0';
		num = num / 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
}
