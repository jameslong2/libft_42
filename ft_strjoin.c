/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:42:07 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/16 10:45:13 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_memcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_strlen(const char *s);

void	*ft_memset(void *b, int c, size_t len);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i[4];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(i[3] + 1);
	if (tmp == 0)
		return (0);
	else if (ft_strlen(s1) == 0 && ft_strlen(s2) > 0)
		ft_strlcpy(tmp, (const char *)s2, (size_t)ft_strlen(s2) + 1);
	else if (ft_strlen(s2) == 0 && ft_strlen(s1) > 0)
		ft_strlcpy(tmp, (const char *)s1, (size_t)ft_strlen(s1) + 1);
	else
	{
		while (i[0]++ < i[3])
		{
			if (s1[i[1]] != '\0')
				tmp[i[1]] = s1[i[1]];
			tmp[(i[1]++) + ft_strlen(s1)] = s2[i[2]++];
		}
		tmp[i[1] + ft_strlen(s1)] = '\0';
	}
	return (tmp);
}
