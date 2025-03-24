/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:07:09 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/18 18:40:11 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
void	ft_putnbr_hex(unsigned long n, int uppercase, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	aux(const char *format, int *i, va_list args, int *count);
int		ft_printf(const char *format, ...);
#endif
