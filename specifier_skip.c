/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_skip.c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:10:28 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/09 06:12:10 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier_skip(const char *fmt)
{
	int	len;

	len = 0;
	while (*fmt != '\0')
	{
		len++;
		if (*fmt == '%')
		{
			fmt++;
			len++;
			while (*fmt != '\0')
			{
				len++;
				if (ft_is_specifier_type(*fmt))
				{
					len++;
					break ;
				}
				fmt++;
			}
			break ;
		}
		fmt++;
	}
	return (len);
}
