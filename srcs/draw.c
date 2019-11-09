/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:56:41 by slimon            #+#    #+#             */
/*   Updated: 2019/11/08 23:13:39 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

#define MAX_ITER_DEF 40;

static void	put_pixel_to_img(t_vars *vars, int x, int y, uint32_t color)
{
	uint32_t	*color_data;
	static int	pixel_size = vars->sl / 4;

	color_data = (uint32_t*)vars->pixels;
	color_data[x + y * pixel_size] = color;
}

void	draw(t_vars *vars)
{
	int			x;
	int			y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			//i = mandelbrot(&(t_frac){.x = x / (float)ZOOM_X - PAN_X , .y = y / (float)ZOOM_Y - PAN_Y, 0}, 0);
			//i = julia(&(t_frac){.x = ((float)x / (float)ZOOM_X - PAN_X), .y = ((float)y / (float)ZOOM_Y - PAN_Y), .C_x = (float)vars->mouse_x, .C_y = (float)vars->mouse_y, .max_iter = 40}, 0);
			i = vars->frac_fun[vars->fun_select](&fractal, {.x = x / (float)zoom - vars->x_pan , .y = y / (float)zoom - vars->y_pan, .C_x = vars->mouse_x, .C_y = vars->mouse_y, .max_iter = MAX_ITER_DEF}, 0);
			put_pixel_to_img(vars, x, y, i * 0xAA + i * 0xFF00 + i * 0xCB0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->ctx, vars->win, vars->image, 0, 0);
}
