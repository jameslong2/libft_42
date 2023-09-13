/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:27:48 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/13 20:35:07 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *c);

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	y;

	i = 0;
	y = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			y = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if (y >= 0)
		return ((char *)&s[y]);
	else
		return (0);
}
