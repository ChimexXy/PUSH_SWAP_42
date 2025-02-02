CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ft_split.c ft_atoi.c

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