/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:20:07 by relamine          #+#    #+#             */
/*   Updated: 2024/06/14 02:47:16 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void fractal_hole(t_data *graph)
{
	if (graph->s == 2)
	{
		graph->x = map_repere(graph->Ci, 0, 800, -2 * graph->zoom , 2 * graph->zoom);
		graph->y = map_repere(graph->Cj, 0, 800, -2 * graph->zoom, 2 * graph->zoom) * -1;
	}
	else
	{
		graph->x = 0;
		graph->y = 0;
		graph->x4 = map_repere(graph->Ci, 0 , 800, -2 * graph->zoom, 2 * graph->zoom);
		graph->y4 = map_repere(graph->Cj, 0 , 800 , 2 * graph->zoom, -2 * graph->zoom);
	}

	while ((pow(graph->x, 2) + pow(graph->y, 2)) <= 4 && graph->iteration < graph->max_iteration)
	{
		graph->tmp_x = graph->x;
		graph->x = pow(graph->x, 2) - pow(graph->y, 2) + graph->x4;
		graph->y = 2 * graph->tmp_x * graph->y + graph->y4;
		graph->iteration++;
	}
}

void fractal(t_data *graph)
{
	graph->Cj = 0;
	graph->max_iteration = 90;

	while (graph->Cj < 800)
	{
		graph->Ci = 0;
		while (graph->Ci < 800)
		{
			graph->iteration = 0;
			fractal_hole(graph);
			if (graph->iteration == graph->max_iteration)
				my_mlx_pixel_put(graph, graph->Ci, graph->Cj, 0X00FFFFFF);
			else
			{
				if (graph->iteration == 0)
					graph->iteration = 1;
				my_mlx_pixel_put(graph, graph->Ci, graph->Cj, 0X000900dc * graph->iteration);
			}
			graph->Ci++;
		}
		graph->Cj++;
	}
}
