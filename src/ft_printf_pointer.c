/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:28:52 by humontas          #+#    #+#             */
/*   Updated: 2024/11/08 09:30:40 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_pointer(size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_pointer_converter(size_t n)
{
	char	*base;
	char	*str;
	int		len;

	str = ft_calloc((ft_len_pointer(n) + 3), sizeof(char));
	if (!str)
		return (0);
	if (!n)
	{
		free(str);
		return (0);
	}
	len = 0;
	base = "0123456789abcdef";
	while (n > 0)
	{
		str[len] = base[n % 16];
		n /= 16;
		len++;
	}
	str[len] = '\0';
	return (str);
}

int	ft_printf_pointer(size_t n)
{
	char	*str;
	int		len;

	str = ft_pointer_converter(n);
	if (!str)
		return (write(1, "(nil)", 5));
	len = (ft_strlen(str));
	write (1, "0x", 2);
	while (len > 0)
	{
		write(1, &str[len - 1], 1);
		len--;
	}
	len = ft_strlen(str);
	free(str);
	return (len + 2);
}
