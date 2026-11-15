/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd < aait-abd@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:03:39 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/15 13:03:40 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_count_digits(unsigned int n)
{
    int count;

    count = 1;
    while (n >= 10)
    {
        n = n / 10;
        count++;
    }
    return (count);
}
static void ft_putnbr(unsigned int n)
{
    char c;
    if (n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write (1, &c, 1);
}
int ft_print_unsigned(unsigned int n)
{
    int count;
    count = ft_count_digits(n);
    ft_putnbr(n);
    return (count);
}
