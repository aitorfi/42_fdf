CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -g
SRC = \
	main.c init.c event_handler.c draw.c map_parser.c map_parser_dimensions.c \
	map_parser_content.c utils.c draw_line.c
OBJS = $(SRC:.c=.o)
NAME = fdf
RM = rm -f
DIR_LIBFT = ./libft
NAME_LIBFT = $(DIR_LIBFT)/libft.a

all: lib $(NAME)

$(NAME): $(NAME_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(NAME_LIBFT) $(OBJS)

$(NAME_LIBFT):
	make -C $(DIR_LIBFT) improved

clean:
	$(RM) $(OBJS)
	make -C $(DIR_LIBFT) clean
	$(MAKE) -C mlx clean

fclean: clean
	$(RM) $(NAME)
	make -C $(DIR_LIBFT) fclean

re: fclean all

lib:
	$(MAKE) -C mlx
