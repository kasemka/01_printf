#include "ft_printf.h"

int	write_string(t_syntax *hld, va_list ptr)
{
	char	*s;
	int		space;
	int		sym_n;

	s = va_arg(ptr, char *);
	space = 0;
	if (s == NULL)
		s = "(null)";
	sym_n = ft_strlen(s);
	if (hld->prc < sym_n && hld->prc >= 0)
		sym_n = hld->prc;
	if (hld->wid > sym_n)
		space = hld->wid - sym_n;
	if (hld->flg != '-')
		putchar_times(' ', space);
	write(1, s, sym_n);
	if (hld->flg == '-')
		putchar_times(' ', space);
	return (space + sym_n);
}
