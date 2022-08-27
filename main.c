#include "push_swap.h"

int	ft_check_and_read(char *argv[], int *argv2)
{
	int	i;
	int	j;
	char	*s;

	i = 0;
	while (argv[++i])
	{
		if ((ft_wrong_arg(argv[i])) || (argv2 == NULL))
			return (1);
		argv2[i - 1] = ft_atoi(argv[i]);
		j = -1;
		while (++j < (i - 1))
		{
			if (argv2[j] == argv2[i - 1])
				return (1);
		}
		s = ft_itoa(argv2[i - 1]);
		if (ft_strcmp(s, argv[i]))
		{
			free(s);
			return (1);
		}
		free(s);
	}
	return (0);
}

int	ft_get_stacka(int argc, char *argv[], t_list **stacka)
{
	t_list	*aux;
	int	i;
	int	*argv2;
	int	*n;

	argv2 = (int *) malloc((argc - 1) * sizeof(int));
	if (ft_check_and_read(argv, argv2))
		return (1);
	ft_bubble_sort(argv2, argc - 1);
	i = -1;
	while (++i < argc - 1)
	{
		if (argv2[i] == ft_atoi(argv[1]))
		{
			n = (int *) malloc(sizeof(int));
			*n = i;
			aux = ft_lstnew(n);
			if (aux == NULL)
				return (1);
			*stacka = aux;
		}
	}
	if (ft_read_arguments(argc, argv2, argv, stacka))
		return (1);
	return (0);
}

void	ft_sort_and_clear(t_list **stacka, t_list **stackb)
{
	if (ft_lstsize(*stacka) == 3)
		ft_sort_3(stacka);
	if (ft_lstsize(*stacka) == 2)
		ft_sort_2(stacka);
	if ((ft_lstsize(*stacka) == 5) || (ft_lstsize(*stacka) == 4))
		ft_sort_5(stacka, stackb);
	if (ft_lstsize(*stacka) > 5)
		ft_sort_big(stacka, stackb);
	if (ft_lstsize(*stacka))
		ft_lstclear(stacka, free);
}

int	main(int argc, char *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	if (argc < 2)
		return (1);
	stacka = NULL;
	if (ft_get_stacka(argc, argv, &stacka))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stackb = NULL;
	if (ft_is_sorted(&stacka))
		return (0);
	ft_sort_and_clear(&stacka, &stackb);
	return (0);
}
