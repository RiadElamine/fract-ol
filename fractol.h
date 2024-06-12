/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:24:13 by relamine          #+#    #+#             */
/*   Updated: 2024/06/12 16:38:34 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct    s_data {
    void    *img;
    char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}        t_data;

typedef struct    s_vatod {
	int			signe;
	double		res;
	int			bol;
	double		dot;
	double		len;
}        t_vatod;




int	ft_parsing(int argc, char **argv);
double	ft_atod(char *str);

#endif