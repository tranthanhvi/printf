/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:47:20 by thantran          #+#    #+#             */
/*   Updated: 2024/11/25 23:47:20 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(unsigned int num, size_t counter)
{
	char	*str;

	str = ft_aux(num, "0123456789");
	ft_print_str(str, counter);
	free(str);
}
