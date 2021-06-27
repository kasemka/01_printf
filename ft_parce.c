#include "ft_printf.h"

static void	struct_init(struct s_syntax *holder)
{
	holder -> flg = -1;
	holder -> wid = -1;
	holder -> prc = -1;
	holder -> type = 0;
}

static const char	*prec_def(t_syntax *holder, const char *format, va_list ptr)
{
	char	*types;

	types = "cspdiuxX%%";
	while (ft_strchr(types, *format) == NULL)
		format++;
	while (ft_strchr(".", *format) == NULL)
		format--;
	format++;
	if (*format >= 48 && *format <= 57)
	{
		holder->prc = ft_atoi(format);
		while (*format >= 48 && *format <= 57)
			format++;
		format--;
	}
	else if (*format == '*')
		holder->prc = va_arg(ptr, int);
	else
	{
		holder->prc = 0;
		format--;
	}
	return (format);
}

static const char	*wid_def(t_syntax *holder, const char *format, va_list ptr)
{
	if (*format >= 48 && *format <= 57)
	{
		holder->wid = ft_atoi(format);
		while (*format >= 48 && *format <= 57)
			format++;
		format--;
	}
	if (*format == '*')
		holder->wid = va_arg(ptr, int);
	if (holder->wid < 0)
	{
		holder->wid = 0 - holder->wid;
		holder->flg = '-';
	}
	return (format);
}

static const char	*flag_def(t_syntax *holder, const char *format)
{
	if (*format == '-')
		holder->flg = *format;
	else if (holder->flg != '-')
		holder->flg = 0;
	return (format);
}

const char	*ft_parce(t_syntax *holder, const char *format, va_list ptr)
{
	char	*types;
	char	*flg;

	types = "cspdiuxX%%";
	flg = "-0.*";
	format++;
	struct_init(holder);
	while (ft_strchr(flg, *format) != NULL || ft_strchr(types, *format) != NULL
		|| (*format >= 49 && *format <= 57) || *format == '*')
	{
		if (ft_strchr(types, *format) != NULL)
		{
			holder->type = *format;
			break ;
		}
		else if (*format == '-' || *format == '0')
			format = flag_def(holder, format);
		else if (*format == '.')
			format = prec_def(holder, format, ptr);
		else if ((*format >= 48 && *format <= 57) || *format == '*')
			format = wid_def(holder, format, ptr);
		format++;
	}
	return (format);
}
