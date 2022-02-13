/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:13 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:54:15 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

int			ft_open(char *path);
int			ft_readline(int fd, char *buf);
long long	ft_atoni(char *str, int n);
char		*ft_read(int fd);
long long	ft_strlen_by_ch(char *str, char ch);

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

t_map	*ft_generate_map(int fd)
{
	t_map	*new_map;
	char	buf[BUFSIZE];
	int		len;

	len = ft_readline(fd, buf);
	if (!((MIN_INPUT_NUM <= len) && (len <= MAX_INPUT_NUM)))
	{
		return (0);
	}
	new_map = (t_map *)malloc(sizeof(t_map));
	if (new_map)
	{
		new_map->num_rows = ft_atoni(buf, len - 4);
		new_map->num_cols = 0ll;
		new_map->empty_ch = buf[len - 4];
		new_map->obstacle_ch = buf[len - 3];
		new_map->full_ch = buf[len - 2];
		new_map->raw_map = ft_read(fd);
		new_map->parsing_map = 0;
		new_map->distance_map = 0;
		new_map->begin_point = 0;
		new_map->end_point = 0;
		new_map->num_cols = ft_strlen_by_ch(new_map->raw_map, '\n');
	}
	return (new_map);
}

int	ft_generate_maps(int argc, char **argv, t_map ***maps)
{
	int		size;
	t_mode	mode;
	int		i;
	int		fd;

	size = ft_set_mode(&mode, argc);
	*maps = (t_map **)malloc(sizeof(t_map *) * size);
	if (mode == INTERACTIVE_MODE)
		(*maps)[0] = ft_generate_map(0);
	else if (mode == FILE_READ_MODE)
	{
		i = 0;
		while (i < size)
		{
			(*maps)[i] = 0;
			fd = ft_open(argv[i + 1]);
			if (fd)
			{
				(*maps)[i] = ft_generate_map(fd);
				close(fd);
			}
			i++;
		}
	}
	return (size);
}

long long	**ft_generate_blank_map(long long num_rows, long long num_cols)
{
	long long	**new_blank_map;
	long long	row;

	new_blank_map
		= (long long **)malloc(sizeof(long long *) * num_rows);
	if (new_blank_map == 0)
	{
		return (0);
	}
	row = 0ll;
	while (row < num_rows)
	{
		new_blank_map[row]
			= (long long *)malloc(sizeof(long long) * num_cols);
		if (new_blank_map[row] == 0)
		{
			return (0);
		}
		row++;
	}
	return (new_blank_map);
}
