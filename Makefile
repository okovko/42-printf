# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olkovale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 19:35:21 by olkovale          #+#    #+#              #
#    Updated: 2017/09/23 21:33:18 by olkovale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(wildcard srcs/*.c)
BINS = $(patsubst srcs/%.c, %.o, $(SRCS))
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
	ar rc $(NAME) $(BINS) $(LIBFT)
	ranlib $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(NAME)

re: fclean all
