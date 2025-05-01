# Executable name

NAME = so_long
BONUS_NAME = so_long_bonus

# Compiler and flags
# -I tells the compiler where to look for header files.

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -I/usr/include/minilibx-linux -L/usr/include/minilibx-linux -lmlx -lXext -lX11

# Directories

PRINTF_DIR = ./printf
GET_NEXT_LINE_DIR = ./get_next_line
SO_LONG_DIR = ./game_2D
SO_LONG_BONUS_DIR = ./game_2D_bonus

# Libraries
# -L tells the linker where to look for library files.

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LDFLAGS = -L. -lmlx -lX11 -lXext -lm $(PRINTF_LIB)

# Source files

GET_NEXT_LINE_SRCS = 	$(GET_NEXT_LINE_DIR)/get_next_line.c \
						$(GET_NEXT_LINE_DIR)/get_next_line_utils.c

# Source files for mandatory version
SO_LONG_SRCS = $(SO_LONG_DIR)/so_long.c \
               $(SO_LONG_DIR)/continue_paring_the_map.c \
               $(SO_LONG_DIR)/make_image.c \
               $(SO_LONG_DIR)/many_functions.c \
               $(SO_LONG_DIR)/flood_fill.c \
               $(SO_LONG_DIR)/map_validation.c \
               $(SO_LONG_DIR)/move_player.c \
               $(SO_LONG_DIR)/parsing_the_map.c

# Source files for the bonus version
SO_LONG_BONUS_SRCS =	$(SO_LONG_BONUS_DIR)/so_long_bonus.c \
						$(SO_LONG_BONUS_DIR)/continue_paring_the_map_bonus.c\
               			$(SO_LONG_BONUS_DIR)/make_image_bonus.c \
               			$(SO_LONG_BONUS_DIR)/many_functions_bonus.c  \
               			$(SO_LONG_BONUS_DIR)/flood_fill_bonus.c \
               			$(SO_LONG_BONUS_DIR)/map_validation_bonus.c  \
               			$(SO_LONG_BONUS_DIR)/move_player_bonus.c \
               			$(SO_LONG_BONUS_DIR)/parsing_the_map_bonus.c\
						$(SO_LONG_BONUS_DIR)/ft_itoa.c

# source file C

SRCS = $(GET_NEXT_LINE_SRCS) $(SO_LONG_SRCS)
SRCS_BONUS = $(GET_NEXT_LINE_SRCS) $(SO_LONG_BONUS_SRCS)

# Object files

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Rules mandatory

all: $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	@ $(CC) $(OBJS) $(LDFLAGS) $(MLX_FLAGS) -o $(NAME)

# Bonus rule version

bonus: $(PRINTF_LIB) $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(PRINTF_LIB)
	@ $(CC) $(OBJS_BONUS) $(LDFLAGS) $(MLX_FLAGS) -o $(BONUS_NAME)

$(PRINTF_LIB):
	@ $(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include/minilibx-linux -c $< -o $@

.SECONDARY : $(OBJS) $(OBJS_BONUS)

clean:
	@ rm -f $(OBJS) $(OBJS_BONUS)
	@ $(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@ rm -f $(NAME) $(BONUS_NAME)
	@ $(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re