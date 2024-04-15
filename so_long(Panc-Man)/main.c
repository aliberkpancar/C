/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:47:57 by apancar           #+#    #+#             */
/*   Updated: 2024/01/20 15:12:19 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"

static t_so	*allocation(void)
{
	t_so	*so;

	so = (t_so *)malloc(sizeof(t_so));
	if (!so)
		msg (ALLO_ERROR);
	so->board = (t_board *)malloc(sizeof(t_board));
	if (!so->board)
		msg (ALLO_ERROR);
	so->hero = (t_hero *)malloc(sizeof(t_hero));
	if (!so->hero)
		msg (ALLO_ERROR);
	so->board->exit = (t_exit *)malloc(sizeof(t_exit));
	if (!so->board->exit)
		msg (ALLO_ERROR);
	return (so);
}

int	ft_is_ber(char	*str)
{
	size_t	len;

	len = ft_strlen((char *)str);
	if (len > 4 && ft_strncmp(".ber", &str[len - 4], 4) == 0)
		if ((str[len -5] != '/') && str[len - 5])
			return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_so	*so;

	if (ac != 2)
		msg_error(ARG_ERROR);
	so = allocation();
	ft_read_map(so, av[1]);
	ft_init_game(so);
	ft_check_border(so);
	ft_check_game(so);
	ft_check_tools(so);
	ft_put_image(so);
	mlx_key_hook(so->win, ft_hook, so);
	mlx_hook(so->win, X, 0, ft_exit_game, so);
	mlx_loop(so->mlx);
	return (0);
}
