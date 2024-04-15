/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:01:32 by apancar           #+#    #+#             */
/*   Updated: 2024/01/20 15:14:52 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"
#include "./inc/ft_printf/ft_printf.h"

int	ft_exit_game(t_so *so)
{
	mlx_destroy_image(so->mlx, so->hero->image);
	mlx_destroy_image(so->mlx, so->board->wall);
	mlx_destroy_image(so->mlx, so->board->floor);
	mlx_destroy_image(so->mlx, so->board->collect);
	mlx_destroy_image(so->mlx, so->board->exit->image);
	mlx_destroy_window(so->mlx, so->win);
	ft_printf("See U:)\n");
	exit (0);
	return (0);
}
