#include "so_long.h"

int	is_valid_ext(char *str)
{
	char	*ext;
	int		len;

	len = ft_strlen(str);
	ext = str + (len - 4);
	if (ft_strncmp(ext, ".ber", 4) != 0)
		return (0);
	return (1);
}

int main(int ac, char *av[])
{
	int		line_map;
	t_game	*game;

	if (ac != 2) 
		handle_error("error arg");
	if (is_valid_ext(av[1]) == 0) 
		handle_error("wrong map file extension");
	line_map = get_map_lines(av[1]);
	if (line_map == -1)
		handle_error("file map does not exists");
	else if (line_map == 0)
		handle_error("empty file");
	allocate_game(&game);
	game->map_h = line_map;
	game->map = malloc(sizeof(char*) * (line_map + 1));
	if (!game->map)
		handle_error("Error allocation");
	read_map(av[1], game->map);
	game->map_w = ft_strlen(game->map[0]);
	is_map_valid(game);
	print_map(game->map);
	init_game(game);
	render_all_map(game);
	mlx_key_hook(game->win, move_player, game);
	mlx_loop(game->mlx);

}
