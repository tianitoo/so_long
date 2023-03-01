/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:48:15 by hnait             #+#    #+#             */
/*   Updated: 2022/10/25 11:38:14 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	if (!dst && !dstsize)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] != 0 && i < dstsize - 1 - dstlen)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// int main()
// {

// 	// printf ("return %lu|\n", strlcat("null", NULL, 0));
// 	printf ("return %lu|\n", ft_strlcat("null", NULL, 0));

// }