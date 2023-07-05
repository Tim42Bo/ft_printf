/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %d%i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:53:32 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:53:32 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_decimal(int arg)
{
	int		ret;
	int		neg;
	int		len;
	char	*buffer;

	neg = 0;
	if (arg < 0)
	{
		neg = 1;
		arg = -arg;
	}
	len = ft_numlen(arg) + neg;
	buffer = (char *) malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	if (neg)
		buffer[0] = '-';
	ft_int_to_ascii(arg, buffer + neg);
	ret = write(1, buffer, len);
	free(buffer);
	return (ret);
}
