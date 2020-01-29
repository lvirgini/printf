# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/01/29 16:42:00 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#			VARIABLES				#
#	nom, sources et localisations	#
#									#

NAME =		libftprintf.a

LIBFT_A =	libft.a

LIB_DIR =	./libft/
SRC_DIR =	./src/
OBJ_DIR =	obj/

PRINTF_H =	-I $(SRC_DIR)
LIBFT_H = 	-I $(LIB_DIR)

HEADERS =	$(SRC_DIR)ft_printf.h \
			$(LIB_DIR)libft.h

SRC =		ft_printf.c 		\
			collect_flags.c 	\
			conversion.c 		\
			ft_printf_utils.c 	\
			make_options.c		\
			print_number.c		\
			type_args.c			\
			print_alpha.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

#	VARIABLES		#
#	Compilation		#
#					#

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra

COMP =		$(CC) $(CFLAGS)  $(LIBFT_H)


#	FONCTIONS	#

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $< 

all: $(NAME)

$(LIBFT_A):
			make -C $(LIB_DIR) all

$(NAME): $(LIBFT_A) $(OBJ) 
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			libtool -static -o libftprintf.a $(LIB_DIR)$(LIBFT_A)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
			mkdir -p $(OBJ_DIR)
			$(COMP) -o $@ -c $<


# 	CLEAN	#

clean:
			/bin/rm -rf $(OBJ_DIR)
			make -C $(LIB_DIR) clean

fclean: clean
			/bin/rm -f $(NAME)
			make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re
