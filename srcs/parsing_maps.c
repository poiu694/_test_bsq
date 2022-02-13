/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:21 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 11:29:40 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

long long	**ft_generate_blank_map(long long num_rows, long long num_cols);

void	ft_parse_map(t_map **map)
{
	long long			row;
	long long			col;
	unsigned long long	matrix_idx;
	unsigned long long	cur_idx;

	row = 0ll;
	while (row < (*map)->num_rows)
	{
		col = 0ll;
		while (col < (*map)->num_cols)
		{
			(*map)->parsing_map[row][col] = 0ll;
			matrix_idx = row * (*map)->num_rows + col;
			cur_idx = matrix_idx + (matrix_idx / (*map)->num_cols);
			if ((*map)->raw_map[cur_idx] == (*map)->empty_ch)
			{
				(*map)->parsing_map[row][col] = 1ll;
			}
			col++;
		}
		row++;
	}
}

void	ft_generate_parsing_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps[i] && maps[i]->raw_map)
		{
			maps[i]->parsing_map
				= ft_generate_blank_map(maps[i]->num_rows, maps[i]->num_cols);
			if (maps[i]->parsing_map)
			{
				ft_parse_map(&maps[i]);
			}
		}
		i++;
	}
}
