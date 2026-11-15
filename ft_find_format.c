/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-abd < aait-abd@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:04:16 by aait-abd          #+#    #+#             */
/*   Updated: 2026/11/15 13:09:15 by aait-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_find_format(char format, va_list *args)
{
    if (format == 'd' || format == 'i')
        return (ft_print_numbers(va_arg(*args, int)));
    else if (format == 'u')
        return (ft_print_unsigned(va_arg(*args, unsigned int)));
    else if (format == 'x')
        return (ft_print_hex(va_arg(*args, unsigned int), 0));
    else if (format == 'X')
        return (ft_print_hex(va_arg(*args, unsigned int), 1));
    else if (format == 'p')
        return (ft_print_pointers(va_arg(*args, void *)));
    else if (format == 's')
        return (ft_print_strings(va_arg(*args, char *)));
    else if (format == 'c')
        return (ft_print_char(va_arg(*args, int)));
    else if (format == '%')
        return (ft_print_char('%'));
    return (0);
}