#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'



# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2



# define BOX_SIZE 50
# define ESC 53



typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		p_x;
	int		p_y;
	int		map_h;
	int		map_w;
	char	**map;
	int		c;
	int		e;
	int		p;
	int		move;
	

	void	*wall;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*bg;
}	t_game;

void	handle_error(char *msg);
void	allocate_game(t_game **game);
void	print_map(char **map);
int		get_map_lines(char *file_map);
void	read_map(char *file_map, char **map);
void	is_map_valid(t_game *g);
void	init_game(t_game *game);
int		is_path_correct(t_game *game);
int		init_image(t_game *game);
void	free_map(char **map, int size);
void 	render(t_game *g, int x, int y);
int 	render_all_map(t_game *game);
int		find_player(char **map, int *x, int *y);
int	move_player(int keycode, t_game *game);


#endif