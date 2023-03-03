# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 11:25:42 by alsaez            #+#    #+#              #
#    Updated: 2023/03/03 18:21:30 by alsaez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE= ft_printf.h

SRC= ft_printf.c \
	 ft_treatment.c \
     ft_treat_flags.c \
     ft_treat_print2.c \
	 ft_treat_print4.c \
     ft_print_char.c \
     ft_print_flag.c \
	 ft_print_hexa.c \
	 ft_print_int.c \
	 ft_print_ptr.c \
	 ft_print_str.c \
	 ft_print_uint.c

OBJ= ${SRC:.c=.o}

CC= gcc

FLAGS= -Wall -Werror -Wextra

NAME= libftprintf.a

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C ./libft/
	cp libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJ}
	echo "${NAME} created"
	ranlib ${NAME}
	echo "${NAME} indexed"

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	make clean -C ./libft/
	rm -f ${OBJ}
	echo "Objects deleted"

fclean: clean
	make fclean -C ./libft/
	rm -f ${NAME}
	echo "${NAME} deleted"

re: fclean all
	make re -C ./libft/
