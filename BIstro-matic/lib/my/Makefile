##
## EPITECH PROJECT, 2020
## lib/my/Makefile
## File description:
## library makefile
##

OUTPUTFILE	=	libmy.a

SRCC		=	./my_str_isupper.c\
			./my_showstr.c\
			./my_revstr.c\
			./my_putchar.c\
			./my_strncat.c\
			./my_putstr.c\
			./my_str_isalpha.c\
			./my_getnbr.c\
			./my_compute_power_rec.c\
			./my_strcpy.c\
			./my_sort_int_array.c\
			./my_str_isnum.c\
			./my_strlen.c\
			./my_strlowcase.c\
			./my_swap.c\
			./my_str_islower.c\
			./my_strcapitalize.c\
			./my_strcmp.c\
			./my_strncpy.c\
			./my_strupcase.c\
			./my_is_prime.c\
			./my_compute_square_root.c\
			./my_strncmp.c\
			./my_isneg.c\
			./my_strstr.c\
			./my_strcat.c\
			./my_find_prime_sup.c\
			./my_str_isprintable.c\
			./my_put_nbr.c\
			./my_showmem.c\
			./my_strdup.c

SRCO		=	$(SRCC:.c=.o)
SRCH		=	./my.h\
			./my_err.h\
			./bistromatic.h\
			./my_evalexpr.h

all:
		gcc -c $(SRCC)
		ar rc $(OUTPUTFILE) $(SRCO)
		cp $(OUTPUTFILE) ../
		mkdir -p ../../include;
		cp $(SRCH) ../../include/
		rm $(SRCO)

clean:
	rm $(SRCO)

fclean: clean
	rm $(OUTPUTFILE) ../$(OUTPUTFILE)

re: fclean all
