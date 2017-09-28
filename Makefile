# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olkovale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 19:35:21 by olkovale          #+#    #+#              #
#    Updated: 2017/09/28 02:21:22 by olkovale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(wildcard srcs/*.c)
SRCS_LIBFT = $(wildcard libft/srcs/*.c)
BINS = $(patsubst srcs/%.c, %.o, $(SRCS))
BINS_LIBFT = $(patsubst libft/srcs/%.c, libft/%.o, $(SRCS_LIBFT))
FLAGS = -g -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

.PHONY: re all clean fclean

%.o : srcs/%.c
	gcc -Iincs -Ilibft/incs $(FLAGS) -c $<

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(BINS)
	ar rc $(NAME) $(BINS) $(BINS_LIBFT)
	ranlib $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(NAME)

re: fclean all
