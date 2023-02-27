# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 11:25:42 by alsaez            #+#    #+#              #
#    Updated: 2023/02/22 14:54:43 by alsaez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE= ft_printf.h

SRC= ft_printf.c \
     ft_printf_utils.c

OBJ= ${SRC:.c=.o}

CC= gcc

FLAGS= -Wall -Werror -Wextra

NAME= libftprintf.a

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C libft/
	cp libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJ}
	echo "${NAME} created"
	ranlib ${NAME}
	echo "${NAME} indexed"

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}
	echo "Objects deleted"

fclean: clean
	rm -f ${NAME}
	echo "${NAME} deleted"

re: fclean all
