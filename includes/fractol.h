/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:34:05 by slimon            #+#    #+#             */
/*   Updated: 2019/11/12 21:15:03 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <libft.h>
# include "keys_consts.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define X_PAN_DEF 2.0
# define Y_PAN_DEF 1.5
# define ZOOM_DEF 200.0
# define MAX_ITER_DEF 50

typedef struct	s_frac
{
    float		mouse_x;
	float		mouse_y;
	int			max_iter;
}				t_frac;

typedef struct	s_vars
{
	float		(*frac_fun[4])(t_frac *frac, int i, float x, float y);
	int			max_iter;
	int			fun_select;
    void		*ctx;
	void		*win;
	float		mouse_x;
	float		mouse_y;
	float		zoom;
	float		x_pan;
	float		y_pan;
	void		*image;
	char		*pixels;
	int			*colors;
	int			sl;
	int			bpp;
	int			endian;
	int			pixel_size;
}				t_vars;

/*
** fractols.c
*/
float	mandelbrot(t_frac *frac, int i, float x, float y);
float	julia(t_frac *frac, int i, float x, float y);
float	julia_cubed(t_frac *frac, int i, float x, float y);
float	bship(t_frac *frac, int i, float x, float y);
/*
** controls.c
*/
void			move(int key, t_vars *vars);
void			zoom(int key, t_vars *vars);

/*
** draw.c
*/
void			draw(t_vars *vars);

/*
** callbacks.c
*/
# define KEY_PRESS_EVENT 2
# define WINDOW_CLOSE_EVENT 17
# define MOUSE_MOVE_EVENT 6

int				key_press_cb(int keycode, t_vars *vars);
int				mouse_move_cb(int x, int y, t_vars *vars);
int				loop_cb(t_vars *vars);
int				exit_cb(t_vars *vars);
int				scroll_cb(int key, int x, int y, t_vars *vars);

/*
** hooks.c
*/
void			setup_hooks(t_vars *vars);
#endif
