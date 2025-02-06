NAME=so_long

CC=cc
CFLAGS=-Wall -Wextra -Werror
MLX_FLAGS=-lmlx -framework OpenGL -framework AppKit

LIBFT_DIR=lib/libft
PRINTF_DIR=lib/ft_printf
GNL_DIR=lib/get_next_line


CFILES=mandatory/floodfill.c mandatory/game_utils.c mandatory/main.c \
		mandatory/read_map.c mandatory/utilis.c mandatory/validate_map.c \
		mandatory/free_map.c mandatory/image.c mandatory/render.c mandatory/move.c \
		$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJECTS=$(CFILES:.c=.o)

LIBFT_LIB   =   $(LIBFT_DIR)/libft.a
PRINTF_LIB  =   $(PRINTF_DIR)/libftprintf.a

all: $(LIBFT_DIR) $(PRINTF_DIR) $(NAME)

$(LIBFT_DIR):
	make -C $(LIBFT_DIR)

$(PRINTF_DIR):
	make -C $(PRINTF_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -c $<

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: $(LIBFT_DIR) $(PRINTF_DIR)