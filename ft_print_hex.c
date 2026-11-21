/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd <aait-abd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:04:03 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/20 05:30:55 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static int	ft_puthex(unsigned int n, int uppercase)
{
	const char	*str;

	if (uppercase == 0)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (ft_puthex(n / 16, uppercase) == -1)
			return (-1);
	}
	if (ft_print_char(str[n % 16]) == -1)
		return (-1);
	return (0);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	int	count;

	count = ft_count_digits(n);
	if (ft_puthex(n, uppercase) == -1)
		return (-1);
	return (count);
}
