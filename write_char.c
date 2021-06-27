#include "ft_printf.h"

int	write_char(t_syntax *holder, va_list ptr)
{
	char	c;
	int		len;

	len = 1;
	if (holder->type == 'c')
		c = va_arg(ptr, int);
	if (holder->flg != '-' && holder->type == 'c')
		putchar_times(' ', holder->wid - 1);
	if (holder->flg == -1 && holder->type == '%')
		putchar_times(' ', holder->wid - 1);
	if (holder->flg == 0 && holder->type == '%')
		putchar_times('0', holder->wid - 1);
	if (holder->type == 'c')
		write(1, &c, 1);
	if (holder->type == '%')
		write(1, "%%", 1);
	if (holder->flg == '-')
		putchar_times(' ', holder->wid - 1);
	if (holder->wid > 1)
		len = holder->wid;
	return (len);
}
