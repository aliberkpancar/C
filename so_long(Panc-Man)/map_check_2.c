/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 07:10:24 by apancar           #+#    #+#             */
/*   Updated: 2024/01/31 10:38:15 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"

int	ft_strlen_so(char *s)
{
	int	i;

	if (s == NULL )
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_check_rectangular(t_so *so)
{
	int	i;

	i = 0;
	while (i < so->board->height - 2)
	{
		if (ft_strlen_so(so->board->line[i])
			!= ft_strlen_so(so->board->line[i + 1]))
			msg_error(MAP_ERROR);
		if ((ft_strlen_so(so->board->line[so->board->height - 2])
				- ft_strlen_so(so->board->line[so->board->height - 1])) != 1)
			msg_error(MAP_ERROR);
		i++;
	}
}
