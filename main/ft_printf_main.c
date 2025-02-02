/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:12:06 by thantran          #+#    #+#             */
/*   Updated: 2025/02/02 15:55:21 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *specifier, size_t *counter)
{
	if (*specifier == 'c')
		ft_print_char(va_arg(va, int), counter);
	else if (*specifier == 's')
		ft_print_str(va_arg(va, char *), counter);
	else if (*specifier == 'p')
		ft_print_ptr(va_arg(va, void *), counter);
	else if (*specifier == 'i' || *specifier == 'd')
		ft_print_nbr(va_arg(va, int), counter);
	else if (*specifier == 'u')
		ft_print_uint(va_arg(va, unsigned int), counter);
	else if (*specifier == 'x' || *specifier == 'X')
	{
		if (*specifier == 'x')
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*specifier == '%')
		ft_print_char('%', counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				ft_format(va, (char *)str, &counter);
		}
		else
			ft_print_char(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}

#include "ft_printf.h"

void	ft_format(va_list va, char *specifier, size_t *counter)
{
	if (*specifier == 'c')
		ft_print_char(va_arg(va, int), counter);
	else if (*specifier == 's')
		ft_print_str(va_arg(va, char *), counter);
	else if (*specifier == 'p')
		ft_print_ptr(va_arg(va, void *), counter);
	else if (*specifier == 'i' || *specifier == 'd')
		ft_print_nbr(va_arg(va, int), counter);
	else if (*specifier == 'u')
		ft_print_uint(va_arg(va, unsigned int), counter);
	else if (*specifier == 'x' || *specifier == 'X')
	{
		if (*specifier == 'x')
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else
			ft_print_hex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*specifier == '%')
		ft_print_char('%', counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				ft_format(va, (char *)str, &counter);
		}
		else
			ft_print_char(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
#include "ft_printf.h"

int main(void)
{
    size_t count;

    // 1. Print a string
    count = ft_printf("String: %s\n", "Hello, World!");
    // Expected: "String: Hello, World!"
    // Characters printed: 20

    // 2. Print a character
    count = ft_printf("Char: %c\n", 'A');
    // Expected: "Char: A"
    // Characters printed: 7

    // 3. Print an integer (signed)
    count = ft_printf("Integer: %d\n", 42);
    // Expected: "Integer: 42"
    // Characters printed: 12

    // 4. Print an unsigned integer
    count = ft_printf("Unsigned: %u\n", 42);
    // Expected: "Unsigned: 42"
    // Characters printed: 14

    // 5. Print a hexadecimal number (lowercase)
    count = ft_printf("Hex (lower): %x\n", 255);
    // Expected: "Hex (lower): ff"
    // Characters printed: 16

    // 6. Print a hexadecimal number (uppercase)
    count = ft_printf("Hex (upper): %X\n", 255);
    // Expected: "Hex (upper): FF"
    // Characters printed: 16

    // 7. Print a pointer address
    int num = 42;
    count = ft_printf("Pointer: %p\n", &num);
    // Expected: "Pointer: 0x7ffeefbff6f0" (or a similar address depending on your system)
    // Characters printed: varies by address length

    // 8. Print a percent sign
    count = ft_printf("Percent: %%\n");
    // Expected: "Percent: %"
    // Characters printed: 9

    // 9. Null pointer test
    count = ft_printf("Null pointer: %p\n", NULL);
    // Expected: "Null pointer: (nil)"
    // Characters printed: 20

    // 10. Edge case: Empty string
    count = ft_printf("Empty string: %s\n", "");
    // Expected: "Empty string: "
    // Characters printed: 16

    // 11. Edge case: Negative integer
    count = ft_printf("Negative: %d\n", -42);
    // Expected: "Negative: -42"
    // Characters printed: 14

    // 12. Edge case: Zero value
    count = ft_printf("Zero: %d\n", 0);
    // Expected: "Zero: 0"
    // Characters printed: 8

    // 13. Edge case: Large number (signed)
    count = ft_printf("Large number: %d\n", 2147483647);
    // Expected: "Large number: 2147483647"
    // Characters printed: 22

    // 14. Edge case: Large number (unsigned)
    count = ft_printf("Large unsigned: %u\n", 4294967295);
    // Expected: "Large unsigned: 4294967295"
    // Characters printed: 24

    return 0;
}
