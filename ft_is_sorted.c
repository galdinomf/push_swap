#include "push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*aux;
	t_list	*last_node;

	last_node = ft_lstlast(*stack);
	aux = *stack;
	while (aux != last_node)
	{
		if ((*(int *) aux->content) > (*(int *) aux->next->content))
			return (0);
		aux = aux->next;
	}
	return (1);
}
