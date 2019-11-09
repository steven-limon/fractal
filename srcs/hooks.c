/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:42:59 by slimon            #+#    #+#             */
/*   Updated: 2019/11/08 22:47:55 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define hooks
*/

#include <fractol.h>

void	setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KEY_PRESS_EVENT, 0, key_press_cb, vars);
	mlx_hook(vars->win, MOUSE_MOVE_EVENT, 0, mouse_move_cb, vars);
	mlx_hook(vars->win, 4, 0, scroll_cb, vars);
	mlx_hook(vars->win, WINDOW_CLOSE_EVENT, 0, exit_cb, vars);
}
