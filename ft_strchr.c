/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:11:21 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/13 20:36:16 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		if (*(s + i++) == (char)c)
			return ((char *)(s + i - 1));
	if (s[i] == (char)c)
		return ((char *)(s + i));
	else
		return (0);
}
