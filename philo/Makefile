# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:20:50 by malaakso          #+#    #+#              #
#    Updated: 2023/03/30 13:37:42 by malaakso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ft_putnbr_base(long nbr, int base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base)
		ft_putnbr_base(nbr / (long)base, base);
	ft_putchar("0123456789abcdef"[nbr % (long)base]);
}






NAME			=	philo
COMPILER		=	cc

OBJ_FOLDER		=	obj
FOLDER_LIST		=	$(OBJ_FOLDER)

H_FILES			=	
C_FILES			=	

H_PATHS			=	$(H_FILES)
C_PATHS			=	$(C_FILES)
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, \
					$(patsubst %.c, %.o, $(C_FILES)))

C_FLAGS_OBJ		=	-Wall -Wextra -Werror
C_FLAGS_NAME	=	$(C_FLAGS_OBJ)

.PHONY: all
all: $(NAME)

$(NAME): $(FOLDER_LIST) $(OBJ_PATHS)
	$(COMPILER) $(C_FLAGS_NAME) $(OBJ_PATHS) -o $@

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS)
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
