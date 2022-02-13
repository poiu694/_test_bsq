/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:09 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:54:05 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		bsq(int argc, char **argv, t_map ***maps);
void	ft_free_maps(t_map **maps, int size);

int	main(int argc, char *argv[])
{
	t_map	**maps;
	int		size;

	maps = 0;
	size = bsq(argc, argv, &maps);
	ft_free_maps(maps, size);
	return (0);
}
