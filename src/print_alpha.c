/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:28:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/22 18:59:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Impression des CHAR
*/

void	print_character(t_flag *flag)
{
	int				nb_oct;
	char			s[flag->width];

	nb_oct = char_or_unicode(flag);
	flag->total_print += nb_oct;
	if (flag->width > nb_oct)
	{
		flag->width -= nb_oct;
		ft_memset((char *)s, ' ', flag->width);
		flag->total_print += flag->width;
	}
	if (flag->left == 1)
	{
		convert_unicode(flag, nb_oct);
		if (flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, flag->width);
	}
	else
	{
		if (flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, flag->width);
		convert_unicode(flag, nb_oct);
	}
}
/*
** Impression des W CHAR *
*/

void	print_string_unicode(t_flag *flag)
{
	int		i;
	int 	len;
	int 	nb;
	wchar_t *ls;
	int		total_nb;

	ls = flag->ls;
	i = 0;
	len = 0;
	total_nb = 0;

	while (ls[i])
	{
		flag->uarg = ls[i];
			len += char_or_unicode(flag);
		if (flag->precision < len && flag->precision != -1)
		{
			len -= char_or_unicode(flag);
			if (len > 0 && flag->precision - len > flag->width)
				flag->width += (flag->precision - len);
			break;
		}
		i++;
	}
	i = 0;
	if (flag->left == 1)
	{
		while (ls[i])
		{
			flag->uarg = ls[i];
			nb = char_or_unicode(flag);
			total_nb += nb;
			if ((total_nb) <= len)
			{
				convert_unicode(flag, nb);
				flag->total_print += nb;
			}
			i++;
		}
		while (flag->width > len)
		{
			ft_putchar_fd(' ', 1);
			flag->width--;
			flag->total_print += 1;
		}
	}
	else
	{
		while (flag->width > len)
		{
			ft_putchar_fd(' ', 1);
			flag->width--;;
			flag->total_print += 1;
		}
		while (ls[i])
		{
			flag->uarg = ls[i];
			nb = char_or_unicode(flag);
			total_nb += nb;
			if ((total_nb) <= len)
			{
				convert_unicode(flag, nb);
				flag->total_print += nb;
			}
			i++;
		}
	}
	//flag->total_print += len;
}

/*
** Impression des CHAR *
*/

void	print_string(t_flag *flag)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	if (flag->ls != NULL)
		print_string_unicode(flag);
	else
	{
		if (!flag->s)
		{
			//if (flag->precision < 6 && flag->precision != -1)
			//	s = "";
			//else
				flag->s = "(null)";
		}
		len = ft_strlen(flag->s);
		if (flag->precision < len && flag->precision != -1)
			len = flag->precision;
		flag->s = ft_substr(flag->s, 0, len);
		if (flag->left == 1)
			f = &print_after;
		else
			f = &print_before;
		if (flag->width > len)
			flag->s = f(flag->width, ' ', flag->s, &len);
		ft_putstr_fd(flag->s, 1);
		flag->total_print += len;
		free(flag->s);
	}
}
