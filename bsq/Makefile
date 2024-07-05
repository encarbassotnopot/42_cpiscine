NAME = bsq

<<<<<<< HEAD:bsq/Makefile
MY_SOURCES = main.c \
			 result_utils.c \
			 result_utils2.c \
			 result_utils3.c \
			 bernat_test.c
=======
MY_SOURCES = main.c str_utils.c

MY_INCLUDES = datatypes.h str_utils.h
>>>>>>> bsq/us-odio:Makefile

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		$(CC) $(MY_OBJECTS) -o $(NAME)

%.c: %.o

clean reclean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

.PHONY: all clean reclean fclean re
