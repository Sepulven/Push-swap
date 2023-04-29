# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 13:36:29 by asepulve          #+#    #+#              #
#    Updated: 2023/04/11 14:06:00 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	checker
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror
RM 			= 	rm -f
OPERATIONS_SRC = ab_utils.c a_utils.c b_utils.c
SRC			= main.c checker_utils.c \
			  $(addprefix operations/,$(OPERATIONS_SRC))

OBJ		 	= 	${SRC:.c=.o}
INCLUDES	=	libft/libft.a

all:		${NAME}

%.o: %.c
		@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):${OBJ}
			@make -s -C libft
			@${CC} ${CFLAGS} ${OBJ}  libft/libft.a -o ${NAME}

clean:
			@make clean -s -C libft
			@${RM} ${OBJ}

fclean:		clean
			@make fclean -s -C libft
			@${RM} ${NAME}

re:			fclean ${NAME}

.PHONY: all clean fclean re
