/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:56:41 by slimon            #+#    #+#             */
/*   Updated: 2019/10/29 18:07:34 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_pixel_to_img(t_vars *vars, int x, int y, uint32_t color)
{
	uint32_t *color_data;

	color_data = (uint32_t*)vars->pixels;
	color_data[x + y * (vars->sl / 4)] = color;
}
#include <stdio.h>
#define ZOOM_X 200.0
#define ZOOM_Y 200.0
#define PAN_X 2.0
#define PAN_Y 1.5
void	draw(t_vars *vars)
{
	int			x;
	int			y;
	t_frac		fractal;
	float		i;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			#if 0
			/*
			fractal.x = x;
			fractal.y = y;
			fractal.max_iter = 50;
			i = mandelbrot(&fractal, x/(float)200 - 2.0 , y/(float)200 - 1.5, 0);
			//i = mandelbrot(&fractal, x, y, -1);
			//i = i / (float)fractal.max_iter;
			//if (y == 0)
			//	printf("i is: %f\n", i);
			put_pixel_to_img(vars, x, y, i * 0xAA + i * 0xFF00 + i * 0xCB0000);
			//put_pixel_to_img(vars, x, y, i * 0x00FFFFFF);
			x++;
			*/
			#endif
			fractal.x = x;
			fractal.y = y;
			fractal.max_iter = 50;
			//i = mandelbrot(&fractal, x / (float)ZOOM_X - PAN_X , y / (float)ZOOM_Y - PAN_Y, 0);
			ft_putnbr(vars->mouse_x);
			ft_putnbr(vars->mouse_y);
			i = julia(&fractal, x/(float)ZOOM_X - PAN_X , y/ (float)ZOOM_Y - PAN_Y, vars->mouse_x, vars->mouse_y, -.1);
			//i = biomorph(&fractal, x/(float)ZOOM_X - PAN_X , y/ (float)ZOOM_Y - PAN_Y, 0.2, -.1);
			//put_pixel_to_img(vars, x, y, i * 0xAA + i * 0xFF00 + i * 0xCB0000);
			put_pixel_to_img(vars, x, y, i * 0xAA + i * 0xFF00 + i * 0xCB0000);
			//put_pixel_to_img(vars, x, y, i * 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->ctx, vars->win, vars->image, 0, 0);
}
