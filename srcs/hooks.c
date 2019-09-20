/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:42:59 by slimon            #+#    #+#             */
/*   Updated: 2019/09/18 22:37:04 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Define hooks
*/

#include "fractol.h"

void	setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KEY_PRESS_EVENT, 0, key_press_cb, vars);
	mlx_expose_hook(vars->win, loop_cb, vars);
	mlx_hook(vars->win, WINDOW_CLOSE_EVENT, 0, exit_cb, vars);
	mlx_loop_hook(vars->ctx, loop_cb, vars);
}
