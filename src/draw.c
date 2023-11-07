/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:46:45 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/07 17:29:48 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/*unsigned int	get_psy_color(int	iter)
{
	float	s_red = (int)(sin(0.1 * iter) + 1) * 127.5;
	float	s_green = (int)(sin(0.2 * iter) + 1) * 127.5;
	float	s_blue = (int)(sin(0.3 * iter) + 1) * 127.5;

	int	red = (int)s_red;
	int	green = (int)s_green;
	int	blue = (int)s_blue;
	return (red << 16) | (green << 8) | blue;
}
*/

unsigned int get_psy_color(int iteration)
{
    int red;
    int green;
    int blue;

    red = (int)((sin(0.1 * iteration) + 1) * 0.5 * 255);
    green = (int)((sin(0.2 * iteration) + 1) * 0.5 * 255);
    blue = (int)((sin(0.3 * iteration) + 1) * 0.5 * 255);
    return ((red << 16) | (green << 8) | blue);
}


int	get_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0x000000);
	return (get_psy_color(iter));
}

void	put_pixel_to_image(t_graph *graph, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = graph->addr + (y * graph->line_lenght + x * (graph->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_fractal(t_fractal *fractal, t_graph *graph)
{
	int		x;
	int		y;
	int		color;
	int		iter;
	double	re;
	double	im;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			re = fractal->min_re + (fractal->max_re - fractal->min_re) * x / WIN_WIDTH;
			im = fractal->min_im + (fractal->max_im - fractal->min_im) * y / WIN_HEIGHT;

			iter = fractal->calculate_fractal(re, im, fractal->max_iter);
			color = get_color(iter, fractal->max_iter);

			put_pixel_to_image(graph, x, y, color);
			x++;
		}
		y++;
	}
}
