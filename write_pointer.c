#include "ft_printf.h"

int	write_pointer(t_syntax *hld, va_list ptr)
{
	unsigned long	num;
	int				sym_n;
	int				space;

	space = 0;
	num = va_arg(ptr, unsigned long);
	if (num == 0 && hld->prc == 0)
		sym_n = 2;
	else
		sym_n = hex_n(num) + 2;
	if (hld->wid > sym_n)
		space = hld->wid - sym_n;
	if (hld->flg != '-')
		putchar_times(' ', space);
	write(1, "0x", 2);
	put_hex(num, hld);
	if (hld->flg == '-')
		putchar_times(' ', space);
	return (sym_n + space);
}
