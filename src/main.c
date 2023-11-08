/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:53:36 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/08 13:39:58 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void cleanup(t_graph *graph) {
    if (graph->img) {
        mlx_destroy_image(graph->mlx, graph->img);
    }
    if (graph->win) {
        mlx_destroy_window(graph->mlx, graph->win);
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

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_graph		graph;

	graph.mlx = mlx_init();
	if (!graph.mlx)
		return (EXIT_FAILURE);
	graph.win = mlx_new_window(graph.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!graph.win)
		return (EXIT_FAILURE);
	init_img(&graph);
	if (argc == 2 && select_fractal(argv[1], &fractal))
	{
		draw_fractal(&fractal, &graph);
		mlx_put_image_to_window(graph.mlx, graph.win, graph.img, 0, 0);
		mlx_loop(graph.mlx);
	}
	else
		help_message();
//	cleanup(&graph);

	return (EXIT_SUCCESS);
}

