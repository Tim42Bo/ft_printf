/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:24:35 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/05 08:24:35 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(long long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
