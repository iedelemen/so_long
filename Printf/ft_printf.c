/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:43:48 by idelemen          #+#    #+#             */
/*   Updated: 2024/01/03 18:11:29 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_check(char form)
{
	if (form == 'c' || form == 'd' || form == 'i' || form == 'u' || form == '%'
		|| form == 's' || form == 'x' || form == 'X' || form == 'p')
		return (1);
	return (0);
}

int	ft_format(va_list *arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (format == 's')
		return (ft_putstr(va_arg((*arg), char *)));
	else if (format == 'p')
		return (ft_point(va_arg((*arg), unsigned long), 1));
	else if (format == 'd' || format == 'i')
		return (ft_int(va_arg((*arg), int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg((*arg), unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_hex(va_arg((*arg), unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;
	int		value;

	len = 0;
	i = -1;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			value = ft_format(&arg, format[++i]);
			if (value == -1)
				return (-1);
			len += value;
		}
		else if (format[i] != '%' && ft_putchar(format[i]) == -1)
			return (-1);
		else if (format[i] != '%')
			len++;
	}
	va_end(arg);
	return (len);
}
