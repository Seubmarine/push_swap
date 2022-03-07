# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 02:24:45 by tbousque          #+#    #+#              #
#    Updated: 2022/03/07 02:46:37 by tbousque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I list_double/ -I stack/ -fsanitize=address

SRCS_DOUBLE_LIST = lstd_operation.c lstd_rotation.c lstd_creation.c
SRCS_STACK = stack_push_swap.c stack_rotation.c

SRCS = $(addprefix list_double/, $(SRCS_DOUBLE_LIST)) $(addprefix stack/, $(SRCS_STACK)) unit_test.c init.c
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -fsanitize=address -static-libasan

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean 
