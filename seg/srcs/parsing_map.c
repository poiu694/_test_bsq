#include <stdlib.h>
#include <fcntl.h>

#include "bsq.h"

int		ft_open(char *path);
int		ft_readline(int fd, char *buf);
void	ft_close(int fd);
int		ft_atoi_n(char *str, int size);
int		ft_nbrlen(int n);
char	**ft_read(int fd, int row);
typedef enum e_mode	t_mode;

enum e_mode
{
	INTERACTIVE_MODE = 1,
	FILE_READ_MODE
};

int	ft_set_mode(t_mode *mode, int argc)
{
	if (argc == 1)
	{
		*mode = INTERACTIVE_MODE;
		return (1);
	}
	*mode = FILE_READ_MODE;
	return (argc - 1);
}

t_map	*ft_generate_parsing_map(int fd)
{
	t_map	*new_map;
	char	buf[BUFSIZE];
	int		len;
	int		nbr_len;

	new_map = 0;
	len = ft_readline(fd, buf);
	if ((MIN_INPUT_NUM <= len) && (len <= MAX_INPUT_NUM))
	{
		return (new_map);
	}
	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->num_rows = ft_atoi_n(buf, len - 3);
	nbr_len = ft_nbrlen(new_map->num_rows);
	new_map->empty_ch = buf[len - 1];
	new_map->obstacle_ch = buf[len - 2];
	new_map->full_ch = buf[len - 3];
	new_map->map = ft_read(fd, new_map->num_rows);
	new_map->distance_map = 0;
	new_map->begin_point = (t_point){0, 0};
	new_map->end_point = (t_point){0, 0};
	return (new_map);
}

int	ft_generate_parsing_maps(int argc, char **argv, t_map ***maps)
{
	int		size;
	t_mode	mode;
	int		i;
	int		fd;

	size = ft_set_mode(&mode, argc);
	*maps = (t_map **)malloc(sizeof(t_map *) * size);
	if (mode == INTERACTIVE_MODE)
	{
		(*maps)[0] = ft_generate_parsing_map(0);
	}
	else if (mode == FILE_READ_MODE)
	{
		i = 0;
		while (i < size)
		{
			(*maps)[i] = 0;
			fd = ft_open(argv[i + 1]);
			if (fd)
			{
				(*maps)[i] = ft_generate_parsing_map(fd);
				ft_close(fd);
			}
			i++;
		}
	}
	return (size);
}

void	ft_free_maps(t_map **maps, int size)
{
	int	i;
	int	**cur_distance_map;

	i = 0;
	while (i < size)
	{
		free(maps[i]->map);
		cur_distance_map = maps[i]->distance_map;
		while (cur_distance_map && *cur_distance_map)
		{
			free(cur_distance_map);
			cur_distance_map++;
		}
		free(maps[i]->distance_map);
		free(maps[i]);
		i++;
	}
	free(maps);
}
