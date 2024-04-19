/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:41:09 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/20 17:21:11 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		size;

	src = (char *) s;
	size = ft_strlen(src);
	while (size >= 0)
	{
		if (*src == (char)c)
			return (src);
		src++;
		size--;
	}
	return (0);
}
