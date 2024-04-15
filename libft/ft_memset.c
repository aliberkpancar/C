/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:14 by apancar           #+#    #+#             */
/*   Updated: 2023/10/09 12:17:14 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s_p, int a, size_t n)
{
	unsigned char	*s_p1;
	size_t			i;

	s_p1 = (unsigned char *)s_p;
	i = 0;
	while (i < n)
	{
		*(s_p1 + i) = (unsigned char)a;
		i++;
	}
	return (s_p);
}
