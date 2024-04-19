/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:46:39 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/15 17:42:30 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s[i])
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!str)
		return (NULL);
	while (i < ft_wordcount(s, c))
	{
		while (s[j] == c)
			j++;
		str[i] = ft_substr(s, j, ft_wordlen(&s[j], c));
		if (!str[i])
			return (ft_free(str));
		i++;
		j = j + ft_wordlen(&s[j], c);
	}
	str[i] = NULL;
	return (str);
}
