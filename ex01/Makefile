# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnera <earnera@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 10:19:25 by earnera           #+#    #+#              #
#    Updated: 2025/09/10 11:49:47 by earnera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	Serializer
FUNCTION = ./src/main.cpp ./src/Serializer.cpp

all: $(NAME)

$(NAME) : $(FUNCTION)
		$(CC) $(CFLAGS) $(FUNCTION) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re