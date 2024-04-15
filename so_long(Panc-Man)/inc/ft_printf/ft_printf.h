/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:15:32 by apancar           #+#    #+#             */
/*   Updated: 2023/12/30 08:08:28 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
unsigned int	ft_putchar(char c);
unsigned int	ft_putnbr(long nb);
unsigned int	ft_putstr(char *str);
int				ft_strlen_p(const char *str);

#endif
