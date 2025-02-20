NAME = push_swap
# CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ft_split.c ft_atoi.c lst_new_node.c utils_swap.c greedy_sort.c chanks_algo.c\
		ft_strjoin.c ft_ret_lst.c check_erro.c lst_add_back.c rotate_utils.c lst_add_front.c \
		reverse_rotate_utils.c take_list.c ft_push.c lst_count.c sort_list.c sort_algo.c indix.c

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BSRC:.c=.o}

all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
				$(CC) $(CFLAGS) $^ -o $(NAME_BONUS)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all