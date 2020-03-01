/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:50:04 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/13 10:13:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** retourne un pointeur sur une nouvelle chaîne de caractères qui est dupliquée
** depuis s. La mémoire occupée par cette nouvelle chaîne est obtenue
** en appelant malloc.
*/

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*dst;

	i = 0;
	while (s[i])
		++i;
	if (!(dst = malloc(sizeof(*s) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}
