/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:40:42 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 18:11:56 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# ifndef TYPEDEF_CPLX
#  define TYPEDEF_CPLX

typedef long double	t_re;
typedef long double	t_im;

# endif

# ifndef MARGIN_ERROR
#  define MARGIN_ERROR (t_re)0.000001
# endif

# ifndef COL_SHELL
#  define COL_SHELL
#  define COL_INIT "\033[0m"
#  define COL_BLACK "\033[30m"
#  define COL_RED "\033[31m"
#  define COL_GREEN "\033[32m"
#  define COL_YELLOW "\033[33m"
#  define COL_BLUE "\033[34m"
#  define COL_MAGENTA "\033[35m"
#  define COL_CYAN "\033[36m"
#  define COL_WHITE "\033[37m"
#  define COL_BG_BLACK "\033[40m"
#  define COL_BG_RED "\033[41m"
#  define COL_BG_GREEN "\033[42m"
#  define COL_BG_YELLOW "\033[43m"
#  define COL_BG_BLUE "\033[44m"
#  define COL_BG_MAGENTA "\033[45m"
#  define COL_BG_CYAN "\033[46m"
#  define COL_BG_WHITE "\033[47m"
#  define FONT_BOLD "\033[1m"
#  define FONT_DIM "\033[2m"
#  define FONT_ITALIC "\033[3m"
#  define FONT_UNDER "\033[4m"
#  define FONT_BLINK "\033[5m"
#  define FONT_INVERT "\033[7m"
#  define FONT_HIDDEN "\033[8m"
#  define FONT_STRIKE "\033[9m"
# endif

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isnumber(char *s);
int					ft_ishex(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
int					ft_memdel2dim(void ***t, size_t n);
int					ft_memlen(void *tab, size_t content_size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(int c);
void				ft_putchar_fd(int c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_base(int n, unsigned int base);
void				ft_putnbr_base_fd(int n, unsigned int base, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_lstadd(t_list **alst, t_list *newlist);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *t);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

int					ft_atoi_base(const char *str, unsigned int base);
char				*ft_itoa_base(int n, unsigned int base);
int					ft_power(int a, int exp);
char				*ft_replace(const char *s, const char *o, const char *n);
int					ft_abs(int a);
t_re				ft_absf(t_re a);

int					get_next_line(const int fd, char **line);

size_t				ft_strset(char *dst, int c, size_t n);
char				*ft_strmset(int c, size_t n);
void				ft_putcenter(const char *s, int width, int c);
int					ft_lenchar(int c);

int					barely_zero(t_re a);
int					barely_equals(t_re a, t_re b);

#endif
