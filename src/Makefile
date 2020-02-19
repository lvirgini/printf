# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/19 17:28:51 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS =	-Wall -Wextra -I. -I../libft/

NAME =		a.out

CC =		gcc

LIB =		libft.a

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
