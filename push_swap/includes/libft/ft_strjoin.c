/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:21:30 by apancar           #+#    #+#             */
/*   Updated: 2024/01/29 12:27:14 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *prof, char *buff)
{
	char	*str;
	size_t	str_len;
	size_t	i;
	size_t	j;

	if (!prof)
	{
		prof = malloc(sizeof(char) * 1);
		prof[0] = '\0';
	}
	str_len = ft_strlen(prof) + ft_strlen(buff);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (prof[++i])
		str[i] = prof[i];
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	return (free(prof), str);
}
