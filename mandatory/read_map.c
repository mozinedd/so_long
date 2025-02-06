/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozinedd <mozinedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:25:01 by mozinedd          #+#    #+#             */
/*   Updated: 2025/01/31 21:04:26 by mozinedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_lines(char *file_map)
{
	char	*line;
	int		n;
	int		fd;

	n = 0;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		n++;
	}
	close (fd);
	return (n);
} 

void	read_map(char *file_map, char **map)
{
	char *line;
	int n;
	int fd;

	n = 0;
	fd = open (file_map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		int size = ft_strlen(line);
		if (line[size - 1] == '\n')
			size--;
		char *tmp_line = ft_substr(line, 0, size);
		free(line);
		map[n] = tmp_line;
		line = get_next_line(fd);
		n++;
	}
	map[n] = NULL;
} 

void	print_map(char **map)
{
	int i;
	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}