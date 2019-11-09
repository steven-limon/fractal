/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:34:05 by slimon            #+#    #+#             */
/*   Updated: 2019/11/08 22:59:33 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <libft.h>
# include "keys_consts.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_frac
{
    float		x;
	float		y;
	float		re;
	float		im;
	int			max_iter;
	float		C_y;
	float		C_x;
}				t_frac;

typedef struct	s_vars
{
	float		(*frac_fun[4])(float *t_frac, float i);
	int			fun_select;
    void		*ctx;
	void		*win;
	float		mouse_x;
	float		mouse_y;
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
float			mandelbrot(t_frac *frac, int i);
float			julia(t_frac *frac, int i);
float			julia_cubed(t_frac *frac, int i);
float			bship(t_frac *frac, int i);

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

/*
** hooks.c
*/
void			setup_hooks(t_vars *vars);
#endif
