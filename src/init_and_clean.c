/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:46:35 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/23 14:06:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Malloc la structure complete.
*/

t_flag		*struct_malloc(void)
{
	if (!(g_flag = (t_flag *)malloc(sizeof(*g_flag))))
		return (NULL);
	g_flag->total_print = 0;
	struct_init();
	return (g_flag);
}

/*
** Reinitialise les elements de la structure.
*/

void		struct_init(void)
{
	g_flag->left = 0;
	g_flag->zero = 0;
	g_flag->width = 0;
	g_flag->precision = -1;
	g_flag->specifiers = 0;
	g_flag->arg = 0;
	g_flag->uarg = 0;
	g_flag->s = NULL;
	g_flag->ls = NULL;
	g_flag->arg_error = 0;
}

/*
** Free de la structure et renvoie le total imprimé par printf.
*/

int			struct_clean_end(void)
{
	int total_print;

	total_print = g_flag->total_print;
	free(g_flag);
	return (total_print);
}
