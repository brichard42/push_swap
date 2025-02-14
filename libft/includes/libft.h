/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:04:57 by brichard          #+#    #+#             */
/*   Updated: 2019/08/27 17:24:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
**	TYPEDEF
*/

typedef unsigned long long	t_ullong;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**	FT_STR
*/

size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, \
				const char *needle, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strequ(char const *s1, char const *s);
int				ft_strnequ(char const *s1, char const *s, size_t n);
char			*ft_strnew(size_t size);
char			*ft_realloc(char **s, size_t len, int start);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
**	ATO - ITO
*/

int				ft_atoi(const char *str);
char			*ft_lltoa(long long l);
char			*ft_ftoa_u(long double lf, int prec);
char			*ft_ulltoa_ubase(unsigned long long ul, char *base);
int				ft_get_num_size(unsigned long long ul, \
								size_t b_size);

/*
**	MATHS
*/

long double		ft_pow_ldo(long double b, int p);
int				ft_abs(int a);
void			ft_quicksort(int *tab, int low, int high);

/*
**	GNL
*/

int				get_next_line(const int fd, char **line, char sep);

/*
**	FT_IS
*/

int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

/*
**	FT_TO
*/

int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	FT_PRINTF
*/

int				ft_printf(const char *format, ...);

/*
**	FT_PUT
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(long long l);
void			ft_print_tab(char **tab);
void			ft_putnbr_base(long long l, char *base);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	FT_MEM
*/

int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *src, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
int				ft_int_realloc(int **tab, size_t *size, int new);

/*
**	FT_LST
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstfind(t_list *lst, void *data);
t_list			*ft_lstnelem(t_list *lst, unsigned int n);
size_t			ft_lstlen(t_list *lst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstapp(t_list **alst, t_list *lst);
void			ft_lstswap(t_list **begin, int n);
void			ft_del_cont(void *content, size_t size);

void			ft_exit_malloc(void);

#endif
