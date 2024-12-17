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

int		print_ptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
//char *putnbr(long n, char *base_to);

#endif