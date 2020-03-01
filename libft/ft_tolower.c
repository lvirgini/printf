/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:57:20 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 16:05:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Renvoie le caractere (c) en minuscule s' il est Majuscule.
*/

int		ft_tolower(int c)
{
	return (c >= 65 && c <= 90 ? c + 32 : c);
}