/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:43:34 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/12/19 16:14:03 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mandelbrot(double real, double imag)
{
	int		iteration;
	double	z_real;
	double	z_imag;
	double	z_real_sq;
	double	z_imag_sq;

	z_real = real;
	z_imag = imag;
	z_real_sq = z_real * z_real;
	z_imag_sq = z_imag * z_imag;
	iteration = 0;
	while (z_real_sq + z_imag_sq <= 4.0 && iteration < MAX_ITER)
	{
		z_imag = 2 * z_real * z_imag + imag;
		z_real = z_real_sq - z_imag_sq + real;
		z_real_sq = z_real * z_real;
		z_imag_sq = z_imag * z_imag;
		iteration++;
	}
	return (iteration);
}