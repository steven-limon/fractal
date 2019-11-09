/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:44:41 by slimon            #+#    #+#             */
/*   Updated: 2019/11/08 23:03:57 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define callbacks.
*/

#include <fractol.h>
#include <limits.h>

int		key_press_cb(int keycode, t_vars *vars)
{
	if (keycode == KEY_RIGHT)
		vars->fun_select = (vars->fun_select + 1) % 3;
	else if (keycode == KEY_A || keycode == KP_D)
		vars->x_pan += (keycode = KEY_A) ? .05 : -.05;
	else if (keycode == KEY_S || keycode == KP_W)
		vars->y_pan += (keycode = KEY_S) ? .05 : -.05;
	draw(vars);
	return (0);
}

int		mouse_move_cb(int x, int y, t_vars *vars)
{
	vars->mouse_x = x;
	vars->mouse_y = y;
	draw(vars);
	return (0);
}

int		scroll_cb(int key, int x, int y, t_vars *vars)
{
	if (x <= WIN_WIDTH && x >= 0 && y <= WIN_HEIGHT && y >= 0)
		if (keycode == 4 && vars->zoom < INT_MAX)
			vars->zoom += 100;
		else if (key == 5 && vars->zoom > INT_MIN)
			vars->zoom -= 100;
	draw(vars); 
	return (0);
}

int		exit_cb(t_vars *vars)
{
	mlx_destroy_window(vars->ctx, vars->win);
	exit(0);
}
