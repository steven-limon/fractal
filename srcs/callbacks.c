/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:44:41 by slimon            #+#    #+#             */
/*   Updated: 2019/11/12 21:57:03 by slimon           ###   ########.fr       */
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
		vars->fun_select = (vars->fun_select + 1) % 4;
	else if (keycode == KEY_A || keycode == KEY_D)
		vars->x_pan += (keycode == KEY_A) ? .05 : -.05;
	else if (keycode == KEY_S || keycode == KEY_W)
		vars->y_pan += (keycode == KEY_W) ? .05 : -.05;
	else if (keycode == KEY_R)
	{
		vars->x_pan = X_PAN_DEF;
		vars->y_pan = Y_PAN_DEF;
		vars->zoom = ZOOM_DEF;
		vars->max_iter = MAX_ITER_DEF;
	}
	else if (keycode == KEY_UP && vars->max_iter < 300)
		vars->max_iter += 10;
	else if (keycode == KEY_DOWN && vars->max_iter >= 20)
		vars->max_iter -= 10;
	draw(vars);
	return (0);
}

int		mouse_move_cb(int x, int y, t_vars *vars)
{
	vars->mouse_x = x * 4.0 / WIN_HEIGHT - 2;
	vars->mouse_y = y * 4.0 / WIN_WIDTH - 2;
	draw(vars);
	return (0);
}

int		scroll_cb(int key, int x, int y, t_vars *vars)
{
	if (x <= WIN_WIDTH && x >= 0 && y <= WIN_HEIGHT && y >= 0)
	{
		if (key == 4 && vars->zoom < INT_MAX)
			vars->zoom += 100;
		else if (key == 5 && vars->zoom > INT_MIN)
			vars->zoom -= 100;
	}
	draw(vars);
	return (0);
}

int		exit_cb(t_vars *vars)
{
	mlx_destroy_window(vars->ctx, vars->win);
	exit(0);
}
