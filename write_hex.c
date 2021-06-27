#include "ft_printf.h"

static int	zero_hex(t_syntax *hld)
{
	int	len;

	len = 0;
	if (hld->prc == 0 && hld->wid > 0)
	{
		putchar_times(' ', hld->wid);
		return (hld->wid);
	}
	if (hld->prc < 0 && hld->flg == 0 && hld->wid > 0)
		putchar_times('0', hld->wid - 1);
	if (hld->prc < 0 && hld->flg == -1)
		putchar_times(' ', max(1, hld->wid) - 1);
	if (hld->prc < 0)
		putchar_times('0', 1);
	if (hld->prc < 0 && hld->flg == '-' && hld->wid > 0)
		putchar_times(' ', hld->wid - 1);
	if (hld->prc < 0)
		return (max(1, hld->wid));
	if (hld->prc > 0 && hld->flg != '-' && hld->wid > 0)
		putchar_times(' ', max(hld->wid, hld->prc) - hld->prc);
	if (hld->prc > 0)
		putchar_times('0', hld->prc);
	if (hld->prc > 0 && hld->flg == '-')
		putchar_times(' ', max(hld->wid, hld->prc) - hld->prc);
	return (max(hld->wid, hld->prc));
}

int	write_hex(t_syntax *hld, va_list ptr)
{
	unsigned int	num;
	int				sym_n;
	int				space;
	int				zero;

	zero = 0;
	space = 0;
	num = va_arg(ptr, unsigned int);
	sym_n = hex_n(num);
	if (num == 0)
		return (zero_hex(hld));
	if (hld->prc > sym_n)
		zero = hld->prc - sym_n;
	else if (hld->flg == 0 && hld->prc < 0 && hld->wid > sym_n)
		zero = hld->wid - sym_n;
	if (hld->wid > max(hld->prc, sym_n))
		space = hld->wid - zero - sym_n;
	if (hld->flg != '-')
		putchar_times(' ', space);
	putchar_times('0', zero);
	put_hex(num, hld);
	if (hld->flg == '-')
		putchar_times(' ', space);
	return (sym_n + space + zero);
}
