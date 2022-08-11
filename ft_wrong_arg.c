#include "push_swap.h"

int	ft_wrong_arg(char *arg)
{
	int	i;
	int	result;

	result = 0;
	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			result = 1;
	}
	return (result);
}
