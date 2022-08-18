#include "push_swap.h"

int	ft_check_and_read(int argc, char *argv[], int *argv2)
{
	int	i;
	int	j;
	//int	last_digit;

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
		//last_digit = argv2[i - 1] % 10;
		//if (argv2[i - 1] < 0)
		//	last_digit *= -1;
		//if (last_digit != argv[i][ft_strlen(argv[i]) - 1] - '0')
		if (ft_strcmp(ft_itoa(argv2[i-1]), argv[i]))
			return (1);
	}
	ft_bubble_sort(argv2, argc - 1);
	return (0);
}

int	ft_get_stackA(int argc, char *argv[], t_list **stackA)
{
	t_list	*aux;
	int	i;
	int	*argv2;
	int	*n;

	argv2 = (int *) malloc((argc - 1) * sizeof(int));
	if (ft_check_and_read(argc, argv, argv2))
		return (1);
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
			*stackA = aux;
		}
	}
	if (ft_read_arguments(argc, argv2, argv, stackA))
		return (1);
	free(argv2);
	return (0);
}

void	printf_node(void *content)
{
	printf(" %d", *((int *) content));
}

int	main(int argc, char *argv[])
{
	t_list	*stackA;
	t_list	*stackB;

	if (argc < 2)
		return (1);
	stackA = NULL;
	if (ft_get_stackA(argc, argv, &stackA))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stackB = NULL;
	//ft_push(&stackA, &stackB);
	//ft_push(&stackA, &stackB);
	//ft_push(&stackA, &stackB);
	//printf("\n stackA :");
	//ft_lstiter(stackA, printf_node);
	if (ft_lstsize(stackA) == 3)
	ft_sort_3A(&stackA);
	if (ft_lstsize(stackA) == 2)
	ft_sort_2A(&stackA);
	if (ft_lstsize(stackA) == 5)
	ft_sort_5A(&stackA, &stackB);
	//printf("\n stackA sorted:");
	//ft_lstiter(stackA, printf_node);
	//printf("\n stackB :");
	//ft_lstiter(stackB, printf_node);
	//printf("\n");
	if (ft_lstsize(stackA))
	ft_lstclear(&stackA, free);
	if (ft_lstsize(stackB))
	ft_lstclear(&stackB, free);
	//printf("%d\n", *((int *) stackA->content));
	return (0);
}
