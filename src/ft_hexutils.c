/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:04:07 by tbornema          #+#    #+#             */
/*   Updated: 2023/06/08 11:44:23 by tbornema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_globalvariable	g_lobal;

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
	g_lobal.buffer = (char *)malloc((numdig + 1) * sizeof(char));
	if (g_lobal.buffer == NULL)
		return ;
	g_lobal.buffer[numdig] = '\0';
	g_lobal.i = numdig - 1;
	while (g_lobal.i >= 0)
	{
		g_lobal.buffer[g_lobal.i] = hexdig[num % 16];
		num /= 16;
		g_lobal.i--;
	}
	g_lobal.len = write(1, g_lobal.buffer, numdig);
	free(g_lobal.buffer);
}
