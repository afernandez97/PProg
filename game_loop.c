/**
@file game_loop.c
@version 4.0
@date 04-11-2016
@authors Guillermo Rodriguez and Alejandro Sanchez

@brief
It implements the game loop.

@version
Sept. 23, 2016 Version 1.0 (initial release)
@version
Sept. 23, 2016 Version 2.0 
	Commented the file.
@version
Oct. 08, 2016 Version 2.1 
	Added "Id object" and "Id player", and use them in 
	"game_init_from_file" after creating ADT Object and ADT Player. 
@version
Oct. 16, 2016 Version 3.0
	Added "Id die" and use it in "game_init_from_file" after 
	creating ADT Die. 
	Included <time.h> to use "time()".
@version
Oct. 27, 2016 Version 3.1
	Deleted "Id object" and added "argv[2] to "game_init_from_file".
@version
Nov. 04, 2016 Version 3.2
	Modified the function after creating ADT Command.
	Modified the function to generate a file with the results of 
	the execution.
@version
Nov. 26, 2016 Version 4.0
	Updated headers to use Doxygen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"


int main(int argc, char *argv[]){						
	Game * game = NULL;
	Command *command = NULL;
	Id die = 1;
	_STATUS status;
	FILE *f = NULL;
	T_Command cmd;

	int flag = 0, arg = 1, player = 0;
	char answer[WORD_SIZE];
	
	/* Check if user enters the name of the file that contains the spaces */	
	if(argc < 2){	
		fprintf(stderr, "Use (in this order): %s <game_data_path> (-l <log_file> < <entry_file>)\n", argv[0]); 
		return 1;
	}
	

	game = game_init_from_file(argv[arg], die);
	/* Check if game initializes correctly */
	if(game == NULL){	
		fprintf(stderr, "Error while initializing game.\n"); 
		return 1;
	}

	arg++;

	/* Check if user enters the command to register the results of the execution */
	if(argc > 3){
		if(strcmp(argv[arg], "-l") == 0){
			arg++;
			f = fopen(argv[arg], "w");
			if(!f){	 /* Check if the file has been opened correctly */
				game_destroy(game);
				return 1;
			}
		}
	}
	
	/* Game loop */
	while((command_get_cmd(command) != QUIT) && !game_is_over(game)){	
		game_print_screen(game, player);
		command_destroy(command); /* Destroy the previous command */
		command = get_user_input(game); 
		status = game_update(game, command, player); 
		/* If the file is open, print there the status of the last command */
		if(f != NULL){ 
			cmd = command_get_cmd(command);
			switch(cmd){
				case UNKNOWN:
					if(status == _OK){
						fprintf(f, "UNKNOWN: _OK\n");
					} else {
						fprintf(f, "UNKNOWN: _ERROR\n");
					}
					break;
				case QUIT:
					if(status == _OK){
						fprintf(f, "QUIT: _OK\n");
					} else{
						fprintf(f, "QUIT: _ERROR\n");
					}
					break;
				case CATCH:
					if(status == _OK){
						fprintf(f, "CATCH %s: _OK\n", command_get_arg(command));
					} else{
						fprintf(f, "CATCH %s: _ERROR\n", command_get_arg(command));
					}
					break;
				case LEAVE:
					if(status == _OK){
						fprintf(f, "LEAVE %s: _OK\n", command_get_arg(command));
					} else{
						fprintf(f, "LEAVE %s: _ERROR\n", command_get_arg(command));
					}
					break;
				case GO:
					if(status == _OK){
						fprintf(f, "GO %s: _OK\n", command_get_arg(command));
					} else{
						fprintf(f, "GO %s: _ERROR\n", command_get_arg(command));
					}
					break;
				case ROLL:
					if(status == _OK){
						fprintf(f, "ROLL: _OK\n");
					} else{
						fprintf(f, "ROLL: _ERROR\n");
					}
					break;
				case INSPECT:
					if(status == _OK){
						fprintf(f, "INSPECT %s: _OK\n", command_get_arg(command));
					} else{
						fprintf(f, "INSPECT %s: _ERROR\n", command_get_arg(command));
					}
				case NO_CMD:
					break;
				default: /* We must never arrive here */
					break;
			} /* switch */
		} /* if(f != NULL) */
	} /* while */ 
	
	/* If the file is open, close it */
	if(f != NULL){
		fclose(f);
	} 

	command_destroy(command); /* Destroy the command */
	game_destroy(game);	/* The game finishes */
		
	return 0;
}
