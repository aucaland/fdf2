NAME		= fdf
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs
SRCS		=




OBJS		=	$(SRCS:%.c=$(OBJ_DIR)%.o)

MLX_FLAG = -lft -lmlx -lm
####Compil####

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

#### OS ####

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX_FLAG += -lXext -lX11 -lz
		MLX = ./mlx/mlx_linux
	endif
	ifeq ($(UNAME_S),Darwin)
		MLX_FLAG += -framework OpenGL -framework Appkit
		MLX = ./mlx/mlx_macos
	endif

#####LIBS#####

LIBS	= LIBFT/libft.a $(MLX)/libmlx.a
LDFLAG	= -LLIBFT -L$(MLX)
CH_FLAG	= -I$(MLX) -I$(LIBFT) -I./
## Rules ##

all:			$(NAME)

LIBFT/libft.a:
	@echo "Making LIBFT"
	@make -C LIBFT

$(MLX)/libmlx.a:
	@echo "Making MLX"
	@make -C $(MLX)

$(NAME):		$(OBJS) $(LIBS)
	@$(CC) $^ -o $(CFLAGS) $(LDFLAG) $(MLX_FLAG)
	@echo  "-\033[1;35mEdit/Create: \033[0m $?                    \033[0;32m[OK]\033[0m"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(CH_FLAG)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS)  $(CH_FLAG) -c $< -o $@
	@echo "-\033[1;92mCompiling : \033[0m $?"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(MLX)
	@make clean -C LIBFT
	@echo  "-\033[1;33m Remove objs file  \033[0m  \".o\"         \033[0;32m [OK] \033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C LIBFT
	@make fclean -C $(MLX)
	@echo  "-\033[1;33m Remove \033[0m             \"$(NAME)\"    \033[0;32m [OK] \033[0m"

re: fclean all

.PHONY: all clean fclean re