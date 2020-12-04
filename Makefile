NAME = fractol

COMP = gcc
FLAG = -Wall -Werror -Wextra -O3
LIB = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx_macos/
MLX_HEADERS = $(MLX_DIR)

HEADERS_LIST = fractol.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = ./src/
SRC_LIST =		ft_abs_float.c \
				ft_arrow_handler.c \
				ft_color.c \
				ft_complex.c \
				ft_draw.c \
				ft_exit.c \
				ft_fractol_form.c \
				ft_fractol_list.c \
				ft_fractol_struct_init.c \
				ft_key_handler.c \
				ft_scale.c \
				ft_fractol_handler.c \
				ft_image.c \
				ft_input_handler.c \
				ft_julia_specific_handler.c \
				main.c \

SOURCES = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@$(COMP) $(FLAG) $(LIB) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(COMP) $(FLAG) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(MLX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
