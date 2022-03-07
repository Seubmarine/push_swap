NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I list_double/ -I stack/

SRCS_DOUBLE_LIST = lstd_operation.c lstd_rotation.c lstd_creation.c
SRCS_STACK = stack_push_swap.c stack_rotation.c

SRCS = $(addprefix list_double/, $(SRCS_DOUBLE_LIST)) $(addprefix stack/, $(SRCS_STACK)) unit_test.c init.c
OBJS = $(SRCS:%.c=%.o)

all = $(NAME)

(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm $(OBJS)
