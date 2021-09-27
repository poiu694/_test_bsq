#ifndef BSQ_H
# define BSQ_H

# define BUFSIZE 1024
# define MIN_INPUT_NUM 4
# define MAX_INPUT_NUM 20

typedef struct s_point	t_point;

struct s_point
{
	int	x;
	int	y;
};

typedef struct s_map	t_map;

struct s_map
{
	int		num_rows;
	int		num_cols;
	char	empty_ch;
	char	obstacle_ch;
	char	full_ch;
	char	**map;
	int		**distance_map;
	t_point	begin_point;
	t_point	end_point;
};

#endif
