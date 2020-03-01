# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 18:13:44 by lvirgini          #+#    #+#              #
#    Updated: 2020/02/25 16:57:56 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES				#
#	nom, sources et localisations	#
#									#

NAME =		libft.a

HEADERS = 	libft.h

OBJ_DIR =	obj/

LIBFT_H = 	-I .

SRC =		ft_atoi.c \
			ft_atoi_base.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_lltoa.c \
			ft_ulltoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_base_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strcmp.c \
			ft_strchr.c \
			ft_strchr_set.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_utoa.c

SRC_BONUS = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c 

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

OBJ_BONUS = ${SRC_BONUS:%.c=%.o}

#	VARIABLES		#
#	Compilation		#

CC = 		gcc

CFLAGS =	-Wall -Werror -Wextra

COMP =		$(CC) $(CFLAGS) $(LIBFT_H)
 
 # 	FONCTIONS	#

%.o: %.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
			#${CC} -o $@ $^ 
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
			mkdir -p $(OBJ_DIR)
			$(COMP) -o $@ -c $<
			
all:		${NAME}

bonus :		
			${CC} ${CFLAGS} -c ${SRC_BONUS} ${SRC}
			ar rc ${NAME} ${OBJ_BONUS} ${OBJ}
			ranlib ${NAME}

clean:
			/bin/rm -rf $(OBJ_DIR)

fclean:		clean
			/bin/rm -f $(NAME)${NAME_BONUS}

re:			fclean all

re_bonus :	fclean bonus 

.PHONY: 	all clean fclean re