##
## EPITECH PROJECT, 2024
## B-CPE-200-NAN-2-1-amazed-enoal.fauchille-bolle
## File description:
## Makefile
##

SRC =	src/main.c												\
		src/linked_list/add.c									\
		src/linked_list/del.c									\
		src/linked_list/free_list.c								\
		src/linked_list/list_len.c								\
		src/linked_list/list_reverse.c							\
		src/conversions/cartesian_to_iso.c						\
		src/conversions/index_to_pos.c							\
		src/conversions/clamp.c									\
		src/conversions/random.c								\
		src/conversions/get_chunk_coords.c						\
		src/debug/print_fps.c									\
		src/debug/mini_printf.c									\
		src/debug/my_put_nbr.c									\
		src/debug/my_strcmp.c									\
		src/debug/draw_bounding_box.c							\
		src/app/init_app.c										\
		src/app/init_window.c									\
		src/app/destroy_app.c									\
		src/app/block_types/init_blocks.c						\
		src/app/block_types/update_blocks.c						\
		src/app/block_types/rotated_faces.c						\
		src/app/block_types/vertex_util.c						\
		src/app/block_types/destroy_block.c						\
		src/app/block_types/air.c								\
		src/app/block_types/barrel.c							\
		src/app/block_types/beehive.c							\
		src/app/block_types/bookshelf.c							\
		src/app/block_types/cactus.c							\
		src/app/block_types/grass_block.c						\
		src/app/block_types/oak_log.c							\
		src/app/block_types/spruce_log.c						\
		src/app/block_types/planks.c							\
		src/app/block_types/stone.c								\
		src/app/block_types/sand.c								\
		src/app/block_types/dirt_path.c							\
		src/app/block_types/grass.c								\
		src/app/block_types/cobblestone.c						\
		src/app/block_types/dead_bush.c							\
		src/app/block_types/sandstone.c							\
		src/app/block_types/ice.c								\
		src/app/block_types/water.c								\
		src/app/block_types/jungle_log.c						\
		src/app/block_types/mossy_cobblestone.c					\
		src/app/block_types/fern.c								\
		src/app/block_types/poppy.c								\
		src/app/block_types/dandelion.c							\
		src/app/block_types/wheat.c								\
		src/app/block_types/beetroots.c							\
		src/app/block_types/white_wool.c						\
		src/app/block_types/oak_wood.c							\
		src/app/block_types/leaves.c							\
		src/app/block_types/snow.c								\
		src/app/block_types/end_stone_bricks.c					\
		src/app/block_types/stripped_birch_wood.c				\
		src/app/block_types/hay_block.c							\
		src/app/block_types/dirt.c								\
		src/app/block_types/concrete_powder.c					\
		src/app/block_types/concrete.c							\
		src/app/block_types/dead_coral.c						\
		src/app/block_types/moss.c								\
		src/app/block_types/quartz.c							\
		src/app/block_types/lava.c								\
		src/app/block_types/blackstone.c						\
		src/app/block_types/polished_blackstone.c				\
		src/app/block_types/coal_block.c						\
		src/app/block_types/obsidian.c							\
		src/app/block_types/magma_block.c						\
		src/app/chunk/add_cube.c								\
		src/app/chunk/create_chunk.c							\
		src/app/chunk/destroy_chunk.c							\
		src/app/chunk/get_block.c								\
		src/app/entity/create_entity.c							\
		src/app/entity/destroy_entity.c							\
		src/app/entity/add_entity.c								\
		src/app/inventory/events/manage_inventory_events.c		\
		src/app/game/events/manage_game_events.c 				\
		src/app/game/events/drag_view.c							\
		src/app/game/movement.c									\
		src/app/game/render_game.c								\
		src/events/get_letterbox_view.c							\
		src/events/handle_closed.c								\
		src/app/game/events/handle_key_pressed.c 				\
		src/app/inventory/events/handle_key_pressed.c			\
		src/app/inventory/events/handle_mouse_button_pressed.c	\
		src/app/inventory/events/handle_mouse_moved.c			\
		src/app/game/events/handle_mouse_wheel.c 				\
		src/events/handle_resized.c								\
		src/app/inventory/events/manage_armor_slots.c			\
		src/app/inventory/events/handle_mouse_right.c			\
		src/app/inventory/inventory_management.c 				\
		src/app/inventory/inventory_setup.c						\
		src/app/inventory/hotbar_management.c 					\
		src/app/inventory/is_armor.c							\
		src/app/inventory/draw_highlighted_slot.c 				\
		src/app/inventory/free_functions.c						\
		src/conversions/get_slot_index.c						\
		src/conversions/get_armor_index.c						\
		src/debug/draw_bounds.c									\
		src/app/splash_screen/splash_screen.c					\
		src/text_and_button/set_text.c							\
		src/text_and_button/set_button.c						\
		src/app/menu/menu.c										\
		src/app/menu/events/click_button.c						\
		src/app/menu/events/poll_events_menu.c					\
		src/app/setting/setting.c								\
		src/app/setting/sound/parameter_sound.c					\
		src/app/setting/video/parameter_video.c					\

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I ./include

LIBS	= -L ./libs -lm

NAME	=	my_rpg

CFLAGS += -Wall -Wextra -Wshadow $(INCLUDES) $(LIBS) -g

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

cs:		fclean
		@coding-style . .
		@cat coding-style-reports.log
		@rm -f coding-style-reports.log

tests_run: $(NAME)
	valgrind $(VALGRIND_FLAGS)./$(NAME) &

run: all
	./$(NAME)
