/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:31:20 by apancar           #+#    #+#             */
/*   Updated: 2023/10/09 12:31:20 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_p;
	const char	*src_p;
	size_t		i;

	if (!dest && !src)
		return (0);
	dest_p = (char *)dest;
	src_p = (const char *)src;
	i = 0;
	while (i < n)
	{
		*(dest_p + i) = *(src_p + i);
		i++;
	}
	return (dest_p);
}
