/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:17 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:54:34 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int n1, int n2, int n3)
{
	int	min;

	min = n1;
	if (min > n2)
	{
		min = n2;
	}
	if (min > n3)
	{
		min = n3;
	}
	return (min);
}