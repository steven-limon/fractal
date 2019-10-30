/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:44:41 by slimon            #+#    #+#             */
/*   Updated: 2019/10/29 18:09:32 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define callbacks.
*/

#include <fractol.h>

int		key_press_cb(int keycode, t_vars *vars)
{
	if (keycode == KEY_W || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_Q || keycode == KEY_E)
		move(keycode, vars);
	else if (keycode == KP_PLUS || keycode == KP_MINUS)
		zoom(keycode, vars);
	return (0);
}

int		mouse_move_cb(int x, int y, t_vars *vars)
{
	ft_putstr("mouse move cb\n");
	vars->mouse_x = 4.0 * x / WIN_WIDTH - 2;
	vars->mouse_y = 4.0 * y / WIN_HEIGHT - 2;
	vars->mouse_moved = 1;

	return (0);
}

int		loop_cb(t_vars *vars)
{
	if (vars->mouse_moved)
	{
		ft_putstr("mouse moved\n");
		draw(vars);
		vars->mouse_moved = 0;
	}
	else
		draw(vars);
	return (0);
}

int		exit_cb(t_vars *vars)
{
	mlx_destroy_window(vars->ctx, vars->win);
	exit(0);
}
