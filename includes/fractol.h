/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:34:05 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 19:44:21 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1024
# define HEIGHT 1024
# define ZOOM_DEF .01

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
** fractols.c
*/
int				mandelbrot(t_frac *frac, float x, float y);
int				julia(t_frac *frac, float x, float y);
int				biomorph(t_frac *frac, float x, float y);

/*
** controls.c
*/
void			zoom(int key, t_vars *vars);

/*
** draw.c
*/
void			loop_cb(s_vars *vars);

/*
** callbacks.c
*/
int				key_press_cb(int keycode, t_vars *vars);
int				mouse_move_cb(int x, int y, t_vars *vars);
int				loop_cb(t_vars *vars);
int				exit_cb(t_frac *vars);
#endif
