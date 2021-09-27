#include <unistd.h>

void	ft_write_error(void)
{
	write(2, "map error\n", 10);
}
