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
	MODE = echo "\033[0;31m MODE DEBUG SANITIZE \033[0m"
endif
ifneq ($(D), 1)
	MODE = echo "\033[0;31m MODE RELEASE \033[0m"
endif

#### LIBS ####

LDFLAG	= -LLIBFT -L$(MLX)
CH_FLAG	= -I. -I$(MLX) -ILIBFT

## Rules ##

all:			build_lib $(NAME)

build_lib:
	@echo "Making LIBFT"
	@make all -C LIBFT
	@echo "Making MLX"
	@make all -C $(MLX)

$(NAME):	 $(OBJ)
	@$(CC) $^ -o $(NAME) $(CFLAGS) $(LDFLAG) $(CH_FLAG) $(MLX_FLAG)
	@echo  "-\033[1;35mEdit/Create: \033[0m $?                    \033[0;32m[OK]\033[0m"
	@$(MODE)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INCS_FDF)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CH_FLAG) -o $@ -c $<
	@echo "-\033[1;92mCompiling : \033[0m $?"

clean:
	@rm -rf $(OBJ)
	@make clean -C LIBFT
	@echo  "-\033[1;33m Remove objs file  \033[0m  \".o\"  for Fdf    	   \033[0;32m [OK] \033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C LIBFT
	@echo  "-\033[1;33m Remove \033[0m             \"$(NAME)\"    		   \033[0;32m [OK] \033[0m"

re: fclean all

.PHONY: all clean fclean re
