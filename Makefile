NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc 
MLX_DIR = mlx
SRCS_DIR = src
OBJS_DIR = obj
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/draw.c $(SRCS_DIR)/mandelbrot.c
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
MLX_LIB = $(MLX_DIR)/libmlx.dylib

##RULES

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re
