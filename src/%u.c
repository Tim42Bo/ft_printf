/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:58:17 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:58:17 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_unsigned_decimal(va_list args)
{
	unsigned int	num;
	int				ret;
	char			*buffer;
	int				len;

	num = va_arg(args, unsigned int);
	len = ft_uint_len(num);
	buffer = (char *) malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	ft_uint_to_ascii(num, buffer);
	ret = write(1, buffer, len);
	free(buffer);
	return (ret);
}
