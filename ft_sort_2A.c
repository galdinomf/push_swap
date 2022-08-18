#include "push_swap.h"

void	ft_sort_2A(t_list **stackA)
{
	int	n1;
	int	n2;

	n1 = (*(int *) (*stackA)->content);
	n2 = (*(int *) (*stackA)->next->content);
	if (n1 > n2)
		ft_swap(stackA, 'A');
}
