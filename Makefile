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

NAME =	fdf
SRC = main.c get_next_line.c create_image.c write_line.c create_3dmap.c \
get_color.c revers_coordinate.c hook.c check.c check_z.c
LIB=libft/libft.a
HEADER=fdf.h
FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-c -Wall -Wextra -Werror
OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	make -C libft/
	gcc -o $(NAME) $(OBJECTS) -L. $(LIB) -lmlx $(FRAMEWORKS)

%.o:%.c $(HEADER)
	gcc $(FLAGS) -o $@ $<

clean:
	make -C libft/ clean
	rm -Rf $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all