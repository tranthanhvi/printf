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

static size_t	ft_strlen(const	char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

static void	ft_bzero(void *pointer, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)pointer;
	while (size)
	{
		*p++ = 0;
		size--;
	}
}

static void	ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	while (total--)
		*p-- = 0;
	return (p - nmemb * size);
}

static size_t	ft_len(unsigned long long num, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (num >= base_len)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

char	*ft_aux(unsigned long long num, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_len(num, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len--;
		str[num_len] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
