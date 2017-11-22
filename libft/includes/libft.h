/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:44:50 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/21 13:23:27 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);

char				**ft_strsplit(char *s, char delimiter);

void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

char				*ft_itoa(int n);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *d, char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *str, const char *query);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s, const char *find, size_t slen);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinchar(char const *s1, char c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strreplace(char *search, char *replace, char *subject);
char				*ft_strreplace_first(char *se, char *re, char *s);
char				*ft_itoa_base(int n, const char *base);

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putstr_classic(char *str);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);

int					ft_strlen_classic(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					math_pow(int nb, int power);
int					math_sqrt(int nb);
int					math_log(int n);
int					math_round(double x);

t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_lstsize(t_list *list);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **list, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **list, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstprint(t_list *list, void (*print_function)(t_list*));
void				ft_lstpush(t_list **list, t_list *value);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
