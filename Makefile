# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnera <earnera@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 17:58:01 by earnera           #+#    #+#              #
#    Updated: 2025/08/28 17:58:48 by earnera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	ScalarConverter
FUNCTION = ./src/main.cpp ./src/ScalarConverter.cpp

all: $(NAME)

$(NAME) : $(FUNCTION)
		$(CC) $(CFLAGS) $(FUNCTION) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re