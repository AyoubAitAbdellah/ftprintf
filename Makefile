
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
HEADER = ft_printf.h

SRCS = ft_printf.c \
       ft_find_format.c \
       ft_print_char.c \
       ft_print_strings.c \
       ft_print_numbers.c \
       ft_print_unsigned.c \
       ft_print_hex.c \
       ft_print_pointers.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

