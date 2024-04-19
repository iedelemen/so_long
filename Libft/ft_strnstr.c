/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:33 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/09 14:37:08 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + k] == needle[k] && haystack[i + k] && (k + i) < len)
			k++;
		if (needle[k] == '\0')
			return ((char *) & haystack[i]);
		i++;
		k = 0;
	}
	return (0);
}
