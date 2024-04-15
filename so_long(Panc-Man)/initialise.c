/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:27:50 by apancar           #+#    #+#             */
/*   Updated: 2024/01/05 17:42:36 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"

void	ft_init_game(t_so *so)
{
	so->mlx = mlx_init();
	so->win = mlx_new_window(so->mlx, so->board->width * 64,
			so->board->height * 64, "Panc-Man");
}
