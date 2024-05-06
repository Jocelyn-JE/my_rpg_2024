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
		src/get_letterbox_view.c				\
		src/linked_list/add.c					\
		src/linked_list/del.c					\
		src/linked_list/free_list.c				\
		src/linked_list/list_len.c				\
		src/linked_list/list_reverse.c			\
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
		src/app/block_types/init_blocks.c		\
		src/app/block_types/vertex_util.c		\
		src/app/block_types/destroy_block.c		\
		src/app/block_types/air.c				\
		src/app/block_types/barrel.c			\
		src/app/block_types/beehive.c			\
		src/app/block_types/bookshelf.c			\
		src/app/block_types/cactus.c			\
		src/app/block_types/grass_block.c		\
		src/app/block_types/oak_log.c			\
		src/app/block_types/oak_planks.c		\
		src/app/block_types/stone.c				\
		src/app/block_types/sand.c				\
		src/app/block_types/dirt_path.c			\
		src/app/block_types/grass.c				\
		src/app/block_types/cobblestone.c		\
		src/app/block_types/dead_bush.c			\
		src/app/block_types/sandstone.c			\
		src/app/block_types/ice.c				\
		src/app/block_types/water.c				\
		src/app/block_types/jungle_log.c		\
		src/app/block_types/mossy_cobblestone.c	\
		src/app/block_types/fern.c				\
		src/app/chunk/add_cube.c				\
		src/app/chunk/create_chunk.c			\
		src/app/chunk/destroy_chunk.c			\
		src/app/entity/create_entity.c			\
		src/app/entity/destroy_entity.c			\
		src/app/entity/add_entity.c				\

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I ./include

LIBS	= -L ./libs -lm

NAME	=	my_rpg

CFLAGS += -Wall -Werror -Wshadow $(INCLUDES) $(LIBS) -g

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
