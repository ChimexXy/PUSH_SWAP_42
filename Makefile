NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address 
SRC = push_swap.c ft_split.c ft_atoi.c lst_new_node.c swap_utils.c intializ_index.c \
		ft_strjoin.c ft_ret_lst.c check_erro.c lst_add_back.c rotate_utils.c lst_add_front.c \
		reverse_rotate_utils.c take_list.c ft_push.c lst_count.c sort_list.c sort_algo.c 

OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all