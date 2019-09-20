/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:44:41 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 17:46:40 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define callbacks.
*/

#include "fractol.h"

int		key_press_cb(int keycode, t_vars *vars)
{
	if (keycode == KEY_W || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_Q || keycode == KEY_E)
		move(keycode, param);
	else if (keycode == KP_PLUS || keycode == KP_MINUS)
		zoom(keycode, param);
	return (0);
}

int		mouse_move_cb(int x, int y, t_vars *vars)
{
	vars->mouse_x = x;
	vars->mouse_y = y;
	vars->changed = 1;

	return (0);
}

int		loop_cb(t_vars *vars)
{
	if (vars->mouse_moved)
		draw(&vars);
	return (0);
}

int		exit_cb(t_frac *vars)
{
	mlx_destroy_window(vars->ctx, vars->win);
	exit(0);
}
