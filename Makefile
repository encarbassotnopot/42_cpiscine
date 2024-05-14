NAME = bsq

MY_SOURCES = bernat_test.c \
			 result_utils.c \
			 result_utils2.c \
			 main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS)
		cc -o $(NAME) $(MY_OBJECTS)
