/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:47:20 by thantran          #+#    #+#             */
/*   Updated: 2024/11/28 20:52:05 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(unsigned int num, size_t *counter)
{
	char	*str;

	if (num == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return ;
		str[0] = '0';
	}
	else
	{
		str = ft_aux(num, "0123456789");
		if (!str)
			return ;
	}
	ft_print_str(str, counter);
	free(str);
}

// #include <stdio.h>
// void	main(void)
// {
// 	printf(" %u ", 0);
// }