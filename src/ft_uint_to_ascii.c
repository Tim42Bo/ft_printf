/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:28:43 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/05 08:28:43 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uint_to_ascii(unsigned long long num, char *buffer)
{
	int	len;
	int	i;

	len = ft_uint_len(num);
	i = len - 1;
	while (num != 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	buffer[len] = '\0';
}
