#include "push_swap.h"

void	ft_sort_2(t_list **stacka)
{
	int	n1;
	int	n2;

	n1 = (*(int *)(*stacka)->content);
	n2 = (*(int *)(*stacka)->next->content);
	if (n1 > n2)
		ft_swap(stacka, 'A');
}
