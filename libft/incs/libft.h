/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:29:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 13:00:47 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define ISSPACE(c) (c == ' ' || c == '\t' || c == '\n' || ISSPACE2(c))
# define ISSPACE2(c) (c == '\r' || c == '\v' || c== '\f')
# define ISDIGIT(c) (c >= '0' && c <= '9')
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct		s_lst
{
	void			*dat;
	int				sz;
	struct s_lst	*nxt;
}					t_lst;

typedef enum		e_bool
{
	false,
	true,
}					t_bool;

void				ft_memero(void *mm, int sz);
void				*ft_memset(void *mm, int cc, int sz);
void				*ft_memcpy(void *dst, const void *src, int sz);
void				*ft_memccpy(void *dst, const void *src, int cc, int sz);
void				*ft_memmove(void *dst, const void *src, int sz);
void				*ft_memchr(const void *mm, int cc, int sz);
int					ft_memcmp(const void *m1, const void *m2, int sz);
int					ft_strlen(const char *ss);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, int sz);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, int sz);
int					ft_strlcat(char *dest, const char *src, int sz);
char				*ft_strchr(const char *ss, char qry);
char				*ft_strchrnul(const char *ss, char qry);
char				*ft_strrchr(const char *ss, char qry);
char				*ft_strstr(const char *ss, const char *qry);
char				*ft_strnstr(const char *ss,
								const char *qry, int sz);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, int sz);
int					ft_strspn(const char *ss, const char *dlm);
int					ft_strcspn(const char *ss, const char *dlm);
char				*ft_strpbrk(const char *ss, const char *dlm);
char				*ft_strtok(char *ss, const char *dlm);
char				*ft_strtokbeg(const char *ss, const char *dlm);
int					ft_strtokamt(const char *ss, const char *dlm);
char				*ft_strtokcpy(char *dst, const char *src, const char *dlm);
char				*ft_strtoknxt(const char *ss, const char *dlm);
int					ft_strtoklen(const char *ss, const char *dlm);
int					ft_atoi(char *ss);
int					ft_isalpha(int cc);
int					ft_isdigit(int cc);
int					ft_isalnum(int cc);
int					ft_isascii(int cc);
int					ft_isprint(int cc);
int					ft_toupper(int cc);
int					ft_tolower(int cc);
void				*ft_memalloc(int sz);
void				ft_memdel(void **mem);
char				*ft_strnew(int sz);
void				ft_strdel(char **ss);
void				ft_strclr(char *ss);
void				ft_striter(char *ss, void (*ff)(char *));
void				ft_striteri(char *ss, void (*ff)(int, char *));
char				*ft_strmap(char const *ss, char (*ff)(char));
char				*ft_strmapi(char const *ss, char (*ff)(int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, int sz);
char				*ft_strsub(char const *ss, int beg, int sz);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *ss);
char				**ft_strsplit(char const *ss, const char *dlm);
char				*ft_itoa(int val);
void				ft_putchar(char cc);
void				ft_putstr(char const *ss);
void				ft_putendl(char const *ss);
void				ft_putnbr(int val);
void				ft_putchar_fd(char cc, int fd);
void				ft_putstr_fd(char const *ss, int fd);
void				ft_putendl_fd(char const *ss, int fd);
void				ft_putnbr_fd(int val, int fd);
t_lst				*ft_lstnew(void const *dat, int sz);
t_lst				*ft_lstdelone(t_lst **ll, void (*del)(void *, int));
t_lst				*ft_lstdel(t_lst **ll, void (*del)(void *, int));
t_lst				*ft_lstadd(t_lst **ll, t_lst *nod);
t_lst				*ft_lstiter(t_lst *ll, void (*ff)(t_lst *elm));
t_lst				*ft_lstmap(t_lst *ll, t_lst *(*ff)(t_lst *elm));
int					ft_diglen(int val);
char				*ft_strrev(char *ss);
t_lst				*ft_lstsrev(t_lst **beg);
t_lst				*ft_lstnode(void const *dat, int sz);
t_lst				*ft_lstnfree(t_lst **ll, int dpth);
t_lst				*ft_lstdelcmp(t_lst **ll, void *qry,
								int (*cmp)(const void *, const void *, int));
t_lst				*ft_lstfind(t_lst *ll, void *qry,
								int (*cmp)(void *, void *, int));
t_lst				*ft_lstmemfind(t_lst *ll, void *qry, int ofst, int sz);
void				*ft_memcchr(const void *mm, int cc, int sz);
char				*ft_strbuf(const char *buf, int sz);
char				*ft_lststr(t_lst *ll);
int					ft_lstszsum(t_lst *ll);
int					get_next_scan(const char *buf, const char *dlm, char **out);
int					get_next_buf(int fd, int sz, char **buf);

#endif
