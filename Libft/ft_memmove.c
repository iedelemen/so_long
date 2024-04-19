/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:22:00 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/08 14:46:34 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest1;
	const char	*src1;

	dest1 = (char *)dest;
	src1 = (const char *)src;
	if (dest1 < src1)
		return (ft_memcpy(dest1, src1, len));
	else if (dest1 > src1)
	{
		while (len)
		{
			dest1[len - 1] = src1[len - 1];
			len--;
		}
	}
	else
		return (dest1);
	return (dest1);
}
