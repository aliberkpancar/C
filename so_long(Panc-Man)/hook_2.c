/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:47:07 by apancar           #+#    #+#             */
/*   Updated: 2024/01/31 11:38:20 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"
#include "./inc/libft/libft.h"
#include "./inc/ft_printf/ft_printf.h"

int	ft_check_next_step(t_so *so, int side, char step)
{
	int	new_x;
	int	new_y;

	new_x = so->hero->x;
	new_y = so->hero->y;
	if (side == GO_RIGHT || side == GO_RIGHT2)
		new_x++;
	else if (side == GO_LEFT || side == GO_LEFT2)
		new_x--;
	else if (side == GO_DOWN || side == GO_DOWN2)
		new_y++;
	else if (side == GO_UP || side == GO_UP2)
		new_y--;
	if (new_x < 0 || new_x >= so->board->width || new_y < 0
		|| new_y >= so->board->height)
		return (0);
	return (so->board->line[new_y][new_x] == step);
}

int	ft_check_move(t_so *so, int side)
{
	if (ft_check_next_step(so, side, WALL))
		return (0);
	if (ft_check_next_step(so, side, COLLECT))
		so->board->collect_count--;
	if (ft_check_next_step(so, side, EXIT) && so->board->collect_count == 0)
	{
		so->hero->movements++;
		ft_printf("Congratulations. :) !\n");
		ft_printf("You finished the game in %d movements.\n",
			so->hero->movements);
		ft_exit_game(so);
	}
	so->hero->movements++;
	ft_printf("Movements: %d\n", so->hero->movements);
	return (1);
}

void	ft_fill(t_so *so, char c, int x, int y)
{
	if (c != WALL && c != PLAYER && c != COLLECT && c != EXIT)
		mlx_put_image_to_window(so->mlx, so->win, so->board->floor, x, y);
	if (c == WALL)
		mlx_put_image_to_window(so->mlx, so->win, so->board->wall, x, y);
	if (c == PLAYER)
		mlx_put_image_to_window(so->mlx, so->win, so->hero->image, x, y);
	if (c == COLLECT)
		mlx_put_image_to_window(so->mlx, so->win, so->board->collect, x, y);
	if (c == EXIT)
		mlx_put_image_to_window(so->mlx, so->win, so->board->exit->image, x, y);
}
