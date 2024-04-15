/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:25:32 by apancar           #+#    #+#             */
/*   Updated: 2024/01/31 10:57:27 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"
#include "./inc/gnl/get_next_line.h"

int	fda(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (127);
	return (fd);
}

void	ft_get_dimensions(t_so *so, char *file_name)
{
	int		fd;
	char	**line;
	int		i;

	fd = fda(file_name);
	line = (char **)malloc(MAX_HEIGHT * sizeof(char *));
	if (!line)
		msg_error(ALLO_ERROR);
	i = -1;
	while (++i < MAX_HEIGHT)
	{
		line[i] = get_next_line(fd);
		if (!line[i])
			break ;
	}
	if (ft_strchr(line[i - 1], '\n') != NULL)
		msg_error(MAP_ERROR);
	so->board->height = i;
	so->board->width = ft_strlen(line[0]) - 1 ;
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
	close (fd);
}

static void	ft_get_map_datas(t_board *board, char *file_name)
{
	int	fd;
	int	i;

	board->line = (char **)malloc(sizeof(char *) * board->height);
	if (!board->line)
		msg_error(ALLO_ERROR);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		msg_error(FILE_ERROR);
	i = 0;
	while (i < board->height)
	{
		board->line[i] = get_next_line(fd);
		if (!board->line[i])
		{
			free(board->line[i]);
			break ;
		}
		i++;
	}
	close(fd);
}

void	ft_coordinats(t_so *so)
{
	int	i;
	int	j;

	j = -1;
	while (++j < so->board->height)
	{
		i = -1;
		while (++i < so->board->width)
		{
			if (so->board->line[j][i] == 'P')
			{
				so->hero->x = i;
				so->hero->y = j;
				so->hero->count++;
			}
			if (so->board->line[j][i] == 'C')
				so->board->collect_count++;
			if (so->board->line[j][i] == 'E')
			{
				so->board->exit->x = i;
				so->board->exit->y = j;
				so->board->exit->count++;
			}
		}
	}
}

void	ft_read_map(t_so *so, char *file_name)
{
	so->hero->movements = 0;
	so->hero->count = 0;
	so->board->exit->count = 0;
	if (ft_is_ber(file_name) == 0 || !file_name)
		msg_error(FILE_ERROR);
	ft_get_dimensions(so, file_name);
	if (so->board->height < 3 || so->board->width < 3)
		msg_error(MAP_ERROR);
	if (so->board->width > 40 || so->board->height > 30)
		msg_error(MAP_ERROR);
	ft_get_map_datas(so->board, file_name);
	ft_coordinats(so);
	if (so->board->collect_count < 1)
		msg_error("There is not enough collect.");
	if (so->hero->count != 1 || so->board->exit->count != 1)
		msg_error("There is not a hero or an exit or there are more than one.");
}
