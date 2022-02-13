/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:31:22 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:52:43 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "bsq.h"

int		ft_generate_maps(int argc, char **argv, t_map ***maps);
void	ft_inspect_maps(t_map **maps, int size);
void	ft_generate_parsing_maps(t_map **maps, int size);
void	ft_generate_distance_maps(t_map **maps, int size);
void	ft_find_each_max_in_distance_maps(t_map **maps, int size);
void	ft_write_error(void);

void	ft_write_character(t_map *map, long long y, long long x)
{
	int	is_coverage;

	is_coverage = ((map->begin_point->x <= x) && (x <= map->end_point->x))
		&& ((map->begin_point->y <= y) && (y <= map->end_point->y));
	if (is_coverage)
	{
		write(1, &map->full_ch, 1);
	}
	else if (map->parsing_map[y][x] == 0)
	{
		write(1, &map->obstacle_ch, 1);
	}
	else
	{
		write(1, &map->empty_ch, 1);
	}
}

void	ft_draw_grid_map(t_map *map)
{
	long long	x;
	long long	y;

	y = 0;
	while (y < map->num_rows)
	{
		x = 0;
		while (x < map->num_cols)
		{
			ft_write_character(map, y, x);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_draw_grid_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps && maps[i] && maps[i]->begin_point && maps[i]->end_point)
		{
			ft_draw_grid_map(maps[i]);
		}
		else
		{
			ft_write_error();
		}
		i++;
	}
}

int	bsq(int argc, char **argv, t_map ***maps)
{
	int	size;

	size = ft_generate_maps(argc, argv, maps);
	ft_inspect_maps(*maps, size);
	ft_generate_parsing_maps(*maps, size);
	ft_generate_distance_maps(*maps, size);
	ft_find_each_max_in_distance_maps(*maps, size);
	ft_draw_grid_maps(*maps, size);
	return (size);
}
