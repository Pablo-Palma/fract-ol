/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:46 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/10 14:02:17 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_arrow_keys(int keycode, t_graph *graph)
{
	double	move_step;

	move_step = (graph->fractal->max_re - graph->fractal->min_re) * 0.05;
	if (keycode == KEY_UP)
	{
		graph->fractal->min_im -= move_step;
		graph->fractal->max_im -= move_step;
	}
	else if (keycode == KEY_DOWN)
	{
		graph->fractal->min_im += move_step;
		graph->fractal->max_im += move_step;
	}
	else if (keycode == KEY_LEFT)
	{
		graph->fractal->min_re -= move_step;
		graph->fractal->max_re -= move_step;
	}
	else if (keycode == KEY_RIGHT)
	{
		graph->fractal->min_re += move_step;
		graph->fractal->max_re += move_step;
	}
}

int	handle_key_press(int keycode, t_graph *graph)
{
	if (keycode == KEY_ESC)
		cleanup(graph);
	else if (keycode == KEY_SPACE)
		graph->fractal->julia_fixed = !graph->fractal->julia_fixed;
	else if (keycode == 8)
		graph->color_mode = (graph->color_mode + 1) % 3;
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		handle_arrow_keys(keycode, graph);
	draw_fractal(graph->fractal, graph);
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
	return (0);
}

int	handle_close(void *param)
{
	t_graph	*graph;

	graph = (t_graph *)param;
	cleanup(graph);
	return (0);
}

int	handle_mouse_scroll(int button, int x, int y, t_graph *graph)
{
	t_fractal	*fractal;
	t_zoom		zoom;

	fractal = graph->fractal;
	zoom.mouse_re = (double)x / (WIN_WIDTH / (fractal->max_re
				- fractal->min_re)) + fractal->min_re;
	zoom.mouse_im = (double)y / (WIN_HEIGHT / (fractal->max_im
				- fractal->min_im)) + fractal->min_im;
	if (button == 5)
		zoom.zoom_factor = 0.9; 
	else if (button == 4)
		zoom.zoom_factor = 1.1; 
	else
		return (0);
	zoom.range_re = (fractal->max_re - fractal->min_re) * zoom.zoom_factor;
	zoom.range_im = (fractal->max_im - fractal->min_im) * zoom.zoom_factor;
	fractal->min_re = zoom.mouse_re - (x / (double)WIN_WIDTH) * zoom.range_re;
	fractal->max_re = fractal->min_re + zoom.range_re;
	fractal->min_im = zoom.mouse_im - (y / (double)WIN_HEIGHT) * zoom.range_im;
	fractal->max_im = fractal->min_im + zoom.range_im;
	draw_fractal(fractal, graph);
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
	return (0);
}

void	setup_hooks(t_graph *graph)
{
	mlx_hook(graph->win, 2, 1L << 0, handle_key_press, graph);
	mlx_hook(graph->win, 17, 0L, handle_close, graph);
	mlx_hook(graph->win, 4, 0L, handle_mouse_scroll, graph);
	mlx_hook(graph->win, 6, 0L, julia_motion, graph);
}
