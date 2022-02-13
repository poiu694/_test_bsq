/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:31:48 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 11:30:24 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

long long	**ft_generate_blank_map(long long num_rows, long long num_cols);
int			ft_min(int n1, int n2, int n3);
void		ft_set_max_points_idx(long long row, long long col,
				long long *max_row, long long *max_col);

void	ft_calc_distance_map(t_map **map)
{
	long long	row;
	long long	col;

	row = 0ll;
	while (row < (*map)->num_rows)
	{
		col = 0ll;
		while (col < (*map)->num_cols)
		{
			(*map)->distance_map[row][col] = 0ll;
			if ((row == 0) || (col == 0))
			{
				(*map)->distance_map[row][col] = (*map)->parsing_map[row][col];
			}
			else if ((*map)->parsing_map[row][col])
			{
				(*map)->distance_map[row][col]
					= ft_min((*map)->distance_map[row][col - 1ll],
						(*map)->distance_map[row - 1ll][col],
						(*map)->distance_map[row - 1ll][col - 1ll]) + 1ll;
			}
			col++;
		}
		row++;
	}
}

void	ft_generate_distance_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps[i] && maps[i]->parsing_map)
		{
			maps[i]->distance_map
				= ft_generate_blank_map(maps[i]->num_rows, maps[i]->num_cols);
			if (maps[i]->distance_map)
			{
				ft_calc_distance_map(&maps[i]);
			}
		}
		i++;
	}
}

void	ft_set_begin_and_end_point(t_map **map,
	long long max_num,
	long long max_row_idx,
	long long max_col_idx)
{
	(*map)->begin_point = (t_point *)malloc(sizeof(t_point));
	(*map)->end_point = (t_point *)malloc(sizeof(t_point));
	(*map)->begin_point->x = max_col_idx - max_num + 1;
	(*map)->begin_point->y = max_row_idx - max_num + 1;
	(*map)->end_point->x = max_col_idx;
	(*map)->end_point->y = max_row_idx;
}

void	ft_find_max_in_distance_map(t_map **map)
{
	long long	max_num;
	long long	max_row_idx;
	long long	max_col_idx;
	long long	row;
	long long	col;

	max_num = (*map)->distance_map[0][0];
	max_row_idx = 0ll;
	max_col_idx = 0ll;
	row = 0ll;
	while (row < (*map)->num_rows)
	{
		col = 0ll;
		while (col < (*map)->num_cols)
		{
			if (max_num < (*map)->distance_map[row][col])
			{
				max_num = (*map)->distance_map[row][col];
				ft_set_max_points_idx(row, col, &max_row_idx, &max_col_idx);
			}
			col++;
		}
		row++;
	}
	ft_set_begin_and_end_point(map, max_num, max_row_idx, max_col_idx);
}

void	ft_find_each_max_in_distance_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps[i] && maps[i]->distance_map)
		{
			ft_find_max_in_distance_map(&maps[i]);
		}
		i++;
	}
}
