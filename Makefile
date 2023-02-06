# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:57:37 by alsaez            #+#    #+#              #
#    Updated: 2023/02/06 18:04:00 by alsaez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = libft.h

SRC = ft_atoi.c \
      	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_split.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

.c.o:	gcc ${FLAGS} -c $< -o ${NAME}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}
	echo "${NAME} created"
	ranlib ${NAME}
	echo "${NAME} indexed"

clean:
	rm -f ${OBJ}
	echo "Objects deleted"

fclean: clean
	rm -f ${NAME}
	echo "${NAME} deleted"

re: fclean all

