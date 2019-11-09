/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:00:06 by slimon            #+#    #+#             */
/*   Updated: 2019/11/08 21:30:15 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RADIUS_TWO_SQR 4
#define MAX_ITER 50.0
#define SQR(x) ((x) * (x))
#include <math.h>
#include <fractol.h>

float	mandelbrot(t_frac *frac, int i)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;

	z_re = frac->x;
	z_im = frac->y;
	i = -1;
	while (++i <= MAX_ITER)
	{
		sqr_z_re = z_re * z_re;
		sqr_z_im = z_im * z_im;
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i/(float)MAX_ITER);
		tmp_z_im = 2 * z_re * z_im + frac->y;
		z_re = sqr_z_re - sqr_z_im + frac->x;
		z_im = tmp_z_im;
	}
	return 0;
}

float	julia(t_frac *frac, int i)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;
	
	z_re = frac->x;
	z_im = frac->y;
	i = -1;
	while (++i <= MAX_ITER)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i/(float)MAX_ITER);
		tmp_z_im = 2 * z_re * z_im + frac->C_y;
		z_re = sqr_z_re - sqr_z_im + frac->C_x;
		z_im = tmp_z_im;
	}
	return (0);
}

float	julia_cubed(t_frac *frac, int i)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;
	
	z_re = frac->x;
	z_im = frac->y;
	i = -1;
	while (++i <= MAX_ITER)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i/(float)MAX_ITER);
		tmp_z_im = z_im * (3 * sqr_z_re - sqr_z_im) + C_y;
		z_re = z_re *(sqr_z_re - 3 * sqr_z_im) + C_x;
		z_im = tmp_z_im;
	}
	return (0);
}

float	bship(t_frac *frac, int i)
{
	float	z_re;
	float	z_im;
	float	sqr_z_re;
	float	sqr_z_im;
	float	tmp_z_im;
	
	z_re = frac->x;
	z_im = frac->y;
	i = -1;
	while (++i <= MAX_ITER)
	{
		sqr_z_re = SQR(z_re);
		sqr_z_im = SQR(z_im);
		if (sqr_z_re + sqr_z_im > RADIUS_TWO_SQR)
			return ((float)i/(float)MAX_ITER);
		tmp_z_im = fabs(2 * z_re * z_im) + frac->y;
		z_re = sqr_z_re - sqr_z_im + frac->x;
		z_im = tmp_z_im;
	}
	return (0);
}
