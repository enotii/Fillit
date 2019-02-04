NAME = fillit

all: $(NAME)
$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/ -o ft_read_map.o -c ft_read_map.c
	clang -Wall -Wextra -Werror -I libft/ -o ft_fill_it.o -c ft_fill_it.c
	clang -Wall -Wextra -Werror -I libft/ -o go_go_figure.o -c go_go_figure.c
	clang -Wall -Wextra -Werror -I libft/ -o main.o -c main.c
	clang -o $(NAME) main.o ft_read_map.o -I libft/ -L libft/ -lft
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all
