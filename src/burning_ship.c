/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:02:45 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/10 12:41:31 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burning_ship(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 1.5;
	fractal->min_im = -2.0;
	fractal->max_im = 1.0;
	fractal->max_iter = MAX_ITER;
	fractal->calculate_fractal = calculate_burning_ship;
}

int	calculate_burning_ship(double re, double im, t_fractal *fractal)
{
	int		i;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;

	i = 0;
	new_re = 0;
	new_im = 0;
	old_re = 0;
	old_im = 0;
	while (i < fractal->max_iter)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + re;
		new_im = 2 * fabs(old_re * old_im) + im;
		new_re = fabs(new_re);
		new_im = fabs(new_im);
		if ((new_re * new_re + new_im * new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
