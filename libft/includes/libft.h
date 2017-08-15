/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:29:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:03:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# include "macrosft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_rect
{
	size_t			x0;
	size_t			x1;
	size_t			y0;
	size_t			y1;
}					t_rect;

typedef struct		s_text
{
	char			*start;
	char			*end;
	char			delim;
}					t_text;

typedef struct		s_drange
{
	int				*start;
	int				*end;
}					t_drange;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memjoin(void const *m1, void const *m2,
								size_t s1, size_t s2);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strbuf(const char *buf, size_t sz);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, char c);
char				*ft_strrchr(const char *str, char c);
char				*ft_strchrnul(const char *str, char c);
char				*ft_strstr(const char *str, const char *c);
char				*ft_strnstr(const char *str,
								const char *c, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrev(char *str);
char				*ft_strset(char *str, char c);
char				*ft_strnchr(const char *str, char c, size_t n);
char				*ft_strvchr(char *head, char *from, char q);
char				*ft_strvchrhed(char *head, char *from, char q);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strevery(char const *s, int (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*my_strsub(char const *start, char const *end);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnfree(t_list **alst, size_t n);
t_list				*ft_lstscpy(t_list *lst);
t_list				*ft_lstdcpy(t_list *lst);
void				**ft_lstsarr(t_list *lst);
t_list				*ft_arrslst(void *arr, size_t sz);
int					*ft_newdarri(size_t len);
int					*ft_darrfind(int *arr, int value, int len);
int					*ft_darrmin(int *arr, int len);
int					*ft_darrmingt(int *arr, int val, int len);
t_list				*ft_lstnode(void const *content, size_t content_size);
size_t				ft_lstlen(t_list *lst);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstpush(t_list **alst, t_list *new);
t_list				*ft_lstpop(t_list **alst);
t_list				*ft_lstfpop(t_list **alst);
t_list				*ft_lstfree(t_list **alst);
t_list				*ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstsrev(t_list **begin_list);
t_list				*ft_lstdrev(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_bool				ft_lstevery(t_list *lst, int (*f)(t_list *elem));
size_t				ft_count_digits(long value);
char const			*ft_next_word(char const *str, char delim);
char				*ft_word_copy(char *dest, char const *src, char delim);
unsigned			ft_count_words(char const *str, char delim);
unsigned			ft_word_length(char const *str, char delim);
char				*ft_wordchr(const char *str, char c, char d);
char				*ft_wordnchr(const char *str, char c, char d, size_t n);
t_point				*ft_ptnew(int x, int y);
t_point				*ft_ptsub(t_point *minuend, t_point *subtrahend);
t_point				*ft_ptless(t_point *pt, t_point *less);
char				*ft_next_in_rect(t_text *tx, t_rect *rx, char *pos);
char				*ft_rectchr(t_text *tx, t_rect *rx, char *pos, char query);
char				*ft_rectrpl(t_text *tx, t_rect *rx, char q, char r);
char				*ft_x_in_str(t_text *tx, char *pos, int x);
char				*ft_xy_in_str(t_text *tx, char *pos, int x, int y);
t_point				*ft_xy_from_str(t_text *tx, t_rect *rx, char *pos);
t_drange			*ft_newdrng(int a, int b, int (*f)(int));
size_t				ft_drnglen(int a, int b, int (*f)(int));
t_bool				ft_dpermute(int *first, int *last);
int					ft_dinc(int n);
int					ft_dmin(int *first, int *last);
void				*ft_cpyrev(void *start, void *end, size_t sz);
void				ft_cpyswap(void *a, void *b, size_t sz);
void				ft_ptrswap(void **a, void **b);
int					ft_dsqrt(int n);
double				ft_fsqrt(double n);
int					ft_ceilsqrt(int n);

#endif
