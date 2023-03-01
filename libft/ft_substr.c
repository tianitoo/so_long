/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:13:05 by marvin            #+#    #+#             */
/*   Updated: 2022/10/26 09:09:19 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	ss = (char *) malloc (sizeof (char) * len + 1);
	if (!ss)
		return (0);
	while (i < len && start < ft_strlen(s) && s[i + start])
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	// system("leaks a.out");
	return (ss);
}

// int main ()
// {
// 	char *str = "i just want this part #############";
// 	size_t size = 22;
// 	char *ret = ft_substr(str, 0, size);
// 	printf("|%s|\n", ret);
// }
