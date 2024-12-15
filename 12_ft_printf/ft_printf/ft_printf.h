#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> ////////////////////////////////////////
# include "libft/libft.h"
#include <stdint.h>

int print_char(int c);
int print_str(char *str);

int print_ptr(void *ptr);

char *ft_convert_base(char *nbr, char *base_from, char *base_to);
//char *putnbr(long n, char *base_to);

#endif