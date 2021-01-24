##
## EPITECH PROJECT, 2020
## lib/my/Makefile
## File description:
## evalexpr makefile
##

OUTPUTFILE 	=	calc

SRCC		=	main.c\
			eval_expr/calc.c\
			eval_expr/cond_function.c\
			eval_expr/cond_function2.c\
			eval_expr/conversion.c\
			eval_expr/do_op.c\
			eval_expr/eval_expr.c\
			infin_operator/infin_add.c\
			infin_operator/infin_sub.c\
			infin_operator/infin_mul.c\
			infin_operator/infin_div.c\
			infin_operator/infin_mod.c\
			translate_base.c\
			errors/brackets.c\
			errors/implicit_mul.c\
			errors/wrong_syntax.c

SRCO		=	$(SRCC:.c=.o)

all:	libcreate compile

libcreate:
	make -C lib/my all

compile: $(SRCO)
	gcc $(SRCO) -I./include -Llib/ -lmy -Wall -o $(OUTPUTFILE)

libclean:
	make -C ./lib/my clean

libfclean:
	make -C ./lib/my fclean

clean:
	rm $(SRCO)

fclean:
	rm $(SRCO)
	rm $(OUTPUTFILE)

re: fclean compile
