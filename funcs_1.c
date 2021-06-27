#include "ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	fig_n(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++ ;
	}
	return (i);
}

int	uns_n(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++ ;
	}
	return (i);
}

int	hex_n(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16 > 0)
	{
		n = n / 16;
		i++ ;
	}
	return (i);
}

void	put_hex(unsigned long n, t_syntax *hld)
{
	char			nums[17];
	int				i;
	unsigned long	num;

	i = 0;
	num = n;
	while (num > 0)
	{
		if (num % 16 < 10)
			nums[i] = (num % 16) + 48;
		else if (num % 16 >= 10 && hld->type != 'X')
			nums[i] = (num % 16) + 87;
		else if (num % 16 >= 10 && hld->type == 'X')
			nums[i] = (num % 16) + 55;
		i++;
		num = num / 16;
	}
	if (n == 0 && hld->prc != 0)
		write(1, "0", 1);
	i--;
	while (i >= 0)
	{
		write(1, &nums[i], 1);
		i--;
	}
}
