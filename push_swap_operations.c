#include "push_swap.h"

void	ft_swap(t_list **stackx, char stack_letter)
{
	t_list	*aux;
	int	size;

	size = ft_lstsize(*stackx);
	if ((size == 1) || (size == 0))
		return ;
	aux = (*stackx)->next;
	(*stackx)->next = aux->next;
	aux->next = *stackx;
	*stackx = aux;
	if (stack_letter == 'A')
		write(1, "sa\n", 3);
	if (stack_letter == 'B')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **stackx, t_list **stacky, char stack_letter)
{
	t_list	*aux;
	int	size;

	size = ft_lstsize(*stackx);
	if (size == 0)
		return ;
	aux = (*stackx)->next;
	if (stacky)
		(*stackx)->next = (*stacky);
	else
		(*stackx)->next = NULL;
	*stacky = *stackx;
	*stackx = aux;
	if (stack_letter == 'A')
		write(1, "pa\n", 3);
	if (stack_letter == 'B')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_list **stackx, char stack_letter)
{
	t_list	*aux;

	aux = ft_lstlast(*stackx);
	aux->next = *stackx;
	*stackx = (*stackx)->next;
	aux->next->next = NULL;
	if (stack_letter == 'A')
		write(1, "ra\n", 3);
	if (stack_letter == 'B')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_list **stackx, char stack_letter)
{
	t_list	*aux;

	aux = *stackx;
	while (aux->next->next)
		aux = aux->next;
	aux->next->next = *stackx;
	*stackx = aux->next;
	aux->next = NULL;
	if (stack_letter == 'A')
		write(1, "rra\n", 4);
	if (stack_letter == 'B')
		write(1, "rrb\n", 4);
}
