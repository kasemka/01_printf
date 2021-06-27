#include "ft_printf.h"

int	ft_write(t_syntax *hld, va_list ptr)
{
	int	len;

	len = 0;
	if (hld->type == 'i' || hld-> type == 'd')
		len = write_integer(hld, ptr);
	else if (hld->type == 'c' || hld->type == '%')
		len = write_char(hld, ptr);
	else if (hld->type == 's')
		len = write_string(hld, ptr);
	else if (hld->type == 'u')
		len = write_unsign(hld, ptr);
	else if (hld->type == 'p')
		len = write_pointer(hld, ptr);
	else if (hld->type == 'x' || hld->type == 'X')
		len = write_hex(hld, ptr);
	return (len);
}
