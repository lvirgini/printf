/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:28:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/22 20:26:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
*/

int		print_space(unsigned int len)
{
	char	s[len];
	ft_memset((char *)s, ' ', len);
	ft_putstr_fd_maxlen(s, 1, len);
	return(len);
}

void		print_ls(t_flag *flag, wchar_t *ls, int len)
{
	int 	i;
	int 	oct;
	int		total_oct;

	i = 0;
	total_oct = 0;
	while (ls[i])
	{
		oct = char_or_unicode(ls[i]);
		if ((total_oct += oct) <= len)
			flag->total_print += convert_unicode(ls[i], oct);
		i++;
	}
}
/*
** Impression des CHAR
*/

void	print_character(t_flag *flag)
{
	int				nb_oct;
	char			s[flag->width];

	nb_oct = char_or_unicode(flag->uarg);
	flag->total_print += nb_oct;
	if (flag->width > nb_oct)
	{
		flag->width -= nb_oct;
		ft_memset((char *)s, ' ', flag->width);
		flag->total_print += flag->width;
	}
	if (flag->left == 1)
	{
		convert_unicode(flag->uarg, nb_oct);
		if (flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, flag->width);
	}
	else
	{
		if (flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, flag->width);
		convert_unicode(flag->uarg, nb_oct);
	}
}
/*
** Impression des W CHAR *
*/

void	print_string_unicode(t_flag *flag)
{
	int		i;
	int 	len;
	wchar_t *ls;

	ls = flag->ls;
	i = 0;
	len = 0;
	while (ls[i])
	{
		len += char_or_unicode(ls[i]);
		if (flag->precision < len && flag->precision != -1)
		{
			len -= char_or_unicode(ls[i]);
			if (len > 0 && flag->precision - len > flag->width)
				flag->width += (flag->precision - len);
			break;
		}
		i++;
	}
	if (flag->left == 1)
	{
		print_ls(flag, ls, len);
		if((flag->width - len) > 0)
			flag->total_print += print_space(flag->width - len);
	}
	else
	{
		if((flag->width - len) > 0)
			flag->total_print += print_space(flag->width - len);
		print_ls(flag, ls, len);
	}
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
