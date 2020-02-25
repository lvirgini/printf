/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:09:20 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/25 12:51:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Recherche de la taille de l'argument à récupérer.
*/

int		type_size(const char *format, int i, va_list args)
{
	int		(*f)(const char *, int, va_list args);
	int		j;

	j = 0;
	f = &type_classic;
	while (ft_strchr("hl", format[i + j]))
	{
		if (format[i + j] == 'h')
			f = &type_short;
		else
			f = &type_long;
		++j;
	}
	g_flag->specifiers = format[i + j];
	return (f(format, i, args));
}

/*
** Récupère l'argument sans specification de taille.
*/

int		type_classic(const char *format, int i, va_list args)
{
	if ((ft_strchr("di", format[i])))
		g_flag->arg = (int)va_arg(args, int);
	else if ((ft_strchr("cuxX", format[i])))
		g_flag->uarg = (unsigned int)va_arg(args, unsigned int);
	else if ((format[i] == 'p'))
		g_flag->uarg = (t_ull)va_arg(args, t_ull);
	else if ((format[i] == 's'))
		g_flag->s = va_arg(args, char *);
	else if ((format[i] == '%'))
		;
	else
		g_flag->arg_error = 1;
	return (i);
}

/*
** Récupère l'argument avec les flags (l) ou (ll).
*/

int		type_long(const char *format, int i, va_list args)
{
	while (format[i] != 'l')
		i++;
	if (format[i + 1] == 'l')
	{
		if ((ft_strchr("di", format[i + 2])))
			g_flag->arg = (long long)va_arg(args, long long);
		else if ((ft_strchr("uxX", format[i + 2])))
			g_flag->uarg = (t_ull)va_arg(args, t_ull);
		else
			g_flag->arg_error = 1;
		return (i + 2);
	}
	if ((ft_strchr("di", format[i + 1])))
		g_flag->arg = (long)va_arg(args, long);
	else if ((ft_strchr("uxX", format[i + 1])))
		g_flag->uarg = (unsigned long int)va_arg(args, unsigned long int);
	else if (format[i + 1] == 's')
		g_flag->ls = va_arg(args, wchar_t *);
	else if (format[i + 1] == 'c')
		g_flag->uarg = (int)va_arg(args, int);
	else
		g_flag->arg_error = 1;
	return (i + 1);
}

/*
** Récupère l'argument avec les g_flags (h) ou (hh).
*/

int		type_short(const char *format, int i, va_list args)
{
	while (format[i] != 'h')
		i++;
	if (format[i + 1] == 'h')
	{
		if ((ft_strchr("di", format[i + 2])))
			g_flag->arg = (char)va_arg(args, int);
		else if ((ft_strchr("uxX", format[i + 2])))
			g_flag->uarg = (unsigned char)va_arg(args, int);
		else
			g_flag->arg_error = 1;
		return (i + 2);
	}
	if ((ft_strchr("di", format[i + 1])))
		g_flag->arg = (short int)va_arg(args, int);
	else if ((ft_strchr("uxX", format[i + 1])))
		g_flag->uarg = (unsigned short int)va_arg(args, int);
	else
		g_flag->arg_error = 1;
	return (i + 1);
}
