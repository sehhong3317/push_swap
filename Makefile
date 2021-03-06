# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 11:21:01 by sehhong           #+#    #+#              #
#    Updated: 2021/11/05 15:35:36 by sehee            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_DIR = ./srcs/mandatory/
SRCS = $(addprefix $(SRCS_DIR), \
			choose_max_chunk.c choose_min_chunk.c linked_list_functions.c \
			main.c merge.c parse_arguments.c push.c reverse_rotate.c \
			rotate.c sort_fix_4_or_5_numbers.c sort_fix_lt_4_numbers.c \
			sort_skip_lt_4_numbers.c sort.c swap.c \
			)
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./includes/ -I./libft/

LIBFT_DIR = ./libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)libft.a

CHECKER_DIR = ./srcs/bonus/
CHECKER_NAME = checker

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR) all

bonus: $(NAME)
	make -C $(CHECKER_DIR) all
	cp $(CHECKER_DIR)$(CHECKER_NAME) ./$(CHECKER_NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(CHECKER_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER_NAME)		
	make -C $(LIBFT_DIR) fclean
	make -C $(CHECKER_DIR) fclean

re: fclean all 

.PHONY: all bonus clean fclean re
