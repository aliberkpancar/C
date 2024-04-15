/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:21:12 by apancar           #+#    #+#             */
/*   Updated: 2023/10/16 10:15:00 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_p;
	unsigned char	ch;

	i = 0;
	str_p = (unsigned char *)str;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (*(str_p + i) == ch)
			return (str_p + i);
		i++;
	}
	return (NULL);
}
