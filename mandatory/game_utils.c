/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:03:08 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/02 17:27:17 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		handle_error("allocation failed");
	ft_memset(*game, 0, sizeof(t_game));
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		handle_error("init mlx failed");
		return ;
	}
	ft_printf("win width: %d\n", game->map_w * BOX_SIZE);
	ft_printf("win height: %d\n", game->map_h * BOX_SIZE);
	game->win = mlx_new_window(game->mlx, game->map_w * BOX_SIZE, game->map_h * BOX_SIZE, "so_long");
	if (!game->win)
		handle_error("init mlx failed");
	init_image(game);
}


