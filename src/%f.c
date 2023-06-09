/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %f.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:47:54 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/09 06:02:30 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

int	ft_handle_float(double num, int precision)
{
	g_lobal.num_digits = 0;
	g_lobal.integral = (int)num;
	if (precision < 0)
		precision = 6;
	if (precision > 15)
		precision = 15;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (g_lobal.integral == 0)
	{
		write(1, "0", 1);
		g_lobal.num_digits++;
	}
	else
	{
		ft_write_integral_part(g_lobal.integral, &g_lobal.num_digits);
	}
	ft_write_fractional_part(num, precision);
	return (g_lobal.num_digits + 1 + precision);
}
