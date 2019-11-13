/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:56:41 by slimon            #+#    #+#             */
/*   Updated: 2019/11/12 21:17:10 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_pixel_to_img(t_vars *vars, int x, int y, uint32_t color)
{
	uint32_t	*color_data;

	color_data = (uint32_t*)vars->pixels;
	color_data[x + y * vars->pixel_size] = color;
}

void	draw(t_vars *vars)
{
	int			x;
	int			y;
	float		i;
	t_frac		frac;

	frac.mouse_x = vars->mouse_x;
	frac.mouse_y = vars->mouse_y;
	frac.max_iter = vars->max_iter;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			//i = mandelbrot(&(t_frac){.x = x / (float)ZOOM_DEF - X_PAN_DEF , .y = y / (float)ZOOM_DEF - Y_PAN_DEF, 0}, 0, 50);
			//i = julia(&fractal, 0, 40);
			//i = mandelbrot(&frac, -1, (float)x / (float)ZOOM_DEF - X_PAN_DEF, (float)y / (float)ZOOM_DEF - Y_PAN_DEF);
			i = vars->frac_fun[vars->fun_select](&frac, -1, (float)x / (float)ZOOM_DEF - X_PAN_DEF, (float)y / (float)ZOOM_DEF - Y_PAN_DEF);
			put_pixel_to_img(vars, x, y, i * 0xAA + i * 0xFF00 + i * 0xCB0000);
		}
	}
	mlx_put_image_to_window(vars->ctx, vars->win, vars->image, 0, 0);
}
