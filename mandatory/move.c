/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:35:47 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/06 13:19:20 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	
	int new_x;
	int new_y;
	
	new_x = game->p_x;
	new_y = game->p_y;
	if (keycode == ESC)
		exit (0);
	if (keycode == RIGHT)
		new_x += 1;
	else if (keycode == LEFT)
		new_x -= 1;
	else if (keycode == UP)
		new_y -= 1;
	else if (keycode == DOWN)
		new_y += 1;
	if (game->map[new_y][new_x] != WALL)
	{	
		if (game->map[new_y][new_x] == COLLECTIBLE)
		{
			game->c--;
			game->map[new_y][new_x] = '0';
		}
		if (game->c == 0 && game->map[new_y][new_x] == 'E')
			exit (0);
		if((game->p_y != new_y) || (game->p_x != new_x))
		{
			game->move++;
			ft_printf("moves: %d\n", game->move);
		}
		game->p_x = new_x;
		game->p_y = new_y;
	}
	
	render_all_map(game);
	return (0);
}

