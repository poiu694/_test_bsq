int		ft_atoi_n(char *str, int size)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i < size)
	{
		if (str[i] == '\0')
			break ;
		if ('0' <= str[i] && str[i] <= '9')
		{
			n *= 10;
			n += str[i] - '0';
		}
		else
			return (-1);
		i++;
	}
	return (n);
}

int	is_printable(char ch)
{
	if (' ' <= ch && ch != 127)
		return (1);
	return (0);
}