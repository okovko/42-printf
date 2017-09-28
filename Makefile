# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olkovale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 19:35:21 by olkovale          #+#    #+#              #
#    Updated: 2017/09/28 02:35:31 by olkovale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(wildcard srcs/*.c)
SRCS_LIBFT = $(wildcard libft/srcs/*.c)
BINS = $(patsubst srcs/%.c, %.o, $(SRCS))
BINS_LIBFT = $(patsubst libft/srcs/%.c, %.o, $(SRCS_LIBFT))
FLAGS = -g -Wall -Wextra -Werror

.PHONY: re all clean fclean

%.o : libft/srcs/%.c
	gcc -Ilibft/incs $(FLAGS) -c $<

%.o : srcs/%.c
	gcc -Iincs -Ilibft/incs $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(BINS_LIBFT) $(BINS)
	ar rc $(NAME) $(BINS) $(BINS_LIBFT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(BINS_LIBFT)
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
