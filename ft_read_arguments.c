#include "push_swap.h"

int	ft_is_duplicate(int *n, t_list **stackA)
{
	t_list	*aux;

	aux = *stackA;
	while (aux->next)
	{
		if (*n == *((int *) aux->content))
			return (1);
		aux = aux->next;
	}
	if (*n == *((int *) aux->content))
		return (1);
	return (0);
}

int	ft_read_arguments(int argc, int *argv2, char *argv[], t_list **stackA)
{
	int	i;
	int	j;
	int	*n;
	t_list	*aux;

	i = 1;
	while (argv[++i])
	{
		j = -1;
		while (++j < argc - 1)
		{
			if (ft_atoi(argv[i]) == argv2[j])
			{
				n = (int *) malloc(sizeof(int));
				*n = j;
				aux = ft_lstnew(n);
				if (aux == NULL)
					return (1);
				ft_lstadd_back(stackA, aux);
			}
		}
	}
	free(argv2);
	return (0);
}
