/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %f.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:47:54 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/26 16:45:31 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_float(double num, int precision)
{
	int	num_digits;
	int	integral;

	num_digits = 0;
	integral = (int)num;
	if (precision < 0)
		precision = 6;
	if (precision > 15)
		precision = 15;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (integral == 0)
	{
		write(1, "0", 1);
		num_digits++;
	}
	else
	{
		ft_write_integral_part(integral, &num_digits);
	}
	ft_write_fractional_part(num, precision);
	return (num_digits + 1 + precision);
}
