/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd <aait-abd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:03:50 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/15 15:16:56 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(uintptr_t address)
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

static void	ft_putptr_address(uintptr_t address)
{
	const char	*str;

	str = "0123456789abcdef";
	if (address >= 16)
		ft_putptr_address(address / 16);
	write(1, &str[address % 16], 1);
}

int	ft_print_pointers(void *ptr)
{
	int			count;
	uintptr_t	address;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	address = (uintptr_t)ptr;
	write(1, "0x", 2);
	count = ft_count(address) + 2;
	ft_putptr_address(address);
	return (count);
}
