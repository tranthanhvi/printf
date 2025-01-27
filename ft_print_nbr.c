/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:11:43 by thantran          #+#    #+#             */
/*   Updated: 2024/11/28 19:17:44 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_print_nbr((num / 10), counter);
		ft_print_char('8', counter);
	}
	else if (num < 0)
	{
		ft_print_char('-', counter);
		ft_print_nbr(-num, counter);
	}
	else
	{
		if (num > 9)
			ft_print_nbr((num / 10), counter);
		ft_print_char(('0' + num % 10), counter);
	}
}
