CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = utils.a

UTILS_SRCS = ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthexaupcase.c ft_puthexalocase.c ft_putpointer.c ft_printf.c ft_putnbr_unsigned.c

UTILS_OBJS = $(UTILS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(UTILS_OBJS)
	ar rc $(NAME) $(UTILS_OBJS)
	
clean:
	$(RM) $(UTILS_OBJS)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all
