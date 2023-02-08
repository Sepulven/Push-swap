# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:06:30 by asepulve          #+#    #+#              #
#    Updated: 2023/02/08 14:51:03 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror
RM 			= 	rm -f
SRC			=	main.c
INCLUDES	=	libft/libft.a
OBJ		 	= 	${SRC:.o=.c}

.o:.c
			${CC} ${CFLAGS} $< -c

all:		${NAME}

$(NAME):	
			make -s -C libft
			@${CC} ${CFLAGS} ${OBJ} libft/libft.a -o ${NAME}

clean:
			@make clean -s -C libft
			@${RM} ${OBJ}

fclean:		clean
			@make fclean -s -C libft
			@${RM} ${NAME}

re:			fclean ${NAME}
