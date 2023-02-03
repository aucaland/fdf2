NAME		= libft.a
ALIAS		= libft
INC_DIR		= ./
INC			= libft.h
SRCS_DIR 	= srcs
OBJS_DIR	= objs

SRCS_NAME		=	ft_atoi.c\
				ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_itoa.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strlen.c\
				ft_strlcpy.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strlcat.c\
				ft_calloc.c\
				ft_bzero.c\
				ft_memset.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strjoin.c\
				ft_strdup.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_split.c\
				ft_striteri.c\
				ft_strmapi.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_printf.c\
                ft_print_cust.c\
                ft_dec_to_hex.c\
                ft_udec_to_hex.c\
				ft_lstsize.c \
				ft_lstclear.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstlast.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				get_next_line.c\
				get_next_line_utils.c\
				ft_free.c\
				ft_isspace.c\
				ft_convert_base.c\
				ft_convert_base2.c\
				ft_freetabi.c

OBJS		=	$(SRCS_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJS_DIR)/,$(OBJS))
SRC = $(addprefix $(SRCS_DIR)/,$(SRCS_NAME))

#### Compil ####

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

#### Rules ####

all:			$(NAME)

$(NAME):		$(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@
	@printf %b "\n"
	@printf %b "-\033[1;35m[$(ALIAS)]__Create and Index\033[0m     \"$(NAME)\"     \033[0;32m[OK]\033[0m\n"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(INC)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS)  -c $< -o $@ -I$(INC_DIR)
	@printf %b "-\033[1;35m[$(ALIAS)]\033[0m__Compiling \033[1;92m$<\033[0m in \033[1;92m$@\033[0m... "
	@printf "\r"

clean:
	@rm -rf $(OBJ)
	@printf %b  "-\033[1;33m[$(NAME)]__Remove objs file  \033[0m  \".o\"         \033[0;32m [OK] \033[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@printf %b  "-\033[1;33m[$(NAME)]__Remove \033[0m             \"$(NAME)\"    \033[0;32m [OK] \033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus