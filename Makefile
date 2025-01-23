NAME = libftprintf.a

SRCS = ft_print_hex.c \
       ft_print_nbr.c \
       ft_print_char.c \
       ft_print_ptr.c \
       ft_print_str.c \
       ft_print_uint.c \
       ft_base_convert.c \
       ft_printf.c

OBJ = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
