/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:47:02 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/23 14:32:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	lecture de la chaine *format.
**	Recherche du %
**	Print la partie de la chaine en s'arretant au %
**	Envoie pour verification, recuperation, conversion et print de l'argument.
*/

t_flag	*g_flag;

int		ft_printf(const char *restrict format, ...)
{
	unsigned int	len;
	va_list			args;

	va_start(args, format);
	if (!*format || !(g_flag = struct_malloc()))
		return (-1);
	while (format)
	{
		len = ft_strchr_i(format, '%');
		ft_putstr_fd_maxlen((char *)format, 1, len);
		g_flag->total_print += len;
		if (format[len] == '\0')
			return (struct_clean_end());
		if (format[len] == '%')
		{
			len++;
			len += flag_collect(format + len, args);
			struct_init();
		}
		format += len;
	}
	va_end(args);
	return (struct_clean_end());
}
