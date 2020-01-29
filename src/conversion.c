/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:11:30 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/28 15:33:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convertis le nombre décimal en hexadecimal
** Retourne sous forme char * pour traitement d'impression
*/

char	*convert_hexadecimal(t_flag *flag)
{
	ULL		i;
	int		len;
	char	*result;
	char	*hexa_base;

	len = 0;
	if (flag->specifiers == 'x')
		hexa_base = "0123456789abcdef";
	else
		hexa_base = "0123456789ABCDEF";
	i = flag->uarg;
	while ((i /= 16) > 0)
		++len;
	if(!(result = malloc(sizeof(result) * (++len + 1))))
		return (NULL);
	result[len] = '\0';
	if (flag->uarg == 0)
		result[0] = '0';
	while (flag->uarg)
	{
		result[--len] = hexa_base[flag->uarg % 16];
		flag->uarg = flag->uarg / 16;
	}
	return (result);
}

/*
** Convertis le nombre décimal des adresses en hexadecimal
** Retourne sous forme char * pour traitement d'impression.
*/

char	*convert_adress(t_flag *flag)
{
	ULL		i;
	int		len;
	char	*result;
	char	*hexa_base;

	len = 0;
	hexa_base = "0123456789abcdef";
	i = flag->uarg;
	while ((i /= 16) > 0)
		++len;
	if(len == 0 || !(result = malloc(sizeof(result) * (++len + 3))))
		return (NULL);
	return(NULL);
	len += 2;
	result[len] = '\0';
	while (flag->uarg)
	{
		result[--len] = hexa_base[flag->uarg % 16];
		flag->uarg = flag->uarg / 16;
	}
	result[0] = '0';
	result[1] = 'x';
	return(result);
}
