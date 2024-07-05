NAME = bsq

MY_SOURCES = main.c \
			 result_utils.c \
			 result_utils2.c \
			 result_utils3.c \
			 bernat_test.c

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
