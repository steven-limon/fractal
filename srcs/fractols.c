/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:06 by slimon            #+#    #+#             */
/*   Updated: 2019/11/12 21:57:17 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RADIUS_TWO_SQR 4
#define SQR(x) ((x) * (x))
#include <math.h>
#include <fractol.h>

float	mandelbrot(t_frac *frac, int i, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;

	z_re = x;
	z_im = y;
	while (++i <= frac->max_iter)
	{
		sqr_z_re = z_re * z_re;
		sqr_z_im = z_im * z_im;
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i / (float)frac->max_iter);
		tmp_z_im = 2 * z_re * z_im + y;
		z_re = sqr_z_re - sqr_z_im + x;
		z_im = tmp_z_im;
	}
	return (0);
}

float	julia(t_frac *frac, int i, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;

	z_re = x;
	z_im = y;
	while (++i <= frac->max_iter)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i / (float)frac->max_iter);
		tmp_z_im = 2 * z_re * z_im + frac->mouse_y;
		z_re = sqr_z_re - sqr_z_im + frac->mouse_x;
		z_im = tmp_z_im;
	}
	return (0);
}

float	julia_cubed(t_frac *frac, int i, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;

	z_re = x;
	z_im = y;
	while (++i <= frac->max_iter)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i / (float)frac->max_iter);
		tmp_z_im = z_im * (3 * sqr_z_re - sqr_z_im) + frac->mouse_y;
		z_re = z_re * (sqr_z_re - 3 * sqr_z_im) + frac->mouse_x;
		z_im = tmp_z_im;
	}
	return (0);
}

float	bship(t_frac *frac, int i, float x, float y)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;

	z_re = x;
	z_im = y;
	while (++i <= frac->max_iter)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i / (float)frac->max_iter);
		tmp_z_im = fabs(2 * z_re * z_im) + y;
		z_re = sqr_z_re - sqr_z_im + x;
		z_im = tmp_z_im;
	}
	return (0);
}
