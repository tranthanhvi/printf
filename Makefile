NAME = libftprintf.a

SRCS = ft_print_hex.c \
				ft_print_nbr.c \
				ft_print_ptr.c \
				ft_printcs.c \
				ft_printf.c \

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra


all:

clean:

fclean:

re:

.PHONY: all bonus clean fclean re
