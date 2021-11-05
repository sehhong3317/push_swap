# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 11:13:06 by sehee             #+#    #+#              #
#    Updated: 2021/11/05 15:37:56 by sehee            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), \
			get_next_line_bonus.c linked_list_functions_bonus.c main_bonus.c \
			parse_arguments_bonus.c push_bonus.c reverse_rotate_bonus.c \
			rotate_bonus.c swap_bonus.c \
			)
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I../../includes -I../../libft/

LIBFT_DIR = ../../libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -o $@ $^

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