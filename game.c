/* =================================================================== 
   File: game.c
   Version: 4.0
   Date: 05-11-2016
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description:
    It implements the game interface and all the associated callbacks
    for each command.

   Revision history:
    Jan. 13, 2015 Version 1.0 (initial release)
    Sept. 23, 2016  Version 2.0 
      Commented the file.
    Oct. 04, 2016 Version 2.1
      Changed "Id player_location" and "Id object_location" fields 
      for "Player *player" and "Object *object".
      Added macros for each structure field.
      Added input control to the functions.
      Added two inputs (player and object) to "game_init" and 
      "game_init_from_file" after creating ADT Player and ADT Object. 
    Oct. 08, 2016 Version 2.2
      Added callbacks CATCH and LEAVE.
      Changed "game_set_player_location", "game_get_player_location", 
      "game_set_object_location" and "game_get_object_location".
		Oct. 20, 2016 Version 3.0
      Modified some functions after creating ADT Die and ADT Set.
      Added callback ROLL.
    Oct. 27, 2016 Version 3.1
			Created function "game_get_object".
      Made public the function "game_get_space".
    Oct. 30, 2016 Version 3.2
      Modified "game_set_player_location", "game_get_player_location", 
      "game_set_object_location" and "game_get_object_location".
    Nov. 02, 2016 Version 3.3
      Created function "game_print_objects" and modified function 
      "game_print_screen" to show the graphic description.
    Nov. 04, 2016 Version 3.4
      Modified callbacks CATCH and LEAVE to receive input's argument.
      Modified "game_update" and callbacks to return a status.
    Nov. 05, 2016 Version 4.0
      Made "Game" structure private.
      Modified some functions after this change.
      Added command GO and removed commands NEXT, BACK and JUMP.
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

#ifdef __WINDOWS_BUILD__
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/*** Constant values description ***/
#define player(X) (X)->player
#define spaces(X) (X)->spaces
#define objects(X) (X)->objects
#define die(X) (X)->die
#define links(X) (X)->links

/* Data structure definition and description */
/*** The Game structure stores information of the game and its elements ***/
struct _Game{
  Player *player; /* Player of the game */
  Object *objects[MAX_OBJECTS + 1]; /* Objects of the game */
  Space *spaces[MAX_SPACES + 1]; /* Spaces of the game */
  Die *die; /* Die of the game*/ 
  Link *links[MAX_LINKS + 1]; /* Links of the game */
};


/*** List of callbacks for each command in the game ***/
STATUS callback_UNKNOWN(Game *game);
STATUS callback_QUIT(Game *game);
STATUS callback_CATCH(Game *game, char *arg);
STATUS callback_LEAVE(Game *game, char *arg);
STATUS callback_ROLL(Game *game);
STATUS callback_GO(Game *game, char *arg);

/*** Private functions description ***/
Id game_get_space_id_at(Game *game, int position);

Object * game_get_object(Game *game, Id id);

STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);

STATUS game_set_object_location(Game *game, Id object, Id id);
Id game_get_object_location(Game *game, Id object);


/*** Game interface implementation ***/
/*** Public functions definition ***/
/* --------------------------------------------------------------------
   Function: game_init
   Date: 05-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Initializes a game.

   Input: 
    Id player: the identifier of the player of the game.
    Id die: the identifier of the die of the game.

   Output: 
    Game *game: the game initialized.
   -------------------------------------------------------------------- */
Game * game_init(Id player, Id die){
  int i;
  Game *game=NULL;

  /* Check that the inputs are not empty */ 
  if(player == NO_ID || !objects(game) || die == NO_ID){  
    return NULL;
  }

  game = (Game *)malloc(sizeof(Game));
  if(!game){    /* Check if memory has been allocated */
		return NULL;
  }
  for(i=0; i < MAX_SPACES; i++){  
    spaces(game)[i] = NULL;   /* Initialize to NULL each space */
  }
    
  player(game) = player_create(player); /* Create a player */
  if(!player(game)){	 /* Check if memory has been allocated */
    free(game);
    return NULL;
  }

  for(i=0; i < MAX_OBJECTS; i++){  
    objects(game)[i] = NULL;   /* Initialize to NULL each object */
  }

  die(game) = die_create(die);  /* Create a die */
  if(!die(game)){   /* Check if memory has been allocated */
	  player_destroy(player(game));  /* Free the memory that you created */
    free(game);
    return NULL;
    
  }
  return game;
}



