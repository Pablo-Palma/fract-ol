/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:12:55 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/08 16:50:00 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_message(void)
{
	ft_printf("\nWelcome to Fract'ol\n\n");
	ft_printf("Usage: ./fractol <fractal name>\n");
	ft_printf("Options:\n");
	ft_printf("\t - Mandelbrot\n");
    ft_printf("\t - Julia\n");
	ft_printf("Controls:\n");
	ft_printf("  - ESC: Exit.\n\n");
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
		help_message();
		return (0);
	}
}
