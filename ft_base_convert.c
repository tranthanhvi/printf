/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:13:41 by thantran          #+#    #+#             */
/*   Updated: 2025/01/23 13:13:41 by thantran         ###   ########.fr       */
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

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

static size_t	ft_numlen(unsigned long long num, char *base)
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

char	*ft_base_convert(unsigned long long num, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	num_len = ft_numlen(num, base);
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
