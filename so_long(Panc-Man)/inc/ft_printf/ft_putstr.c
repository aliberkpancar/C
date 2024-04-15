/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:03:12 by apancar           #+#    #+#             */
/*   Updated: 2023/10/25 08:45:51 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (*str != '\0')
	{
		ft_putchar(*str);
		str ++;
		i++;
	}
	return (i);
}
