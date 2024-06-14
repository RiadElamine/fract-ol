/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:20:07 by relamine          #+#    #+#             */
/*   Updated: 2024/06/14 10:57:51 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_hole(t_data *graph)
{
	if (graph->s == 2)
	{
		graph->x = map_repere(graph->ci, -2 * graph->zoom, 2 * graph->zoom);
		graph->y = map_repere(graph->cj, -2 * graph->zoom,
				2 * graph->zoom) * -1;
	}
	else
	{
		graph->x = 0;
		graph->y = 0;
		graph->x4 = map_repere(graph->ci, -2 * graph->zoom, 2 * graph->zoom);
		graph->y4 = map_repere(graph->cj, 2 * graph->zoom, -2 * graph->zoom);
	}
	while ((pow(graph->x, 2) + pow(graph->y, 2)) <= 4
		&& graph->iteration < graph->max_iteration)
	{
		graph->tmp_x = graph->x;
		graph->x = pow(graph->x, 2) - pow(graph->y, 2) + graph->x4;
		graph->y = 2 * graph->tmp_x * graph->y + graph->y4;
		graph->iteration++;
	}
}

void	fractal(t_data *graph)
{
	graph->cj = 0;
	graph->max_iteration = 90;
	while (graph->cj < 800)
	{
		graph->ci = 0;
		while (graph->ci < 800)
		{
			graph->iteration = 0;
			fractal_hole(graph);
			if (graph->iteration == graph->max_iteration)
				my_mlx_pixel_put(graph, graph->ci, graph->cj, 0X00FFFFFF);
			else
			{
				if (graph->iteration == 0)
					graph->iteration = 1;
				graph->iteration = 0X000900dc * graph->iteration;
				my_mlx_pixel_put(graph, graph->ci, graph->cj,
					graph->iteration);
			}
			graph->ci++;
		}
		graph->cj++;
	}
}
