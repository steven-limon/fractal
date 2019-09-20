/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:54:15 by slimon            #+#    #+#             */
/*   Updated: 2019/09/19 17:11:16 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int main(int argc, char *argv[])
{
	t_vars vars;
    if (argc ! 2)
	{
		ft_putstr("usage: ./fractol [julia | mandelbrot | mystery]\n");
		exit(0);
	}
	init(&vars);
	setup_hooks(&vars);
	mlx_loop(vars.ctx);
    return 0;
}

void init(t_vars *vars)
{
	vars->ctx = mlx_init();
	vars->win = mlx_new_window(vars->ctx, WIDTH, HEIGHT, "fractol");
	vars->zoom = 100.0;
	vars->x_pan = 0.5;
	vars->y_pan = 0.3;
	vars->image = mlx_new_image(vars->ctx, WIDTH, HEIGHT);
	vars->pixels = mlx_get_data_addr(vars->imgage, &(vars->bpp), &(vars->sl), &(vars->endian));
}
