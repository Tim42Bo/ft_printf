/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %f.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:47:54 by tbornema          #+#    #+#             */
/*   Updated: 2023/07/06 13:17:00 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_lobal
{
	int	num_digits;
	int	integral;
} g_bal;

int	ft_handle_float(double num, int precision)
{
	if (!num)
		return (write(1, "0", 1));
	g_bal.num_digits = 0;
	g_bal.integral = (int)num;
	if (precision < 0)
		precision = 6;
	if (precision > 15)
		precision = 15;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (g_bal.integral == 0)
	{
		write(1, "0", 1);
		g_bal.num_digits++;
	}
	else
	{
		ft_write_integral_part(g_bal.integral, &g_bal.num_digits);
	}
	ft_write_fractional_part(num, precision);
	return (g_bal.num_digits + 1 + precision);
}
