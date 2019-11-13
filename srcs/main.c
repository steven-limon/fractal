/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:54:15 by slimon            #+#    #+#             */
/*   Updated: 2019/11/12 21:56:49 by slimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	init(t_vars *vars, int mode)
{
	vars->frac_fun[0] = &mandelbrot;
	vars->frac_fun[1] = &julia;
	vars->frac_fun[2] = &julia_cubed;
	vars->frac_fun[3] = &bship;
	vars->fun_select = mode;
	vars->ctx = mlx_init();
	vars->win = mlx_new_window(vars->ctx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->x_pan = X_PAN_DEF;
	vars->y_pan = Y_PAN_DEF;
	vars->image = mlx_new_image(vars->ctx, WIN_WIDTH, WIN_HEIGHT);
	vars->pixels = mlx_get_data_addr(vars->image, &(vars->bpp), &(vars->sl),
										&(vars->endian));
	vars->pixel_size = vars->sl / 4;
	vars->mouse_x = 0;
	vars->mouse_y = 0;
	vars->zoom = ZOOM_DEF;
	vars->max_iter = MAX_ITER_DEF;
}

int			main(int argc, char *argv[])
{
	t_vars vars;

	(void)argv;
	if (argc != 2 || ft_atoi(argv[1]) > 3 || ft_atoi(argv[1]) < 0)
	{
		ft_putstr("usage: ./fractol 0:mandelbrot 1:julia 2:"\
				"julia_cubed 3:burning ship]\n");
		exit(0);
	}
	init(&vars, ft_atoi(argv[1]));
	setup_hooks(&vars);
	draw(&vars);
	mlx_loop(vars.ctx);
	return (0);
}
