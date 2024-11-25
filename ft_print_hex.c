/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:09:04 by thantran          #+#    #+#             */
/*   Updated: 2024/11/26 00:09:04 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int num, size_t *counter, char *base)
{
	char	*str;

	str = ft_aux(num, base);
	ft_print_str(str, counter);
	free(str);
}
