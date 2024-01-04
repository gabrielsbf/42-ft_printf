NAME=libftprintf.a

SRCS_FLDR=/srcs

RAW_SRCS=$(shell find .$(SRCS_FLDR))

SRCS=$(filter %.c, $(RAW_SRCS))

OBJS=$(SRCS:.c=.o)

CFLAGS=-Wall -Wextra -Werror

CC = cc $(CFLAGS) -I ./include

.o : .c
	$(CC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY:  all clean fclean re
