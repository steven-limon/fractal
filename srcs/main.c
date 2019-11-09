/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:54:15 by slimon            #+#    #+#             */
/*   Updated: 2019/11/08 23:02:55 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	init(t_vars *vars, int mode)
{
	vars->fun_frac[0] = &mandelbrot;
	vars->fun_frac[1] = &julia;
	vars->fun_frac[2] = &julia_cubed;
	vars->fun_frac[3] = &bship;
	vars->fun_select = 0;
	vars->ctx = mlx_init();
	vars->win = mlx_new_window(vars->ctx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->zoom = 100.0;
	vars->x_pan = 2.0;
	vars->y_pan = 1.5;
	vars->image = mlx_new_image(vars->ctx, WIN_WIDTH, WIN_HEIGHT);
	vars->pixels = mlx_get_data_addr(vars->image, &(vars->bpp), &(vars->sl), &(vars->endian));
	vars->mouse_x = 0;
	vars->mouse_y = 0;
	vars->zoom = 450.0;
}

int			main(int argc, char *argv[])
{
	t_vars vars;
	
	(void)argv;
    if (argc != 2 || ft_atoi(argv[1][0]) > 3|| ft_atoi(argv[1][0]) < 0)
	{
		ft_putstr("usage: ./fractol 0:mandelbrot 1:julia 2:julia_cubed 3:burning ship]\n");
		exit(0);
	}
	init(&vars, ft_atoi(argv[1][0]));
	setup_hooks(&vars);
	draw(&vars);
	mlx_loop(vars.ctx);
    return (0);
}
