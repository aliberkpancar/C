/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:36:33 by aliberk           #+#    #+#             */
/*   Updated: 2023/11/03 10:45:58 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_hex(unsigned long n, int base, const char *format)
{
	char	*hex;
	int		i;

	if (*format == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 0;
	if (n > 15)
	{
		i += ft_convert_hex(n / base, base, format);
		i += ft_putchar(hex[n % base]);
	}
	else
		i += ft_putchar(hex[n % base]);
	return (i);
}

static int	is_flag(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' || c == 'p'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_format_printer(const char *format, va_list args,
	unsigned int len)
{
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar(*format++);
		if (*format == '%' && is_flag(*(format + 1)))
		{
			if (*(++format) == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (*format == 'd' || *format == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (*format == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
				len += ft_putstr("0x")
					+ ft_convert_hex(va_arg(args, unsigned long), 16, format);
			else if (*format == 'u')
				len += ft_putnbr(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
				len += ft_convert_hex(va_arg(args, unsigned int), 16, format);
			else
				len += ft_putchar(*format);
			format++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	len;

	va_start(args, format);
	len = 0;
	len = ft_format_printer(format, args, len);
	va_end(args);
	return (len);
}
