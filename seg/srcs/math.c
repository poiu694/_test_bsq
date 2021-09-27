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
