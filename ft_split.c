/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:40:07 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/18 18:24:54 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strtrim(char const *s1, char *s);

int		strcount(char *s, char c)
{
	int	i;

	i = 1;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != 0)
			i++;
		s++;
	}
	return (i);
}

char	*strend(char *s, char c)
{
	while (*s != c && *s)
		s++;
	return (s);
}

char	*strstart(char *s, char c)
{
	while (*s == c && *s)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		i[2];
	char	*mod;
	char	*end;

	mod = ft_strtrim(s, &c);
	if (c == '\0' && ft_strchr(mod, c) == 0)
		i[0] = 1;
	else
		i[0] = strcount(mod, c);
	i[1] = 0;
	tmp = (char **)malloc(i[0] * sizeof(char *));
	if (tmp == 0)
		return (0);
	end = mod;
	while (i[1] < i[0])
	{
		mod = strstart(end, c);
		end = strend(mod, c);
		if (i[0] == 1)
			tmp[i[1]++] = ft_substr(mod, 0, ft_strlen(mod));
		else
			tmp[i[1]++] = ft_substr(mod, 0, (size_t)(end - mod) + 1);
		if (tmp[i[1] - 1] == 0)
			return (0);
	}
	free(mod);
	return (tmp);
}
