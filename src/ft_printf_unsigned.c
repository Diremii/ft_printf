/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:59:47 by humontas          #+#    #+#             */
/*   Updated: 2024/11/06 11:15:43 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_number_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_count_number_unsigned(n);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		i--;
		while (n > 0)
		{
			str[i] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
	return (str);
}

int	ft_printf_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		str = ft_itoa_unsigned(n);
		len += ft_printstr(str);
		free(str);
	}
	return (len);
}
