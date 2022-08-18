#include "push_swap.h"

void	ft_swap(t_list **stackX, char stack_letter)
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
	if (stack_letter == 'A')
		write(1, "sa\n", 3);
	if (stack_letter == 'B')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **stackX, t_list **stackY, char stack_letter)
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
	if (stack_letter == 'A')
		write(1, "pa\n", 3);
	if (stack_letter == 'B')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_list **stackX, char stack_letter)
{
	t_list	*aux;
	
	aux = ft_lstlast(*stackX);
	aux->next = *stackX;
	*stackX = (*stackX)->next;
	aux->next->next = NULL;
	if (stack_letter == 'A')
		write(1, "ra\n", 3);
	if (stack_letter == 'B')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_list **stackX, char stack_letter)
{
	t_list	*aux;
	
	aux = *stackX;
	while (aux->next->next)
		aux = aux->next;
	aux->next->next = *stackX;
	*stackX = aux->next;
	aux->next = NULL;
	if (stack_letter == 'A')
		write(1, "rra\n", 4);
	if (stack_letter == 'B')
		write(1, "rrb\n", 4);
}
