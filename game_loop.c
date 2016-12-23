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
#include "graphic_engine.h"
#include "dialogue.h"


int main(int argc, char *argv[]){						
	Game * game = NULL;
	Command *command = NULL;
	Id die = 1;
	STATUS_ status;
	FILE *f = NULL;
	T_Command cmd;
	Dialogue *dialogue = NULL;
	int arg = 1, player = 0, num;
	
	/* Check if user enters the name of the file that contains the spaces */	
	if(argc < 2){	
		fprintf(stderr, "Use (in this order): %s <game_data_path> (-l <log_file> < <entry_file>)\n", argv[0]); 
		return 1;
	}
	
	dialogue = dialogue_create ();
	/* Check if dialogue initializes correctly */
	if (!dialogue){
		return 1;
	}

	game = game_init_from_file(argv[arg], die, TRUE_);
	/* Check if game initializes correctly */
	if(game == NULL){	
		fprintf(stderr, "Error while initializing game.\n");
		dialogue_destroy (dialogue); 
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
				dialogue_destroy (dialogue);
				return 1;
			}
		}
	}

	/* Game loop */
	while((command_get_cmd(command) != QUIT) && !game_is_over(game)){	
		num = game_get_num_players(game);
		game_print_screen(game, player);
		game_screen_refresh(game);
		dialogue_set_command_prev(dialogue,command,status);
		command_destroy(command); /* Destroy the previous command */
		game_set_text(game, "");
		command = get_user_input(game);
		status = game_update(game, command, &player, num, die);
		dialogue_set_command_act(dialogue, command, status);
		dialogue_set_text(dialogue);
		game_add_text(game, dialogue_get_text(dialogue));
		/* If the file is open, print there the status of the last command */
		if(f != NULL){ 
			cmd = command_get_cmd(command);
			switch(cmd){
				case UNKNOWN:
					if(status == OK_){
						fprintf(f, "UNKNOWN: OK_\n");
					} else {
						fprintf(f, "UNKNOWN: ERROR_\n");
					}
					break;
				case QUIT:
					if(status == OK_){
						fprintf(f, "QUIT: OK_\n");
					} else{
						fprintf(f, "QUIT: ERROR_\n");
					}
					break;
				case CATCH:
					if(status == OK_){
						fprintf(f, "CATCH %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "CATCH %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case LEAVE:
					if(status == OK_){
						fprintf(f, "LEAVE %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "LEAVE %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case GO:
					if(status == OK_){
						fprintf(f, "GO %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "GO %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case ROLL:
					if(status == OK_){
						fprintf(f, "ROLL: OK_\n");
					} else{
						fprintf(f, "ROLL: ERROR_\n");
					}
					break;
				case INSPECT:
					if(status == OK_){
						fprintf(f, "INSPECT %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "INSPECT %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case TURNON:
					if(status == OK_){
						fprintf(f, "TURNON %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "TURNON %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case TURNOFF:
					if(status == OK_){
						fprintf(f, "TURNOFF %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "TURNOFF %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case OPENL:
					if(status == OK_){
						fprintf(f, "OPENL %s WITH %s: OK_\n", command_get_arg(command), command_get_arg2(command));
					} else{
						fprintf(f, "OPENL %s WITH %s: ERROR_\n", command_get_arg(command), command_get_arg2(command));
					}
					break;

				case LOAD:
					if(status == OK_){
						fprintf(f, "LOAD GAME IN %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "LOAD GAME IN %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case SAVE:
					if(status == OK_){
						fprintf(f, "SAVE GAME IN %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "SAVE GAME IN %s: ERROR_\n", command_get_arg(command));
					}
					break;

				case BUY:
					if(status == OK_){
						fprintf(f, "BUY %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "BUY %s: ERROR_\n", command_get_arg(command));
					}
					break;

				case SELL:
					if(status == OK_){
						fprintf(f, "SELL %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "SELL %s: ERROR_\n", command_get_arg(command));
					}
					break;
				case ANSWER:
					if(status == OK_){
						fprintf(f, "ANSWER  %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "ANSWER %s: ERROR_\n", command_get_arg(command));
					}
					break;	
				case TALK:
					if(status == OK_){
						fprintf(f, "TALK  %s: OK_\n", command_get_arg(command));
					} else{
						fprintf(f, "TALK %s: ERROR_\n", command_get_arg(command));
					}
					break;							
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
	dialogue_destroy(dialogue);	/* Destroy the dialogue */
	game_destroy_screen(game); 	/* Destroy the screen */
	game_destroy(game); 	/* The game finishes */
	
	printf("\n\n\nCONGRATULATIONS: YOU HAVE FAILED CIREL ;)\n\n\n\n");
	return 0;
}
