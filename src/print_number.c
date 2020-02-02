/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:39:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/02 16:14:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Imprime tous les entiers.
*/

void	print_int(t_flag *flag, char *s)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	if (*s)
	{
		if ((flag->precision == 0 && s[0] == '0'))
			s[0] = '\0';
		len = ft_strlen(s);
		f = &print_before;
		if (s[0] == '-' && len--)
			f = &print_before_sign;
		if (flag->precision > len)
			s = f(flag->precision, '0', s, &len);
		len = ft_strlen(s);
		if (flag->zero && flag->width > len && flag->left == 0)
			s = f(flag->width, '0', s, &len);
		f = &print_before;
		if (flag->left == 1)
			f = &print_after;
		if (flag->width > len)
			s = f(flag->width, ' ', s, &len);
		ft_putstr_fd(s, 1);
		flag->total_print += len;
		free(s);
	}
}

/*
** Imprime les hexadecimaux et les adresses.
*/

void	print_hexa(t_flag *flag, char *s)
{
	int		len;
	char	*(*f)(int, char, char *, int *);

	f = &print_before;
	if (flag->specifiers == 'p' && s)
		f = &print_before_0x;
	if (!s)
		s = ft_strdup("(null)");
	if (flag->precision == 0 && s[0] == '0' && ft_strlen(s) == 1)
		s[0] = '\0';
	len = ft_strlen(s);
	if (flag->precision > len)
		s = f(flag->precision, '0', s, &len);
	len = ft_strlen(s);
	if (flag->zero && flag->width > len && flag->left == 0)
		s = f(flag->width, '0', s, &len);
	f = &print_before;
	if (flag->left == 1)
		f = &print_after;
	if (flag->width > len)
		s = f(flag->width, ' ', s, &len);
	ft_putstr_fd(s, 1);
	flag->total_print += len;
	free(s);
}
