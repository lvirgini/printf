# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/24 15:13:43 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#			VARIABLES				#

NAME =		libftprintf.a

LIB_DIR =	libft/
OBJ_DIR =	obj/
SRC_DIR =	$(shell find src -type d)
#INC_DIR = 	$(shell find includes -type d) $(LIB_DIR) ./src

LIB		=	ft

SRC 	=	ft_printf.c 		\
			ft_printf_utils.c	\
			flags_collect.c 	\
			type_args.c			\
			init_and_clean.c 	\
			conversion.c 		\
			dispatch.c 			\
			make_options.c		\
			print_character.c 	\
			print_number.c 		\
			print_string.c 		\
			unicode.c

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

#	COMPILATION		#

CC = 		gcc

CFLAG = 	-Wall -Werror -Wextra 
IFLAG = 	-I src/ -I libft/	
#IFLAG = 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG  =	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )


#	FONCTIONS	#


all:		$(NAME)

$(LIB):
			make -C $(LIB_DIR) all

$(OBJ_DIR)%.o: %.c
			mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAG) -I src/ -o $@ -c $<

$(NAME): 	$(LIB) $(OBJ)
			cp $(LIB_DIR)/libft.a $@
			ar rcs $(NAME) $(OBJ) 


# 	CLEAN	#

clean:
			rm -rf $(OBJ_DIR)
			make -C $(LIB_DIR) clean

fclean: clean
			rm -f $(NAME)
			make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re
