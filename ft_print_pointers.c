/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd <aait-abd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:03:50 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/20 02:33:28 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long address)
{
	int	count;

	count = 1;
	while (address >= 16)
	{
		address = address / 16;
		count++;
	}
	return (count);
}

static int	ft_putptr_address(unsigned long address)
{
	const char	*str;

	str = "0123456789abcdef";
	if (address >= 16)
	{
		if (ft_putptr_address(address / 16) == -1)
			return (-1);
	}
	if (ft_print_char(str[address % 16]) == -1)
		return (-1);
	return (0);
}

int	ft_print_pointers(void *ptr)
{
	int				count;
	unsigned long	address;

	if (ptr == NULL)
	{
		if (ft_print_strings("(nil)") == -1)
			return (-1);
		return (5);
	}
	address = (unsigned long)ptr;
	if (ft_print_strings("0x") == -1)
		return (-1);
	count = ft_count(address) + 2;
	if (ft_putptr_address(address) == -1)
		return (-1);
	return (count);
}
