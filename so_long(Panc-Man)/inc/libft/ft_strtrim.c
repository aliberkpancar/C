/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:19:16 by apancar           #+#    #+#             */
/*   Updated: 2024/01/05 18:47:18 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_first(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;

	if (!s1)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	while (i < s1_len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_last(char const *s1, char const *set)
{
	size_t	j;
	size_t	s1_len;

	if (!s1)
		return (0);
	j = 0;
	s1_len = ft_strlen(s1);
	while (j < s1_len)
	{
		if (ft_strchr(set, s1[s1_len - j - 1]) == NULL)
			break ;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	str_len;
	size_t	k;
	size_t	l;

	if (set == 0 || s1 == 0)
		return (NULL);
	k = ft_first(s1, set);
	if (k == ft_strlen(s1))
		return (ft_strdup(""));
	str_len = ft_strlen(s1) - (k + ft_last(s1, set));
	str = malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	k = ft_first(s1, set);
	l = 0;
	while (k < ft_strlen(s1) - ft_last(s1, set))
	{
		str[l] = s1[k];
		l++;
		k++;
	}
	str[l] = '\0';
	return (str);
}