/* --------------------------------------------------------------------
   Function: game_init_from_file
   Date: 05-11-2016 
   Author: Guillermo Rodriguez

   Description: 
    Initializes a game from two files which contain the spaces and objects.

   Input: 
    char *filename1: the file that contains the spaces.
    char *filename2: the file that contains the objects.
    Id player: the identifier of the player of the game.
    Id die: the identifier of the die of the game.
   
   Output: 
    Game *game: the game initialized.
   -------------------------------------------------------------------- */
Game * game_init_from_file(char *filename1, char *filename2, Id player, Id die){
  Game *game = NULL;

  /* Check that the inputs are not empty */ 
  if(!filename1 || !filename2 || player == NO_ID || !objects(game) || die == NO_ID){  
    return NULL;
  }

  /* Initialize the elements of the game and check if it has worked */
  game = game_init(player, die);
  if(!game){
    game_destroy(game); 
    return NULL; 
  }

  /* Load the spaces from the file and check if it has worked */
  if(game_load_spaces(game, filename1) == ERROR){ 
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  }

  if(game_load_objects(game, filename2) == ERROR){
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  }	

  /* Set the player on the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0)); 
  
  return game;
}



/* --------------------------------------------------------------------
   Function: game_destroy
   Date: 05-11-2016 
   Author: Guillermo Rodriguez

   Description: 
    Destroys a game.

   Input: 
    Game *game: the game to destroy.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_destroy(Game *game){
  int i;

  if(!game){  /* Check that the input is not empty */
    return ERROR;
  }

  /* Destroy the player */
  player_destroy(player(game));
  
  /* Destroy the die */
  die_destroy(die(game));

  /* Destroy the spaces */
  for(i=0; i < MAX_SPACES; i++){
    space_destroy(spaces(game)[i]);
  }
  /* Destroy the objects */
  for(i=0; i < MAX_OBJECTS; i++){
    object_destroy(objects(game)[i]);
  }

  free(game);   /* Eliminate the memory of the game */ 

  return OK;
}



/* --------------------------------------------------------------------
   Function: game_update
   Date: 05-11-2016 
   Author: Guillermo Rodriguez

   Description: 
    Updates a game.

   Input: 
    Game *game: the game to update.
    Command *cmd: the command typed by the user.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_update(Game *game, Command *command){
  T_Command cmd;
  char arg[CMD_LENGTH] = "";
  STATUS status = ERROR;

  if(!game || !command){ /* Check that the inputs are not empty */
    return ERROR;
  }

  cmd = command_get_cmd(command);
  strcpy(arg, command_get_arg(command));
  /* Call a function depending on the command */
  switch(cmd){
    case UNKNOWN:
      status = callback_UNKNOWN(game);
      break;
    case QUIT:
      status = callback_QUIT(game);
      break;
    case CATCH:
      status = callback_CATCH(game, arg);
      break;
    case LEAVE:
      status = callback_LEAVE(game, arg);
      break;
    case GO:
      status = callback_GO(game, arg);
      break;
    case ROLL:
	    status = callback_ROLL(game);
      break;
    case NO_CMD:
      break;
    default: /* We must never arrive here */
      break;
  }
  return status;
}



/* --------------------------------------------------------------------
   Function: game_get_space
   Date: 04-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives a specific space.

   Input: 
    Game *game: the game where the space is.
    Id id: the id of the space you want.

   Output: 
    Space *: the space you want or NULL on error.
   -------------------------------------------------------------------- */
Space * game_get_space(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
  
  return NULL;
  }

  /* Look for the space you want */
  for(i=0; i < MAX_SPACES && spaces(game)[i] != NULL; i++){
    if(id == space_get_id(spaces(game)[i])){
      return spaces(game)[i];
    }
  }
    
  return NULL;
}



/* --------------------------------------------------------------------
   Function: game_is_over
   Date: 23-09-2016 
   Author: Alejandro Sanchez

   Description: 
    Ends the game.

   Input: 
    Game *game: the game to end.

   Output: 
    BOOL: FALSE.
   -------------------------------------------------------------------- */
BOOL game_is_over(Game *game){
    return FALSE;
}



/* --------------------------------------------------------------------
   Function: game_print_data
   Date: 20-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Prints the data of the game.

   Input: 
    Game *game: the game to print its elements.

   Output: 

   -------------------------------------------------------------------- */
