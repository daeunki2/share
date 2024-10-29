NAME = so_long

MINILIBX_DIR = ./minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRCS = ft_split.c\
		get_next_line.c\
		get_next_line_utils.c\
		map_read.c\
		map_tool.c\
		map_print.c\
		main.c\
		move.c\
		key_press.c\
		free_error.c\
		dfs.c\
		set_up.c\
		name_check.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MINILIBX_DIR) -I$(FT_PRINTF_DIR)
LDFLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -L$(FT_PRINTF_DIR) -lftprintf

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MINILIBX_LIB) $(FT_PRINTF_LIB) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(MINILIBX_LIB):
	make -C $(MINILIBX_DIR)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

all: $(NAME)

clean:
	make -C $(MINILIBX_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all

norm:
	@echo "Cheking the norminette"
	@echo --
	@norminette $(SRCS) $(FT_PRINTF_DIR) so_long.h \
	
.PHONY: all clean fclean re
