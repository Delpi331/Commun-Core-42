CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap3.c
OBJS = $(SRCS:.c=.o)
LIBFTPRINTF = ft_printf/libftprintf.a
NAME = push_swap

all: $(LIBFTPRINTF) $(NAME)

$(LIBFTPRINTF):
	make -C ft_printf

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) -Lft_printf -lftprintf -o $(NAME)

clean:
	make clean -C ft_printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all