# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:20:50 by malaakso          #+#    #+#              #
#    Updated: 2023/07/24 09:53:09 by malaakso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
COMPILER		=	cc

OBJ_FOLDER		=	obj
FOLDER_LIST		=	$(OBJ_FOLDER)

H_FILES			=	philo.h
C_FILES			=	philo.c \
					preflight_checks.c \
					my_atoi.c \
					time.c \
					init.c \
					philo_routine.c

H_PATHS			=	$(H_FILES)
C_PATHS			=	$(C_FILES)
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, \
					$(patsubst %.c, %.o, $(C_FILES)))

C_FLAGS_OBJ		=	-Wall -Wextra -Werror -Wpedantic -Wunreachable-code -Wtype-limits -g -fsanitize=address -fsanitize=thread
C_FLAGS_NAME	=	$(C_FLAGS_OBJ) -pthread

.PHONY: all
all: $(NAME)

$(NAME): $(FOLDER_LIST) $(OBJ_PATHS)
	$(COMPILER) $(C_FLAGS_NAME) $(OBJ_PATHS) -o $@

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:%.c $(H_PATHS)
	$(COMPILER) $(C_FLAGS_OBJ) -c $< -o $@

$(FOLDER_LIST):
	mkdir $@

.PHONY: clean
clean:
	rm -f $(OBJ_PATHS)
	rm -rf $(OBJ_FOLDER)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
