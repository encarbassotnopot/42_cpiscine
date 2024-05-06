#include <stdlib.h>

#include <stdio.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	index;
	int *ptr;

	size = max - min;
	if (size < 0)
	{
		range = 0;
		return (0);
	}
	
	ptr = malloc(size);
	if (ptr == 0)
		return (-1);
	*range = ptr;
	index = 0;
	while (index < size)
	{
		*(*range + index) = min + index;
		printf("%d\n", *(*range + index));
		index++;
	}
	return (size);
}
