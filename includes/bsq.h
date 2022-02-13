/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:52:23 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:52:29 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFSIZE 1024
# define MIN_INPUT_NUM 4
# define MAX_INPUT_NUM 100000

typedef struct s_point	t_point;

struct s_point
{
	long long	x;
	long long	y;
};

typedef struct s_map	t_map;

struct s_map
{
	long long	num_rows;
	long long	num_cols;
	char		empty_ch;
	char		obstacle_ch;
	char		full_ch;
	char		*raw_map;
	long long	**parsing_map;
	long long	**distance_map;
	t_point		*begin_point;
	t_point		*end_point;
};

#endif
