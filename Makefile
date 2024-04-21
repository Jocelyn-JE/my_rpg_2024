##
## EPITECH PROJECT, 2024
## B-CPE-200-NAN-2-1-amazed-enoal.fauchille-bolle
## File description:
## Makefile
##

SRC =	src/main.c								\
		src/poll_events.c						\
		src/random.c							\
		src/drag_view.c							\
		src/linked_list/add.c					\
		src/linked_list/del.c					\
		src/linked_list/free_list.c				\
		src/linked_list/list_len.c				\
		src/conversions/cartesian_to_iso.c		\
		src/conversions/index_to_pos.c			\
		src/conversions/clamp.c					\
		src/debug/print_fps.c					\
		src/debug/mini_printf.c					\
		src/debug/my_put_nbr.c					\
		src/debug/my_strcmp.c					\
		src/debug/draw_bounding_box.c			\
		src/app/init_app.c						\
		src/app/init_window.c					\
		src/app/destroy_app.c					\
		src/app/chunk/add_cube.c				\
		src/app/chunk/create_chunk.c			\
		src/app/chunk/destroy_chunk.c			\

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
