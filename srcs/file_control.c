/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:32:01 by sangmlee          #+#    #+#             */
/*   Updated: 2021/09/30 11:10:28 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

char	*ft_strdupcat(char *str1, char *str2);

int	ft_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	return (fd);
}

int	ft_readline(int fd, char *buf)
{
	char	ch;
	int		len;

	len = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			buf[len] = 0;
			return (len + 1);
		}
		buf[len] = ch;
		len++;
	}
	buf[len] = 0;
	return (len);
}

void	ft_init_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < (BUFSIZE + 1))
	{
		buf[i] = 0;
		i++;
	}
}

char	*ft_read(int fd)
{
	char	buf[BUFSIZE + 1];
	char	*new_str;
	char	*tmp;

	new_str = (char *)malloc(sizeof(char) * 1);
	if (new_str)
	{
		new_str[0] = 0;
		ft_init_buf(buf);
		while (read(fd, buf, BUFSIZE) > 0)
		{
			tmp = ft_strdupcat(new_str, buf);
			free(new_str);
			if (tmp == 0)
			{
				return (0);
			}
			new_str = tmp;
			ft_init_buf(buf);
		}
	}
	return (new_str);
}
