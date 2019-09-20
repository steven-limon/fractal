/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:06 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 19:45:39 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RADIUS_TWO_SQR 4
#define SQR(x) ((x) * (x))

#include <fractol.h>

int	mandelbrot(t_frac *frac, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	int		i;
	
	z_re = x;
	z_im = y;
	sqr_z_re = SQR(z_re);
	sqr_z_im = SQR(z_im);
	i = 0;
	while (++i <= frac->max_iterations && sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
	{
		z_im = 2 * z_re * z_im + y;
		z_re = sqr_z_re - sqr_z_im + x;
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
	}
	return (i);
}
/*
int	mandelbrotBoo(t_frac *frac, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	int		i;
	
	z_re = x;
	z_im = y;
	sqr_z_re = SQR(z_re);
	sqr_z_im = SQR(z_im);
	i = 0;
	while (++i <= frac->max_iterations && sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
	{
		z_im = 2 * z_re * z_im + y;
		z_re = sqr_z_re - sqr_z_im + x;
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
	}
	return (i);
}
*/

int	julia(t_frac *frac, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	int		i;
	
	z_re = x;
	z_im = y;
	sqr_z_re = SQR(z_re);
	sqr_z_im = SQR(z_im);
	i = -1;
	while (++i <= frac->max_iterations && sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
	{
		z_im = 2 * z_re * z_im + frac->y;
		z_re = sqr_z_re - sqr_z_im + frac->x;
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
	}
	return (i);
}

void loop(void)
{
	int i;

	y = -1;
	while (y < HEIGHT)
	{
		x = -1;
		while (x < WIDTH)
		{
			x0 = -2.5 * fr->aspectRatio + (2.5 * fr->aspectRatio * 2) * x / WIDTH;
			y0 = -2.5 - (2.5 * 2) * y / HEIGHT;
			i = biomorph(x0, y0);
			if (i == 1)
				putpixel(black);
			else
				putpixel(white);
		}
	}
}

int	biomorph(t_frac *frac, float x, float y)
{
	float	z_re;
	float	z_im;
	float	tmp_re;
	float	tmp_im;
	int		i;
	
	z_re = x;
	z_im = y;
	i = -1;
	while (++i <= frac->max_iterations)
	{
		tmp_re = z_re * (z_re * z_re - 3 * z_im * z_im) + frac->x;
		tmp_im = 3 * z_re * z_re - z_im * z_im + frac->y;
		z_re = tmp_re;
		z_im = tmp_im;
		if (abs(z_re) > 10 || abs(z_im > 10))
			return (1);
		else if (z_re * z_re + z_im + z_im >
			frac->max_iterations * frac->max_iterations)
			return (0);
	}
	return (0);
}
