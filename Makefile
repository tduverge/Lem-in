# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/06 15:23:44 by lotoussa     #+#   ##    ##    #+#        #
#    Updated: 2018/04/25 18:05:36 by tduverge    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = lem-in

CC = gcc

CFLAGS = -Werror -Wextra -Wall

D_SRC = srcs/

D_LIBFT = libft/

HEADER = includes/header.h

SRC1 =	part_1/debug.c \
		part_1/ft_stock.c \
		part_1/ft_get_rooms.c \
		part_1/ft_parsing.c \
		part_1/main.c \
		part_1/errors.c \
		part_1/ft_links.c \
		part_1/links.c \
		part_1/room.c \
		part_2/count_max_path.c \
		part_2/node.c \
		part_2/ft_get_shortest_path.c \
		part_2/second_part.c \
		part_3/print_moves.c \
		part_3/print_sol.c

SRC2 =	libft_files/ft_atoi.c \
		libft_files/ft_bubble_sort.c \
		libft_files/ft_bzero.c \
		libft_files/ft_del.c \
		libft_files/ft_isalnum.c \
		libft_files/ft_isalpha.c \
		libft_files/ft_isascii.c \
		libft_files/ft_isdigit.c \
		libft_files/ft_islower.c \
		libft_files/ft_isprint.c \
		libft_files/ft_isupper.c \
		libft_files/ft_itoa.c \
		libft_files/ft_lstadd.c \
		libft_files/ft_lstdel.c \
		libft_files/ft_lstdelone.c \
		libft_files/ft_lstiter.c \
		libft_files/ft_lstlen.c \
		libft_files/ft_lstmap.c \
		libft_files/ft_lstnew.c \
		libft_files/ft_lstprint_nb.c \
		libft_files/ft_lstpush.c \
		libft_files/ft_memalloc.c \
		libft_files/ft_memccpy.c \
		libft_files/ft_memchr.c \
		libft_files/ft_memcmp.c \
		libft_files/ft_memcpy.c \
		libft_files/ft_memdel.c \
		libft_files/ft_memmove.c \
		libft_files/ft_memset.c \
		libft_files/ft_merge_sort.c \
		libft_files/ft_pow.c \
		libft_files/ft_putchar.c \
		libft_files/ft_putchar_fd.c \
		libft_files/ft_putendl.c \
		libft_files/ft_putendl_fd.c \
		libft_files/ft_putnbr.c \
		libft_files/ft_putnbr_fd.c \
		libft_files/ft_putstr.c \
		libft_files/ft_putstr_fd.c \
		libft_files/ft_strcat.c \
		libft_files/ft_strchr.c \
		libft_files/ft_strclr.c \
		libft_files/ft_strcmp.c \
		libft_files/ft_strcpy.c \
		libft_files/ft_strdel.c \
		libft_files/ft_strdup.c \
		libft_files/ft_strequ.c \
		libft_files/ft_striter.c \
		libft_files/ft_striteri.c \
		libft_files/ft_strjoin.c \
		libft_files/ft_strlcat.c \
		libft_files/ft_strlen.c \
		libft_files/ft_strmap.c \
		libft_files/ft_strmapi.c \
		libft_files/ft_strncat.c \
		libft_files/ft_strncmp.c \
		libft_files/ft_strncpy.c \
		libft_files/ft_strnequ.c \
		libft_files/ft_strnew.c \
		libft_files/ft_strnjoin.c \
		libft_files/ft_strnstr.c \
		libft_files/ft_strrchr.c \
		libft_files/ft_strrev.c \
		libft_files/ft_strsplit.c \
		libft_files/ft_strstr.c \
		libft_files/ft_strsub.c \
		libft_files/ft_strtolower.c \
		libft_files/ft_strtoupper.c \
		libft_files/ft_strtrim.c \
		libft_files/ft_swap.c \
		libft_files/ft_tolower.c \
		libft_files/ft_toupper.c \
		libft_files/get_next_line.c \
		printf/flags.c \
		printf/ft_printf.c \
		printf/pf_applyflags_nb.c \
		printf/pf_applyflags_o.c \
		printf/pf_applyflags_str.c \
		printf/pf_applyflags_x.c \
		printf/pf_base.c \
		printf/pf_c.c \
		printf/pf_d.c \
		printf/pf_litoa_base.c \
		printf/pf_luitoa_base.c \
		printf/pf_p.c \
		printf/pf_percent.c \
		printf/pf_s.c \
		printf/pf_special.c \
		printf/pf_str.c \
		printf/pf_u.c \
		printf/pf_unicode.c \
		printf/pf_upper_c.c \
		printf/pf_upper_s.c

SRC_PRE = $(addprefix $(D_SRC), $(SRC1))

SRC_LIB = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_PRE:.c=.o) $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

./%.o: ./%.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all
