/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:12:08 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/27 12:53:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** recherche du type d'argument, et l'envoie pour son impression.
*/

int		type_dispatch(const char *format, int i, va_list args)
{
	i = type_size(format, i, args);
	if (g_flag->arg_error && (g_flag->total_print += 1) && (write(1, "%%", 1)))
		return (1);
	if (format[i] == '%' && (g_flag->uarg = '%') == '%')
		print_percent();
	g_flag->zero = g_flag->precision >= 0 ? 0 : g_flag->zero;
	if (format[i] == 'c')
	{
		if (format[i - 1] == 'l')
			print_wchar(size_unicode(g_flag->uarg));
		print_character();
	}
	else if (format[i] == 's')
		print_string();
	else if (format[i] == 'p')
		print_hexa((convert_adress(format[i - 1])));
	else if ((format[i] == 'd' || format[i] == 'i'))
		print_int(ft_lltoa(g_flag->arg));
	else if (format[i] == 'u')
		print_int(ft_ulltoa(g_flag->uarg));
	else if (format[i] == 'x' || format[i] == 'X')
		print_hexa((convert_hexadecimal()));
	return (i + 1);
}
