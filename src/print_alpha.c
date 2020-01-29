/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:28:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/25 19:53:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Impression des CHAR
*/

void	print_character(va_list args, t_flag *flag)
{
	int				len;
	char			*s;
	char			c;
	char			*(*f)(int, char, char *, int *);
	
	
	c = va_arg(args, int);
	s = ft_strdup(&c);
	len = 1;
	if (flag->left == 1)
		f = &print_after;
	else 
		f = &print_before;
	if (flag->width > 1)
		s = f(flag->width, ' ', s, &len);
	ft_putstr_fd_maxlen(s, 1, len);
	flag->total_print += len;
	free(s);
}

/*
** Impression des CHAR *
*/

void	print_string(va_list args, t_flag *flag)
{
	int		len;
	char	*(*f)(int, char, char *, int *);
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		if(flag->precision < 6 && flag->precision != -1)
			s = "";
		else
		s = "(null)";
	}
	len = ft_strlen(s);
	if(flag->precision < len && flag->precision != -1)
		len = flag->precision;
	s = ft_substr(s, 0, len);
	if (flag->left == 1)
		f = &print_after;
	else
		f = &print_before;
	if (flag->width > len)
		s = f(flag->width, ' ', s, &len);
	ft_putstr_fd(s, 1);
	flag->total_print += len;
	free(s);
}
