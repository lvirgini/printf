/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:43:58 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/23 13:53:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Imprime la chaine *s sur le fd. au plus max octets.
*/

void	ft_putstr_fd_maxlen(char *s, int fd, unsigned int max)
{
	unsigned int i;

	if (s && fd)
	{
		i = 0;
		while (s[i] && i < max)
			++i;
		write(fd, s, max);;
	}
}

/*
** 	Recherche le caractère (c) dans une chaine de caratere (*s).
** 	Renvoie l'emplacement de la premiere occurence.
*/

int 	ft_strchr_i(const char *s, int a)
{
	unsigned int i;

	i = 0;
	while (s[i] && s[i] != a)
			++i;
	return(i);
}
