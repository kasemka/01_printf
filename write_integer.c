#include "ft_printf.h"

static int	pos_int(int num, t_syntax *holder, int space, int len)
{
	int	zero;

	zero = 0;
	if (holder->prc > len)
		zero = holder->prc - len;
	else if (holder->prc <= len && holder->prc >= 0)
		zero = 0;
	else if (holder->flg == 0 && holder->prc < 0 && holder->wid > len)
		zero = holder->wid - len;
	if (holder->wid > max(holder->prc, len))
		space = holder->wid - zero - len;
	if (holder->flg != '-')
		putchar_times(' ', space);
	putchar_times('0', zero);
	putnum_int(num, 1);
	if (holder->flg == '-')
		putchar_times(' ', space);
	len = len + zero + space;
	return (len);
}

static int	neg_int(int num, t_syntax *holder, int space, int len)
{
	int	zero;

	zero = 0;
	if (holder->prc > len)
		zero = holder->prc - len;
	else if (holder->prc <= len && holder->prc >= 0)
		zero = 0;
	else if (holder->flg == 0 && holder->prc < 0 && holder->wid > len)
		zero = holder->wid - len - 1;
	if (holder->wid > max(holder->prc, len))
		space = holder->wid - zero - len - 1;
	if (holder->flg != '-')
		putchar_times(' ', space);
	write(1, "-", 1);
	putchar_times('0', zero);
	putnum_int(num, 1);
	if (holder->flg == '-')
		putchar_times(' ', space);
	len = len + zero + space + 1;
	return (len);
}

static int	zero_int(t_syntax *holder)
{
	int	len;

	len = 0;
	if (holder->prc == 0 && holder->wid > 0)
	{
		putchar_times(' ', holder->wid);
		return (holder->wid);
	}
	if (holder->prc < 0 && holder->flg == 0 && holder->wid > 0)
		putchar_times('0', holder->wid - 1);
	else if (holder->prc < 0 && holder->flg == -1)
		putchar_times(' ', max(1, holder->wid) - 1);
	if (holder->prc < 0)
		putchar_times('0', 1);
	if (holder->prc < 0 && holder->flg == '-' && holder->wid > 0)
		putchar_times(' ', holder->wid - 1);
	if (holder->prc < 0)
		return (max(1, holder->wid));
	if (holder->prc > 0 && holder->flg != '-' && holder->wid > 0)
		putchar_times(' ', max(holder->wid, holder->prc) - holder->prc);
	if (holder->prc > 0)
		putchar_times('0', holder->prc);
	if (holder->prc > 0 && holder->flg == '-')
		putchar_times(' ', max(holder->wid, holder->prc) - holder->prc);
	return (max(holder->wid, holder->prc));
}

int	write_integer(t_syntax *holder, va_list ptr)
{
	int	len;
	int	num;
	int	space;

	space = 0;
	num = va_arg(ptr, int);
	len = fig_n(num);
	if (num > 0)
		len = pos_int(num, holder, space, len);
	else if (num < 0)
		len = neg_int(num, holder, space, len);
	else
		len = zero_int(holder);
	return (len);
}
