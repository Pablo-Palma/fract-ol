/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:46 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:03 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_press(int keycode, t_graph *graph)
{
	if (keycode == KEY_ESC)
		cleanup(graph);
	return (0);
}

void setup_hooks(t_graph *graph)
{
	mlx_hook(graph->win, 2, 1L<<0, handle_key_press, graph);
}

