/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:34:05 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 17:43:51 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT

# define WIDTH 1024
# define HEIGHT 1024
# defiine ZOOM_DEF .01

typedef struct	s_fractal
{
    double		x;
	double		y;
	double		re;
	double		im;
	int			max_iter;
}				t_fractal;

typedef struct	s_vars
{
    void		*ctx;
	void		*win;
	double		mouse_x;
	double		mouse_y;
	int			mouse_moved;
	double		zoom;
	double		x_pan;
	double		y_pan;
	t_fractal	*fractal;
	void		*image;
	char		*pixels;
	int			*colors;
	int			sl;
	int			bpp;
	int			endian;
}				t_vars;

/*
** fractals.c
*/

int	mandelbrot(t_frac *frac, float x, float y);
int	julia(t_frac *frac, float x, float y);

/*
** callbacks.c
*/
int		loop_cb(t_frac *frac);
int		exit_cb(t_frac *frac);