void game_print_data(Game *game){
  int i;

  if(!game){  /* Check that the input is not empty */
    return;
  }
    
  printf("\n\n-------------\n\n");
  
  /* Print the spaces */  
  printf("=> Spaces: \n");
  for(i=0; i < MAX_SPACES && spaces(game)[i] != NULL; i++){
    space_print(spaces(game)[i]);
  }
  
  /* Print the objects */
  printf("=> Objects: \n");
  for(i=0; i < MAX_OBJECTS && objects(game)[i] != NULL; i++){
    object_print(objects(game)[i]);
  }

  /* Print the die information */  
  die_print(die(game));

  /* Print the player location */
  printf("=> Player location: %d\n", (int)game_get_player_location(game));
  /* Print the objects location */
  for(i=0; i < MAX_OBJECTS && objects(game)[i] != NULL; i++){
     object_print(objects(game)[i]);
  }
  
  return;
}



/* --------------------------------------------------------------------
   Function: game_print_objects
   Date: 02-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Prints the objects of the game (<name>:<location>).

   Input: 
    Game *game: the game to print its objects.
    Space *space: the space where you want to print the objects.

   Output: 

   -------------------------------------------------------------------- */
void game_print_objects(Game *game, Space *space){
  int i, count;
  char *name = NULL;
  Set *set = NULL;
  Object *object = NULL;

  /* Start printing the row of the space */
  fprintf(stdout, " |");
  /* Get the set of objects on the space and how many are there */
  set = space_get_object(space);
  count = set_get_count(set);
  /* Get the different names of the objects and print them */
  for(i=0; i<count; i++){    
    object = game_get_object(game, set_get_object_at_position(set, i));
    name = object_get_name(object);
    /* Maximum three objects per space */   
    if(i < 3){             
      fprintf(stdout, "%s ", name);
    }
  }

  /* Print the rest of the row. The way depends on the number of objects */
  switch(i){
    /* 0 objects */
    case 0:
       fprintf(stdout, "           |\n");
       break;
    /* 1 object */
    case 1:
       fprintf(stdout, "        |\n");
       break;
    /* 2 objects */
    case 2:
       fprintf(stdout, "     |\n");
       break;
    /* 3 objects */
    case 3:
       fprintf(stdout, "  |\n");
       break; 
    /* More than 3 objects */
    default:
       fprintf(stdout, "..|\n");  
       break;
  }

  return; 
}



/* --------------------------------------------------------------------
   Function: game_print_screen
   Date: 02-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Prints the screen of the game.

   Input: 
    Game *game: the game to print its screen.

   Output: 

   -------------------------------------------------------------------- */
