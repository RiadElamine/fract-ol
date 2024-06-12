/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 06:36:11 by relamine          #+#    #+#             */
/*   Updated: 2024/06/12 19:12:03 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (st1[i] != '\0' && st2[i] != '\0' && st1[i] == st2[i])
		i++;
	return (st1[i] - st2[i]);
}

int	ft_parsing(int argc, char **argv)
{
	if (argc >= 2)
	{
		if(ft_strcmp(argv[1], "Mandelbrotset") == 0)
		{
			if (argc > 2)
			{
				write(1,"Enter name without Coordinates", ft_strlen("Enter name without Coordinates"));
				return (0);
			}
			return (1);
		}
		else if(ft_strcmp(argv[1], "Juliaset") == 0)
		{
			if (argc != 4)
			{
				write(1,"Enter two Coordinates x and y", ft_strlen("Enter two Coordinates x and y"));
				return (0);
			}
			return (2);
		}	
	}
	write(1,"enter < Mandelbrotset > or < Juliaset >", ft_strlen("enter < Mandelbrotset > or < Juliaset >"));
	return (0);
}


#include <stdio.h>

static void ft_check_parcing(const char *str, int *bol)
{
	char		*s;
	int			i;

	i = 0;
	if (*str == '\0' || (*str >= 9 && *str <= 13) || *str == 32)
		exit(1);
	s = (char *)str;
	if (*s == '-' || *s == '+')
		i++;
	if (!s[i])
		exit(1);
	while (s[i])
	{
		if (s[0] == '.'|| (s[i] != '.' && !(s[i] >= 48 && s[i] <= 57)))
			exit(1);
		if (s[i] == '.')
			*bol = *bol + 1;
		if (*bol > 1)
			exit(1);
		if (s[i] == '.' && s[i + 1] == '\0')
			exit(1);
		i++;
	}
	*bol = 0;
}

double	ft_atod(char *str)
{
	t_vatod a;

	a.res = 0;
	a.signe = 1;
	a.bol = 0;
	a.len = 0;
	a.dot = 0;
	ft_check_parcing(str, &(a.bol));
	if (*(str) == '-' || *str == '+')
		if (*(str++) == '-')
			a.signe = -1;
	while (*str)
	{
		if (*str == '.')
			a.bol = a.bol + 1;
		if (a.bol == 0)
			a.res = a.res * 10 + (*str - 48);
		else if ((*str >= 48 && *str <= 57))
		{
			a.dot = a.dot * 10 + (*str - 48);
			a.len++;
		}
		str++;
	}
	return ((a.res + (a.dot * pow(10, -a.len)))* a.signe);
}
