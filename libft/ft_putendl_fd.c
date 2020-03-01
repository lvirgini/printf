/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:39:06 by lvirgini          #+#    #+#             */
/*   Updated: 2019/11/12 13:57:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Écrit La chaine de caractères s sur le file
** descriptor donné, suivie d’un retour à la ligne.
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd)
	{
		while (*s)
		{
			write(fd, s, 1);
			++s;
		}
		write(fd, "\n", 1);
	}
}
