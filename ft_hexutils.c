/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:04:07 by tbornema          #+#    #+#             */
/*   Updated: 2023/07/03 13:19:01 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_case(int alphacase)

{
	if (alphacase == 88)
		return ("0123456789ABCDEF");
	else if (alphacase == 120)
		return ("0123456789abcdef");
	else
		return (NULL);
}

void	ft_printhex(unsigned int num, const char *hexdig, int numdig)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc((numdig + 1) * sizeof(char));
	if (buffer == NULL)
		return ;
	buffer[numdig] = '\0';
	i = numdig - 1;
	while (i >= 0)
	{
		buffer[i] = hexdig[num % 16];
		num /= 16;
		i--;
	}
	write(1, buffer, numdig);
	free(buffer);
}
