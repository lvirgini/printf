# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/01/28 16:42:51 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMP =		gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H)

PRINTF_H =	-I $(DIR_PRINTF)
LIBFT_H = 	-I 1-libft/

NAME =		libftprintf.a

LIBFT_A =	libft.a

DIR_PRINTF =	./3-printf/

HEADERS =	$(DIR_PRINTF)ft_printf.h

OBJ_DIR =	obj/
SRC_DIR =	./3-printf/
LIB_DIR =	./1-libft/


SRC =			ft_printf.c 		\
				collect_flags.c 	\
				conversion.c 		\
				ft_printf_utils.c 	\
				make_options.c		\
				print_number.c		\
				type_args.c			\
				print_alpha.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) 
		make -C $(LIB_DIR)
		cp $(LIB_DIR)$(LIBFT_A) .
		mv $(LIBFT_A) $(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		mkdir -p $(OBJ_DIR)
		$(COMP) -o $@ -c $<

clean:
		/bin/rm -rf $(OBJ_DIR)
		make -C $(LIB_DIR) clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re
