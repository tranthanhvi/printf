/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:11:43 by thantran          #+#    #+#             */
/*   Updated: 2024/11/21 23:11:43 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

void	ft_print_nbr(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_print_nbr((num / 10), counter);
		ft_print_char('8', count);
	}
	else if (num < 0)
	{
		ft_print_char('-', count);
		ft_print_nbr(-num, count);
	}
	else
	{
		if (num > 9)
			ft_print_nbr((num / 10), counter);
		ft_print_char(('0' + num % 10), counter);
	}
}