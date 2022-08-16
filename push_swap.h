#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h> //TIRAR!

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int	ft_read_arguments(int argc, int *argv2, char *argv[], t_list **stackA);
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_wrong_arg(char *arg);
size_t	ft_strlen(char *str);
void	ft_swap(t_list **stackX);
void	ft_push(t_list **stackX, t_list **stackY);
void	ft_rotate(t_list **stackX);
void	ft_reverse_rotate(t_list **stackX);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int	ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_bubble_sort(int *arr, int size_arr);

#endif
