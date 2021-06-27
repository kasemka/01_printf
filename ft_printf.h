#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

struct s_syntax
{
	int		flg;
	int		wid;
	int		prc;
	char	type;
};

typedef struct s_syntax	t_syntax;

int			ft_printf(const char *format, ...);
const char	*ft_parce(t_syntax *placeholder, const char *format, va_list ptr);
int			ft_write(t_syntax *placeholder, va_list ptr);
int			write_integer(t_syntax *placeholder, va_list ptr);
int			write_char(t_syntax *holder, va_list ptr);
int			write_string(t_syntax *holder, va_list ptr);
int			write_unsign(t_syntax *holder, va_list ptr);
int			write_pointer(t_syntax *holder, va_list ptr);
int			write_hex(t_syntax *holder, va_list ptr);
int			max(int a, int b);
int			fig_n(int n);
int			uns_n(unsigned int n);
int			hex_n(unsigned long n);
void		put_hex(unsigned long n, t_syntax *hld);
void		ft_putchar_fd(char c, int fd);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
void		putchar_times(char c, int times);
int			ft_atoi(const char *str);
void		putnum_int(int n, int fd);
void		putnum_unsign(unsigned int n, int fd);

#endif