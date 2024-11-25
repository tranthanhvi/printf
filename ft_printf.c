/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:12:06 by thantran          #+#    #+#             */
/*   Updated: 2024/11/21 23:12:06 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_print_char(va_arg(va, int), counter);
	else if (*str == 's')
		ft_print_str(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_print_ptr(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_print_nbr(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_print_str(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_print_char(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va (char *)str, &counter);
		}
		else
			ft_print_char(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
