/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:24 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 09:54:52 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_atoni(char *str, int n)
{
	long long	new_num;
	int			i;

	new_num = 0;
	i = 0;
	while (str[i] && (i < n))
	{
		if (!(('0' <= str[i]) && (str[i] <= '9')))
		{
			return (0ll);
		}
		new_num *= 10;
		new_num += str[i] - '0';
		i++;
	}
	return (new_num);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

long long	ft_strlen_by_ch(char *str, char ch)
{
	int	len;

	len = 0;
	while (str[len] && !(str[len] == ch))
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *str1, char *str2)
{
	unsigned long long	i;

	i = 0llu;
	while (str1[i])
	{
		i++;
	}
	while (*str2)
	{
		str1[i] = *str2;
		i++;
		str2++;
	}
	str1[i] = 0;
	return (str1);
}

char	*ft_strdupcat(char *str1, char *str2)
{
	unsigned long long	str1_len;
	unsigned long long	str2_len;
	char				*new_str;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (str1_len + str2_len + 1llu));
	if (new_str)
	{
		new_str[0] = 0;
		new_str = ft_strcat(new_str, str1);
		new_str = ft_strcat(new_str, str2);
	}
	return (new_str);
}
