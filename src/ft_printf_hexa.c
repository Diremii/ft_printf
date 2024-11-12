/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:29:33 by humontas          #+#    #+#             */
/*   Updated: 2024/11/06 09:45:17 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_hexa(char c)
{
	write(1, &c, 1);
}

int	ft_printf_hexa(unsigned int n, int is_upper)
{
	char	*base;
	int		len;

	len = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_printf_hexa(n / 16, is_upper);
	ft_putchar_hexa(base[n % 16]);
	len++;
	return (len);
}
