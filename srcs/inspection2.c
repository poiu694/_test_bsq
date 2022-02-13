/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:05 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:54:08 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

int	ft_is_printable(char ch);

int	ft_is_map_valid3(t_map *map)
{
	unsigned long long	i;

	i = 0ull;
	while (map->raw_map[i])
	{
		i++;
	}
	return (map->raw_map[i - 1] == '\n');
}

int	ft_is_map_valid4(t_map *map)
{
	unsigned long long	i;

	i = 0ull;
	while (map->raw_map[i])
	{
		if (!((map->raw_map[i] == map->empty_ch)
				|| (map->raw_map[i] == map->obstacle_ch)
				|| (map->raw_map[i] == '\n')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_map_valid5(t_map *map)
{
	return (!((map->empty_ch == map->obstacle_ch)
			|| (map->empty_ch == map->full_ch)
			|| (map->obstacle_ch == map->full_ch)));
}

int	ft_is_map_valid6(t_map *map)
{
	return (ft_is_printable(map->empty_ch)
		&& ft_is_printable(map->obstacle_ch)
		&& ft_is_printable(map->full_ch));
}
