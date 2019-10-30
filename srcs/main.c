/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:54:15 by slimon            #+#    #+#             */
/*   Updated: 2019/10/29 18:04:18 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	init(t_vars *vars)
{
	vars->ctx = mlx_init();
	vars->win = mlx_new_window(vars->ctx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->zoom = 100.0;
	vars->x_pan = 0.5;
	vars->y_pan = 0.3;
	vars->image = mlx_new_image(vars->ctx, WIN_WIDTH, WIN_HEIGHT);
	vars->pixels = mlx_get_data_addr(vars->image, &(vars->bpp), &(vars->sl), &(vars->endian));
	vars->mouse_moved = 1;
	vars->mouse_x = 0;
	vars->mouse_y = 0;
}


int			main(int argc, char *argv[])
{
	t_vars vars;
	vars.mouse_moved = 0;
	(void)argv;
    if (argc != 2)
	{
		ft_putstr("usage: ./fractol [julia | mandelbrot | mystery]\n");
		exit(0);
	}
	init(&vars);
	setup_hooks(&vars);
	mlx_loop(vars.ctx);
    return (0);
}
