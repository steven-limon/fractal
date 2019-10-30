/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:34:05 by slimon            #+#    #+#             */
/*   Updated: 2019/10/26 18:46:02 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <libft.h>
# include "keys_consts.h"

//# define WIDTH 1024
//# define HEIGHT 1024
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ZOOM_DEF 2
# define PAN_DEF .01
# define KEY_PRESS_EVENT 2
# define WINDOW_CLOSE_EVENT 17
# define MOUSE_MOVE_EVENT 6

typedef struct	s_frac
{
    float		x;
	float		y;
	float		re;
	float		im;
	int			max_iter;
}				t_frac;

typedef struct	s_vars
{
    void		*ctx;
	void		*win;
	float		mouse_x;
	float		mouse_y;
	int			mouse_moved;
	float		zoom;
	float		x_pan;
	float		y_pan;
	t_frac		*frac;
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
float				mandelbrot(t_frac *frac, float x, float y, float i);
float				julia(t_frac *frac, float x, float y, float i, float C_x, float C_y);
float				biomorph(t_frac *frac, float x, float y, float C_x, float C_y);

/*
** controls.c
*/
void			move(int key, t_vars *vars);
void			zoom(int key, t_vars *vars);

/*
** draw.c
*/
void	draw(t_vars *vars);

/*
** callbacks.c
*/
int				key_press_cb(int keycode, t_vars *vars);
int				mouse_move_cb(int x, int y, t_vars *vars);
int				loop_cb(t_vars *vars);
int				exit_cb(t_vars *vars);

/*
** hooks.c
*/
void	setup_hooks(t_vars *vars);
#endif
