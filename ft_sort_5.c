#include "push_swap.h"

t_list	*ft_find_first(t_list **stacka)
{
	t_list	*aux;
	int	n;
	t_list	*first;

	first = *stacka;
	aux = *stacka;
	n = *((int *) aux->content);
	while (aux)
	{
		if (*((int *) aux->content) < n)
		{
			n = (*(int *) aux->content);
			first = aux;
		}
		aux = aux->next;
	}
	return (first);
}

void	ft_stacka_in_ascending_order(t_list **stacka)
{
	t_list	*first;
	int	i;
	t_list	*aux;

	first = ft_find_first(stacka);
	aux = first;
	i = 0;
	while (aux->next)
	{
		i++;
		aux = aux->next;
	}
	if (i > 1)
	{
		while (*stacka != first)
			ft_rotate(stacka, 'A');
	}
	else
	{
		while (*stacka != first)
			ft_reverse_rotate(stacka, 'A');
	}
}

void	ft_find_position(t_list **stacka, t_list **stackb, t_list **pos)
{
	t_list	*aux;
	int	n1;
	int	n2;
	int	b;

	aux = *stacka;
	b = *((int *)(*stackb)->content);
	while (aux)
	{
		n1 = *((int *) aux->content);
		n2 = *((int *) aux->next->content);
		if ((b > n1) && (b < n2))
		{
			*pos = aux;
			return ;
		}
		aux = aux->next;
	}
}

void	ft_in_between_extremes(t_list **stacka, t_list **stackb, t_list *aux)
{
	ft_find_position(stacka, stackb, &aux);
	if (aux->next->next == NULL)
	{
		ft_reverse_rotate(stacka, 'A');
		ft_push(stackb, stacka, 'A');
	}
	else
	{
		while (ft_lstlast(*stacka) != aux)
			ft_rotate(stacka, 'A');
		ft_push(stackb, stacka, 'A');
	}
}

void	ft_sort_5(t_list **stacka, t_list **stackb)
{
	t_list	*aux;
	int	n;

	ft_push(stacka, stackb, 'B');
	if (ft_lstsize(*stacka) == 4)
		ft_push(stacka, stackb, 'B');
	ft_sort_3(stacka);
	while (ft_lstsize(*stackb))
	{
	aux = *stacka;
		n = *((int *)(*stackb)->content);
		if (n < *((int *) aux->content))
			ft_push(stackb, stacka, 'A');
		else if (n > *((int *)(ft_lstlast(*stacka))->content))
		{
			ft_push(stackb, stacka, 'A');
			ft_rotate(stacka, 'A');
		}
		else
		{
			ft_in_between_extremes(stacka, stackb, aux);
			ft_stacka_in_ascending_order(stacka);
		}
	}
}
