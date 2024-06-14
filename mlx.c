/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:16:59 by relamine          #+#    #+#             */
/*   Updated: 2024/06/14 01:07:37 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = mlx_get_color_value(data->img, color);
}

double map_repere(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int ft_close(t_data *graph)
{
	mlx_destroy_window(graph->mlx, graph->mlx_win);
	exit(0);
}
int	key_hook(int keycode, t_data *graph)
{
	if (keycode ==  53)
	{
		mlx_destroy_window(graph->mlx, graph->mlx_win);
    	exit(0);
	}
	return (0);
}

