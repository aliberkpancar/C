/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:56:58 by apancar           #+#    #+#             */
/*   Updated: 2024/02/06 12:11:19 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char	*s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_count_letters(char *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		count++;
		index++;
	}
	return (count);
}

static char	**ft_cut(char const *s, char c, size_t i, char **str)
{
	size_t	k;
	size_t	j;
	size_t	size;

	size = ft_count_letters((char *)(s + i), c) + 1;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			str[k] = (char *)malloc(sizeof(char) * size);
			if (!str[k])
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				str[k][j++] = s[i++];
			str[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split(char	const *s, char c)
{
	size_t	i;
	char	**str;

	i = 0;
	str = (char **)malloc((ft_count_words((char *)s, c) + 1) * sizeof(char *));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	str = ft_cut(s, c, i, str);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	return (str);
}
