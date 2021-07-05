NAME		=	so_long

# COMPILER
CC			=	gcc

# FLAGS
CFLAGS		=	-Wall -Werror -Wextra

# HEADER
INC_DIR		=	./include
INC			=	-I $(INC_DIR)

# SOURCES
SRC_DIR		=	./srcs
SRC			=	main.c \
				get_next_line.c \
				init.c \
				init_map.c \
				init_tex.c \
				move.c \
				draw.c \
				exit_game.c

# OBJETS
OBJS_NAME	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME))

# MINILIBX
# MLX_DIR		=	/usr/local/include
MLX_DIR		=	./minilibx_opengl
# MLX_LNK_DIR	=	/usr/local/lib/
MLX_LNK_DIR	=	 $(MLX_DIR)
MLX_INC		=	-I $(MLX_DIR)
MLX_LNK		=	-L $(MLX_LNK_DIR) -lmlx -framework OpenGL -framework AppKit

# LIBFT LIB
FT_DIR		=	./libft
FT_INC		=	-I $(FT_DIR)
FT_LNK		=	-L $(FT_DIR) -lft
LIBFT		=	$(addprefix $(FT_DIR), libft.a)

# RULES
all			:	 $(NAME)

$(LIBFT)	:
				@echo "\nCompiling $(FT_DIR)..."
				@make -C $(FT_DIR)

$(NAME)		:	$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) $(addprefix $(SRC_DIR)/, $(SRC)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

clean		:
				@echo "\nCleaning Directories..."
				@rm -rf $(OBJS)
				@rm -rf $(OBJS_BNS)
				make clean -C $(FT_DIR)

fclean		:	clean
				rm -f $(NAME)
				make fclean -C $(FT_DIR)

re			:	fclean all
