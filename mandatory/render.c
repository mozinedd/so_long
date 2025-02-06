/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:56:49 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/06 12:29:47 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render(t_game *g, int x, int y)
{
	char box = g->map[y][x];
		mlx_put_image_to_window(g->mlx, g->win, g->bg, x * BOX_SIZE, y * BOX_SIZE);
	if (box == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall, x * BOX_SIZE, y * BOX_SIZE);
	else if (box == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->c_img, x * BOX_SIZE, y * BOX_SIZE);
	else if (box == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->e_img, x * BOX_SIZE, y * BOX_SIZE);
}

int render_all_map(t_game *game)
{
	int y;
	int x;
	
	y = 0;
	while(y < game->map_h)
	{
		x = 0;
		while(x < game->map_w)
		{
			render(game, x, y);
			x++;
		}
		y++;
	}
	x = game->p_x;
	y = game->p_y;
	mlx_put_image_to_window(game->mlx, game->win, game->p_img, x * BOX_SIZE, y * BOX_SIZE);
return (1);
}
