# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apancar <apancar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 10:44:11 by apancar           #+#    #+#              #
#    Updated: 2024/04/17 10:48:25 by apancar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

CC= gcc

CFLAGS= -Wall -Wextra -Werror -g -pthread

SOURCES= main.c utils.c init.c bon_appetite.c die_eat_sleep.c

OBJECTS= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re