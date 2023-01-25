NAME = libftprintf.a

SOURCES = \
	ft_printf.c ft_strchr.c print_char.c print_string.c print_nbr.c \
	print_unsigned.c print_hex.c hex_ptr.c toupper_printf.c \
	print_address.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re