# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 23:26:17 by marvin            #+#    #+#              #
#    Updated: 2023/01/27 16:07:24 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = push_swap
CC						= cc
SRCS                    = main.c \
						push_swap_utils_1.c \
						push_swap_utils_2.c \
						sort_small.c \
						sort1.c \
						sort2.c \
						sort3.c \
						sort4.c \
						stack_funcs.c \
						swap_rules_1.c \
						swap_rules_2.c \
						swap_rules_3.c \
						swap_rules_4.c
OBJS                    = $(SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror

$(NAME)     :   $(OBJS)
	@$(MAKE) -C libft/ re
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -L ./libft/ -lft -I .
all :   $(NAME)
clean   :
	rm -f $(OBJS)
	@$(MAKE) -C libft/ clean
fclean  :   clean
	rm -f $(NAME)
	@$(MAKE) -C libft/ fclean
re  :   fclean all
.PHONY  :   all clean fclean re