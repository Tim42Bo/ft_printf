/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %c.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:47:54 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:47:54 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(va_list args)
{
	char	*buffer;
	char	c;
	int		len;

	c = (char) va_arg(args, int);
	buffer = ((char *) malloc(2 * sizeof(char)));
	if (!buffer)
		return (-1);
	buffer[0] = c;
	buffer[1] = '\0';
	len = write(1, buffer, 1);
	free(buffer);
	return (len);
}
