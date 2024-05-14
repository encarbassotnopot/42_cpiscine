NAME = bsq

MY_SOURCES = main.c 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		cc $(MY_OBJECTS) -o $(NAME)

clean reclean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all reclean
