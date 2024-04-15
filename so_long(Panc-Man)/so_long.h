/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:48:16 by apancar           #+#    #+#             */
/*   Updated: 2024/01/16 11:38:56 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./inc/libft/libft.h"
# include "./inc/ft_printf/ft_printf.h"
# include "./minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "./inc/structs.h"
# include <stdio.h>
# include <fcntl.h>
//error_macros
# define FILE_ERROR "The file format is invalid.\n"
# define ARG_ERROR "Invalid argument: Too few or many arguments.\n"
# define ALLO_ERROR "Memory allocation error.\n"
# define MEMORY_ERROR "Memory allocation error.\n"
# define INIT_ERROR "Variable sized object may not be initialized.\n"
# define WIN_ERROR "Couldn't open this file.\n"
# define READ_ERROR "File not found.\n"
# define MAP_ERROR "Map error.\n"
# define MAP_REC_ERROR "The map is not rectangular.\n"
# define MAP_DIM_ERROR "The map dimensions are below the size to be played.\n"
# define EXIT_FAILURE 1
//dimensions
# define MAX_WIDTH 40
# define MAX_HEIGHT 30
//movements
# define WALL '1'
# define GROUND '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'
//key directions
# define GO_LEFT 0
# define GO_RIGHT 2
# define GO_DOWN 1
# define GO_UP 13
# define GO_LEFT2 123
# define GO_RIGHT2 124
# define GO_DOWN2 125
# define GO_UP2 126
# define ESC 53
# define X 17
//error
int		msg(char *error_mesage);
void	msg_error(char	*error_message);
void	ft_init_game(t_so *so);
void	ft_read_map(t_so *so, char *file_name);
void	ft_get_dimensions(t_so *so, char *file_name);
void	ft_coordinats(t_so *so);
void	ft_put_image(t_so *so);
int		ft_is_ber(char	*str);
int		ft_hook(int key, t_so *so);
void	ft_get_image(t_so *so);
void	ft_fill(t_so *so, char c, int x, int y);
int		ft_exit_game(t_so *so);
void	ft_check_game(t_so *so);
int		ft_fill_flood(int x, int y, t_so *so);
void	ft_check_tools(t_so *so);
void	ft_check_border(t_so *so);
int		ft_check_move(t_so *so, int side);
int		ft_check_next_step(t_so *so, int side, char step);
void	ft_put_image_to_window(t_so *so, int i, int j);
int		ft_strlen_so(char *s);
void	ft_check_rectangular(t_so *so);

#endif