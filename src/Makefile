# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/01/29 15:39:00 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS =	-Wall -Wextra -I. -I../1-libft

NAME =		ft_printf

CC =		gcc
LIB =

SRC =		ft_printf.c 		\
			type_args.c 		\
			collect_flags.c		\
			conversion.c 		\
			ft_printf_utils.c 	\
			make_options.c		\
			print_number.c		\
			print_alpha.c		\
			unicode.c


TESTALL =	../TEST/test_all.c

OBJ =		${SRC:%.c=%.o}
			

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	${CC} ${CFLAGS} ${SRC} ${TESTALL} libft.a

all:		${NAME}

clean:
			rm -f ${OBJ} ${OBJ_BONUS}

fclean:		clean
			rm -f ${NAME} ${NAME_BONUS}

re:			fclean all

re_bonus :	fclean bonus

.PHONY:		all clean fclean re
