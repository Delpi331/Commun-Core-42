/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:34:19 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/12/10 20:44:59 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_character_and_string(const char *format, int *i, va_list args,
		int *count)
{
	char	*str;

	if (format[*i] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (format[*i] == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			(*count) += 6;
		}
		else
		{
			ft_putstr_fd(str, 1);
			(*count) += ft_strlen(str);
		}
	}
}

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	addr;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		(*count) += 5;
	}
	else
	{
		addr = (unsigned long)ptr;
		ft_putstr_fd("0x", 1);
		(*count) += 2;
		ft_putnbr_hex(addr, 0, count);
	}
}

void	handle_numbers_and_pointers(const char *format, int *i, va_list args,
		int *count)
{
	char	*str;

	if (format[*i] == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		ft_putstr_fd(str, 1);
		(*count) += ft_strlen(str);
		free(str);
	}
	else if (format[*i] == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
}

void	aux(const char *format, int *i, va_list args, int *count)
{
	(*i)++;
	handle_character_and_string(format, i, args, count);
	handle_numbers_and_pointers(format, i, args, count);
	if (format[*i] == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), 0, count);
	else if (format[*i] == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), 1, count);
	else if (format[*i] == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
}
