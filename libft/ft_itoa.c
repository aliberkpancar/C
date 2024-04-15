/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:58:48 by apancar           #+#    #+#             */
/*   Updated: 2023/10/18 16:51:35 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long c)
{
	int	count;

	count = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		count++;
		c = -c;
	}
	while (c > 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = n;
	str = malloc(sizeof(char) * (ft_num_len(num) + 1));
	if (!str)
		return (NULL);
	i = ft_num_len(num);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (i > 0 && num > 0)
	{
		str[--i] = num % 10 + '0';
		num /= 10;
	}
	return (num + str);
}
