/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:43:51 by idelemen          #+#    #+#             */
/*   Updated: 2024/01/03 18:10:38 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[++i])
	{
		if (write (1, &s[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_point(unsigned long nb, int i)
{
	int	len;
	int	temp;

	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (nb >= 16)
	{
		temp = ft_point(nb / 16, i);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789abcdef"[nb % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_int(int nb)
{
	long	n;
	int		len;
	int		temp;

	len = 0;
	n = nb;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		len++;
	}
	if (n > 9)
	{
		temp = ft_int(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int nb)
{
	int	len;
	int	temp;

	len = 0;
	if (nb > 9)
	{
		temp = ft_unsigned(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789"[nb % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex(unsigned int nb, char format)
{
	int	len;
	int	temp;

	len = 0;
	if (nb >= 16)
	{
		temp = ft_hex(nb / 16, format);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (format == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[nb % 16], 1) == -1)
			return (-1);
	}
	if (format == 'x')
	{
		if (write(1, &"0123456789abcdef"[nb % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}
