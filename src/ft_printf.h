/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:52:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/25 17:02:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Les Includes
*/

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

/*
** Les Typedefs
*/

typedef struct s_flag			t_flag;
typedef long long int			t_ll;
typedef unsigned long long int	t_ull;

struct		s_flag
{
	int		left;
	int		zero;
	int		width;
	int		precision;
	int		total_print;
	char	specifiers;
	t_ll	arg;
	t_ull	uarg;
	char	*s;
	wchar_t	*ls;
	char	arg_error;
};

/*
** Les fonctions qui récupèrent l'argument selon son type
*/

int			ft_printf(const char *restrict format, ...);
int			type_dispatch(const char *format, int i, va_list args);
int			type_size(const char *format, int i, va_list args);
int			type_long(const char *format, int i, va_list args);
int			type_short(const char *format, int i, va_list args);
int			type_classic(const char *format, int i, va_list args);

/*
** Les fonctions qui récupèrent les flags
*/

int			flag_collect(const char *format, va_list args);
int			flag_precision(const char *s, int i, va_list args);
int			flag_precision_is_digit(const char *s);
void		flag_width_is_arg(va_list args);
int			flag_width_is_digit(const char *format);

/*
**	Les fonctions de conversion.
*/

char		*convert_hexadecimal(void);
char		*convert_adress(char format);
int			size_unicode(wchar_t arg);
int			print_unicode(wchar_t arg, int nb_oct);

/*
** Les fonctions d'impression.
*/

char		*print_before(int nbr, char c, char *s, int *len);
char		*print_before_0x(int max, char c, char *s, int *len);
char		*print_before_sign(int max, char c, char *s, int *len);
char		*print_after(int nbr, char c, char *s, int *len);
void		print_hexa(char *s);
void		print_int(char *s);
int			print_character(void);
void		print_string(void);
void		print_string_unicode(void);
void		print_string_unicode2(wchar_t *ls, int len);
int			print_space(unsigned int len);
void		print_ls(wchar_t *ls, int len);
int			print_wchar(int nb_oct);
void		print_percent(void);

/*
** Fonctions d'initialisation et de clean.
*/

t_flag		*struct_malloc(void);
void		struct_init(void);
int			struct_clean_end(void);

/*
** Les fonctions utiles modifiées pour printf.
*/

void		ft_putstr_fd_maxlen(char *s, int fd, unsigned int max);
int			ft_strchr_i(const char *s, int a);

extern	t_flag	*g_flag;

#endif
