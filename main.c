/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:28:08 by relamine          #+#    #+#             */
/*   Updated: 2024/06/12 18:19:11 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = mlx_get_color_value(data->img, color);
}

double map_reperex(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double map_reperey(double y, double in_min, double in_max, double out_min, double out_max) {
  return (in_min - y) * (out_max - out_min) / (in_max - in_min) - out_min;
}


int    main(int argc, char **argv)
{
    void    *mlx;
    void    *mlx_win;
    t_data    img;
    int Ci;
    int Cj;
    int iteration;
    int max_iteration;
    double tmp_x;
    double x4;
    double y4;
    double x;
    double y;
	int s;
	// double zoom = 2;
	s = ft_parsing(argc, argv);
	if (!s)
		return (1);
	if (s == 2)
	{
		x4 = ft_atod(argv[2]);
		printf("%lf\n",x4);
		y4 = ft_atod(argv[3]);
		printf("%lf\n",y4);
	}
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 800, "fractol");
    img.img = mlx_new_image(mlx, 800, 800);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    Cj = 0;
    max_iteration = 90;
    while (Cj < 800)
    {
        Ci = 0;
        while (Ci < 800)
        {
			if (s == 2)
			{
				x = map_reperex(Ci, 0, 800, -2, 2);
				y = map_reperex(Cj, 0, 800, -2, 2) * -1;
			}
			else
			{
				// 0 + (zoom / 2), 800 - (zoom / 2)
				x = 0;
            	y = 0;
				// x4 = map_reperex(Ci, 0 , 800, -2 + (zoom / 2), 2 - (zoom / 2));
				// y4 = map_reperey(Cj, 0 , 800 , 2 - (zoom / 2), -2 + (zoom / 2));
				
				x4 = map_reperex(Ci, 0 , 800, -2 , 2 );
				y4 = map_reperey(Cj, 0 , 800 , 2 , -2 );
				
			}
            iteration = 0;
            while ((pow(x,2)+ pow(y,2)) <= 4 && iteration < max_iteration)
            {
                tmp_x = x;
                x = pow(x,2) - pow(y,2) + x4;
                y= 2 * tmp_x * y + y4;
                iteration++;
            }
            if (iteration == max_iteration)
                my_mlx_pixel_put(&img, Ci, Cj, 0X00FFFFFF);
            else
			{
				if (iteration == 0)
					iteration = 1;
                my_mlx_pixel_put(&img, Ci, Cj, 0X000900dc * iteration);
			}
            Ci++;
        }
        Cj++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}


