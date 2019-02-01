NAME = libft.a
PATH_SRC = ./srcs
SRC = $(PATH_SRC)/*.c
HEADER = ./includes/libft.h
OBJ =  *.o
all: $(NAME)
$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/ \
		-o ft_check_fillit.o -c ft_check_fillit.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_fillit main.o ft_check_fillit.o -I libft/ -L libft/ -lft
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
