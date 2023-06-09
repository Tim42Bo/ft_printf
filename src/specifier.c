/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:59:29 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/09 06:12:50 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_specifier_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x')
		return (c == 'd' || c == 'i' || c == 'u' || c == 'x');
	if (c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%')
		return (c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%');
	return 0;
}

int	ft_specifier_length(const char *specifier)
{
	int	len;

	len = 0;
	while (*specifier && !ft_is_specifier_type(*specifier))
	{
		len++;
		specifier++;
	}
	if (ft_is_specifier_type(*specifier))
	{
		len++;
	}
	return (len);
}
