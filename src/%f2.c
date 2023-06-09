/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %f2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 02:21:40 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/08 11:43:54 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

void	ft_write_integral_part(int integral, int *num_digits)
{
	g_lobal.buffer = (char *)malloc(15 * sizeof(char));
	if (g_lobal.buffer == NULL)
		return ;
	while (integral > 0)
	{
		g_lobal.buffer[*num_digits] = (char)('0' + (integral % 10));
		integral /= 10;
		(*num_digits)++;
	}
	g_lobal.i = *num_digits - 1;
	while (g_lobal.i >= 0)
	{
		write(1, &g_lobal.buffer[g_lobal.i], 1);
		g_lobal.i--;
	}
	free(g_lobal.buffer);
}

void	ft_write_fractional_part(double num, int precision)
{
	int	digit;

	write(1, ".", 1);
	num -= (double)(int)num;
	g_lobal.i = 0;
	while (g_lobal.i < precision)
	{
		g_lobal.i++;
		num *= 10;
		digit = (int)num;
		write(1, &"0123456789"[digit], 1);
		num -= (double)digit;
	}
}
