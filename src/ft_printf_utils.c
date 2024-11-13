/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:03:17 by humontas          #+#    #+#             */
/*   Updated: 2024/11/06 09:45:19 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tab;
	long int		i;

	i = nmemb * size;
	if (i < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab)
		ft_memset(tab, '\0', nmemb * size);
	return (tab);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strcpy(char	*dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = ft_strlen(s);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == 0)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}
