/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <jaucarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:20 by jaucarri          #+#    #+#             */
/*   Updated: 2023/09/19 16:20:58 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	powernbr(int num, int power)
{
	long	po;
	long	i;

	po = 1;
	i = 0;
	while (i < power)
	{
		po = po * num;
		i++;
	}
	return (po);
}

void	recursivenbr(int nb, long div, int fd)
{
	char	tmp;

	if (nb < 0)
	{
		write(fd, "-", 1);
		if (nb == -2147483648)
		{
			write(fd, "2", 1);
			nb += 2000000000;
			div /= 10;
		}
		nb *= -1;
	}
	if (div != 0)
	{
		tmp = ((long)nb / div) % 10 + '0';
		write(fd, &tmp, 1);
		recursivenbr(nb % div, div / 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;
	int	counter;

	temp = n;
	counter = 0;
	if (temp == -2147483648)
		temp++;
	if (temp <= 0)
		temp *= -1;
	while (temp >= 1)
	{
		temp /= 10;
		counter++;
	}
	recursivenbr(n, powernbr(10, counter - 1), fd);
}
