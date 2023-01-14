# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 23:26:17 by marvin            #+#    #+#              #
#    Updated: 2023/01/13 23:26:17 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = push_swap
CC						= cc
SRCS                    = main.c \
						  stack_funcs.c \
						  swap_rules_1.c \
						  swap_rules_2.c \
						  swap_rules_3.c \
						  sort1.c \
						  sort2.c
OBJS                    = $(SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror

$(NAME)     :   $(OBJS)
	@$(MAKE) -C libft/ re
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -L libft/ -I .
all :   $(NAME)
clean   :
	rm -f $(OBJS)
	@$(MAKE) -C libft/ clean
fclean  :   clean
	rm -f $(NAME)
	@$(MAKE) -C libft/ fclean
re  :   fclean all
.PHONY  :   all clean fclean re