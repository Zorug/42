#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifdef BUFFER_SIZE
# define BUFFER_SIZE 42

# endif

char *get_next_line(int fd);

char *ft_strchr(cons char *str, int c);
char *ft_strjoin(char *s1, char const *s2);
size_t ft_strlen(const char *str);

#endif