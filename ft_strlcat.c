/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:02:34 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/13 17:06:44 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	h[3];

	h[0] = ft_strlen(src);
	h[1] = ft_strlen(dst);
	i = 0;
	j = h[1];
	if (dstsize == 0 || dstsize <= h[1])
		return (h[0] + dstsize);
	while (src[i] && i < dstsize - j - 1)
	{
		dst[h[1]] = src[i];
		h[1]++;
		i++;
	}
	dst[h[1]] = '\0';
	return (h[0] + j);
}
