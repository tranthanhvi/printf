/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:53:36 by thantran          #+#    #+#             */
/*   Updated: 2024/11/25 22:53:36 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const	char *str)
{
	size_t	count;
	
	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count)
}

void	ft_bzero(void *pointer, size_t size)
{
	unsigned char	*ptr;

	p = (unsigned char *)pointer;
	while (size > 0)
	{
		*ptr++ = 0;
		size--;
	}
}