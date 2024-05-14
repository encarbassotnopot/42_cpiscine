NAME = BSQ

MY_SOURCES = ft_putchar.c \
			 ft_putstr.c \
			 main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS)
		cc -o $(NAME) $(MY_OBJECTS)

