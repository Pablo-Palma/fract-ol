/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:12:16 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/07 16:48:50 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define MAX_ITER 60

typedef struct s_graph
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
} 			t_graph;

typedef struct s_fractal
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		max_iter;
	int	(*calculate_fractal)(double re, double im, int max_iter);
}			t_fractal;

void	init_mandelbrot(t_fractal *fractal);
int		calculate_mandelbrot(double re, double im, int max_iter);
void	draw_fractal(t_fractal *fractal, t_graph *graph);
#endif

