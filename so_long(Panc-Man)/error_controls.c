/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:58:14 by apancar           #+#    #+#             */
/*   Updated: 2024/01/20 15:14:05 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./inc/structs.h"

int	msg(char *error_mesage)
{
	write (2, error_mesage, ft_strlen(error_mesage));
	return (127);
}

void	msg_error(char *error_message)
{
	perror (error_message);
	exit (127);
}
