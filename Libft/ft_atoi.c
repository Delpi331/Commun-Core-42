/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:43:23 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/08 19:15:38 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	maxymin(int result, int sign, const char *nptr, size_t i)
{
	if (result > 2147483647 / 10 || (result == 2147483647 / 10 && (nptr[i]
				- '0') > 7))
	{
		if (sign == 1)
			return (2147483647);
		else
			return (-2147483648);
	}
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (maxymin(result, sign, nptr, i) != 0)
			return (maxymin(result, sign, nptr, i));
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
