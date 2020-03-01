/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:09:18 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/25 17:02:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** Fonctions verifiant si l'argument donné est bien quelque chose
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Fonctions d'impression et ou de conversion
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base_fd(int nbr, char *base, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *s);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa(int n);
char			*ft_lltoa(long long int n);
char			*ft_utoa(unsigned int n);
char			*ft_ulltoa(unsigned long long int n);

/*
** Fonction dl'allocation de mémoire
*/

void			*ft_calloc(size_t count, size_t size);

/*
** Fonctions traitant les zones mémoires
*/

void			*ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Fonctions traitant les string
*/

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strdup(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*strstr(const char *s, const char *set);
char			*ft_strtrim(char const *s, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** Fonctions traitant les listes (pour le moment bonus de libft)
*/

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif
