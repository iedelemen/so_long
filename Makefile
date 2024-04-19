NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-Lprintf -Llibft -Lminilibx -lftprintf -lft -lmlx -framework OpenGL -framework AppKit
SOURCES	=	source/main.c \
			source/playing.c \
			source/check.c \
			source/init_mlx.c \
			source/validation.c \
			GetNextLine/get_next_line.c \
			GetNextLine/get_next_line_utils.c

OBJ = $(SOURCES:.c=.o)

all: mdir $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

mdir:
	@make -C printf
	@make -C libft
	@make -C minilibx

clean:
	@make -C printf clean
	@make -C libft clean
	@make -C minilibx clean
	@rm -f $(OBJ)

fclean: clean
	@make -C printf fclean
	@make -C libft fclean
	@make -C minilibx clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mdir
