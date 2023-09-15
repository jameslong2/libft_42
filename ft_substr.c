/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:28:14 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/15 10:29:41 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *c);

size_t	power(size_t n, size_t l)
{
	size_t r;

	r = 1;

	while (l > 0)
	{
		r = r * n;
		l--;
	}
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = 0;
	sub = 0;
	if ((len == 0 || start > (unsigned int)ft_strlen(s)) && s != 0)
		len = 1;
	else if ((len > (size_t)ft_strlen(s) && start < (unsigned int)ft_strlen(s))
			|| (ft_strlen(s) != 0 && len == 0))
		len = (size_t)ft_strlen(s) + 1;
	sub = (char *)malloc(len);
	if (!sub || sub == 0)
		return (0);
	if (start < (unsigned int)ft_strlen(s))
		while (s[start] != 0 && s[start] && i < len)
			sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