void game_print_screen(Game *game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID;
  Id id_west = NO_ID, id_obj = NO_ID;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  char *name = NULL;
  Object *object = NULL;
  int i, count;
  Set *set; 
    
  if(!game){ /* Check that the input is not empty */
    return;
  }  

  /* Get actual location of the player */
  id_act = game_get_player_location(game);  
  if(id_act == NO_ID){  /* Check if it has worked */
    return;
  }
  
  /* Get the space where the player is */  
  space_act = game_get_space(game, id_act);

  /* Get the previous space */
  id_back = space_get_north(space_act);
  space_back = game_get_space(game, id_back); 

  /* Get the next space */
  id_next = space_get_south(space_act);
  space_next = game_get_space(game, id_next); 
  
  /* Get the locations of the eastern and western spaces */
  id_east = space_get_east(space_act);
  id_west = space_get_west(space_act);
   
  if(system(CLEAR)){
    return; 
  }

  /* Print the previous space if it is different from NO_ID */
  if(id_back != NO_ID){
   	if(space_get_east(space_back) != NO_ID){
        printf(" |         %2d|>\n", (int)id_back);
      	space_print_gdesc(space_back);
      	printf(" |           |\n");
      	game_print_objects(game, space_back);
		  	printf(" +-----------+\n");
    		printf("       ^\n");
		} else if(space_get_west(space_back) != NO_ID){
        printf("<|         %2d|\n", (int)id_back);
				space_print_gdesc(space_back);
				printf(" |           |\n");
        game_print_objects(game, space_back);
        printf(" +-----------+\n");
    		printf("       ^\n");		
		} else{
        printf(" |         %2d|\n", (int) id_back);
				space_print_gdesc(space_back);
				printf(" |           |\n");
        game_print_objects(game, space_back);
				printf(" +-----------+\n");
				printf("       ^\n");
		}
  }
  
  /* Print the actual space if it is different from NO_ID */
  if(id_act != NO_ID){
  	if(id_east != NO_ID){
  			printf(" +-----------+\n");
		  	printf(" | >8D     %2d|>\n", (int)id_act);
		  	space_print_gdesc(space_act);
		  	printf(" |           |\n");
        game_print_objects(game, space_act);	
		  	printf(" +-----------+\n");
		} else if(id_west != NO_ID){
				printf(" +-----------+\n");
				printf("<| >8D     %2d|\n", (int)id_act);
				space_print_gdesc(space_act);
				printf(" |           |\n");
        game_print_objects(game, space_act);	
				printf(" +-----------+\n");			
		} else{
				printf(" +-----------+\n");
				printf(" | >8D     %2d|\n", (int)id_act);
				space_print_gdesc(space_act);
				printf(" |           |\n");
        game_print_objects(game, space_act);
				printf(" +-----------+\n");
		}
  }
    
  /* Print the next space if it is different from NO_ID */ 
  if(id_next != NO_ID){
   	if(space_get_east(space_next) != NO_ID){
				printf("       v\n");
				printf(" +-----------+\n");
				printf(" |         %2d|>\n", (int)id_next);
				space_print_gdesc(space_next);
				printf(" |           |\n");
        game_print_objects(game, space_next);
        
		} else if(space_get_west(space_next) != NO_ID){
				printf("       v\n");
				printf(" +-----------+\n");
				printf("<|         %2d|\n", (int)id_next);
				space_print_gdesc(space_next);
				printf(" |           |\n");
        game_print_objects(game, space_next);
		} else{
				printf("       v\n");
				printf(" +-----------+\n");
				printf(" |         %2d|\n", (int)id_next);
				space_print_gdesc(space_next);
				printf(" |           |\n");
        game_print_objects(game, space_next);
		}
  }

  /* Print the objects location */
  printf("\nObjects location: ");
  for(i=0; i<MAX_OBJECTS && objects(game)[i] != NULL; i++){
    id_obj = object_get_location(objects(game)[i]);
    name = object_get_name(objects(game)[i]);
    if(id_obj != NO_ID){
      printf("%s:%2d ", name, (int)id_obj);
    }
  }

  /* Print the objects of the game*/  
  set = player_get_object(player(game));
  count = set_get_count(set);
  printf("\nPlayer objects: ");
  /* Get the different names of the objects and print them */
	for(i=0; i<count; i++){    
	  object = game_get_object(game, set_get_object_at_position(set, i));
    name = object_get_name(object);
    printf("%s, ",name);
  }

  /*Print the last die value*/
  printf("\nLast die value: %d", die_get_value(die(game)));
  /* Print the commands the user can type */
  printf("\n[commands: next or n, back or b, catch <obj_name> or c <obj_name>, ");
  printf("jump or j, leave <obj_name> or l <obj_name>, quit or q, roll or r]");
  printf("\nprompt:> ");
}




/* Private functions definition */
/* --------------------------------------------------------------------
   Function: game_get_space_id_at
   Date: 04-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the information of the identifier of the space at the position
    you want.

   Input: 
    Game *game: the game where the space is.
    int position: the position of the space you want the id.

   Output: 
    Id: the identifier of the space you want or NO_ID on error.
   -------------------------------------------------------------------- */
Id game_get_space_id_at(Game *game, int position){
  /* Check that the inputs are correct and not empty */
  if(!game || position < 0 || position >= MAX_SPACES){   
    return NO_ID;
  }

  return space_get_id(spaces(game)[position]);
}



/* --------------------------------------------------------------------
   Function: game_get_object
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives a specific object.

   Input: 
    Game *game: the game where the object is.
    Id id: the id of the object you want.

   Output: 
    Object *: the object you want or NULL on error.
   -------------------------------------------------------------------- */
Object * game_get_object(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the object you want */
  for(i=0; i < MAX_OBJECTS && objects(game)[i] != NULL; i++){
    if(id == object_get_id(objects(game)[i])){
      return objects(game)[i];
    }
  }
    
  return NULL;
}



/* --------------------------------------------------------------------
   Function: game_set_player_location
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Sets a location for a player.

   Input: 
    Game *game: the game where the player is.
    Id location: the location you want for the player.

   Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_player_location(Game *game, Id location){
  /* Set location */
  if(player_set_location(player(game), location) == ERROR){
    return ERROR;
  }
  return OK;
}



/* --------------------------------------------------------------------
   Function: game_get_player_location
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the location of the player.

   Input: 
    Game *game: the game where the player is.

   Output: 
    Id: the location of the player or NO_ID on error.
   -------------------------------------------------------------------- */
