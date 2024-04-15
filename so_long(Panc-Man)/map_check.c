/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:07:20 by apancar           #+#    #+#             */
/*   Updated: 2024/01/20 15:08:17 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"

void	ft_check_border(t_so *so)
{
	int	x;
	int	y;

	x = 0;
	while (x < so->board->width)
	{
		if (so->board->line[0][x] != '1'
			|| so->board->line[so->board->height - 1][x] != '1')
			msg_error(MAP_ERROR);
		x++;
	}
	y = 0;
	while (y < so->board->height)
	{
		if (so->board->line[y][0] != '1'
			|| so->board->line[y][so->board->width - 1] != '1')
			msg_error(MAP_ERROR);
		y++;
	}
	ft_check_rectangular(so);
}

void	ft_check_tools(t_so *so)
{
	int	i;
	int	j;

	j = 0;
	while (j < so->board->height)
	{
		i = 0;
		while (i < so->board->width)
		{
			if (so->board->line[j][i] == '0' || so->board->line[j][i] == '1'
				|| so->board->line[j][i] == '\0' || so->board->line[j][i] == 'C'
				|| so->board->line[j][i] == 'E' || so->board->line[j][i] == 'P')
				i++;
			else
				msg_error(MAP_ERROR);
		}
		j++;
	}
}

void	control(t_so temp)
{
	int		y;
	int		x;

	y = 0;
	while (y < temp.board->height)
	{
		x = 0;
		while (x < temp.board->width)
		{
			if (temp.board->line[y][x] == 'E' || temp.board->line[y][x] == 'C')
				msg_error ("MAP_ERROR");
			x++;
		}
		y++;
	}
}

int	ft_fill_flood(int x, int y, t_so *so)
{
	if (so->board->width < x && so->board->height < y)
		return (0);
	if (so->board->line[y][x] != '1' && so->board->line[y][x] != 'F')
	{
		so->board->line[y][x] = 'F';
		ft_fill_flood(x + 1, y, so);
		ft_fill_flood(x - 1, y, so);
		ft_fill_flood(x, y + 1, so);
		ft_fill_flood(x, y - 1, so);
	}
	return (0);
}

void	ft_check_game(t_so *so)
{
	t_so	temp;
	int		i;

	temp.board = (t_board *)malloc(sizeof(t_board));
	if (!temp.board)
		msg_error(ALLO_ERROR);
	temp.board->line = (char **)malloc(sizeof(char *) * so->board->height);
	if (!temp.board->line)
		msg_error(ALLO_ERROR);
	i = -1;
	while (++i < so->board->height)
		temp.board->line[i] = ft_strdup(so->board->line[i]);
	temp.board->height = so->board->height;
	temp.board->width = so->board->width;
	ft_fill_flood(so->hero->x, so->hero->y, &temp);
	control(temp);
	if (temp.board->line[so->board->exit->y][so->board->exit->x] != 'F')
		msg_error("There is not a path to the game");
	i = -1;
	while (++i < so->board->height)
		free(temp.board->line[i]);
	free(temp.board->line);
	free(temp.board);
}
