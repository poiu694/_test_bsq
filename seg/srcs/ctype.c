int	ft_nbrlen(int n)
{
	int	len;

	if (n == 0)
	{
		return (1);
	}
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
