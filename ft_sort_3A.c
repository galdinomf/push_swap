#include "push_swap.h"

void	ft_sort_3A(t_list **stackA)
{
	int	n1;
	int	n2;
	int	n3;
	
	n1 = *((int *) (*stackA)->content);
	n2 = *((int *) (*stackA)->next->content);
	n3 = *((int *) (*stackA)->next->next->content);
	
	if ((n1 < n2) && (n2 < n3))
		return ;
	if (n1 < n2)
	{
		if (n1 < n3)
			ft_swap(stackA, 'A');
		else
			ft_reverse_rotate(stackA, 'A');
	}
	else
	{
		if ((n2 < n3) && (n1 > n3))
			ft_rotate(stackA, 'A');
		else
			ft_swap(stackA, 'A');
	}
	ft_sort_3A(stackA);	
}
