# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:18:49 by llion             #+#    #+#              #
#    Updated: 2023/02/14 16:19:42 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/push_swap.c		\
			  src/list.c			\
			  src/sorts.c			\
			  src/swap_functions1.c	\
			  src/swap_functions2.c	\
			  src/memory.c			\
			  src/sort_in_tabs.c	\
			  src/utils.c


OBJS		= $(SRCS:.c=.o)
NAME		= push_swap
LIBFT		= libft.a
PRINTF		= libftprintf.a
A_LIB		= libft/$(LIBFT)
F_LIB		= ftprintf/$(PRINTF)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)

debug:		$(OBJS) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJS) -fsanitize=address -o $(NAME)

$(LIBFT):
			@make -C libft
			cp $(A_LIB) .

$(PRINTF):
			@make -C ftprintf
			cp $(F_LIB) .
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(NAME)
			$(RM) $(LIBFT)
			
re:			fclean all

.PHONY:		all clean fclean re
