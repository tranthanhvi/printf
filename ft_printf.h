/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:05:35 by thantran          #+#    #+#             */
/*   Updated: 2024/12/01 15:32:56 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

void	ft_print_char(char c, size_t *counter);
void	ft_print_str(char *str, size_t *counter);
void	ft_print_nbr(int num, size_t *counter);
void	ft_print_uint(unsigned int num, size_t *counter);
void	ft_print_hex(unsigned int num, size_t *counter, char *base);
void	ft_print_ptr(void *ptr, size_t *counter);
char	*ft_base_convert(unsigned long long num, char *base);

#endif