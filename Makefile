##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile for the my_printf project
##

LIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRC = 	./radar/src/screen/screen.c \
		./radar/src/radar.c \
		./radar/src/screen/sprite/background.c \
		./radar/src/screen/plane/plane.c \
		./radar/src/screen/plane/create_plane.c \
		./radar/src/usage.c \
		./lib/my/my_putstr.c \
		./lib/my/my_putchar.c \
		./lib/my/my_strcmp.c \
		./radar/src/screen/parsing/parsing.c \
		./radar/src/screen/parsing/dist.c \
		./radar/src/screen/parsing/calc_len.c \
		./radar/src/screen/tower/create_tower.c \
		./radar/src/screen/tower/tower.c \
		./radar/src/screen/plane/collision.c \
		./radar/src/screen/plane/functions.c \

NAME = my_radar

OBJ = $(SRC:.c=.o)

CFLAGS = -I ./include/

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS) -g3

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS) -g3

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)


re: fclean all
