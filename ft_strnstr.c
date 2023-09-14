/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:06:04 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/14 11:13:19 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len < (size_t)ft_strlen(needle))
		return (0);
	while (*(haystack + i) && i < len - 1)
	{
		j = 0;
		while (*(needle + j))
		{
			if (*(haystack + i + j) != *(needle + j))
				break ;
			if (*(needle + j + 1) == 0)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	if (*(needle + 0) == 0)
		return ((char *)(haystack));
	else
		return (0);
}
