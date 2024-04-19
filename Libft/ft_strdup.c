/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:59:35 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/09 11:54:19 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, ft_strlen(str));
	dest[ft_strlen(str)] = '\0';
	return (dest);
}
