##
## EPITECH PROJECT, 2020
## make file
## File description:
## compile all the files
##

CPPFLAGS     =    -I include/

FILE	=	game/move_sprite.c				\
			game/move_sprites_2.c			\
			game/struct_animals.c			\
			game/struct_animals_2.c			\
			game/struct_other.c				\
			game/hunter_lists.c				\
			game/hunter_lists_2.c			\
			game/init_structs.c				\
			game/init_structs_2.c			\
			game/sprite_creator.c			\
			game/sprite_creator_2.c			\
			game/move_list.c				\
			game/free_list.c				\
			scoreboard/scoreboard.c			\
			scoreboard/scoreboard_sprite.c	\
			scoreboard/set_up_scoreboard.c	\
			menu/menu.c						\
			menu/menu_sprite.c				\
			menu/menu_other.c				\
			game/kill_sprites.c				\
			game/stop_all.c

NORMAL	=	game/main.c				\
			game/spawning.c			\
			game/system_fonctions.c

DEV		=	bonus/dev_commands/main_dev.c				\
			bonus/dev_commands/dev_command.c			\
			bonus/dev_commands/spawning_dev.c			\
			bonus/dev_commands/system_fonctions_dev.c

all:    lib
		cd lib/my && make
		gcc -o my_hunter $(FILE) $(NORMAL) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib -lmy $(CPPFLAGS)

run:
		gcc -o my_hunter $(FILE) $(NORMAL) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib -lmy $(CPPFLAGS)
		./my_hunter

dev:
		gcc -o my_hunter $(FILE) $(DEV) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib -lmy $(CPPFLAGS)
		./my_hunter

g:
		gcc -o my_hunter $(FILE) $(DEV) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib -lmy -g $(CPPFLAGS)

valgrind: g
		valgrind ./my_hunter
clean:
		rm -f *.o

fclean:	clean
		rm -f my_hunter
		cd lib/my && make fclean
		rm -f lib/libmy.a
		rm -f my_hunter

re:		fclean all