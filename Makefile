# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 20:43:11 by alexfuen          #+#    #+#              #
#    Updated: 2025/10/23 20:43:13 by alexfuen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= ft_printf.c ft_printf_utils.c ft_printf_utils_bis.c
OBJS = $(SRC:.c=.o)
NAME = libftprintf.a
HEADERS = ft_printf.h
LIBFT = ./libft/libft.a
AR = ar
MK = make
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm
CP = cp

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CP) $(LIBFT) $(NAME)
	$(AR) -rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MK) -C ./libft
	
%.o:%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MK) clean -C ./libft
	$(RM) -f $(OBJS) 

fclean : clean
	$(RM) -f $(LIBFT)
	$(RM) -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
