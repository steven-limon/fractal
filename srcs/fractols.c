/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:06 by slimon            #+#    #+#             */
/*   Updated: 2019/10/26 18:46:01 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RADIUS_TWO_SQR 4
#define SQR(x) ((x) * (x))

#include <fractol.h>

float	mandelbrot(t_frac *frac, float x, float y, float i)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;

	z_re = x;
	z_im = y;
	i = -1;
	while (++i <= frac->max_iter)
	{
		sqr_z_re = z_re * z_re;
		sqr_z_im = z_im * z_im;
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i/(float)frac->max_iter);
		tmp_z_im = 2 * z_re * z_im + y;
		z_re = sqr_z_re - sqr_z_im + x;
		z_im = tmp_z_im;
	}
	return 0;
}

#include <stdio.h>
float	julia(t_frac *frac, float x, float y, float i, float C_x, float C_y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;
	
	z_re = x;
	z_im = y;
	i = -1;
	while (++i <= frac->max_iter)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i/(float)frac->max_iter);
		tmp_z_im = 2 * z_re * z_im + C_y;
		z_re = sqr_z_re - sqr_z_im + C_x;
		z_im = tmp_z_im;
	}
	return (0);
}
/*
void loop(void)
{
	int i;
	int x;
	int y;

	y = -1;
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (x < WIN_WIDTH)
		{
			x0 = -2.5 * fr->aspectRatio + (2.5 * fr->aspectRatio * 2) * x / WIN_WIDTH;
			y0 = -2.5 - (2.5 * 2) * y / WIN_HEIGHT;
			i = biomorph(x0, y0);
			if (i == 1)
				putpixel(black);
			else
				putpixel(white);
		}
	}
}
*/
#include <math.h>
float	biomorph(t_frac *frac, float x, float y, float C_x, float C_y)
{
	float	z_re;
	float	z_im;
	float	tmp_re;
	float	tmp_im;
	int		i;
	
	z_re = x;
	z_im = y;
	i = -1;
	while (++i <= frac->max_iter)
	{
		tmp_re = z_re * (z_re * z_re - 3 * z_im * z_im) + C_x;
		tmp_im = 3 * z_re * z_re - z_im * z_im + C_y;
		z_re = tmp_re;
		z_im = tmp_im;
		if (fabs(z_re) > 5)
			return (1);
		else if (fabs(z_im) > 5)
			return (0.5);
		else if (z_re * z_re + z_im + z_im >
			frac->max_iter * frac->max_iter)
			return (0);
	}
	return (0);
}

