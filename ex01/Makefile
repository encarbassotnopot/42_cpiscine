OBJ_FILES = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
HDR_FILES = ft.h

SRC_DIR = src
HDR_DIR = includes

vpath %.c $(SRC_DIR)
vpath %.o $(SRC_DIR)
vpath %.h $(HDR_DIR)

OUT = lift.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:  $(OUT)

$(OUT): $(OBJ_FILES)
	ar rc $@ $(OBJ_FILES:%=$(SRC_DIR)/%)

$(OBJ_FILES): %.o:%.c $(HDR_FILES)
	$(CC) $(CFLAGS) -I $(HDR_DIR) -c -o $(<D)/$@ $<

clean reclean:
	rm -f $(OBJ_FILES:%=$(SRC_DIR)/%)

fclean: clean
	rm -f $(OUT)

re: fclean all reclean

.PHONY: all fclean all reclean re
