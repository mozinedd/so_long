/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:30:57 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/06 12:49:23 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int find_player(char **map, int *x, int *y)
{
	int i; 
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_w || y < 0 || y >= game->map_h)
		return ;
	if(map[y][x] == WALL || map[y][x] == 'V')
		return ;
	if (map[y][x] == COLLECTIBLE)
		game->c++;
    map[y][x] = 'V';
    flood_fill(map, x + 1, y, game);
    flood_fill(map, x - 1, y, game);
    flood_fill(map, x, y + 1, game);
    flood_fill(map, x, y - 1, game);
}

int	check_floodfill(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int 	i;

	map_copy = malloc(sizeof(char *) * (game->map_h + 1));
	if (!map_copy)
		return (handle_error("Error allocation"), NULL);
	i = 0;
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	is_path_correct(t_game *game)
{
	char **map_copy;
	int	x;
	int	y;
	
	find_player(game->map, &x, &y);
	game->p_x = x;
	game->p_y = y;
	map_copy = copy_map(game);
	flood_fill(map_copy, x, y, game);
	return (check_floodfill(map_copy));
}