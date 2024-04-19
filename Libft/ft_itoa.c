/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:03:12 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/12 13:25:40 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nb;
	int		numlen;

	nb = n;
	numlen = ft_numlen(nb);
	if (nb < 0)
	{
		nb = -nb;
		numlen++;
	}
	dest = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!dest)
		return (NULL);
	dest[numlen] = '\0';
	while (numlen > 0)
	{
		dest[--numlen] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		dest[0] = '-';
	else if (n == 0)
		dest[0] = '0';
	return (dest);
}
