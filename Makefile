# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onouma <onouma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 17:49:20 by onouma            #+#    #+#              #
#    Updated: 2024/10/13 19:56:26 by onouma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = parsing.c infos.c stack.c main.c \
      utils/cleaner.c utils/conversion.c utils/ft_split.c utils/mem.c utils/print.c utils/string.c \
      moves/push.c moves/rotate_r.c moves/rotate.c moves/swap.c \
	  sort/sort_utils_bis.c sort/sort_utils.c sort/sort.c
all: $(NAME)

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re