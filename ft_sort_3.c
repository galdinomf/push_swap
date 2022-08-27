#include "push_swap.h"

void	ft_sort_3(t_list **stacka)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = *((int *)(*stacka)->content);
	n2 = *((int *)(*stacka)->next->content);
	n3 = *((int *)(*stacka)->next->next->content);
	if ((n1 < n2) && (n2 < n3))
		return ;
	if (n1 < n2)
	{
		if (n1 < n3)
			ft_swap(stacka, 'A');
		else
			ft_reverse_rotate(stacka, 'A');
	}
	else
	{
		if ((n2 < n3) && (n1 > n3))
			ft_rotate(stacka, 'A');
		else
			ft_swap(stacka, 'A');
	}
	ft_sort_3(stacka);
}
