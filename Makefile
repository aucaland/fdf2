NAME		= fdf
SRC_DIR		= srcs
OBJ_DIR		= objs
SRC_NAME	= fdf.c\
			  hook_define.c\
			  parsing.c\
			  parsing2.c\
			  graphics.c\
			  rotate.c\
			  utils_fdf.c\
			  utils2_fdf.c\
			  hook_colors.c\
			  hook_define2.c\
			  menu.c\
			  errors.c\
			  errors2.c
LIB_A		= LIBFT/libft.a

INCS_FDF	= fdf.h\
			  define_utils.h\
			  errors.h\
			  ./Mac/keycode_mac.h\
			  ./Linux/keycode_linux.h



OBJ_NAME		=	$(SRC_NAME:%.c=%.o)

SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

#### Compil ####

CC 		= gcc -O2
CFLAGS 	= -Wall -Wextra -Werror

#### OS ####

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX_FLAG = -lft -lmlx -lXext -lX11 -lm -lz
		MLX = ./mlx/mlx_linux
	endif
	ifeq ($(UNAME_S),Darwin)
		MLX_FLAG = -lft -lmlx -framework OpenGL -framework Appkit
		MLX = ./mlx/mlx_macos/
	endif

### DEBUG ####

D = 0
ifeq ($(D), 1)
	CC += -fsanitize=address -g3
	MODE = printf %b "\033[0;31m MODE DEBUG SANITIZE \033[0m"
endif
ifneq ($(D), 1)
	MODE = printf %b "\033[0;31m MODE RELEASE \033[0m"
endif

#### LIBS ####

LDFLAG	= -LLIBFT -L$(MLX)
CH_FLAG	= -I. -I$(MLX) -ILIBFT

## Rules ##

all:			$(NAME)

$(LIB_A): force
	@make --no-print-directory all -C LIBFT


$(NAME):	 $(OBJ)
	@make --no-print-directory all -C $(MLX)
	@$(CC) $^ -o $(NAME) $(CFLAGS) $(LDFLAG) $(CH_FLAG) $(MLX_FLAG)
	@printf %b  "\033[1;35m-[$(NAME)]__Edit/Create .o in \033[0m  \033[0;32m[OK]\033[0m\n"
	@printf %b  "\r"
	@$(MODE)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INCS_FDF) $(LIB_A)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CH_FLAG) -o $@ -c $<
	@printf %b "-\033[1;35m[$(NAME)]\033[0m__Compiling \033[1;92m$<\033[0m in \033[1;92m$@\033[0m..."
	@printf "\r"


clean:
	@rm -rf $(OBJ)
	@make --no-print-directory clean -C LIBFT
	@printf %b  "-\033[1;33m[$(NAME)]__Remove objs file  \033[0m  \".o\"         \033[0;32m [OK] \033[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@make --no-print-directory fclean -C LIBFT
	@printf %b  "-\033[1;33m[$(NAME)]__Remove \033[0m             \"$(NAME)\"    \033[0;32m [OK] \033[0m\n"

re: fclean all

.PHONY: all clean fclean re force
