/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:06:04 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/16 14:02:21 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i[2];

	i[0] = 0;
	if (haystack == 0 || needle == 0)
		*(int *)haystack = 0;
	if (len < (size_t)ft_strlen(needle))
		return (0);
	while (*(haystack + i[0]) && i[0] < len)
	{
		i[1] = 0;
		while (*(haystack + i[0]) && *(needle + i[1]))
		{
			if (*(haystack + i[0] + i[1]) != *(needle + i[1])
				|| i[1] + i[0] >= (size_t)ft_strlen(haystack)
				- ((size_t)ft_strlen(haystack) - len))
				break ;
			if (*(needle + (i[1]++) + 1) == 0)
				return ((char *)(haystack + i[0]));
		}
		i[0]++;
	}
	if (*(needle + 0) == 0)
		return ((char *)(haystack));
	else
		return (0);
}
