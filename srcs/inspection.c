/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:05 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 11:28:11 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

int	ft_is_printable(char ch);
int	ft_is_map_valid3(t_map *map);
int	ft_is_map_valid4(t_map *map);
int	ft_is_map_valid5(t_map *map);
int	ft_is_map_valid6(t_map *map);

int	ft_is_map_valid1(t_map *map)
{
	long long			num_rows;
	long long			num_cols;
	long long			cur_num_cols;
	unsigned long long	i;

	num_rows = 0ll;
	num_cols = 0ll;
	cur_num_cols = 0ll;
	i = 0ull;
	while (map->raw_map[i])
	{
		if (map->raw_map[i] == '\n')
		{
			if (num_rows == 0ll)
				num_cols = cur_num_cols;
			else if (!(num_cols == cur_num_cols))
				return (0);
			cur_num_cols = -1ll;
			num_rows++;
		}
		cur_num_cols++;
		i++;
	}
	return (!((num_rows == 0) || (num_cols == 0))
		&& ((map->num_rows == num_rows)));
}

int	ft_is_map_valid2(t_map *map)
{
	unsigned long long	i;

	i = 0;
	while (map->raw_map[i])
	{
		if (map->raw_map[i] == map->empty_ch
			|| map->raw_map[i] == map->obstacle_ch)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_inspect_maps(t_map **maps, int size)
{
	int	is_map_valid;
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps[i] && maps[i]->raw_map)
		{
			is_map_valid = 1;
			is_map_valid &= ft_is_map_valid1(maps[i]);
			is_map_valid &= ft_is_map_valid2(maps[i]);
			is_map_valid &= ft_is_map_valid3(maps[i]);
			is_map_valid &= ft_is_map_valid4(maps[i]);
			is_map_valid &= ft_is_map_valid5(maps[i]);
			is_map_valid &= ft_is_map_valid6(maps[i]);
			if (is_map_valid == 0)
			{
				free(maps[i]->raw_map);
				maps[i]->raw_map = 0;
			}
		}
		i++;
	}
}
