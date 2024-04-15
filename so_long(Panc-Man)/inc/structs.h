/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:05:46 by apancar           #+#    #+#             */
/*   Updated: 2024/01/06 08:46:54 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_exit
{
	char	*image;
	int		x;
	int		y;
	int		count;
	int		size_x;
	int		size_y;
}			t_exit;

typedef struct s_hero
{
	void	*image;
	int		movements;
	int		count;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
}				t_hero;

typedef struct s_board
{
	int		width;
	int		height;
	char	**line;
	t_exit	*exit;
	void	*wall;
	void	*floor;
	void	*collect;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	int		start_x;
	int		start_y;
	int		collect_count;
	int		exit_count;
}				t_board;

typedef struct s_so
{
	t_hero	*hero;
	t_board	*board;
	char	*image;
	char	**start;
	void	*mlx;
	void	*win;
}			t_so;

#endif