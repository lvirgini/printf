/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:28:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/23 12:26:13 by lvirgini         ###   ########.fr       */
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

void		print_ls(wchar_t *ls, int len)
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
			g_flag->total_print += convert_unicode(ls[i], oct);
		i++;
	}
}
/*
** Impression des CHAR
*/

void	print_character(void)
{
	int				nb_oct;
	char			s[g_flag->width];

	nb_oct = char_or_unicode(g_flag->uarg);
	g_flag->total_print += nb_oct;
	if (g_flag->width > nb_oct)
	{
		g_flag->width -= nb_oct;
		ft_memset((char *)s, ' ', g_flag->width);
		g_flag->total_print += g_flag->width;
	}
	if (g_flag->left == 1)
	{
		convert_unicode(g_flag->uarg, nb_oct);
		if (g_flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
	}
	else
	{
		if (g_flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
		convert_unicode(g_flag->uarg, nb_oct);
	}
}
/*
** Impression des W CHAR *
*/

void	print_string_unicode(void)
{
	int		i;
	int 	len;
	wchar_t *ls;

	ls = g_flag->ls;
	i = 0;
	len = 0;
	while (ls[i])
	{
		len += char_or_unicode(ls[i]);
		if (g_flag->precision < len && g_flag->precision != -1)
		{
			len -= char_or_unicode(ls[i]);
			if (len > 0 && g_flag->precision - len > g_flag->width)
				g_flag->width += (g_flag->precision - len);
			break;
		}
		i++;
	}
	if (g_flag->left == 1)
	{
		print_ls(ls, len);
		if((g_flag->width - len) > 0)
			g_flag->total_print += print_space(g_flag->width - len);
	}
	else
	{
		if((g_flag->width - len) > 0)
			g_flag->total_print += print_space(g_flag->width - len);
		print_ls(ls, len);
	}
}

/*
** Impression des CHAR *
*/

void	print_string(void)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	if (g_flag->ls != NULL)
		print_string_unicode();
	else
	{
		if (!g_flag->s)
		{
			//if (g_flag->precision < 6 && g_flag->precision != -1)
			//	s = "";
			//else
				g_flag->s = "(null)";
		}
		len = ft_strlen(g_flag->s);
		if (g_flag->precision < len && g_flag->precision != -1)
			len = g_flag->precision;
		g_flag->s = ft_substr(g_flag->s, 0, len);
		if (g_flag->left == 1)
			f = &print_after;
		else
			f = &print_before;
		if (g_flag->width > len)
			g_flag->s = f(g_flag->width, ' ', g_flag->s, &len);
		ft_putstr_fd(g_flag->s, 1);
		g_flag->total_print += len;
		free(g_flag->s);
	}
}
