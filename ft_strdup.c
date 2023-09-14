/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:38:54 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/14 17:43:53 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*re;
	int		i;

	i = 0;
	re = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (re == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		re[i] = s1[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
