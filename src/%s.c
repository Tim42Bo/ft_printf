/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %s.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 05:55:53 by tbornema          #+#    #+#             */
/*   Updated: 2023/05/30 05:55:53 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(va_list args)
{
	char	*arg;
	size_t	len;
	int		returnlen;
	char	*buffer;

	returnlen = 0;
	arg = va_arg(args, char *);
	len = ft_strlen(arg);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	ft_strncpy(buffer, arg, len);
	buffer[len] = '\0';
	returnlen = write(1, buffer, len);
	free(buffer);
	return (returnlen);
}
