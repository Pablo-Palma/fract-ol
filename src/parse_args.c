/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:12:55 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/08 13:39:14 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_message(void)
{
	ft_printf("Usage: ./fractol [Mandelbrot/Julia]\n");
	exit(EXIT_FAILURE);
}

int	select_fractal(char *name, t_fractal *fractal)
{
	if (ft_strncmp(name, "Mandelbrot", 10) == 0)
	{
		init_mandelbrot(fractal);
		return (1);
	}
	else if (ft_strncmp(name, "Julia", 5) == 0)
	{
		init_julia(fractal);
		return (1);
	}
	else
	{
		ft_printf("Usage: ./fractol[Mandlebrot/Julia]\n");
		return (0);
	}
}
