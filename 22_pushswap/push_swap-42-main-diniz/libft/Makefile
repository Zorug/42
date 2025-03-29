# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:56:00 by abessa-m          #+#    #+#              #
#    Updated: 2025/01/28 16:28:13 by abessa-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../libft.a
LIBFT	= libft/libft.a
########################################################### Compiler and Flags #
CC		= cc 
CFLAGS	= -Wall -Wextra -Werror -g 
####################################################################### Remove #
RM		= rm -f
###################################################################### Arquive #
AR		= ar rcs
###################################################################### Sources #
SRCS	=	\
			ft_printf/ft_printf.c \
			ft_printf/ft_printf-conversion-precision.c \
			ft_printf/ft_printf-decimal.c \
			ft_printf/ft_printf-hex.c \
			ft_printf/ft_printf-conversion.c \
			ft_printf/ft_printf-conversion-numeric.c \
			ft_printf/ft_printf-conversion-sign.c \
			\
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c
OBJS	= $(SRCS:.c=.o)
###################################################################### Headers #
HEADERS	= libft.h
############################################################ Mandatory Targets #
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cd libft \
	&& ar x libft.a \
	&& cd .. \
	&& $(AR) $(NAME) libft/*.o $(OBJS) \
	&& echo "$(PURPLE)Library built: $(NAME)$(COR)"

%.o:	%.c 
	@$(CC) $(CFLAGS) -c $< -o $@ 
#	&& echo "$(GRAY)compiled: $(COR) $<: "

clean:
	@make --no-print-directory -C libft clean \
	&& $(RM) $(OBJS) 

fclean: clean
	@make --no-print-directory -C libft fclean \
	&& $(RM) $(NAME) 

re: fclean all
	@echo "$(GRAY)redone$(COR)"

.PHONY: all clean fclean re

################################################################## Build libft #
$(LIBFT):
	@make --no-print-directory -C libft \
	&& echo "$(PURPLE)Library built: $(LIBFT)$(COR)" 
###################################################################### Colors  #
# COlor Remove
COR = \033[0m
# purple
PURPLE = \033[1;35m
# gray
GRAY = \033[1;90m
# yellow
YELLOW = \033[1;93m
