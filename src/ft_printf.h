/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:52:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/28 16:42:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ATTENTION retirer stdio.h + verif des retrait de tous printf
// verifier uint max pour utoa et retirer ses commentaires,
// regler le probleme pour les mauvais flags : retourner la chaine %xdlala
// tester si 4 arg OK mais 5eme mauvais :
// verififier les valeurs de retour de malloc si non fonctionnel

#ifndef		FT_PRINTF_H
# define	FT_PRINTF_H
# define 	LL long long int
# define 	ULL unsigned long long int

/*
**	define des masques binaires et des octets pour recuperation wchar
*/

# define	MB1 0x80
# define	MB2 0xC0
# define	MB3 0xE0
# define	MB4 0xF0
# define	WC1 0x3F
# define	WC2 0x1F
# define	WC3 0xF
# define	WC4	7

/*
** Les Includes
*/

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "libft.h"
#include <stdio.h>

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
	char	arg_error;
};

/*
** Les fonctions principales.
*/

# define PRINTF_ATTR __attribute__ ((format (printf, 1, 2)))
int			ft_printf(const char * restrict format, ...);// PRINTF_ATTR;
int			ft_dispatch_type(const char *format, unsigned int *i,
					va_list args, t_flag *flag);
void		ft_size_type(const char *format, unsigned int *i,
					va_list args, t_flag *flag);
int			ft_what_options(const char *format, unsigned int *i,
					va_list args, t_flag *flag);
void		ft_type_long(const char *format, unsigned int *i,
					va_list args, t_flag *flag);
void		ft_type_short(const char *format, unsigned int *i,
					va_list args, t_flag *flag);
void		ft_type_classic(const char *format, unsigned int *i,
					va_list args, t_flag *flag);

/*
**	Les fonctions de conversion du type d'argument.
*/

void		convert_unicode(t_flag *, char);
char		*convert_hexadecimal(t_flag *flag);
char		*convert_adress(t_flag *flag);

/*
** Les fonctions d'impression.
*/

char		*print_before(int nbr, char c, char *s,int *len);
char		*print_before_0x(int max, char c, char *s, int *len);
char		*print_before_sign(int max, char c, char *s, int *len);
char		*print_after(int nbr, char c, char *s, int *len);
void		print_hexa(t_flag *flag, char *s);
void		print_int(t_flag *flag, char *s);
void		print_character(va_list args, t_flag *flag);
void		print_string(va_list args, t_flag *flag);
void		c_unicode(va_list args, t_flag *flag);

/*
** Les fonctions utiles modifiées pour printf.
*/

void		ft_putstr_fd_maxlen(char *s, int fd, unsigned int max);
int 		ft_strchr_i(const char *s, int a);

#endif
