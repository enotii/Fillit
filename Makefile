NAME = libft.a
PATH_SRC = ./srcs
SRC = $(PATH_SRC)/*.c
HEADER = ./includes/libft.h
OBJ =  *.o
all: $(NAME)
$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/ \
		-o ft_read_map.o -c ft_read_map.c
	clang -Wall -Wextra -Werror -I libft/ -o main.o -c main.c
	clang -o test_fillit main.o ft_read_map.o -I libft/ -L libft/ -lft
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
