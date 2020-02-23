# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/23 15:34:22 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS =	-Wall -Wextra -I. -I../libft/

NAME =		a.out

CC =		gcc

LIB =		libft.a

SRC =		ft_printf.c 		\
			ft_printf_utils.c 	\
			init_and_clean.c	\
			type_args.c 		\
			flag_collect.c		\
			dispatch.c			\
			conversion.c 		\
			make_options.c		\
			print_number.c		\
			print_character.c	\
			print_string.c 		\
			unicode.c

TESTALL =	../TEST/test_all.c

OBJ =		${SRC:%.c=%.o}

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
			${CC} ${CFLAGS} ${SRC} ${TESTALL} $(LIB)

debug :		$(OBJ)
			${CC} -g ${CFLAGS} ${SRC} ${TESTALL} $(LIB)

all:		${NAME}

clean:
			rm -f ${OBJ} ${OBJ_BONUS}

fclean:		clean
			rm -f ${NAME} ${NAME_BONUS}

re:			fclean all

re_bonus :	fclean bonus

.PHONY:		all clean fclean re
