# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 02:24:45 by tbousque          #+#    #+#              #
#    Updated: 2022/03/30 00:31:59 by tbousque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -I ft_std/ -I list_double/ -I stack/ -I operation/#-fsanitize=address

SRCS_LIBFT = ft_strtoll.c
SRCS_DOUBLE_LIST = lstd_operation.c lstd_rotation.c lstd_creation.c
SRCS_OPERATION = operation.c operation_optimisation.c 
SRCS_STACK = stack_push_swap.c stack_rotation.c

SRCS = $(addprefix ft_std/, $(SRCS_LIBFT)) \
	$(addprefix list_double/, $(SRCS_DOUBLE_LIST)) \
	$(addprefix stack/, $(SRCS_STACK)) \
	$(addprefix operation/, $(SRCS_OPERATION))\
	unit_test.c init.c
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) #-fsanitize=address -static-libasan

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean 
