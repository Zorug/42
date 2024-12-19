#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> ////////////////////////////////////////
# include "libft/libft.h"
# include <stdint.h>

int		ft_putchar(int c);
//int		print_str(char *str);
int		ft_putstr(char *str);

int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

//int		ft_putnbr_base(unsigned int  n, char *base_to);
int			ft_putnbr_base(unsigned long n, char *base_to);
//int		ft_putnbr_base(size_t  n, char *base_to);
//char *putnbr(long n, char *base_to);

#endif