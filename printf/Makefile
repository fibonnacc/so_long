NAME = libftprintf.a

SRC =	ft_putlower_hex.c ft_putnbr.c ft_putpointer.c ft_strchr.c \
	ft_putchar.c ft_putlupper_hex.c ft_putnbr_unsigned.c ft_putstr.c ft_printf.c

OBJECT = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECT)
	$(AR) $(NAME) $(OBJECT)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

