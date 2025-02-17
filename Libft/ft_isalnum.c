/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:57 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/08 19:45:04 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char a)
{
	return ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0'
			&& a <= '9'));
}
