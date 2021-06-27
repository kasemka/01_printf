#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		ptr;
	t_syntax	holder;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format != '%' || (*format == '%' && *(format + 1) == '%'))
		{
			write(1, format, 1);
			len++;
			if (*format == '%' && *(format + 1) == '%')
				format++;
		}
		else if (*format == '%' && *(format + 1) != '%')
		{
			format = ft_parce(&holder, format, ptr);
			len = len + ft_write(&holder, ptr);
		}
		format++;
	}
	va_end(ptr);
	return (len);
}
