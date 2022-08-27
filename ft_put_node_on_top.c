#include "push_swap.h"

void	ft_put_node_on_top(t_list *node, t_list **stack, char c)
{
	t_list	*aux;
	int	i;

	i = 0;
	aux = *stack;
	while (aux != node)
	{
		i++;
		aux = aux->next;
	}
	if (i < ft_lstsize(*stack) / 2)
	{
		while (*stack != node)
			ft_rotate(stack, c);
	}
	else
	{
		while (*stack != node)
			ft_reverse_rotate(stack, c);
	}
}
