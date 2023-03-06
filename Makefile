# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:06:30 by asepulve          #+#    #+#              #
#    Updated: 2023/03/06 16:27:49 by asepulve         ###   ########.fr        #
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


# 23 algs
#	127 123 1233 991 8484 823823 7 -23141 -90 -1234 1212349 5667 324523 969678 3462459 -09 -7887 -9685 67431 974596 -0991 6771 459
#	1 6 14 2 11 12 8 15 13 3 9 7 10 4 5 
NAME 		= 	push_swap
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror
RM 			= 	rm -f
SRC			=	a_utils.c ab_utils.c b_utils.c utils.c\
				merge.c merge_tips.c\
				main.c validator.c sort_three.c sort.c
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

commit: fclean
			git add .
			git commit
			git push
fclean:		clean
			@make fclean -s -C libft
			@${RM} ${NAME}

re:			fclean ${NAME}

.PHONY: all clean fclean re
