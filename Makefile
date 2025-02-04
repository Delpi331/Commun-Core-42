NAME := fractol.a

CC := cc

CFLAGS := -Wall -Wextra -Werror -shared
SOURCE := *.c
LIBRARY := -Lminilibx -lmlx
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

clean:
		make clean -C $(MINILIBX)
		rm -rf $(OBJ)

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
