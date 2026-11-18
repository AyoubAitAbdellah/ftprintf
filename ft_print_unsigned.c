/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd <aait-abd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:03:39 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/17 22:57:57 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
	}
	c = n % 10 + '0';
	if (ft_print_char(c) == -1)
		return (-1);
	return (0);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = ft_count_digits(n);
	if (ft_putnbr(n) == -1)
		return (-1);
	return (count);
}
