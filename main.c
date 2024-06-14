/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:28:08 by relamine          #+#    #+#             */
/*   Updated: 2024/06/14 10:18:56 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_destroy_img(t_data *graph)
{
	graph->img = mlx_new_image(graph->mlx, 800, 800);
	graph->addr = mlx_get_data_addr(graph->img, &graph->bits_per_pixel,
			&graph->line_length, &graph->endian);
	fractal(graph);
	mlx_put_image_to_window(graph->mlx, graph->mlx_win,
		graph->img, 0, 0);
	mlx_destroy_image(graph->mlx, graph->img);
}

static int	mouse_hook(int keycode, int x, int y, t_data *graph)
{
	(void)x;
	(void)y;
	if (keycode == scroll_down)
	{
		mlx_clear_window(graph->mlx, graph->mlx_win);
		graph->zoom *= 1.15;
		create_destroy_img(graph);
	}
	else if (keycode == scroll_up)
	{
		mlx_clear_window(graph->mlx, graph->mlx_win);
		graph->zoom /= 1.15;
		create_destroy_img(graph);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	graph;

	graph.s = ft_parsing(argc, argv);
	if (!graph.s)
		return (1);
	if (graph.s == 2)
	{
		graph.x4 = ft_atod(argv[2]);
		graph.y4 = ft_atod(argv[3]);
	}
	graph.mlx = mlx_init();
	graph.mlx_win = mlx_new_window(graph.mlx, 800, 800, "fractol");
	graph.zoom = 1.0;
	create_destroy_img(&graph);
	mlx_mouse_hook(graph.mlx_win, mouse_hook, &graph);
	mlx_hook(graph.mlx_win, ON_DESTROY, 0, ft_close, &graph);
	mlx_key_hook(graph.mlx_win, key_hook, &graph);
	mlx_loop(graph.mlx);
}
