/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:28:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/25 12:45:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Impression des CHAR et WCHAR
*/

void	print_character(void)
{
	int				nb_oct;
	char			s[g_flag->width];

	nb_oct = size_unicode(g_flag->uarg);
	if (g_flag->width >= nb_oct)
	{
		g_flag->width -= nb_oct;
		g_flag->total_print += g_flag->width;
		ft_memset((char *)s, ' ', g_flag->width);
	}
	if (g_flag->left == 1)
	{
		print_unicode(g_flag->uarg, nb_oct);
		if (g_flag->width > nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
	}
	else
	{
		if (g_flag->width >= nb_oct)
			ft_putstr_fd_maxlen(s, 1, g_flag->width);
		print_unicode(g_flag->uarg, nb_oct);
	}
}
