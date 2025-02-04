/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:55:59 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/09 12:05:38 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t numelements, size_t elementsize)
{
	size_t			totalsize;
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	totalsize = numelements * elementsize;
	ptr = malloc(totalsize);
	p = (unsigned char *)ptr;
	i = totalsize;
	if (ptr == NULL)
		return (NULL);
	while (i--)
		p[i] = 0;
	return (ptr);
}
