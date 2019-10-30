/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:57:58 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	move(int key, t_vars *vars)
{
	if (key == KEY_D)
		vars->x_pan -= PAN_DEF;
	else if (key == KEY_A)
		vars->x_pan -= PAN_DEF;
	else if (key == KEY_S)
		vars->y_pan -= PAN_DEF;
	else if (key == KEY_W)
		vars->y_pan -= PAN_DEF;
}

void	zoom(int key, t_vars *vars)
{
	if (key == KP_PLUS)
		vars->zoom += ZOOM_DEF;
	else if (key == KP_MINUS)
		vars->zoom -= ZOOM_DEF;
}
