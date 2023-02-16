NAME		=	so_long
BONUS		=	so_long_bonus

# COMPILER
CC			=	gcc

# FLAGS
CFLAGS		=	-Wall -Werror -Wextra
#-g3 -fsanitize=address

# HEADER
INC_DIR		=	./include
INC			=	-I $(INC_DIR) -I minilibx_opengl

# SOURCES
SRC_DIR		=	./srcs
SRC			=	main.c \
				get_next_line.c \
				init.c \
				init_map.c \
				init_map2.c \
				check_map.c \
				init_tex.c \
				move.c \
				draw.c \
				draw2.c \
				free.c \
				exit_game.c

SRC_BONUS	=	main.c \
				get_next_line.c \
				init_bonus.c \
				init_map.c \
				init_map2.c \
				check_map.c \
				init_tex.c \
				move.c \
				draw_bonus.c \
				draw2.c \
				free.c \
				exit_game.c \
				bonus.c
# OBJETS
OBJS_NAME	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME))

OBJS_NAME_BONUS	=	$(SRC_BONUS:.c=.o)
OBJS_BONUS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME_BONUS))

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

bonus		:	$(LIBFT) $(OBJS_BONUS)
				$(CC) $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) $(addprefix $(SRC_DIR)/, $(SRC_BONUS)) $(FT_LNK) $(MLX_LNK) -o $(BONUS)

clean		:
				@echo "\nCleaning Directories..."
				@rm -rf $(OBJS)
				@rm -rf $(OBJS_BONUS)
				make clean -C $(FT_DIR)
				make clean -C $(MLX_DIR)

fclean		:	clean
				rm -f $(NAME)
				rm -f $(BONUS)
				make fclean -C $(FT_DIR)

re			:	fclean all

run			:
				make \
				&& make clean \
				&& ./so_long map/map.ber
norm		:
				norminette srcs includes
test		:
				make \
				&& make clean \
				&& ./so_long map/invalid_map_border.ber \
				&& ./so_long map/invalid_map_border2.ber \
				&& ./so_long map/invalid_map_border3.ber \
				&& ./so_long map/invalid_map_border4.ber \
				&& ./so_long map/invalid_map_border5.ber \
				&& ./so_long map/invalid_map_collectible.ber \
				&& ./so_long map/invalid_map_exit.ber \
				&& ./so_long map/invalid_map_player.ber \
				&& ./so_long map/invalid_map_player2.ber

test_bonus	:
				make bonus \
				&& make clean \
				&& ./so_long_bonus map/invalid_map_border.ber \
				&& ./so_long_bonus map/invalid_map_border2.ber \
				&& ./so_long_bonus map/invalid_map_border3.ber \
				&& ./so_long_bonus map/invalid_map_border4.ber \
				&& ./so_long_bonus map/invalid_map_border5.ber \
				&& ./so_long_bonus map/invalid_map_collectible.ber \
				&& ./so_long_bonus map/invalid_map_exit.ber \
				&& ./so_long_bonus map/invalid_map_player.ber \
				&& ./so_long_bonus map/invalid_map_player2.ber
