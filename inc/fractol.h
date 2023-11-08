/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:12:16 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/08 13:39:21 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define MAX_ITER 60

typedef struct s_fractal t_fractal; // Forward declaration.

typedef int (*t_fractal_func)(double re, double im, t_fractal *fractal);


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
	double	julia_const_re;
	double	julia_const_im;
	int		max_iter;
	t_fractal_func calculate_fractal;;
}			t_fractal;

void	init_mandelbrot(t_fractal *fractal);
int calculate_mandelbrot(double re, double im, t_fractal *fractal);

void	init_julia(t_fractal *fractal);
int	calculate_julia(double re, double im, t_fractal *fractal);

void	draw_fractal(t_fractal *fractal, t_graph *graph);

int	select_fractal(char *name, t_fractal *fractal);
void	help_message(void);

#endif

