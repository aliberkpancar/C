/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:18:50 by apancar           #+#    #+#             */
/*   Updated: 2023/10/18 16:34:39 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s == NULL && d == NULL)
		return (dest);
	if (s >= d)
		ft_memcpy(d, s, n);
	else
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
