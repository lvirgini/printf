/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:52:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/23 13:23:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ATTENTION retirer stdio.h + verif des retrait de tous printf
// verifier uint max pour utoa et retirer ses commentaires,
// tester si 4 arg OK mais 5eme mauvais :
// verififier les valeurs de retour de malloc si non fonctionnel

#ifndef		FT_PRINTF_H
# define	FT_PRINTF_H
# define 	LL long long int
# define 	ULL unsigned long long int

/*
** Les Includes
*/

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "../libft/libft.h"
#include <stdio.h> //

typedef struct s_flag	t_flag;

struct		s_flag
{
	int		left;
	int 	zero;
	int		width;
	int 	precision;
	int		total_print;
	char	specifiers;
	LL		arg;
	ULL		uarg;
	char	*s;
	wchar_t	*ls;
	char	arg_error;
};

/*
** Les fonctions qui récupère l'argument selon son type
*/

# define PRINTF_ATTR __attribute__ ((format (printf, 1, 2)))
int			ft_printf(const char * restrict format, ...);// PRINTF_ATTR;
int			ft_dispatch_type(const char *format, int i, va_list args);
int			ft_size_type(const char *format, int i, va_list args);
int			ft_type_long(const char *format, int i, va_list args);
int			ft_type_short(const char *format, int i, va_list args);
int			ft_type_classic(const char *format, int i, va_list args);

/*
** Les fonctions qui récupèrent les flags
*/

int			ft_what_options(const char *format,	va_list args);
int			ft_precision_is_digit(const char *s);
int			ft_precision(const char *s, int i, va_list args);
int			ft_width_digit(const char *format);

/*
**	Les fonctions de conversion.
*/

char		*convert_hexadecimal(void);
char		*convert_adress(void);
int			char_or_unicode(wchar_t arg);
int			convert_unicode(wchar_t arg, int nb_oct);

/*
** Les fonctions d'impression.
*/

char		*print_before(int nbr, char c, char *s,int *len);
char		*print_before_0x(int max, char c, char *s, int *len);
char		*print_before_sign(int max, char c, char *s, int *len);
char		*print_after(int nbr, char c, char *s, int *len);
void		print_hexa(char *s);
void		print_int(char *s);
void		print_character(void);
void		print_string(void);

/*
** Les fonctions utiles modifiées pour printf.
*/

void		ft_putstr_fd_maxlen(char *s, int fd, unsigned int max);
int 		ft_strchr_i(const char *s, int a);

extern	t_flag	*g_flag;

#endif
