CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ft_split.c ft_atoi.c lst_new_node.c utils_swap.c \
		ft_strjoin.c ft_ret_lst.c check_erro.c lst_add_back.c rotate_utils.c lst_add_front.c \
		reverse_rotate_utils.c take_list.c ft_push.c lst_count.c sort_list.c

OBJ = $(SRC:.c=.o)  
NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all