Id game_get_player_location(Game *game){
  if(!game){  /* Check that the input is not empty */
    return NO_ID;
  }

  return player_get_location(player(game));
}
 


/* --------------------------------------------------------------------
   Function: game_set_object_location
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Sets a location for an object.

   Input: 
    Game *game: the game where the object is.
    Id id: the location you want for the object.

   Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_object_location(Game *game, Id object, Id location){
  Object *obj = NULL;

  if(!game || object == NO_ID){  /* Check that the inputs are not empty */
    return ERROR;
  }

  /* Get the object */
  obj = game_get_object(game, object);
  
  /* Set its location */
  return object_set_location(obj, location);
}



/* --------------------------------------------------------------------
   Function: game_get_object_location
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the location of the object.

   Input: 
    Game *game: the game where the object is.

   Output: 
    Id: the location of the object or NO_ID on error.
   -------------------------------------------------------------------- */
Id game_get_object_location(Game *game, Id object){
  Object *obj = NULL;

  if(!game || object == NO_ID){  /* Check that the inputs are not empty */
    return NO_ID;
  }

  /* Get the object */
  obj = game_get_object(game, object);

  /* Get its location */
  return object_get_location(obj);
}



/*** Callbacks implementation for each action ***/
/* --------------------------------------------------------------------
   Function: callback_UNKNOWN
   Date: 04-11-2016 
   Author: Alejandro Sanchez

   Description: 
    No actions. It is used when the command is UNKOWN.

   Input: 
    Game *game: the game.

   Output: 
    STATUS: ERROR, because this command can't be typed.
   -------------------------------------------------------------------- */
STATUS callback_UNKNOWN(Game *game){
  return ERROR;
}



/* --------------------------------------------------------------------
   Function: callback_QUIT
   Date: 04-11-2016 
   Author: Alejandro Sanchez

   Description: 
    No actions. It is used when the command is QUIT.

   Input: 
    Game *game: the game.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS callback_QUIT(Game *game){
  if(!game){
    return ERROR;
  }
  
  return OK;
}



/* --------------------------------------------------------------------
   Function: callback_CATCH
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Catches an object from a space. It is used when the command is CATCH.

   Input: 
    Game *game: the game.
    char *arg: the name of the object to catch.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS callback_CATCH(Game *game, char *arg){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
  
  /* Check that the inputs are not empty */
  if(!game || !arg){ 
  	return ERROR;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
  	if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
    	flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR;
  }

  /* Get the set of objects from that space */
  set = space_get_object(spaces(game)[aux]);
  if(!set){ /* Check that there is at least one object on that space */
    return ERROR;
  }
  
  /* Get the number of objects on that space */
  count = set_get_count(set);

  /* Look for the object to catch */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(set, i);
    object = game_get_object(game, object_id);
    if(strcmp(arg, object_get_name(object)) == 0){
      flag = 0;
    }
    i++;
  }

  if(flag == 1){  /* Check that the object was found */
    return ERROR;
  }

  /* Set to the player the object with name "arg" which is on that space */
  if(player_add_object(player(game), object_id) == ERROR){
    return ERROR;
  }

  /* Delete that object from that space */
  if(space_del_object(spaces(game)[aux], object_id) == ERROR){
    return ERROR;
  }

  /* Set that the object is held by a player */
  game_set_object_location(game, object_id, NO_ID);

  return OK; 
}



/* --------------------------------------------------------------------
   Function: callback_LEAVE
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Leaves an object on a space. It is used when the command is LEAVE.

   Input: 
    Game *game: the game.
    char *arg: the name of the object to leave.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS callback_LEAVE(Game *game, char *arg){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
 
  /* Check that the inputs are not empty */
  if(!game || !arg){ 
    return ERROR;
  } 

  /* Get the objects that the player have */
  set = player_get_object(player(game));
  if(!set){ /* Check that the player has at least one object */
    return ERROR;
  }

  /* Get player location */
  space_id = game_get_player_location(game); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR;
  }

  /* Get the number of objects of the player */
  count = set_get_count(set);

  /* Look for the object to leave */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(set, i);
    object = game_get_object(game, object_id);
    if(strcmp(arg, object_get_name(object)) == 0){
      flag = 0;
    }
    i++;
  }

  if(flag == 1){  /* Check that the object was found */
    return ERROR;
  }

  /* Set the object to the space */
  if(space_add_object(spaces(game)[aux], object_id) == ERROR){
    return ERROR;
  }

  /* Set that the player does not have that object */
  if(player_del_object(player(game), object_id) == ERROR){
    return ERROR;
  }

  /* Set that the object is on that space */
  game_set_object_location(game, object_id, space_id);

  return OK;
}



