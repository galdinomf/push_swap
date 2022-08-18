#include "push_swap.h"

t_list	*ft_find_first(t_list **stackA)
{
	t_list	*aux;
	int	n;
	t_list	*first;

	first = *stackA;
	aux = *stackA;
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

void	ft_stackA_in_ascending_order(t_list **stackA)
{
	t_list	*first;
	int	i;
	t_list	*aux;

	first = ft_find_first(stackA);
	aux = first;
	i = 0;
	while (aux->next)
	{
		i++;
		aux = aux->next;
	}
	if (i > 1)
	{
		while (*stackA != first)
			ft_rotate(stackA, 'A');
	}
	else
	{
		while (*stackA != first)
			ft_reverse_rotate(stackA, 'A');
	}
}

void	ft_find_position(t_list **stackA, t_list **stackB, t_list **pos)
{
	t_list	*aux;
	int	n1;
	int	n2;
	int	b;
	int	i;

	i = 0;
	aux = *stackA;
	b = *((int *) (*stackB)->content);
	while (aux)
	{
		n1 = *((int *) aux->content);
		n2 = *((int *) aux->next->content);
		if ((b > n1) && (b < n2))
		{
			*pos = aux;
			return ;
		}
		else
			i++;
		aux = aux->next;
	}
}

void	ft_in_between_extremes(t_list **stackA, t_list **stackB, t_list *aux)
{
	ft_find_position(stackA, stackB, &aux);
	if (aux->next->next == NULL)
	{
		ft_reverse_rotate(stackA, 'A');
		ft_push(stackB, stackA, 'A');
	}
	else
	{
		while (ft_lstlast(*stackA) != aux)
			ft_rotate(stackA, 'A');
		ft_push(stackB, stackA, 'A');
	}
}

void	ft_sort_5A(t_list **stackA, t_list **stackB)
{
	t_list	*aux;
	int	n;

	ft_push(stackA, stackB, 'B');
	ft_push(stackA, stackB, 'B');
	ft_sort_3A(stackA);
	while (ft_lstsize(*stackB))
	{
	aux = *stackA;
		n = *((int *) (*stackB)->content);
		if (n < *((int *) aux->content))
			ft_push(stackB, stackA, 'A');
		else if (n > *((int *) (ft_lstlast(*stackA))->content))
		{
			ft_push(stackB, stackA, 'A');
			ft_rotate(stackA, 'A');
		}
		else
		{
			ft_in_between_extremes(stackA, stackB, aux);
			ft_stackA_in_ascending_order(stackA);
		}
	}
}
