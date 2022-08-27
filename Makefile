SRCS	= main.c\
	  ft_atoi.c\
	  ft_lstadd_back.c\
	  ft_lstclear.c\
	  ft_lstiter.c\
	  ft_lstlast.c\
	  ft_lstnew.c\
	  ft_lstsize.c\
	  ft_isdigit.c\
	  ft_read_arguments.c\
	  ft_wrong_arg.c\
	  ft_strlen.c\
	  push_swap_operations.c\
	  ft_bubble_sort.c\
	  ft_sort_3.c\
	  ft_sort_5.c\
	  ft_itoa.c\
	  ft_strcmp.c\
	  ft_sort_2.c\
	  ft_sort_big.c\
	  ft_put_node_on_top.c\
	  ft_is_sorted.c\
	  ft_pow.c\

SRCS_B	= 

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

PROG_NAME= push_swap

NAME	= $(PROG_NAME).a
NAME_B	= $(PROG_NAME)_bonus.a

HDR	= $(PROG_NAME).h

RM	= rm -f

all:   $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS) $(HDR)
	$(RM) main_bonus.o
	ar -crs $(NAME) $(OBJS)
	$(RM) $(PROG_NAME)
	gcc $(NAME) -o $(PROG_NAME)

%.o: %.c $(HDR_DIR)$(HDR)
	gcc $(CFLAGS) -c $< -o $@

$(NAME_B): $(OBJS_B) $(HDR)
	$(RM) main.o
	ar -crs $(NAME_B) $(OBJS_B)
	$(RM) $(PROG_NAME)
	gcc $(NAME_B) -o $(PROG_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	$(RM) $(PROG_NAME)

re: fclean all

.PHONY: clean fclean re all bonus
