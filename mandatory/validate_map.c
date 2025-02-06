/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:22:05 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/02 18:12:12 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangular(char **map)
{
	int i;
	int length_row;

	i = 0;
	length_row = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != length_row)
		{
			ft_printf("error map is not rect");
			return (0);
		}
		i++;
	}
	return (1);
} 

int have_walls(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		char *str = map[i];
		j = 0;
		if (str[j] != '1')
		{
			ft_printf("error map dont have walls");
			return (0);
		}
		while (str[j])
		{
			if ((i == 0 || map[i + 1] == NULL) && str[j] != '1')
			{
				ft_printf("error map dont have walls");
				return (0);
			}
			j++;
		}
		if (str[j - 1] != '1')
		{
			ft_printf("error map dont have walls");
			return (0);
		}
		i++;
	}
	return (1);
} 

int	valid_character(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		char *str = map[i];
		j = 0;
		while (str[j])
		{
			if (str[j] != '1' && str[j] != '0' && str[j] != 'P' && str[j] != 'E' && str[j] != 'C')
			{
				ft_printf("\nerror map invalid character");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	exact_character(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	e = 0;
	c = 0;
	p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while ( map[i][j])
		{
			if ( map[i][j] == 'P')
				p += 1;
			if (map[i][j] == 'E')
				e += 1;
			if (map[i][j] == 'C')
				c += 1;

			j++;
		}
		i++;
	}
	if (e != 1 || p != 1)
			{
				ft_printf("\nerror number P or E");
				return (0);
			}
	if (c < 1)
	{
		ft_printf("\nno collectible in maps");
		return (0);
	}
	return (1);
}

void is_map_valid(t_game *g)
{
	if (is_rectangular(g->map) == 0)
		handle_error("map is not rectangilar");
	if (have_walls(g->map) == 0)
		handle_error("map is not have walls");
	if (valid_character(g->map) == 0)
		handle_error("invalid character int map");
	if (exact_character(g->map) == 0)
		handle_error("map not have exact character");
	if (is_path_correct(g) == 0)
		handle_error("invalid path");
}