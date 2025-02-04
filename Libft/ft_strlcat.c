/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:55:13 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/09 14:53:42 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	j = 0;
	i = 0;
	l = 0;
	while (dst[l] != '\0' && l < size)
		l++;
	while (src[j] != '\0')
		j++;
	if (l == size)
		return (size + j);
	while (src[i] != '\0' && (l + i) < (size - 1))
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (l + j);
}
