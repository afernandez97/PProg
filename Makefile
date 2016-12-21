# Author: Guillermo Rodriguez and Alejandro Sanchez

all: JuegoOcaPlus 

test: die_test set_test player_test inventory_test space_test link_test object_test graphic_engine_test game_rules_test dialogue_test person_test

CCFLAGS = -g -Wall -pedantic -ansi -c
NCURSESFLAG = -lncurses

JuegoOcaPlus: space.o game_management.o object.o player.o die.o set.o inventory.o link.o graphic_engine.o dialogue.o game_rules.o person.o game.o game_loop.o command.o
	gcc -o $@ $^ $(NCURSESFLAG)

#Tests
die_test: die_test.o die.o
	gcc -o $@ $^ 

player_test: player_test.o player.o inventory.o set.o
	gcc -o $@ $^ 

inventory_test: inventory_test.o inventory.o set.o
	gcc -o $@ $^ 

set_test: set_test.o set.o
	gcc -o $@ $^ 

space_test: space_test.o space.o set.o
	gcc -o $@ $^ 

object_test: object_test.o object.o
	gcc -o $@ $^

link_test: link_test.o link.o
	gcc -o $@ $^

graphic_engine_test: graphic_engine_test.o graphic_engine.o
	gcc -o $@ $^ $(NCURSESFLAG)

die_test.o: die_test.c die.c die.h types.h
	gcc $(CCFLAGS) die_test.c die.c

player_test.o: player_test.c player_test.h types.h 
	gcc $(CCFLAGS) player_test.c

inventory_test.o: inventory_test.c inventory_test.h types.h 
	gcc $(CCFLAGS) inventory_test.c

set_test.o: set_test.c set.c set.h types.h
	gcc $(CCFLAGS) set_test.c set.c

space_test.o: space_test.c space_test.h types.h
	gcc $(CCFLAGS) space_test.c 

link_test.o: link_test.c link_test.h types.h
	gcc $(CCFLAGS) link_test.c

graphic_engine_test.o: graphic_engine_test.c graphic_engine_test.h types.h
	gcc $(CCFLAGS) graphic_engine_test.c

game_rules_test.o: game_rules_test.c game_rules_test.h types.h
	gcc $(CCFLAGS) game_rules_test.c

dialogue_test.o: dialogue_test.c dialogue_test.h types.h
	gcc $(CCFLAGS) dialogue_test.c

person_test.o: person_test.c person_test.h types.h
	gcc $(CCFLAGS) person_test.c


game_loop.o: game_loop.c game.h
	gcc $(CCFLAGS) game_loop.c

game_rules.o: game_rules.c game_rules.h
	gcc $(CCFLAGS) game_rules.c

space.o: space.c space.h types.h
	gcc $(CCFLAGS) space.c

command.o: command.c command.h types.h
	gcc $(CCFLAGS) command.c

game_management.o: game_management.c game_management.h
	gcc $(CCFLAGS) game_management.c

object.o: object.c object.h types.h
	gcc $(CCFLAGS) object.c

player.o: player.c player.h types.h
	gcc $(CCFLAGS) player.c

die.o: die.c die.h types.h
	gcc $(CCFLAGS) die.c

set.o: set.c set.h types.h
	gcc $(CCFLAGS) set.c

inventory.o: inventory.c inventory.h 
	gcc $(CCFLAGS) inventory.c

link.o: link.c link.h
	gcc $(CCFLAGS) link.c

graphic_engine.o: graphic_engine.c graphic_engine.h
	gcc $(CCFLAGS) graphic_engine.c

dialogue.o: dialogue.c dialogue.h
	gcc $(CCFLAGS) dialogue.c

person.o: person.c person.h
	gcc $(CCFLAGS) person.c

game.o: game.c game.h command.h dialogue.h graphic_engine.h object.h person.h link.h set.h die.h game_management.h space.h game_rules.h
	gcc $(CCFLAGS) game.c

#clean and dist
clean: 
	rm -rf *.o *.tgz *.log JuegoOcaPlus *_test *bak Doxyfile html latex 

dist: 
	tar -cvzf I4-cod_JuegoOcaPlus.tgz *c *h Makefile *dat #html latex Doxyfile
