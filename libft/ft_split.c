/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:01:32 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 17:48:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Retourne un tableau de chaine de caractères obtenu en séparant *s à l'aide
** du caractère c, utilisé comme délimiteur.
** le tableau doit être terminé par NULL.
*/

static char		**ft_free(char **tab, unsigned int nb_tab)
{
	while (nb_tab)
	{
		free(tab[nb_tab]);
		--nb_tab;
	}
	free(*tab);
	free(tab);
	return (NULL);
}

static int		ft_count_tab(const char *s, int c)
{
	int		nb_tab;
	int		i;

	nb_tab = 1;
	i = 0;
	while (s[i] == c && s[i])
		++i;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			++nb_tab;
		++i;
	}
	if (s[i - 1] == c)
		--nb_tab;
	return (nb_tab);
}

static char		*ft_super_strcpy(const char *s, int start, int len)
{
	char	*dest;
	int		i;

	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

static char		**ft_split2(char **tab, const char *s, char c, unsigned int i)
{
	unsigned int	word_len;
	unsigned int	nb_tab;

	word_len = 0;
	nb_tab = 0;
	while (s[i] == c)
		++i;
	while (s[i + word_len])
	{
		if (s[i + word_len] == c)
		{
			if (!(tab[nb_tab++] = ft_super_strcpy(s, i, word_len)))
				return (ft_free(tab, --nb_tab));
			while (s[i + word_len] == c && s[i + word_len])
				++word_len;
			i += word_len;
			word_len = 0;
		}
		else
			++word_len;
	}
	if (word_len)
		tab[nb_tab] = ft_super_strcpy(s, i, word_len);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	nb_tab;
	char			**tab;

	nb_tab = 1;
	if (!*s)
	{
		if (!(tab = malloc(sizeof(*tab))))
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	nb_tab = ft_count_tab(s, c);
	if (!(tab = malloc(sizeof(*tab) * (nb_tab + 1))))
		return (NULL);
	if (!(tab = ft_split2(tab, s, c, 0)))
		return (NULL);
	tab[nb_tab] = NULL;
	return (tab);
}
