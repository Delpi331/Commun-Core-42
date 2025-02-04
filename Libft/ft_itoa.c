/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:22:09 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/09 14:55:48 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursivo(int n, char *str, int *index)
{
	if (n >= 10 || n <= -10)
		recursivo(n / 10, str, index);
	if (n < 0)
		str[*index] = -(n % 10) + '0';
	else
		str[*index] = (n % 10) + '0';
	(*index)++;
}

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		index;

	len = n_len(n);
	index = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[index] = '-';
		index++;
	}
	else if (n == 0)
		str[index++] = '0';
	if (n != 0)
		recursivo(n, str, &index);
	str[index] = '\0';
	return (str);
}
