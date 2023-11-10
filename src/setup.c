/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:04 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/10 13:00:07 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup(t_graph *graph)
{
	if (graph->img && graph->img) 
	{
		mlx_destroy_image(graph->mlx, graph->img);
		graph->win = NULL;
	}
	if (graph->win && graph->win)
	{
		mlx_destroy_window(graph->mlx, graph->win);
		graph->win = NULL;
	}
	exit(0);
}

void	init_img(t_graph *graph)
{
	graph->img = mlx_new_image(graph->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!graph->img)
	{
		fprintf(stderr, "Error: mlx_new_image failed\n");
		exit(EXIT_FAILURE);
	}
	graph->addr = mlx_get_data_addr(graph->img, &(graph->bpp),
			&(graph->line_lenght), &(graph->endian));
}

int	setup_gui(t_graph *graph)
{
	graph->mlx = mlx_init();
	if (!graph->mlx)
		return (EXIT_FAILURE);
	graph->win = mlx_new_window(graph->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!graph->win)
		return (EXIT_FAILURE);
	init_img(graph);
	return (EXIT_SUCCESS);
}
