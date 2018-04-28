# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/26 12:37:20 by tduverge     #+#   ##    ##    #+#        #
#    Updated: 2018/04/28 13:52:24 by tduverge    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in

LIB_RULE = libft

LIBFT = libft/libft.a

HEADER = includes/header.h

CC = gcc

CFLAGS = -Wextra -Wall -Werror

SRC =	srcs/part_1/debug.c \
		srcs/part_1/ft_stock.c \
		srcs/part_1/ft_get_rooms.c \
		srcs/part_1/ft_parsing.c \
		srcs/part_1/main.c \
		srcs/part_1/errors.c \
		srcs/part_1/ft_links.c \
		srcs/part_1/links.c \
		srcs/part_1/room.c \
		srcs/part_2/count_max_path.c \
		srcs/part_2/node.c \
		srcs/part_2/ft_get_shortest_path.c \
		srcs/part_2/second_part.c \
		srcs/part_3/print_moves.c \
		srcs/part_3/print_sol.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re $(LIB_RULE)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "\033[32mLem-in created.\033[0m"

$(LIBFT):
	@make -C libft/

./%.o: ./%.c $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[31mLem-in objects deleted.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mLem-in binary deleted.\033[0m"
	@/bin/rm -f $(LIBFT)
	@echo "\033[31mLibft binary deleted.\033[0m"

re: fclean all
