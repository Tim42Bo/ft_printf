/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %x%X.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 06:00:37 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 06:00:37 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_handle_hexadecimal(unsigned int num, int alphacase)
{
	const char		*hexdig;
	unsigned int	tmp;
	int				numdig;

	if (!num)
		return (write(1, "0", 1));
	tmp = num;
	numdig = 0;
	hexdig = ft_case(alphacase);
	if (hexdig == NULL)
		return (-1);
	while (tmp > 0)
	{
		tmp /= 16;
		numdig++;
	}
	if (num == 0)
		write(1, "0", 1);
	else
		ft_printhex(num, hexdig, numdig);
	return (ft_hexlen(num));
}
