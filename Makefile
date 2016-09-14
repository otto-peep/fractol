NAME = fractol

HEAD = ./include/

PATH_LIB = ./libft/

PATH1 = ./src/

FLAGS = -Wall -Wextra -Werror

FILES = main.c\
	  window.c\
	  draw.c\
	  mandel.c\
	  functions.c\
	  julia.c\
	  move.c\
	  budha.c

SRC = $(FILES:%c=$(PATH1)%c)

STATICPATH = -lm -L libft/ -lft -L./minilibx_macos -I./minilibx_macos -lmlx -framework OpenGL -framework AppKit

MLXPATH = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC) -I $(HEAD) $(STATICPATH)

clean :
	make -C libft/ clean

fclean :
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
