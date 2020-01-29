/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:16 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/25 19:42:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** verifie si *s est une specification de format.
*/

static int		ft_is_specific(const char *s, unsigned int *i)
{
	if (ft_isdigit(s[*i]) || s[*i] == '-' || s[*i] == '*')
		return (1);
	return (0);
}

/*
** verifie la precision
*/

static void		ft_precision_is_digit(const char *s, unsigned int *i, t_flag *flag)
{
	char			*tmp;
	unsigned int	j;

	j = 0;
	flag->zero = 0;
	while (ft_isdigit(s[*i + j]))
		++j;
	if (j > 0)
	{
		tmp = ft_substr(s, *i, j);
		if ((flag->precision = ft_atoi(tmp)) < 0)
			flag->precision = -1;
		free(tmp);
		*i += j;
	}
}

static void		ft_precision(const char *s, unsigned int *i, va_list args, t_flag *flag)
{
	int		neg;

	*i += 1;
	neg = 1;
	if (s[*i] == '-' && (*i += 1) && (flag->left = 1))
		neg = -1;
	if (s[*i] == '*' && (*i += 1))
	{
		if ((flag->precision = va_arg(args, int)) < 0)
		{
			if (neg == -1 && (neg = 0) == 0)
				flag->width = flag->precision * -1;
			flag->precision = -1;
		}
	}
	else if (ft_isdigit(s[*i]))
		ft_precision_is_digit(s, i, flag);
	else
		flag->precision = 0;
	if (neg == -1 && flag->precision != 0)
	{
			flag->width = flag->precision;
			flag->precision = 0;
	}
}

/*
**	largeur de champs digital
*/

static void		ft_width_digit(const char *format, unsigned int *i, t_flag *flag)
{
	unsigned int	j;

	j = 0;
	while (ft_isdigit(format[*i + j]))
		++j;
	flag->width = (ft_atoi(ft_substr(format, *i, j)));					 // MALLOC
	*i += j - 1;
}

/*
** Determination de toutes les options précédent le type à afficher.
*/

int			ft_what_options(const char *format, unsigned int *i,
						va_list args, t_flag *flag)
{
	while ((*i += 1) && ft_is_specific(format, i))
	{
		if (format[*i] == '0')
			flag->zero = 1;
		if (format[*i] == '-')
			flag->left = 1;
		if (format[*i] == '*' && ((flag->width = va_arg(args, int)) < 0))
		{
			flag->width *= -1;
			flag->left = 1;
		}
		if (ft_isdigit(format[*i]))
			ft_width_digit(format, i, flag);
	}
	if (format[*i] == '.' && (flag->zero = 0) == 0)
		ft_precision(format, i, args, flag);
	if (format[*i] == '%' && (flag->total_print += 1))
	{
		write(1, "%%", 1);
		return(*i + 1);
	}
	return (ft_dispatch_type(format, i, args, flag));
}
