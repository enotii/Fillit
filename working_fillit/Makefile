NAME = fillit

all: $(NAME)
$(NAME):
	make -C libft/ 
	clang -Wall  -Wall -Wextra -Werror -I libft/ -o ft_cut_figures.o -c ft_cut_figures.c
	clang -Wall  -Wall -Wextra -Werror -I libft/ -o ft_fillit.o -c ft_fillit.c
	clang -Wall  -Wall -Wextra -Werror -I libft/ -o ft_read_map.o -c ft_read_map.c
	clang -Wall  -Wall -Wextra -Werror -I libft/ -o main.o -c main.c
	clang -o $(NAME) main.o ft_cut_figures.o ft_fillit.o ft_read_map.o -I libft/ -L libft/ -lft
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all