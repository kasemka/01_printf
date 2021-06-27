#include "ft_printf.h"

static int	pos_int(unsigned int num, t_syntax *hld, int space, int len)
{
	int	zero;

	zero = 0;
	if (hld->prc > len)
		zero = hld->prc - len;
	else if (hld->prc <= len && hld->prc >= 0)
		zero = 0;
	else if (hld->flg == 0 && hld->prc < 0 && hld->wid > len)
		zero = hld->wid - len;
	if (hld->wid > max(hld->prc, len))
		space = hld->wid - zero - len;
	if (hld->flg != '-')
		putchar_times(' ', space);
	putchar_times('0', zero);
	putnum_unsign(num, 1);
	if (hld->flg == '-')
		putchar_times(' ', space);
	len = len + zero + space;
	return (len);
}

static int	zero_int(t_syntax *hld)
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

int	write_unsign(t_syntax *hld, va_list ptr)
{
	int				len;
	unsigned int	num;
	int				space;

	space = 0;
	num = va_arg(ptr, unsigned int);
	len = uns_n(num);
	if (num > 0)
		len = pos_int(num, hld, space, len);
	else
		len = zero_int(hld);
	return (len);
}
