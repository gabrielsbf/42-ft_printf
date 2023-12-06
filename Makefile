NAME=libftprintf.a

CC = cc

CFLAGS=-Wall -Wextra -Werror

SRCS=ft_printf.c ft_putchar_fd.c ft_puthex_fd.c \
ft_putnbr_fd.c ft_putnbu_fd.c ft_putstr_fd.c \
ft_strchr.c ft_strlcpy.c ft_strlen.c \

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.o : .c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY:  all clean fclean re
