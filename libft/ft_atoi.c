/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:13:47 by hnait             #+#    #+#             */
/*   Updated: 2022/10/22 20:03:24 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (
		c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
	)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		signe;

	nbr = 0;
	signe = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe *= -1;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str++ - '0');
		if (nbr > INT_MAX && signe == 1)
			return (-1);
		if (-nbr < INT_MIN && signe == -1)
			return (0);
	}
	nbr = nbr * signe;
	return (nbr);
}

int main ()
{
	char *n = "2147483649";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf ("| %d |\n", i1);
	printf ("| %d |\n", i2);
}
