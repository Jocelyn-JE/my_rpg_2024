##
## EPITECH PROJECT, 2024
## B-CPE-200-NAN-2-1-amazed-enoal.fauchille-bolle
## File description:
## Makefile
##

SRC =	src/main.c					\
		src/window/init.c			\
		src/app/init_app.c			\
		src/app/destroy_app.c		\
		src/linked_list/add.c		\
		src/linked_list/del.c		\
		src/linked_list/free_list.c	\
		src/linked_list/list_len.c	\
		src/debug/mini_printf.c		\
		src/debug/my_itoa.c			\
		src/debug/my_put_nbr.c		\
		src/debug/my_strcmp.c		\
		src/poll_events.c			\

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I ./include

LIBS	= -L ./libs -lm

NAME	=	my_rpg

CFLAGS += -Wall -Werror -Wshadow $(INCLUDES) $(LIBS) -g

CSFML	= -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

CC	= gcc

.PHONY	=	all re clean fclean lib

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)

re: fclean $(NAME)

clean:
	rm -f $(OBJ) *.gcda *.gcno src/main.o vgcore*

fclean: clean
	rm -f $(NAME)
