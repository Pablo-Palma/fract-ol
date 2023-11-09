/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:12:55 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/09 17:30:56 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	help_message(void)
{
	ft_printf("\nWelcome to Fract'ol\n\n");
	ft_printf("Usage: ./fractol <fractal name>\n");
	ft_printf("Options:\n");
	ft_printf("\t - Mandelbrot\n");
    ft_printf("\t - Julia\n");
	ft_printf("Controls:\n");
	ft_printf("  - ESC: Exit.\n\n");
	exit(EXIT_FAILURE);
}*/

void help_message(void)
{
    ft_printf("\nWelcome to Fract'ol - A window to the beauty of fractals\n\n");
    ft_printf("Usage: ./fractol <fractal name> [optional parameters]\n");
    ft_printf("Options:\n");
    ft_printf("\t - Mandelbrot: Explore the famous Mandelbrot Set\n");
    ft_printf("\t - Julia: Dive into the mesmerizing Julia Sets with optional parameters\n");
    ft_printf("\t - Burning_ship: Take the helm in this sea of flames\n");
    ft_printf("\n");
    ft_printf("Examples of Julia Sets:\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf(" | Parameters       | Description                     |\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf(" | -0.4 0.6         | A Classic Swirl                 |\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf(" | 0.285 0.01       | A Distant Nebula                |\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf(" | -0.8 0.156       | The Dragon's Lair               |\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf(" | -0.70176 -0.3842 | An Alien Glyph                  |\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf(" | 0.355 0.355      | A Spiral Galaxy                 |\n");
    ft_printf(" +------------------+---------------------------------+\n");
    ft_printf("\nControls:\n");
    ft_printf("  - ESC: Exit.\n");
    ft_printf("  - Arrow keys: Move around the fractal.\n");
    ft_printf("  - Mouse scroll: Zoom in and out.\n");
    ft_printf("\nHappy Fractal Exploring!\n\n");
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
	else if (ft_strncmp(name, "Burning_ship", 12) == 0)
	{
		init_burning_ship(fractal);
		return (1);
	}
	else
	{
		help_message();
		return (0);
	}
}
