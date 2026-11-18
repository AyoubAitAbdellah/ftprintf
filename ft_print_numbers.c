/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd <aait-abd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:03:59 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/17 22:56:19 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		if (ft_print_char(c) == -1)
			return (-1);
		n = -n;
	}
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

int	ft_print_numbers(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = ft_count_digits(nb);
	if (ft_putnbr(nb) == -1)
		return (-1);
	return (count);
}
