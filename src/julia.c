/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:04:44 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/08 12:27:03 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->max_iter = MAX_ITER;
	fractal->calculate_fractal = calculate_julia;
	fractal->julia_const_re = -0.7;
	fractal->julia_const_im = 0.27015;
}

int	calculate_julia(double re, double im, t_fractal *fractal)
{
	int		i;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;

	i = 0;
	new_re = re;
	new_im = im;
	while (i < fractal->max_iter)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + fractal->julia_const_re;
		new_im = 2 *old_re * old_im  + fractal->julia_const_im;
		if ((new_re * new_re + new_im * new_im) > 4)
			break;
		i++;
	}
	return (i);
}
