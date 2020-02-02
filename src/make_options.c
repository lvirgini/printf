/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:23:35 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/02 16:51:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Ecrit avant *s le caractere (c)
** Pour les 0x des adresses.
*/

char	*print_before_0x(int max, char c, char *s, int *len)
{
	char *tmp;

	max -= *len;
	*len += 2;
	if ((tmp = malloc(sizeof(*tmp) * (max + *len + 1))))
	{
		tmp[0] = s[0];
		tmp[1] = s[1];
		ft_memset(tmp + 2, c, max);
		ft_memmove(tmp + max + 2, s + 2, *len);
		*len += max;
		tmp[*len] = '\0';
	}
	free(s);
	*len -= 2;
	return (tmp);
}

/*
** Ecrit avant *s le caractere (c)
** Pour les entiers négatifs, max+1 car le signe n'est pas compris.
*/

char	*print_before_sign(int max, char c, char *s, int *len)
{
	char *tmp;

	max -= *len;
	*len += 1;
	if ((tmp = malloc(sizeof(*tmp) * (max + *len + 1))))
	{
		tmp[0] = s[0];
		ft_memset(tmp + 1, c, max);
		ft_memmove(tmp + max + 1, s + 1, *len);
		*len += max;
		tmp[*len] = '\0';
	}
	free(s);
	*len -= 1;
	return (tmp);
}

/*
** Ecrit avant *s le caractere (c)
*/

char	*print_before(int max, char c, char *s, int *len)
{
	char *tmp;

	max -= *len;
	if ((tmp = malloc(sizeof(*tmp) * (max + *len + 1))))
	{
		ft_memset(tmp, c, max);
		ft_memmove(tmp + max, s, *len);
		*len += max;
		tmp[*len] = '\0';
	}
	free(s);
	return (tmp);
}

/*
** Ecrit après *s le caractere (c)
*/

char	*print_after(int max, char c, char *s, int *len)
{
	char *tmp;

	max -= *len;
	if ((tmp = malloc(sizeof(*tmp) * (max + *len + 1))))
	{
		ft_memmove(tmp, s, *len);
		ft_memset(tmp + *len, c, max);
		*len += max;
		tmp[*len] = '\0';
	}
	free(s);
	return (tmp);
}
