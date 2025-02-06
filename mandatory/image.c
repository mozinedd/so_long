/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:30:37 by mozinedd          #+#    #+#             */
/*   Updated: 2025/02/03 16:22:44 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *loading_image(t_game *game, char *location)
{
	char	*image;
	int		width;
	width = BOX_SIZE;

	image = mlx_xpm_file_to_image(game->mlx, location, &width, &width);
	if (!image)
	{
		handle_error("faileD loading image");
		return (NULL);
	}
	return (image);
}

int init_image(t_game *game)
{
	game->wall = loading_image(game, "./textures/wall.xpm");
	game->p_img = loading_image(game, "./textures/player.xpm");
	game->c_img = loading_image(game, "./textures/collectible.xpm");
	game->e_img = loading_image(game, "./textures/exit.xpm");
	game->bg = loading_image(game, "./textures/bg.xpm");
	if (!game->wall || !game->p_img || !game->c_img || !game->e_img || !game->bg)
	{
		handle_error("no image");
		return (0);
	}
	return (1);
}