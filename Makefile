# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 02:24:45 by tbousque          #+#    #+#              #
#    Updated: 2022/07/19 12:23:41 by tbousque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -I ft_std/ -I list_double/ -I stack/ -I operation/ -I main_sort/ -I sort/ -I ft_qsort/

SRCS_LIBFT = ft_strtoll.c ft_memcpy.c
SRCS_DOUBLE_LIST = lstd_operation.c lstd_rotation.c lstd_creation.c
SRCS_OPERATION = operation.c operation_optimisation.c 
SRCS_STACK = stack_push_swap.c stack_rotation.c
SRCS_MAIN_SORT = helper.c helper2.c main_sort.c
SRCS_SORT = three_sort_a.c three_sort_b.c three_sort_alone_b.c three_sort_alone_a.c
SRCS_FT_QSORT = ft_qsort.c

SRCS = $(addprefix ft_std/, $(SRCS_LIBFT)) \
	$(addprefix list_double/, $(SRCS_DOUBLE_LIST)) \
	$(addprefix stack/, $(SRCS_STACK)) \
	$(addprefix operation/, $(SRCS_OPERATION))\
	$(addprefix main_sort/, $(SRCS_MAIN_SORT)) \
	$(addprefix sort/, $(SRCS_SORT))\
	$(addprefix ft_qsort/, $(SRCS_FT_QSORT))\
	unit_test.c init.c init2.c main.c
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
 
SRCS_CHECKER_BONUS = init_bonus.c get_next_line.c libft_bonus.c

SRCS_BONUS = $(addprefix ft_std/, $(SRCS_LIBFT)) \
	$(addprefix list_double/, $(SRCS_DOUBLE_LIST)) \
	$(addprefix stack/, $(SRCS_STACK)) \
	$(addprefix operation/, $(SRCS_OPERATION))\
	$(addprefix main_sort/, $(SRCS_MAIN_SORT)) \
	$(addprefix sort/, $(SRCS_SORT))\
	$(addprefix ft_qsort/, $(SRCS_FT_QSORT))\
	$(addprefix checker_bonus/, $(SRCS_CHECKER_BONUS))\
	unit_test.c init.c init2.c

CFLAGS = -g3 -Wall -Wextra -Werror -I ./ -I ft_std/ -I list_double/ -I stack/ -I operation/ -I main_sort/ -I sort/ -I ft_qsort/ -I checker_bonus/
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

$(BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) -o $(BONUS)

bonus : $(BONUS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean 
