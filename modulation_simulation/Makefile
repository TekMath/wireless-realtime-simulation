###############################################
# Makefile for modulation_simulation project  #
# Author: TekMath                         	  #
# Date: 2025-01-09                            #
###############################################

MAIN 	=		main.c
SRC		=		src/encode.c \
				src/noise.c \
				src/decode.c \
				src/debug.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

CFLAGS 	=		-Wall -Iinclude -lm

NAME 	= 		simulator

all:			$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
