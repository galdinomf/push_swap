#include "push_swap.h"

int	ft_check_and_read_args(char *argv[], t_list **stackA)
{
	t_list	*aux;
	int	*n;

	if (ft_wrong_arg(argv[1]))
		return (1);
	n = (int *) malloc(sizeof(int));
	*n = atoi(argv[1]);
	if (*n % 10 != argv[1][ft_strlen(argv[1]) - 1] - '0')
		return (1);
	aux = ft_lstnew(n);
	if (aux == NULL)
		return (1);
	*stackA = aux;
	if (ft_read_arguments(argv, stackA))
		return (1);
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
	if (ft_check_and_read_args(argv, &stackA))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stackB = NULL;
	ft_push(&stackA, &stackB);
	ft_push(&stackA, &stackB);
	ft_push(&stackA, &stackB);
	printf("\n stackA :");
	ft_lstiter(stackA, &printf_node);
	printf("\n stackB :");
	ft_lstiter(stackB, &printf_node);
	printf("\n");
	//printf("%d\n", *((int *) stackA->content));
	return (0);
}
