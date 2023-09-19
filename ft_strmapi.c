/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:15:07 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/19 15:17:38 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*sfinal;

	i = 0;
	while (s[i])
		i++;
	sfinal = (char *)malloc(i + 1);
	if (sfinal == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		sfinal[i] = f(i, s[i]);
		i++;
	}
	sfinal[i] = '\0';
	return (sfinal);
}
