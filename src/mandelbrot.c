/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:45:18 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/07 13:00:37 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;
	fractal->max_iter = MAX_ITER;
	fractal->calculate_fractal = calculate_mandelbrot;
}

int	calculate_mandelbrot(double re, double im, int max_iter)
{
	int		i;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	pr;
	double	pi;

	i = 0;
	old_re = 0;
	old_im = 0;
	new_re = 0;
	new_im = 0;
	pr = re;
	pi = im;
	while (i < max_iter)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im *old_im + pr;
		new_im = 2 * old_re * old_im + pi;
		if ((new_re * new_re + new_im * new_im) > 4)
			break;
				i++;
	}
	return (i);
}
