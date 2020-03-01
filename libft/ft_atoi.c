/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:33:09 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/13 09:55:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction atoi convertit le début la chaine pointée par *s
** en entier de type int.
*/

static int		ft_is_ok(long int result, int sign)
{
	result *= sign;
	if (result > 2147483647)
		return (-1);
	if (result < -2147483648)
		return (0);
	return ((int)result);
}

int				ft_atoi(const char *s)
{
	int			i;
	int			max;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '\0')
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		++i;
	}
	max = 0;
	while (s[i] >= '0' && s[i] <= '9' && max++ < 13)
	{
		result = result * 10 + (s[i] - '0');
		++i;
	}
	return (ft_is_ok(result, sign));
}
