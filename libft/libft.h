/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:25:16 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/14 22:43:58 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dest, const void *source, int c, size_t n);
void			*ft_memchr(const void *arr, int num, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest_arr, const void *src_ptr, size_t num);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *arr, int value, size_t num);
char			*ft_strcat(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *dst, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *src, int n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strrchr(const char *src, int c);
char			*ft_strstr(const char *src, const char *to_find);
char			*ft_strnstr(const char *src, const char *to_find, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
void			ft_putendl(char *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_free_list(t_list *lst);
int				ft_count_words(char const *s, char c);
void			ft_swap(int *a, int *b);
int				ft_isdel(int c);
int				ft_abs(int c);

#endif
