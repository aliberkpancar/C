NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

FILES = pipex.c ft_split.c ft_strlen.c ft_strdup.c ft_strstr.c ft_find_env.c

OBJ_FILES = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean :
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re