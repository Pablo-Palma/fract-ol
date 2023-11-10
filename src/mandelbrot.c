/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:45:18 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/10 14:26:59 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_calc(t_fractal_calc *calc, double re, double im)
{
	calc->old_re = 0;
	calc->old_im = 0;
	calc->new_re = 0;
	calc->new_im = 0;
	calc->pr = re;
	calc->pi = im;
}

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;
	fractal->max_iter = MAX_ITER;
	fractal->calculate_fractal = calculate_mandelbrot;
}

int	calculate_mandelbrot(double re, double im, t_fractal *fractal)
{
	int				i;
	t_fractal_calc	calc;

	i = 0;
	init_fractal_calc(&calc, re, im);
	calc.q = (calc.pr - 0.25) * (calc.pr - 0.25) + calc.pi * calc.pi;
	if ((calc.q *(calc.q + (calc.pr - 0.25)) < 0.25 * calc.pi * calc.pi)
		|| ((calc.pr + 1) * calc.pr + 1) + calc.pi * calc.pi < 0.0625)
		return (fractal->max_iter);
	while (i < fractal->max_iter)
	{
		calc.old_re = calc.new_re;
		calc.old_im = calc.new_im;
		calc.new_re = calc.old_re * calc.old_re - calc.old_im * calc.old_im
			+ calc.pr;
		calc.new_im = 2 * calc.old_re * calc.old_im + calc.pi;
		if ((calc.new_re * calc.new_re + calc.new_im * calc.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
