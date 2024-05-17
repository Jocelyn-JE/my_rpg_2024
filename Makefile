##
## EPITECH PROJECT, 2024
## B-CPE-200-NAN-2-1-amazed-enoal.fauchille-bolle
## File description:
## Makefile
##

SRC =	src/main.c									\
		src/app/init_app.c							\
		src/app/destroy_app.c						\
		src/linked_list/add.c						\
		src/linked_list/del.c						\
		src/linked_list/free_list.c					\
		src/linked_list/list_len.c					\
		src/debug/mini_printf.c						\
		src/debug/my_put_nbr.c						\
		src/debug/my_strcmp.c						\
		src/poll_events.c							\
		src/app/splash_screen/splash_screen.c		\
		src/random.c								\
		src/drag_view.c								\
		src/get_letterbox_view.c					\
		src/conversions/cartesian_to_iso.c			\
		src/conversions/index_to_pos.c				\
		src/conversions/clamp.c						\
		src/debug/print_fps.c						\
		src/debug/draw_bounding_box.c				\
		src/app/init_window.c						\
		src/app/chunk/add_cube.c					\
		src/app/chunk/create_chunk.c				\
		src/app/chunk/destroy_chunk.c				\
		src/text_and_button/set_text.c				\
		src/text_and_button/set_button.c			\
		src/app/menu/menu.c							\
		src/app/menu/events/click_buton.c			\
		src/app/menu/events/poll_events_menu.c		\
		src/app/setting/setting.c					\
		src/app/setting/sound/parameter_sound.c		\
		src/app/setting/video/parameter_video.c		\
		src/events/handle_resized.c					\

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I ./include

LIBS	= -L ./libs -lm

NAME	=	my_rpg

CFLAGS += -Wall -Werror -Wshadow $(INCLUDES) $(LIBS) -g -pg

CSFML	= -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

CC	= gcc

CLEAN	=	*.gcda *.gcno src/main.o vgcore* gmon.out valgrind.*

VALGRIND_LOG	=	valgrind.log

VALGRIND_FLAGS	=	--leak-check=full					\
					--show-leak-kinds=definite			\
					--track-origins=yes					\
					--errors-for-leak-kinds=definite	\
					--log-file="$(VALGRIND_LOG)"		\

.PHONY	=	all re clean fclean lib tests_run prof

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)

prof: re $(OBJ)
	./$(NAME)
	gprof $(NAME) | gprof2dot | dot -Tpng -o output.png

re: fclean $(NAME)

clean:
	rm -f $(OBJ) $(VALGRIND_LOG) $(CLEAN)

fclean: clean
	rm -f $(NAME)

tests_run: $(NAME)
	valgrind $(VALGRIND_FLAGS)./$(NAME) &

run: all
	./$(NAME)
