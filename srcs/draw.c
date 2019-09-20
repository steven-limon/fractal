/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:56:41 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 19:45:56 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_pixel_to_img(t_vars *vars, int x, int y, int color)
{
	uint32_t *color_data;

	color_data = (uint32_t*)vars->image->pixels;
	color_data[x + y * (vars->image->sl / 4)] = color;
}

static void	draw(s_vars *vars)
{
	int			x;
	int			y;
	int			color;
	t_fractal	fractal;
	float		i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal.x = x;
			fractal.y = y;
			fractal.max_iter = 100;
			i = (float)mandelbrot(&fractal, x, y);
			i /= 100.0;
			put_pixel_to_img(&vars, x, y, 0xFF0000 * (i / 2) + 0xFF00 * (i / 4) + 0XFF * i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->ctx, vars->win, vars->image, 0, 0);
}

void		loop_cb(s_vars *vars)
{
	draw(vars);
}
