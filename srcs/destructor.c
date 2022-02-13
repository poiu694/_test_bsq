/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:31:36 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:52:58 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
}

void	ft_free_map(t_map *map)
{
	int	i;

	ft_free(map->raw_map);
	i = 0;
	while (i < map->num_rows)
	{
		if (map->parsing_map)
		{
			ft_free(map->parsing_map[i]);
		}
		if (map->distance_map)
		{
			ft_free(map->distance_map[i]);
		}
		i++;
	}
	ft_free(map->parsing_map);
	ft_free(map->distance_map);
	ft_free(map->begin_point);
	ft_free(map->end_point);
	ft_free(map);
}

void	ft_free_maps(t_map **maps, int size)
{
	int	i;

	if (maps)
	{
		i = 0;
		while (i < size)
		{
			if (maps[i])
			{
				ft_free_map(maps[i]);
			}
			i++;
		}
		ft_free(maps);
	}
}
