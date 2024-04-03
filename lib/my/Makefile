##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my lib
##

NAME	=	libmy.a

SRC	=	my_putchar.c		\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_find_prime_sup.c	\
		my_getnbr_base.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_show_word_array.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strdup.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_str_to_word_array.c	\
		my_strupcase.c		\
		my_swap.c		\
		put_nbr/my_put_nbr.c		\
		put_nbr/my_put_unsigned.c	\
		put_nbr/extras_nbr.c		\
		put_nbr/my_putnbr_base.c	\
		printf/my_printf.c	\
		printf/parsing.c	\
		printf/specifiers/flag_c.c	\
		printf/specifiers/flag_d_i.c	\
		printf/specifiers/flag_o.c	\
		printf/specifiers/flag_p.c	\
		printf/specifiers/flag_s.c	\
		printf/specifiers/flag_u.c	\
		printf/specifiers/flag_xx.c	\
		printf/specifiers/flag_perc.c

OBJ	=	gcc -c $(SRC)

all:
	cp printf/my_printf.h .
	cp my_printf.h ../../include
	cp my.h ../../include
	$(OBJ)
	ar rc $(NAME) *.o
	cp $(NAME) ../
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
