/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:32:37 by apancar           #+#    #+#             */
/*   Updated: 2023/10/16 10:15:00 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_p;

	s_p = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			s_p = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		s_p = (char *)(s + i);
	return (s_p);
}
