/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:40:07 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/19 08:32:35 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

//char	*ft_strdup(const char *s1);

//char	*ft_strtrim(char const *s1, char *s);

int		strcount(char *s, char c)
{
	int	i;

	i = 1;
	while (*s == c)
		s++;
	if (*s == 0)
		return (-1);
	if (c != '\0')
	{
		while (*s)
		{
			if (*s == c && *(s + 1) != c && *(s + 1) != 0)
				i++;
			s++;
		}
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
	int		i;
	int		j;
	char	*end;
	
	i = strcount((char *)s, c);
	j = 0;
	if (i == 0 && ft_strlen(s) > 0)
		i = 1;
	else if (ft_strlen(s) == 0 || i == -1)
		i = 0;
	tmp = (char **)malloc((size_t)(i + 1) * sizeof(char *));
	if (tmp == 0)
		return (0);
	end = (char *)s;
	while (j < i)
	{
		s = (char const *)strstart(end, c);
		end = strend((char *)s, c);
		tmp[j] = ft_substr(s, 0, (int)(end - s));
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}
