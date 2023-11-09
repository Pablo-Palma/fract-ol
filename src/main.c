/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:53:36 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/09 14:28:24 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_graph		graph;
	int			check;

	check = 0;
	fractal.julia_const_re = UNSET_VALUE;
	fractal.julia_const_im = UNSET_VALUE;
	if (setup_gui(&graph) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	graph.fractal = &fractal;
	if (argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		fractal.julia_const_re = ft_atof(argv[2]);
		fractal.julia_const_im = ft_atof(argv[3]);
		check = 1;
	}
	if ((argc == 2 || check == 1) && select_fractal(argv[1], &fractal))
	{
		draw_fractal(&fractal, &graph);
		mlx_put_image_to_window(graph.mlx, graph.win, graph.img, 0, 0);
		setup_hooks(&graph);
		mlx_loop(graph.mlx);
	}
	else
		help_message();
//	cleanup(&graph);

	return (EXIT_SUCCESS);
}

