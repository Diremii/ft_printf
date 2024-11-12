/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humontas <humontas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:07:48 by humontas          #+#    #+#             */
/*   Updated: 2024/11/06 09:39:36 by humontas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *str, ...);
int			ft_printchar(int c);
int			ft_printstr(char *str);
int			ft_printnbr(int n);
int			ft_printf_unsigned(unsigned int n);
int			ft_printf_hexa(unsigned int n, int is_upper);
int			ft_printf_pointer(size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);

#endif