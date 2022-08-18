#include "push_swap.h"

int	ft_wrong_arg(char *a)
{
	int	i;
	int	result;

	result = 0;
	i = -1;
	if ((a[0] != '-') || (a[0] != '+'))
		i++;
	while (a[++i])
	{
		if (!ft_isdigit(a[i]))
			result = 1;
	}
	return (result);
}
