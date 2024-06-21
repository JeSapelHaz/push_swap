# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 18:55:41 by hbutt             #+#    #+#              #
#    Updated: 2024/06/18 16:07:36 by hbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c check_args.c init_stack.c print_stack.c push.c reverse_rotate.c rotate.c \
		sort.c swap.c utils_stack.c utils.c printf/ft_printf.c printf/ft_format.c printf/utils.c \
		utils_stack_bis.c utils_ab.c do_ab.c sort_big.c utils_ba.c do_ba.c ft_split.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re