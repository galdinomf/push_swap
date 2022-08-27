#include "push_swap.h"

t_list	*ft_find_first_radix(t_list **stack, int i)
{
	t_list	*aux;

	aux = *stack;
	while ((aux) && ((*(int *) aux->content >> i) & 1))
		aux = aux->next;
	return (aux);
}

t_list	*ft_find_first_nb(t_list **stack, int i)
{
	t_list	*aux;

	aux = *stack;
	while ((aux) && !((*(int *) aux->content >> i) & 1))
		aux = aux->next;
	return (aux);
}

int	ft_send_to_b(t_list **stacka, t_list **stackb, int i)
{
	t_list	*first;

	first = ft_find_first_radix(stacka, i);
	if (first)
	{
		ft_put_node_on_top(first, stacka, 'A');
		ft_push(stacka, stackb, 'B');
		return (1);
	}
	else
		return (0);
}

int	ft_send_to_a(t_list **stacka, t_list **stackb, int i)
{
	t_list	*first;

	first = ft_find_first_nb(stackb, i + 1);
	if (first)
	{
		ft_put_node_on_top(first, stackb, 'B');
		ft_push(stackb, stacka, 'A');
		return (1);
	}
	else
		return (0);
}

void	ft_sort_big(t_list **stacka, t_list **stackb)
{
	int	i;
	t_list	*first_nb;
	int	size;

	size = ft_lstsize(*stacka);
	i = 0;
	while ((size - 1) / ft_pow(2, i))
	{
		first_nb = ft_find_first_nb(stacka, i);
		while (ft_send_to_b(stacka, stackb, i))
			;
		ft_put_node_on_top(first_nb, stacka, 'A');
		first_nb = ft_find_first_radix(stackb, i + 1);
		while (ft_send_to_a(stacka, stackb, i))
			;
		ft_put_node_on_top(first_nb, stackb, 'B');
		first_nb = ft_find_first_nb(stacka, i);
		i++;
	}
	while (ft_lstsize(*stackb))
		ft_push(stackb, stacka, 'A');
}
