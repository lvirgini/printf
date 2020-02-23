/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_g_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:16 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/02 17:13:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Determination de tous les g_flags.
*/

int			ft_what_options(const char *format,	va_list args)
{
	int i;

	i = 0;
	if (format[i] == '%' && (g_flag->total_print += 1))
	{
		write(1, "%%", 1);
		return (i + 1);
	}
	while (ft_strchr("0123456789-*", format[i]))
	{
		if (format[i] == '0')
			g_flag->zero = 1;
		if (format[i] == '-')
			g_flag->left = 1;
		if (format[i] == '*' && ((g_flag->width = va_arg(args, int)) < 0))
		{
			g_flag->width *= -1;
			g_flag->left = 1;
		}
		if (ft_isdigit(format[i]))
			i += ft_width_digit(format + i) - 1;
		i++;
	}
	if (format[i] == '.' && (g_flag->zero = 0) == 0)
		i = ft_precision(format, i + 1, args);
	return (ft_dispatch_type(format, i, args));
}

/*
**	largeur de champs : si elle est inscrite dans la chaine format;
*/

int			ft_width_digit(const char *format)
{
	char	*tmp;
	int		j;

	j = 0;
	while (ft_isdigit(format[j]))
		++j;
	tmp = ft_substr(format, 0, j);
	g_flag->width = ft_atoi(tmp);
	free(tmp);
	return (j); 
}

/*
** Récupère la precision.
*/

int			ft_precision(const char *s, int i, va_list args)
{
	int		neg;

	neg = 1;
	if (s[i] == '-' && (i += 1) && (g_flag->left = 1))
		neg = -1;
	if (s[i] == '*' && (i += 1))
	{
		if ((g_flag->precision = va_arg(args, int)) < 0)
		{
			if (neg == -1 && (neg = 0) == 0)
				g_flag->width = g_flag->precision * -1;
			g_flag->precision = -1;
		}
	}
	else if (ft_isdigit(s[i]))
		i += ft_precision_is_digit(s + i);
	else
		g_flag->precision = 0;
	if (neg == -1 && g_flag->precision != 0)
	{
		g_flag->width = g_flag->precision;
		g_flag->precision = 0;
	}
	return (i);
}

/*
** Suite de ft_précision : si c'est inscrit dans la chaine format.
*/

int			ft_precision_is_digit(const char *s)
{
	char	*tmp;
	int		j;

	j = 0;
	while (ft_isdigit(s[j]))
		++j;
	if (j > 0)
	{
		tmp = ft_substr(s, 0, j);
		if ((g_flag->precision = ft_atoi(tmp)) < 0)
			g_flag->precision = -1;
		free(tmp);
	}
	return (j);
}
