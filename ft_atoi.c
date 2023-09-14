/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:24:16 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/14 14:04:53 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	power(int n, int e)
{
	int	f;

	f = 1;
	while (e > 0)
	{
		f = f * n;
		e--;
	}
	return (f);
}

int	numlen(const char *n)
{
	int	i;

	i = 0;
	while (*(n + i) >= '0' && *(n + i) <= '9')
		i++;
	return (i);
}

int	recursive(int div, const char *num)
{
	if (div > 1)
	{
		return ((*(num) - '0') * div + recursive(div / 10, num + 1));
	}
	else
	{
		return (*(num) - '0');
	}
}

const char	*skip(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int	result;

	str = skip(str);
	if (*str == '-' && numlen(str + 1) != 0)
	{
		while (*(str + 1) == '0' && numlen(str + 1) - 1 > 0)
			str++;
		result = -recursive(power(10, numlen(str + 1) - 1), str + 1);
	}
	else if (*str == '+' && numlen(str + 1) != 0)
	{
		while (*(str + 1) == '0' && numlen(str + 1) > 0)
			str++;
		result = recursive(power(10, numlen(str + 1) - 1), str + 1);
	}
	else if (*str >= '0' && *str <= '9')
	{
		while (*(str) == '0' && numlen(str) - 1 > 0)
			str++;
		result = recursive(power(10, numlen(str) - 1), str);
	}
	else
		result = 0;
	return (result);
}
