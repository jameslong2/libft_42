#include <stdlib.h>
long	power(int num, int power)
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

void	recursive(char *tmp, int nb, long div)
{
	if (nb < 0)
	{
		*tmp++ = '-';
		if(nb == -2147483648)
		{
			*tmp++ = '2';
			nb += 2000000000;
			div /= 10;
		}
		nb *= -1;
	}
	if (div != 0)
	{
	    *tmp = ((long)nb / div) % 10 + '0';
		recursive(tmp + 1, nb % div, div / 10);
	}
	else
	{
		*tmp = '\0';
	}
}

char	*ft_itoa(int n)
{
	int	temp;
	int	counter;
	int	extra;
	char *tmp;

	temp = n;
	counter = 0;
	extra = 0;
	if (temp == -2147483648)
        temp++;
	if (temp <= 0)
	{
		temp *= -1;
		extra+=2;
	}
	while (temp >= 1)
	{
		temp /= 10;
		counter++;
	}
	tmp = (char *)malloc((counter + extra + 1) * sizeof(char));
	if (tmp == 0)
		return (0);
	if (n != 0)
		recursive(tmp, n, power(10,counter - 1));
	else
	{
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	return (tmp);
}
