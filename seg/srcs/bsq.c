#include <unistd.h>

#include "bsq.h"

int		ft_generate_parsing_maps(int argc, char **argv, t_map ***maps);
void	ft_inspect_parsing_maps(t_map **maps, int size);
void	ft_generate_distance_maps(t_map **maps, int size);
void	ft_find_each_max_in_distance_maps(t_map *maps, int size);
void	ft_write_error(void);

void	ft_draw_grid_map(t_map *_map)
{
	int		x;
	int		y;
	t_point	b_point;
	t_point	e_point;

	b_point = _map->begin_point;
	e_point = _map->end_point;
	x = 0;
	while (x < _map->num_rows)
	{
		y = 0;
		while (y < _map->num_rows)
		{
			if ((b_point.x <= x && x <= e_point.x)
				&& (b_point.y <= y && y <= e_point.y))
				write(1, &_map->full_ch, 1);
			else if (_map->map[x][y] == _map->obstacle_ch)
				write(1, &_map->obstacle_ch, 1);
			else
				write(1, &_map->empty_ch, 1);
			y++;
		}
		x++;
		write(1, "\n", 1);
	}
}

//	TODO:	maps를 그려주는데 maps의 begin_point와 end_point를
//			참고하여 그려주어야 함
//	XXX	:	만약 maps가 비어있는 경우 ft_write_error 함수를
//			호출하고 다음 맵으로 넘어가면 됨
void	ft_draw_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps[i] == 0)
			ft_write_error();
		else
			ft_draw_grid_map(maps[i]);
		i++;
	}
}

int	bsq(int argc, char **argv, t_map ***maps)
{
	int	size;

	size = ft_generate_parsing_maps(argc, argv, maps);
	ft_inspect_parsing_maps(*maps, size);
	ft_generate_distance_maps(*maps, size);
//	ft_find_each_max_in_distance_maps(*maps, size);
	ft_draw_maps(*maps, size);
	return (size);
}
