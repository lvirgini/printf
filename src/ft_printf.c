/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:47:02 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/22 16:05:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialization de la structure
*/

static void		ft_struct_reset(t_flag *f)
{
	f->left = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = -1;
	f->specifiers = 0;
	f->arg = 0;
	f->uarg = 0;
	f->s = NULL;
	f->ls = NULL;
	f->arg_error = 0;
}

static t_flag	*ft_initialize_struct(void)
{
	t_flag *f;

	if (!(f = (t_flag *)malloc(sizeof(*f))))
		return (NULL);
	f->total_print = 0;
	ft_struct_reset(f);
	return (f);
}

/*
** Free de la structure et renvoie le total imprimé par printf.
*/

static int		ft_clean_end(t_flag *flag)
{
	int total_print;

	total_print = flag->total_print;
	free(flag);
	return (total_print);
}

/*
**	lecture de la chaine *format.
**	Recherche du %
**	Print la partie de la chaine en s'arretant au %
**	Envoi pour verification, recuperation, conversion et print du flag.
*/

int				ft_printf(const char *restrict format, ...)
{
	unsigned int	len;
	va_list			args;
	t_flag			*flag;

	va_start(args, format);
	if (!*format || !(flag = ft_initialize_struct()))
		return (-1);
	while (format)
	{
		
		len = ft_strchr_i(format, '%');
		ft_putstr_fd_maxlen((char *)format, 1, len);
		flag->total_print += len;
		if (format[len] == '\0')
			return (ft_clean_end(flag));
		if (format[len] == '%')
		{
			len++;
			len += ft_what_options(format + len, args, flag);
			ft_struct_reset(flag);
		}
		format += len;
	}
	va_end(args);
	return (ft_clean_end(flag));
}
