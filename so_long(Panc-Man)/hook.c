/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:46:00 by apancar           #+#    #+#             */
/*   Updated: 2024/01/31 11:46:02 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"
#include "./inc/libft/libft.h"
#include "./inc/ft_printf/ft_printf.h"

void	ft_get_image(t_so *so)
{
	int	i;
	int	j;

	j = 0;
	while (j < so->board->height)
	{
		i = 0;
		while (i < so->board->width)
		{
			if ((i >= 0 && i < so->board->width)
				&& (j >= 0 && j < so->board->height))
				ft_fill(so, so->board->line[j][i], i * 64, j * 64);
			i++;
		}
		j++;
	}
}

static void	ft_move_ud(t_so *so, int side)
{
	if (side == GO_UP || side == GO_UP2)
	{
		so->hero->y--;
		so->board->line[so->hero->y][so->hero->x] = PLAYER;
		if ((so->board->exit->x == \
		so->hero->x && (so->board->exit->y - 1 == so->hero->y || \
		so->board->exit->y - 1 == 'C')))
			so->board->line[so->hero->y + 1][so->hero->x] = EXIT;
		else
			so->board->line[so->hero->y + 1][so->hero->x] = GROUND;
	}
	if (side == GO_DOWN || side == GO_DOWN2)
	{
		so->hero->y++;
		so->board->line[so->hero->y][so->hero->x] = PLAYER;
		if ((so->board->exit->x == \
		so->hero->x && (so->board->exit->y + 1 == so->hero->y || \
		so->board->exit->y + 1 == 'C')))
			so->board->line[so->hero->y - 1][so->hero->x] = EXIT;
		else
			so->board->line[so->hero->y - 1][so->hero->x] = GROUND;
	}
	if (so->hero->x >= 0 && so->hero->x < so->board->width - 1
		&& so->hero->y >= 0 && so->hero->y < so->board->height)
		so->board->line[so->hero->y][so->hero->x] = PLAYER;
}

static void	ft_move_rl(t_so *so, int side)
{
	if (side == GO_LEFT || side == GO_LEFT2)
	{
		so->hero->x--;
		so->board->line[so->hero->y][so->hero->x] = PLAYER;
		if (((so->board->exit->x \
		== so->hero->x + 1 || so->board->exit->x + 1 == 'C') && \
		so->board->exit->y == so->hero->y))
			so->board->line[so->hero->y][so->hero->x + 1] = EXIT;
		else
			so->board->line[so->hero->y][so->hero->x + 1] = GROUND;
	}
	if (side == GO_RIGHT || side == GO_RIGHT2)
	{
		so->hero->x++;
		so->board->line[so->hero->y][so->hero->x] = PLAYER;
		if (((so->board->exit->x \
		== so->hero->x - 1 || so->board->exit->x - 1 == 'C') && \
		so->board->exit->y == so->hero->y))
			so->board->line[so->hero->y][so->hero->x - 1] = EXIT;
		else
			so->board->line[so->hero->y][so->hero->x - 1] = GROUND;
	}
	if (so->hero->x >= 0 && so->hero->x < so->board->width - 1
		&& so->hero->y >= 0 && so->hero->y < so->board->height)
		so->board->line[so->hero->y][so->hero->x] = PLAYER;
}

int	ft_hook(int key, t_so *so)
{
	if (!(so->hero->y >= 0 && so->hero->y < so->board->height
			&& so->hero->x >= 0 && so->hero->x < so->board->width))
		return (1);
	if (key == GO_LEFT && ft_check_move(so, GO_LEFT))
		ft_move_rl(so, GO_LEFT);
	else if (key == GO_RIGHT && ft_check_move(so, GO_RIGHT))
		ft_move_rl(so, GO_RIGHT);
	else if (key == GO_UP && ft_check_move(so, GO_UP))
		ft_move_ud(so, GO_UP);
	else if (key == GO_DOWN && ft_check_move(so, GO_DOWN))
		ft_move_ud(so, GO_DOWN);
	else if (key == GO_LEFT2 && ft_check_move(so, GO_LEFT2))
		ft_move_rl(so, GO_LEFT2);
	else if (key == GO_RIGHT2 && ft_check_move(so, GO_RIGHT2))
		ft_move_rl(so, GO_RIGHT2);
	else if (key == GO_UP2 && ft_check_move(so, GO_UP2))
		ft_move_ud(so, GO_UP2);
	else if (key == GO_DOWN2 && ft_check_move(so, GO_DOWN2))
		ft_move_ud(so, GO_DOWN2);
	else if (key == ESC)
		ft_exit_game(so);
	ft_get_image(so);
	return (0);
}
