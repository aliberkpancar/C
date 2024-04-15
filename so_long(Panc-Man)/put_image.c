/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:19:43 by apancar           #+#    #+#             */
/*   Updated: 2024/01/16 11:32:53 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"
#include "./inc/gnl/get_next_line.h"

void	ft_put_image(t_so *so)
{
	so->board->wall = mlx_xpm_file_to_image(so->mlx, "./xpm/wall.xpm",
			&so->board->size_x, &so->board->size_y);
	so->board->floor = mlx_xpm_file_to_image(so->mlx, "./xpm/floor.xpm",
			&so->board->size_x, &so->board->size_y);
	so->board->collect = mlx_xpm_file_to_image(so->mlx, "./xpm/collect.xpm",
			&so->board->size_x, &so->board->size_y);
	so->hero->image = mlx_xpm_file_to_image(so->mlx, "./xpm/hero.xpm",
			&so->hero->size_x, &so->hero->size_y);
	so->board->exit->image = mlx_xpm_file_to_image(so->mlx, "./xpm/exit.xpm",
			&so->board->size_x, &so->board->size_y);
	if (!so->board->wall || !so->board->floor || !so->board->collect
		|| !so->hero->image || !so->board->exit)
		msg_error("File not found.");
	ft_put_image_to_window(so, -1, -1);
}

void	ft_put_image_to_window(t_so *so, int i, int j)
{
	while (++j < so->board->height)
	{
		i = -1;
		while (++i < so->board->width)
		{
			if (so->board->line[j][i] == '1')
				mlx_put_image_to_window(so->mlx, so->win,
					so->board->wall, i * 64, j * 64);
			else if (so->board->line[j][i] == '0')
				mlx_put_image_to_window(so->mlx, so->win,
					so->board->floor, i * 64, j * 64);
			else if (so->board->line[j][i] == 'C')
				mlx_put_image_to_window(so->mlx, so->win,
					so->board->collect, i * 64, j * 64);
			else if (so->board->line[j][i] == 'P')
				mlx_put_image_to_window(so->mlx, so->win,
					so->hero->image, i * 64, j * 64);
			else if (so->board->line[j][i] == 'E')
				mlx_put_image_to_window(so->mlx, so->win,
					so->board->exit->image, i * 64, j * 64);
		}
	}
}
