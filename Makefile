# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:48:30 by mcombeau          #+#    #+#              #
#    Updated: 2024/01/05 19:05:11 by bsyvasal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = 	push_swap \
		push \
		revrot \
		rotate \
		swap \
		turk_sort \
		utils
		
LIB =	libft/libft.a
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

$(LIB):
	make -C ./libft

all: $(NAME)

clean:
	@make clean -C ./libft
	@rm -f *.o

fclean: clean
	@make fclean -C ./libft 
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re bonus
