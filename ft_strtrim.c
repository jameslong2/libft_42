/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:21:41 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/17 13:08:33 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = ft_strlen(s1);
	while (ft_strchr(set, (int)s1[i[0]]) != 0)
		i[1] = ++i[0];
	i[0] = i[2];
	while (ft_strchr(set, (int)s1[i[0]]) != 0 && i[0] >= 0)
		i[2] = i[0]--;
	return (ft_substr(s1, (unsigned int)i[1], (size_t)(i[2] - i[1])));
}
