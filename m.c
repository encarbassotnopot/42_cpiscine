#include "ex02/ft_ultimate_range.c"
#include <stdio.h>
int main(int argc, char** argv) {
	int** pt = malloc(sizeof(int *) * 19);
	if (pt == 0)
		return (0);
	int sz = ft_ultimate_range(pt, 0, 18);
	if (*pt == NULL)
		return (0);
	if (sz <= 0) 
		free (pt);
	else {
		for (int i = 0; i < sz; i++)
		{
		printf("%d\n", (*pt)[i]);
		}
		free (*pt);
		free (pt);
	}
}
