NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Iinc/libft/inc
MLX_DIR = mlx
SRCS_DIR = src
OBJS_DIR = obj
LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/draw.c $(SRCS_DIR)/mandelbrot.c $(SRCS_DIR)/julia.c $(SRCS_DIR)/parse_args.c
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
MLX_LIB = $(MLX_DIR)/libmlx.dylib

##RULES

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "Libft compiled successfully!"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft
	@echo "Fract'ol compiled successfully!"

clean :
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "Executable and object files removed!"

re: fclean all

.PHONY: all clean fclean re
