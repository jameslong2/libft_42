/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:21:41 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/16 12:42:20 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i[5];

	i[0] = 0;
	i[1] = 0;
	i[2] = ft_strlen(set);
	i[3] = 0;
	i[4] = ft_strlen(s1);
	if (ft_strlen(set) > ft_strlen(s1) || (ft_strlen(set) == 0
	&& ft_strlen(s1) > 0))
		return (ft_substr(s1, 0, (size_t)ft_strlen(s1)));
	while (s1[i[0]])
	{
		i[1] = 0;
		while (set[i[1]] && i[0] < ft_strlen(s1) / 2)
		{
			if (s1[i[0] + i[1]] != set[i[1]])
				break;
			if (set[(i[1]++) + 1] == 0)
				i[3] = i[0] - 1;
		}
		i[1] = 0;
		while (set[i[1]] && i[0] > i[2] && i[0] < ft_strlen(s1) / 2)
		{
			if (s1[ft_strlen(s1) - i[0] + i[1]] != set[i[1]])
				break;
			if (set[(i[1]++) + 1] == 0)
				i[4] = ft_strlen(s1) - i[0];
		}
		i[0]++;
	}
	return (ft_substr(s1, (unsigned int)i[3], (size_t)(i[4]-i[3])));
}
