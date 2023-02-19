# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:06:30 by asepulve          #+#    #+#              #
#    Updated: 2023/02/17 00:10:56 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#   5 numbers -> < 12 moves
#   100 numbers:
#       <700 moves = 5pts
#       <900 numbers = 4pts
#       <1,100 numbers = 3pts
#       <1,300 numbers = 2pts
#       <1,500 numbers = 1pts
#   500 numbers:
#       <5,500 moves = 5pts
#       <7,000 moves = 4pts
#       <8,500 moves = 3pts
#       <10,000 moves = 2pts
#       <11,500 moves = 1pts

NAME 		= 	push_swap
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror
RM 			= 	rm -f
SRC			=	main.c a_utils.c ab_utils.c b_utils.c
OBJ		 	= 	${SRC:.c=.o}
INCLUDES	=	libft/libft.a

all:		${NAME}

%.o: %.c
			@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): ${OBJ}
			@make -s -C libft
			@${CC} ${CFLAGS} ${OBJ} libft/libft.a -o ${NAME}

clean:
			@make clean -s -C libft
			@${RM} ${OBJ}

fclean:		clean
			@make fclean -s -C libft
			@${RM} ${NAME}

re:			fclean ${NAME}

.PHONY: all clean fclean re
