/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %f2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 02:21:40 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/26 16:49:48 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_integral_part(int integral, int *num_digits)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc(15 * sizeof(char));
	if (buffer == NULL)
		return ;
	while (integral > 0)
	{
		buffer[*num_digits] = (char)('0' + (integral % 10));
		integral /= 10;
		(*num_digits)++;
	}
	i = *num_digits - 1;
	while (i >= 0)
	{
		write(1, &buffer[i], 1);
		i--;
	}
	free(buffer);
}

void	ft_write_fractional_part(double num, int precision)
{
	int	digit;
	int	i;

	i = 0;
	write(1, ".", 1);
	num -= (double)(int)num;
	while (i < precision)
	{
		i++;
		num *= 10;
		digit = (int)num;
		write(1, &"0123456789"[digit], 1);
		num -= (double)digit;
	}
}
