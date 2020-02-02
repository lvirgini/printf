/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:09:20 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/02 20:13:06 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** recherche du type d'argument, et l'envoie pour son impression.
*/

int		ft_dispatch_type(const char *format, int i,
						va_list args, t_flag *flag)
{
	i = ft_size_type(format, i, args, flag);
	if (flag->arg_error && (flag->total_print += 1))
	{
		write(1, "%%", 1);
		return (1);
	}
	flag->specifiers = format[i];
	if (format[i] == 'c')
		print_character(flag);
	else if (format[i] == 's')
		print_string(args, flag);
	else if (format[i] == 'p')
		print_hexa(flag, (convert_adress(flag)));
	else if ((format[i] == 'd' || format[i] == 'i'))
		print_int(flag, ft_lltoa(flag->arg));
	else if (format[i] == 'u')
		print_int(flag, ft_ulltoa(flag->uarg));
	else if (format[i] == 'x' || format[i] == 'X')
		print_hexa(flag, (convert_hexadecimal(flag)));
	return (i + 1);
}

/*
** Recherche de la taille de l'argument à récupérer.
*/

int 	ft_size_type(const char *format, int i, va_list args, t_flag *flag)
{
	int		(*f)(const char *, int, va_list, t_flag *);
	int		j;

	j = 0;
	f = &ft_type_classic;
	while (ft_strchr("hl", format[i + j]))
	{
		if (format[i] == 'h')
			f = &ft_type_short;
		else
			f = &ft_type_long;
		++j;
	}
	return (f(format, i, args, flag));
}

/*
** Récupère l'argument sans specification de taille.
*/

int		ft_type_classic(const char *format, int i,
					va_list args, t_flag *flag)
{
	if ((ft_strchr("di", format[i])))
		flag->arg = (int)va_arg(args, int);
	else if ((ft_strchr("cuxX", format[i])))
		flag->uarg = (unsigned int)va_arg(args, unsigned int);
	else if ((format[i] == 'p'))
		flag->uarg = (ULL)va_arg(args, ULL);
	//else if (format[i] == 'c')
	//	flag->uarg = (int)va_arg(args, int);
	else if (ft_strchr("cs", format[i]))
		;
	else
		flag->arg_error = 1;
	return (i);
}

/*
** Récupère l'argument avec les flags (l) ou (ll).
*/

int		ft_type_long(const char *format, int i,
					va_list args, t_flag *flag)
{
	while (format[i] != 'l')
		i++;
	if (format[i + 1] == 'l')
	{
		if ((ft_strchr("di", format[i + 2])))
			flag->arg = (long long)va_arg(args, long long);
		else if ((ft_strchr("uxX", format[i + 2])))
			flag->uarg = (ULL)va_arg(args, ULL);
		else
			flag->arg_error = 1;
		return (i + 2);
	}
	else
	{
		if ((ft_strchr("di", format[i + 1])))
			flag->arg = (long)va_arg(args, long);
		else if ((ft_strchr("uxX", format[i + 1])))
			flag->uarg = (unsigned long int)va_arg(args, unsigned long int);
	//	else if (format[i + 1] == 's')
	//		str_unicode(flag);
		else if (format[i + 1] == 'c')
			flag->uarg = (int)va_arg(args, int);
		else
			flag->arg_error = 1;
		return (i + 1);
	}
}

/*
** Récupère l'argument avec les flags (h) ou (hh).
*/

int		ft_type_short(const char *format, int i,
					va_list args, t_flag *flag)
{
	while (format[i] != 'h')
		i++;
	if (format[i + 1] == 'h')
	{
		if ((ft_strchr("di", format[i + 2])))
			flag->arg = (char)va_arg(args, int);
		else if ((ft_strchr("uxX", format[i + 2])))
			flag->uarg = (unsigned char)va_arg(args, int);
		else
			flag->arg_error = 1;
		return (i + 2);
	}
	else
	{
		if ((ft_strchr("di", format[i + 1])))
			flag->arg = (short int)va_arg(args, int);
		else if ((ft_strchr("uxX", format[i + 1])))
			flag->uarg = (unsigned short int)va_arg(args, int);
		else
			flag->arg_error = 1;
		return (i + 1);
	}
}
