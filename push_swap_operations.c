#include "push_swap.h"

void	ft_swap(t_list **stackX)
{
	t_list	*aux;
	int	size;

	size = ft_lstsize(*stackX);
	if ((size == 1) || (size == 0))
		return ;
	aux = (*stackX)->next;
	(*stackX)->next = aux->next;
	aux->next = *stackX;
	*stackX = aux;
}

void	ft_push(t_list **stackX, t_list **stackY)
{
	t_list	*aux;
	int	size;

	size = ft_lstsize(*stackX);
	if (size == 0)
		return ;
	aux = (*stackX)->next;
	if (stackY)
		(*stackX)->next = (*stackY);
	else
		(*stackX)->next = NULL;
	*stackY = *stackX;
	*stackX = aux;
}

void	ft_rotate(t_list **stackX)
{
	t_list	*aux;
	
	aux = ft_lstlast(*stackX);
	aux->next = *stackX;
	*stackX = (*stackX)->next;
	aux->next->next = NULL;
}

void	ft_reverse_rotate(t_list **stackX)
{
	t_list	*aux;
	
	aux = *stackX;
	while (aux->next->next)
		aux = aux->next;
	aux->next->next = *stackX;
	*stackX = aux->next;
	aux->next = NULL;
}
