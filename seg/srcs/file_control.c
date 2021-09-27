#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "bsq.h"

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
	while (read(fd, &ch, 1))
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

void	ft_close(int fd)
{
	close(fd);
}

//	TODO:	파일 끝까지 읽어 들인후 반환하는 함수를 구현하면 됨
char	**ft_read(int fd, int size)
{
	int		i;
	int		j;
	int		len;
	char	buf[BUFSIZE];
	char	**map;

	map = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		len = ft_readline(fd, buf);
		map[i] = (char *)malloc((len + 1) * sizeof(char));
		j = 0;
		while (buf[j] != '\0')
		{
			if (buf[j] == '\n')
				break ;
			map[i][j] = buf[j];
			j++;
		}
		i++;
	}
	return (map);
}
