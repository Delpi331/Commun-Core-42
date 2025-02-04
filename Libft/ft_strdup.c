/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:49:54 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/08 19:50:25 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	totalsize;
	char	*p;
	size_t	i;

	totalsize = 0;
	totalsize = ft_strlen(s);
	i = 0;
	p = malloc(totalsize + 1);
	if (p == NULL)
		return (NULL);
	while (i < totalsize)
	{
		p[i] = s[i];
		i++;
	}
	p[totalsize] = '\0';
	return (p);
}
