float	mandelbrot(double x, double y)
{
	double	z_re;
	double	z_im;
//	double	sqr_z_re;
//	double	sqr_z_im;
	double	tmp_z_re;
	double	tmp_z_im;
	float		i;
	
	//z_re = 1.5 * (x - WIDTH / 2) / (.5 * WIDTH);
	//z_im = (y - HEIGHT / 2) / (.5 * HEIGHT);
	z_re = x / 600.0 - 0.0;
	z_im = y / 600.0 - 0.0;
	i = -1;
	//while (++i <= frac->max_iter)
	while (++i <= 10)
	{
		tmp_z_re = z_re * z_re - z_im * z_im + x;
		tmp_z_im = 2 * z_re * z_im + y;
		z_re = tmp_z_re;
		z_im = tmp_z_im;
		//if (z_re * z_re + z_im * z_im > 4.0)
	}
	if (z_re * z_im < 5)
		return 1;
	return (0);
}
#include <stdio.h>
int main(void)
{
//	float x = 20;
//	float y = 30;
	
	int row = -1;
	while (++row < 600)
	{
		int col = -1;
		while (++col < 600)
		{
			if (mandelbrot(col, row) > 0)
				printf("%f ", 1.0);
		}
			
		printf("\n");
	}
	return 0;
}
