#include <stdlib.h>

#include "bsq.h"

int ft_min(int n1, int n2, int n3);

/**
 * malloc distance map
 * 동적 할당으로 distance map을 만들고 초기화
 * 비어있으면 1로 초기화
 * 나머지는 0으로 초기화
 */
void ft_create_distance_map(t_map **_map)
{
	int	i;
	int	j;

	(*_map)->distance_map = (int **)malloc(((*_map)->num_rows + 1) * sizeof(int *));
	i = 0;
	while (i < (*_map)->num_rows)
	{
		(*_map)->distance_map[i] = (int *)malloc(((*_map)->num_rows + 1) * sizeof(int));
		j = 0;
		while (j < (*_map)->num_rows)
		{
			if ((*_map)->map[i][j] == (*_map)->empty_ch && (i == 0 || j == 0))
				(*_map)->map[i][j] = 1;
			else
				(*_map)->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

/**
 * distance 를 계산해주는 함수 
 */
void	ft_set_distance_map(t_map **map)
{
	int	i;
	int	j;

	i = 1;
	while (i < (*map)->num_rows)
	{
		j = 1;
		while (j < (*map)->num_rows)
		{
			if ((*map)->map[i][j] == (*map)->empty_ch)
				(*map)->distance_map[i][j] = ft_min(
					(*map)->distance_map[i - 1][j],
					(*map)->distance_map[i - 1][j - 1],
					(*map)->distance_map[i][j - 1]) + 1;
			else
				(*map)->distance_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

//	TODO:	maps의 distance_map을 만들어주는 함수를 구현 하면 됨
//	XXX	:	마지막 배열은 0의 주소를 가지게 해야함
void	ft_generate_distance_maps(t_map **maps, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		ft_create_distance_map(&maps[i]);
		ft_set_distance_map(&maps[i]);
		i++;
	}
	maps[i] = 0;
}

/**
 *	begin_point와 end_point설정 
 */
void	ft_set_points_in_distance_map(t_map **map)
{
	int		x;
	int		y;
	int		max_len;
	t_point	e_point;

	x = 0;
	while (x < (*map)->num_rows)
	{
		y = 0;
		while (y < (*map)->num_rows)
		{
			if (max_len < (*map)->distance_map[x][y])
			{
				e_point = (t_point){x, y};
				max_len = (*map)->distance_map[x][y];
			}
			y++;
		}
		x++;
	}
	(*map)->end_point = e_point;
	(*map)->begin_point = (t_point){e_point.x - max_len + 1, e_point.y - max_len + 1};
}

//	TODO:	각 maps의 최대값을 찾은 후 maps의
//			begin_point와 end_point에 만들어 주는 함수를 구현 하면 됨
//			이때 begin_point는 좌측 상단 좌표를
//			end_point는 우측 하단 좌표를 넣어주면 됨
void	ft_find_each_max_in_distance_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_set_points_in_distance_map(&maps[i]);
		i++;
	}
}
