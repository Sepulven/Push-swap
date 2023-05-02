# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:06:30 by asepulve          #+#    #+#              #
#    Updated: 2023/05/02 02:30:43 by asepulve         ###   ########.fr        #
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

NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

OPERATIONS_SRC	=	a_utils.c ab_utils.c b_utils.c

UTILS_SRC		=	costs.c  greatness.c utils.c validator.c checker.c send.c

SORT_SRC		=	tips.c utils_sort.c tips_sorted.c split_stack.c\
					split_stack_sort.c sort_n_own_stack.c

SRC				=	$(addprefix operations/,$(OPERATIONS_SRC)) \
					$(addprefix utils/,$(UTILS_SRC)) \
					$(addprefix sort/,$(SORT_SRC)) \
					main.c

OBJ				=	${SRC:.c=.o}
INCLUDES		=	libft/libft.a

ARG				=

all:		${NAME}

%.o: %.c
		@$(CC) $(CFLAGS) -c $^ -o $@
 
$(NAME):${OBJ}
			@make -s -C libft
			@${CC} ${CFLAGS} ${OBJ}  libft/libft.a -o ${NAME}

clean:
			@make clean -s -C libft
			@${RM} ${OBJ}

vchecker:
		@make -s
		@valgrind --verbose --leak-check=full --show-leak-kinds=all ./push_swap $ARG 2>valgrind.txt
		
v:
		@make -s
		@valgrind --verbose --leak-check=full --log-file=valgrind.log --track-origins=yes --show-leak-kinds=all ./push_swap

fclean:		clean
			@make fclean -s -C libft
			@${RM} ${NAME}

re:			fclean ${NAME}

.PHONY: all clean fclean re
