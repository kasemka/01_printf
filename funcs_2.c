#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_strlen(const char *s)
{
	const char	*ps;

	ps = s;
	while (*ps != '\0')
		ps++;
	return (ps - s);
}

char	*ft_strchr(const char *s, int c)
{
	char	sm;

	sm = (char)c;
	while (*s)
	{
		if (*s == sm)
			return ((char *)s);
		s++;
	}
	if (sm == '\0')
		return ((char *)s);
	return (NULL);
}

void	putchar_times(char c, int times)
{
	while (times > 0)
	{
		write(1, &c, 1);
		times--;
	}
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;
	unsigned long long	len;

	sign = 1;
	num = 0;
	len = 9223372036854775807;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (num >= len && sign == 1)
			return (-1);
		else if (num > len && sign == -1)
			return (0);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
