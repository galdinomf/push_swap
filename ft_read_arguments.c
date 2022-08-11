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

int	ft_read_arguments(char *argv[], t_list **stackA)
{
	int	i;
	int	*n;
	t_list	*aux;

	i = 1;
	while (argv[++i])
	{
		if (ft_wrong_arg(argv[i]))
			return (1);
		n = (int *) malloc(sizeof(int));
		*n = atoi(argv[i]);
		if (*n % 10 != argv[i][ft_strlen(argv[i]) - 1] - '0')
			return (1);
		aux = ft_lstnew(n);
		if (aux == NULL)
			return (1);
		if (ft_is_duplicate(n, stackA))
			return (1);
		ft_lstadd_back(stackA, aux);
	}
	return (0);
}

