/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:43:48 by thantran          #+#    #+#             */
/*   Updated: 2024/11/25 23:43:48 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(void *ptr, size_t counter)
{
	char	*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_print_str("0x", counter);
	str = ft_aux(ptr_address, HEX_LOW_BASE);
	ft_print_str(str);
	free(str);
}