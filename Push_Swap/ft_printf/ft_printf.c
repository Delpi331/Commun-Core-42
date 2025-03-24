/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:09:53 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/12/12 12:25:54 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_hex(unsigned long n, int uppercase, int *count)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase, count);
	ft_putchar_fd(base[n % 16], 1);
	(*count)++;
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, count);
	ft_putchar_fd((n % 10) + '0', 1);
	(*count)++;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			aux(format, &i, args, &count);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
// int	main(void)
// {
// 	ft_printf("Hola %s, tienes %d años.\n", "Carlos", 25);
// 	ft_printf("Este es un número: %d y esta es una palabra: %s.\n", 123,
// 		"prueba");
// 	ft_printf("Imprimiendo un caracter: %c\n", 'A');
// 	ft_printf("Imprimiendo un puntero: %p\n", main);
// 	ft_printf("Imprimiendo unsigned: %u\n", 123456);
// 	ft_printf("Imprimiendo hexadecimal: %x\n", 255);
// 	ft_printf("Imprimiendo hexadecimal en mayúsculas: %X\n", 255);
// 	ft_printf("Imprimiendo porcentaje: %%\n");
// 	ft_printf("Imprimiendo porcentaje: %%");
// 	printf("Imprimiendo porcentaje: %s", "");
// 	ft_printf("Imprimiendo porcentaje: %s", "");
// 	return (0);
// }

// int	main(void)
// {
// 	int count_ft;
// 	int count_orig;
// 	char *str = "Hola, Mundo!";
// 	int num = 42;
// 	unsigned int un = 123456789;
// 	void *ptr = &num;
// 	void *null_ptr = NULL;

// 	count_orig = printf("Imprimiendo una cadena: %s\n", str);
// 	count_ft = ft_printf("Imprimiendo una cadena: %s\n", str);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un número entero: %d\n", num);
// 	count_ft = ft_printf("Imprimiendo un número entero: %d\n", num);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un número sin signo: %u\n", un);
// 	count_ft = ft_printf("Imprimiendo un número sin signo: %u\n", un);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un puntero: %p\n", ptr);
// 	count_ft = ft_printf("Imprimiendo un puntero: %p\n", ptr);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un puntero nulo: %p\n", null_ptr);
// 	count_ft = ft_printf("Imprimiendo un puntero nulo: %p\n", null_ptr);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un número hexadecimal: %x\n", num);
// 	count_ft = ft_printf("Imprimiendo un número hexadecimal: %x\n", num);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un número hexadecimal en mayúsculas: %X\n",
// 			num);
// 	count_ft = ft_printf("Imprimiendo un número hexadecimal en mayúsculas:
// 			%X\n", num);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	count_orig = printf("Imprimiendo un puntero nulo de nuevo: %p\n", NULL);
// 	count_ft = ft_printf("Imprimiendo un puntero nulo de nuevo: %p\n", NULL);
// 	printf("printf: %d | ft_printf: %d\n\n", count_orig, count_ft);

// 	return (0);
// }