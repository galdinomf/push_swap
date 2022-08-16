#include "push_swap.h"

void	ft_bubble_sort(int *arr, int size_arr)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < size_arr - 1)
	{
		j = -1;
		while (++j < size_arr - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}
