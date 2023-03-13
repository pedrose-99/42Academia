#include <stdlib.h>

int	ft_absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	*ft_rrange(int start, int end)
{
	int	idx;
	int	size;
	int	*tab;

	idx = 0;
	if (start > end)
		return (ft_rrange(end, start));
	size = ft_absolute_value(start - end);
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	while (idx < start)
	{
		tab[idx] = start;
		start++;
		idx++;
	}
	return (tab);
}

#include <stdio.h>
int	main(void)
{
	int	*tab;
	int	idx;
	int	start;
	int	end;
	int	size;
	idx = 0;
	start = -5;
	end = 5;
	tab = ft_rrange(start, end);
	size = (end - start) + 1;
	if (size < 0)
		size = size*-1;
	while (idx < size)
	{
		printf(" [%i] ", tab[idx]);
		idx++;
	}
	printf("\n");
}