/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:26:05 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/20 17:19:21 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
