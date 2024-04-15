NAME = so_long

CC = gcc

SRC_FILES = main.c error_controls.c initialise.c read.c put_image.c hook.c hook_2.c exit.c map_check.c \
			map_check_2.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

MLX	= mlx.a

LIBFT = libft.a

FT_PRINTF = printf.a

GNL = get_next_line.a

STRCTS = structs.a

LFLAGS = -L ./inc/libft -lft -L ./inc/ft_printf -lftprintf -L ./inc/gnl -lgnl -L ./inc -lft -L ./minilibx -lmlx -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX) $(LIBFT) $(FT_PRINTF) $(GNL) 
	@$(CC) $(OBJ_FILES) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(LIBFT): 
	@make -C ./inc/libft

$(FT_PRINTF): 
	@make -C ./inc/ft_printf

$(STRCTS): 
	@make -C ./inc

$(GNL):	
	@make -C ./inc/gnl

$(MLX):
	@make -C ./minilibx >& /dev/null
	
clean :
	rm -rf $(OBJ_FILES)
	make clean -C ./minilibx
	make clean -C ./inc/libft
	make clean -C ./inc/ft_printf
	make clean -C ./inc/gnl

fclean : clean
	@rm -rf $(NAME)
	make fclean -C ./inc/libft
	make fclean -C ./inc/ft_printf
	make fclean -C ./inc/gnl
	
		
re : fclean all

.PHONY: all clean fclean re 
