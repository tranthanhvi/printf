/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:12:06 by thantran          #+#    #+#             */
/*   Updated: 2025/02/02 15:55:12 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *specifier, size_t *counter)
{
	if (*specifier == 'c')
		ft_print_char(va_arg(va, int), counter);
	else if (*specifier == 's')
		ft_print_str(va_arg(va, char *), counter);
	else if (*specifier == 'p')
		ft_print_ptr(va_arg(va, void *), counter);
	else if (*specifier == 'i' || *specifier == 'd')
		ft_print_nbr(va_arg(va, int), counter);
	else if (*specifier == 'u')
		ft_print_uint(va_arg(va, unsigned int), counter);
	else if (*specifier == 'x' || *specifier == 'X')
	{
		if (*specifier == 'x')
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*specifier == '%')
		ft_print_char('%', counter);
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
			if (*str)
				ft_format(va, (char *)str, &counter);
		}
		else
			ft_print_char(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}


