/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:08:27 by hnait             #+#    #+#             */
/*   Updated: 2022/10/22 13:31:23 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dst;
	if (s < d)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}

// int main()
// {
// 	char *src = "this is a good nyancat !|\r|\n";
// 	char dst1[100];
// 	char dst2[100];

// 	printf("________________\n|");
// 	printf("%zu\n", ft_strlen(src));
// 	//printf("%s", ft_memmove(dst1, src, ft_strlen(src)));
// 	printf("\n_____________\n");
// 	printf("%s", memmove(dst2, src, ft_strlen(src)));
// 	printf("\n|________________");

// }
