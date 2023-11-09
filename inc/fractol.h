/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:12:16 by pabpalma          #+#    #+#             */
/*   Updated: 2023/11/09 17:16:11 by pabpalma         ###   ########.fr       */
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

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

#define ITER_ADJ_FACTOR 100
#define UNSET_VALUE -123456789.0

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
	t_fractal	*fractal;
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
	t_fractal_func calculate_fractal;
}			t_fractal;

///###   Mandelbrot_set   ###////
void	init_mandelbrot(t_fractal *fractal);
int calculate_mandelbrot(double re, double im, t_fractal *fractal);

///###   Julia's_set   ###////
void	init_julia(t_fractal *fractal);
int	calculate_julia(double re, double im, t_fractal *fractal);

///###   Burning_ship_set   ###////
void	init_burning_ship(t_fractal *fractal);
int	calculate_burning_ship(double re, double im, t_fractal *fractal);

void	draw_fractal(t_fractal *fractal, t_graph *graph);

int	select_fractal(char *name, t_fractal *fractal);
void	help_message(void);

//###   setup   ###//
void	init_img(t_graph *graph);
int	setup_gui(t_graph *graph);
void cleanup(t_graph *graph);

//###   events   ###//
void setup_hooks(t_graph *graph);

#endif

