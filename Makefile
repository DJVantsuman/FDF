# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsuman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 18:22:44 by itsuman           #+#    #+#              #
#    Updated: 2017/05/12 21:46:23 by itsuman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FdF
FLAGS = -Wall -Werror -Wextra
SRC = main.c get_next_line.c create_image.c write_line.c create_3dmap.c \
get_color.c revers_coordinate.c
OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OSRC) libft/libft.a
	make clean

%.o: %.c
	gcc -g $(FLAGS) -c -o $@ $<

clean:
	make clean -C libft
	rm -f $(OSRC)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all