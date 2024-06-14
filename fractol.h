/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:24:13 by relamine          #+#    #+#             */
/*   Updated: 2024/06/14 10:58:37 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		ci;
	int		cj;
	int		iteration;
	int		max_iteration;
	double	tmp_x;
	double	x4;
	double	y4;
	double	x;
	double	y;
	int		s;
	double	zoom;
}	t_data;

typedef struct s_vatod
{
	int			signe;
	double		res;
	int			bol;
	double		dot;
	double		len;
}	t_vatod;

enum
{
	ON_DESTROY = 17,
	scroll_up = 4,
	scroll_down = 5
};

int			ft_parsing(int argc, char **argv);
double		ft_atod(char *str);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		map_repere(double x, double out_min, double out_max);
int			ft_close(t_data *graph);
int			key_hook(int keycode, t_data *graph);
void		fractal(t_data *graph);

#endif