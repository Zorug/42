# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 13:21:39 by abessa-m          #+#    #+#              #
#    Updated: 2024/10/27 12:05:04 by abessa-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADERS = ../libft.h

SRCS = $(ORIGINALS) $(PERSONALS)
OBJS = $(SRCS:.c=.o)

%.o:	%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

# ADditional functions for personal use
PERSONALS = \
	ad_malloc_cat_free.c \
	ad_trim_str.c 

ORIGINALS = \
	ft_strlen.c ft_memcpy.c ft_memset.c ft_bzero.c \
		ft_memmove.c ft_memcmp.c ft_memchr.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strlcat.c ft_strlcpy.c ft_atoi.c ft_strnstr.c \
		ft_strncmp.c ft_calloc.c ft_strdup.c \
	\
	ft_substr.c ft_strjoin.c  ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c ft_itoa.c \
	\
	ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c \
	ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
	ft_lstiter.c ft_lstmap.c 

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re
