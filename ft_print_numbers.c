/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd <aait-abd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:03:59 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/15 15:15:00 by aait-abd         ###   ########.fr       */
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

static void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write (1, &c, 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int	ft_print_numbers(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = ft_count_digits(nb);
	ft_putnbr(nb);
	return (count);
}
