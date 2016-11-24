# Author: Guillermo Rodriguez and Alejandro Sanchez

all: ocabas die_test set_test player_test inventory_test space_test link_test

CCFLAGS = -g -Wall -pedantic -ansi -c

ocabas: game.o game_loop.o space.o command.o game_reader.o object.o player.o die.o set.o inventory.o link.o
	gcc -o $@ $^ 

die_test: die_test.o die.o
	gcc -o $@ $^ 

player_test: player_test.o player.o inventory.o set.o
	gcc -o $@ $^ 

inventory_test: inventory_test.o inventory.o set.o
	gcc -o $@ $^ 

set_test: set_test.o set.o
	gcc -o $@ $^ 

space_test: space_test.o space.o
	gcc -o $@ $^ 

link_test: link_test.o link.o
	gcc -o $@ $^

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

game.o: game.c game.h 
	gcc $(CCFLAGS) game.c

game_loop.o: game_loop.c game.h
	gcc $(CCFLAGS) game_loop.c

space.o: space.c space.h types.h
	gcc $(CCFLAGS) space.c

command.o: command.c command.h types.h
	gcc $(CCFLAGS) command.c

game_reader.o: game_reader.c game_reader.h
	gcc $(CCFLAGS) game_reader.c

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

clean: 
	rm -rf *.o *.tgz *.log ocabas *_test

dist: 
	tar -cvzf s2-cod_OcaBasicaIni-2.tgz *c *h Makefile *dat 
