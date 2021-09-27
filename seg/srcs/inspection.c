#include "bsq.h"

int	is_printable(char ch);

int	ft_check_column(t_map *_map)
{
	int	i;
	int	j;
	int len;

	i = 0;
	len = -1;
	while (i < _map->num_rows)
	{
		j = 0;
		while (_map->map[i][j] != '\0')
		{
			if (_map->map[i][j] != _map->empty_ch
				&& _map->map[i][j] != _map->obstacle_ch)
				return (-1);
			if (_map->map[i][j] == _map->full_ch)
				return (-1);
			j++;
		}
		if (len != -1 && len != j)
			return (-1);
		len = j;
		i++;
	}
	return (1);
}

int	ft_check_arg(t_map *map)
{
	if (!is_printable(map->full_ch))
		return (-1);
	if (!is_printable(map->obstacle_ch))
		return (-1);
	if (!is_printable(map->empty_ch))
		return (-1);
	if (map->full_ch == map->obstacle_ch)
		return (-1);
	if (map->full_ch == map->empty_ch)
		return (-1);
	if (map->obstacle_ch == map->empty_ch)
		return (-1);
	return (1);
}

//	TODO:	유효한 지도인지 검사하는 함수로 유효하지 않은 지도는 아래와 같음
//
//			1. columns의 길이가 전부 동일하지 않는 경우
//			2. rows의 길이가 1인 경우(XXX:명확하지 않음, 원본 참고 바람)
//			3. rows의 맨 끝에 \n(newline)이 없는 경우
//			4. 지도를 표현한 캐릭터중 첫번째 줄에서 입력 받은 캐릭터가 아닌 경우
//			5. 첫번째 줄에서 입력 받은 캐릭터가 유효하지 않거나 중복되는 경우
//			6. 첫번째 줄에 입력되는 캐릭터가 출력 불가능 캐릭터인 경우
//
//			위와 같이 유효하지 않는 지도의 경우 maps를 0의 주소를 가르키게 변경
//	XXX	:	나중에 한번에 에러처리를 하게 될거임
void	ft_inspect_parsing_maps(t_map **maps, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (ft_check_arg(maps[i]) == -1)
			maps[i] = 0;
		else if (ft_check_column(maps[i]) == -1)
			maps[i] = 0;
		i++;
	}
}