/* --------------------------------------------------------------------
   Function: callback_GO
   Date: 05-11-2016 
   Author: Guillermo Rodriguez

   Description: 
    Moves the player to a new space. It is used when the command 
    is GO.

   Input: 
    Game *game: the game.
    char *arg: the direction you want to move the player.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS callback_GO(Game *game, char *arg){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, auxl = NO_ID, i = 0, flag = 0, count;
  Id space_id, space_id2, link_id;

  /* Check that the inputs are not empty */
  if(!game || !arg){ 
  	return ERROR;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game); 
	if(space_id == NO_ID){  /* Check if it has worked */
    return ERROR;
  }

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
  	if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
    	flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR;
  }
  
  if(!strcmp(arg, "north") || !strcmp(arg, "n")){
  	link_id = space_get_link(spaces(game)[aux], 1);
  } else if(!strcmp(arg, "south") || !strcmp(arg, "s")){
  	 link_id = space_get_link(spaces(game)[aux], 2);  
  } else if(!strcmp(arg, "west") || !strcmp(arg, "w")){
  	 link_id = space_get_link(spaces(game)[aux], 3);  
  } else if(!strcmp(arg, "east") || !strcmp(arg, "e")){
  	 link_id = space_get_link(spaces(game)[aux], 4);  
  } else{
      return ERROR;
  }

  /* If there is not link connection */
  if(link_id == ERROR){
  	return ERROR; 
  }

  /* Find the space with the same link*/
  i = 0;
  while(i < MAX_LINKS && flag == 0){
  	if(link_id == link_get_id(links(game)[i])){
      auxl = i;
    	flag = 1;
    }
    i++;
  }
	
  
  if(auxl == NO_ID){ /* Check that the link was found */
  	return ERROR;
  }
  
  if(space_id == link_get_space(links(game)[auxl], 1)){
  	space_id2 = link_get_space(links(game)[auxl], 2);
  } else{
      space_id2 = link_get_spaces_id(links(game)[auxl], 1);  
  }

  /* Check the link is open */
  if(link_is_open(links(game)[auxl]) == TRUE){
  	game_set_player_location(game, space_id2);
  	return OK; 
  }

  return ERROR; 
}



/* --------------------------------------------------------------------
   Function: callback_ROLL
   Date: 04-11-2016 
   Author: Guillermo Rodriguez

   Description: 
    Rolls a die of the game. It is used when the command is ROLL.

   Input: 
    Game *game: the game.

   Output: 
	  STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS callback_ROLL(Game *game){
  /* Check that the input is not empty and the die exists */
  if(!game || !die(game)){  
		return ERROR;
	 }
    
  /* Roll the die */  
  die_roll(die(game));

  return OK;
}


/* --------------------------------------------------------------------
   Function: game_set_space_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Set a space in a specific position.

   Input: 
    Game *game: the game where the player is.
    Space *space : the space you want to set
    int i: the number of the spaces

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_space_position(Game *game,Space*space,int i){
  if(!game || !space || i < 0){  /* Check that the input is not empty */
    return ERROR;
  }
  spaces(game)[i] = space;
  return OK;
}
 
/* --------------------------------------------------------------------
   Function: game_set_object_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Set a object in a specific position.

   Input: 
    Game *game: the game where the player is.
    Object *object : the object you want to set
    int i: the number of the object

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_object_position(Game *game, Object*object,int i){
  if(!game || !object || i < 0){  /* Check that the input is not empty */
    return ERROR;
  }
  objects(game)[i] = object;
  return OK;


}

/* --------------------------------------------------------------------
   Function: game_get_object_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Get a object in a specific position.

   Input: 
    Game *game: the game where the player is.
    int i: the number of the object

   Output: 
      Object *object : the object you want to know
   -------------------------------------------------------------------- */

Object * game_get_object_position(Game *game, int i){
	if(!game || i< 0){
		return NULL;	
	}
  
  return objects(game)[i];
}

/* --------------------------------------------------------------------
   Function: game_get_space_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Get a space in a specific position.

   Input: 
    Game *game: the game where the player is.
    int i: the number of the object

   Output: 
      Space *space : the object you want to know
   -------------------------------------------------------------------- */

Space* game_get_space_position(Game *game, int i){
	if(!game || i< 0){
		return NULL;	
	}
  
  return spaces(game)[i];
}


