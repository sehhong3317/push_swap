# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 11:21:01 by sehhong           #+#    #+#              #
#    Updated: 2021/10/07 23:49:46 by sehee            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_DIR = ./srcs/mandatory/
SRCS = $(wildcard ./srcs/mandatory/*.c)
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./includes/ -I./libft/

LIBFT_DIR = ./libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -g3 -fsanitize=address -o $@ -c $<

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -g3 -fsanitize=address -L$(LIBFT_DIR) -l$(LIBFT_NAME) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	$(RM) $(OBJS) 
	make -C $(LIBFT_DIR) clean 

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all 

.PHONY: all clean fclean re
