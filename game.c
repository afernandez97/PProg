/**
@file game.c
@version 5.0
@date 20-11-2016
@authors Guillermo Rodriguez, Alejandro Sanchez, Adrian Fernandez and Ricardo Riol

@brief
It implements the game interface and all the associated callbacks
for each command.

@version
Jan. 13, 2015 Version 1.0 (initial release)
@version
Sept. 23, 2016  Version 2.0 
  Commented the file.
@version
Oct. 04, 2016 Version 2.1
  Changed "Id player_location" and "Id object_location" fields 
  for "Player *player" and "Object *object".
  Added macros for each structure field.
  Added input control to the functions.
  Added two inputs (player and object) to "game_init" and 
  "game_init_from_file" after creating ADT Player and ADT Object. 
@version
Oct. 08, 2016 Version 2.2
  Added callbacks CATCH and LEAVE.
  Changed "game_set_player_location", "game_get_player_location", 
  "game_set_object_location" and "game_get_object_location".
@version
Oct. 20, 2016 Version 3.0
  Modified some functions after creating ADT Die and ADT Set.
  Added callback ROLL.
@version
Oct. 27, 2016 Version 3.1
	Created function "game_get_object".
  Made public the function "game_get_space".
@version
Oct. 30, 2016 Version 3.2
  Modified "game_set_player_location", "game_get_player_location", 
  "game_set_object_location" and "game_get_object_location".
@version
Nov. 02, 2016 Version 3.3
  Created function "game_print_objects" and modified function 
  "game_print_screen" to show the graphic description.
@version
Nov. 04, 2016 Version 3.4
  Modified callbacks CATCH and LEAVE to receive input's argument.
  Modified "game_update" and callbacks to return a status.
@version
Nov. 05, 2016 Version 4.0
  Made "Game" structure private.
  Modified some functions after this change.
  Added callback GO and removed callbacks NEXT, BACK and JUMP.
@version
Nov. 13, 2016 Version 4.1
  Added field "Link *links" to the structure after creating ADT Link.
  Created functions "game_spaces_are_linked" and "game_is_link_open"
@version
Nov. 20, 2016 Version 4.2
  Added callback INSPECT.
@version
Nov. 26, 2016 Version 5.0
  Updated headers to use Doxygen.
*/

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

/*!< Constant values description */
#define player(X) (X)->player
#define spaces(X) (X)->spaces
#define objects(X) (X)->objects
#define die(X) (X)->die
#define links(X) (X)->links

/**
@brief
The Game structure stores information of the game and its elements.
*/
struct _Game{
  Player *player;                     /*!< Player of the game */
  Object *objects[MAX_OBJECTS + 1];   /*!< Objects of the game */
  Space *spaces[MAX_SPACES + 1];      /*!< Spaces of the game */
  Die *die;                           /*!< Die of the game*/ 
  Link *links[MAX_LINKS + 1];         /*!< Links of the game */
};


/*!< List of callbacks for each command in the game */
STATUS callback_UNKNOWN(Game *game);
STATUS callback_QUIT(Game *game);
STATUS callback_CATCH(Game *game, char *arg);
STATUS callback_LEAVE(Game *game, char *arg);
STATUS callback_ROLL(Game *game);
STATUS callback_GO(Game *game, char *arg);
STATUS callback_INSPECT(Game *game, char *arg);

/*!< Private functions description */
Id game_get_space_id_at(Game *game, int position);

Object * game_get_object(Game *game, Id id);
Link * game_get_link(Game *game, Id id);

STATUS game_set_player_location(Game *game, Id id);
Id game_get_player_location(Game *game);

STATUS game_set_object_location(Game *game, Id object, Id id);
Id game_get_object_location(Game *game, Id object);

BOOL game_spaces_are_linked(Game *game, Space *space1, Space *space2);
BOOL game_is_link_open(Game *game, Id link);


/*!< Public functions definition */

/**
@date 05-10-2016 
@author Guillermo Rodriguez

@brief game_init
Initializes a game.

@param Id player: the identifier of the player of the game.
@param Id die: the identifier of the die of the game.

@return Game *game: the game initialized.
*/
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



/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief game_init_from_file
Initializes a game from two files which contain the spaces and objects.

@param char *filename1: the file to concatenate the spaces,links and objects
@param Id player: the identifier of the player of the game.
@param Id die: the identifier of the die of the game.

@return Game *game: the game initialized.
*/
Game * game_init_from_file(char *filename,Id player, Id die){
  Game *game = NULL;
  char f[WORD_SIZE]="";

  /* Check that the inputs are not empty */ 
  if(!filename || player == NO_ID || die == NO_ID){  
    return NULL;
  }

  strcpy(f, filename);

  /* Initialize the elements of the game and check if it has worked */
  game = game_init(player, die);
  if(!game){
    game_destroy(game);
    return NULL; 
  }

  /* Load the links from the file and check if it has worked */
  if(game_load_links(game, f) == ERROR){
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  } 

  /* Load the spaces from the file and check if it has worked */
  if(game_load_spaces(game, f) == ERROR){ 
    printf("%s\n", f);
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  }

  if(game_load_objects(game, f) == ERROR){
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  } 

  /* Set the player on the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0)); 
  
  return game;
}


/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief game_destroy
Destroys a game.

@param Game *game: the game to destroy.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
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
  /* Destroy the links*/ 
  for(i=0; i < MAX_LINKS; i++){
    link_destroy(links(game)[i]);
  }

  free(game);   /* Eliminate the memory of the game */ 

  return OK;
}



/**
@date 05-11-2016 
@author Ricardo Riol

@brief game_update
Updates a game.

@param Game *game: the game to update.
@param Command *cmd: the command typed by the user.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
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
    case INSPECT:
      status = callback_INSPECT(game, arg);
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



/**
@date 04-10-2016 
@author Alejandro Sanchez

@brief game_get_space
Gives a specific space.

@param Game *game: the game where the space is.
@param Id id: the id of the space you want.

@return Space *: the space you want or NULL on error.
*/
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



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_set_space_at_position
Sets a space in a specific position.

@param Game *game: the game where the space is.
@param Space *space : the space you want to set
@param int position: the position where you want to set the space.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_set_space_at_position(Game *game, Space *space, int position){
  if(!game || !space || position < 0){  /* Check that the inputs are not empty */
    return ERROR;
  }

  if(spaces(game)[position] != NULL){
    space_destroy(spaces(game)[position]);
  }

  spaces(game)[position] = space;

  return OK;
}



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_get_space_at_position
Gets the space in a specific position.

@param Game *game: the game where the space is.
@param int position: the position of the space.

@return Space *space : the space in that position or NULL on error.
*/
Space * game_get_space_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return spaces(game)[position];
}



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_set_object_at_position
Sets an object in a specific position.

@param Game *game: the game where the object is.
@param Object *object : the object you want to set
@param int position: the position where you want to set the object.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_set_object_at_position(Game *game, Object *object, int position){
  if(!game || !object || position < 0){  /* Check that the inputs are not empty */
    return ERROR;
  }

  if(objects(game)[position] != NULL){
    object_destroy(objects(game)[position]);
  }

  objects(game)[position] = object;

  return OK;
}



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_get_object_at_position
Gets the object in a specific position.

@param Game *game: the game where the object is.
@param int position: the position of the object

@return Object *object : the object in that position or NULL on error.
*/
Object * game_get_object_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return objects(game)[position];
}



/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_set_link_at_position
Sets a link in a specific position.

@param Game *game: the game where the link is.
@param Link *link : the link you want to set
@param int position: the position where you want to set the link.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_set_link_at_position(Game *game, Link *link, int position){
  if(!game || !link || position < 0){  /* Check that the inputs are not empty */
    return ERROR;
  }

  if(links(game)[position] != NULL){
    link_destroy(links(game)[position]);
  }

  links(game)[position] = link;

  return OK;
}



/**
@date 13-10-2016 
@author Alejandro Sanchez

@brief game_get_link_at_position
Gets the link in a specific position.

@param Game *game: the game where the link is.
@param int position: the position of the link.

@return Link *link : the link in that position or NULL on error.
*/
Link * game_get_link_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return links(game)[position];
}



/**
@date 23-09-2016 
@author Alejandro Sanchez

@brief game_is_over
Ends the game.

@param Game *game: the game to end.

@return BOOL: FALSE.
*/
BOOL game_is_over(Game *game){
    return FALSE;
}



/**
@date 20-10-2016 
@author Alejandro Sanchez

@brief game_print_data
Prints the data of the game.

@param Game *game: the game to print its elements.

@return
*/
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
  
  /* Print the linka */
  printf("=> Links: \n");
  for(i=0; i < MAX_LINKS && links(game)[i] != NULL; i++){
    link_print(links(game)[i]);
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



/**
@date 02-11-2016 
@author Alejandro Sanchez

@brief game_print_objects
Prints the objects of the game (<name>:<location>).

@param Game *game: the game to print its objects.
@param Space *space: the space where you want to print the objects.

@return
*/
void game_print_objects(Game *game, Space *space){
  int i, count;
  char *name = NULL;
  Set *set = NULL;
  Object *object = NULL;

  /* Start printing the row of the space */
  fprintf(stdout, "     |");
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



/**
Function: 
@date 02-11-2016 
@author Alejandro Sanchez

@brief game_print_screen
Prints the screen of the game.

@param Game *game: the game to print its screen.

@return
*/
void game_print_screen(Game *game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID;
  Id id_west = NO_ID, id_obj = NO_ID, id_spc_back = NO_ID, id_spc_next = NO_ID;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  Link *link_back = NULL, *link_next = NULL;
  char *name = NULL;
  Object *object = NULL;
  int i, count;
  Inventory *inv = NULL; 
    
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
  if(id_back != NO_ID){
    link_back = game_get_link(game, id_back);
    id_spc_back = link_get_space2(link_back);
    space_back = game_get_space(game, id_spc_back);
  }
 

  /* Get the next space */
  id_next = space_get_south(space_act);
  if(id_next != NO_ID){
    link_next = game_get_link(game, id_next);
    id_spc_next = link_get_space2(link_next);
    space_next = game_get_space(game, id_spc_next); 
  }
  
   
  if(system(CLEAR)){
    return; 
  }

  /* Print the previous space if it is different from NO_ID */
  if(id_back != NO_ID){
    id_east = space_get_east(space_back);
    id_west = space_get_west(space_back);
    if(id_east != NO_ID && id_west != NO_ID){
      link_back = game_get_link(game, id_east);
      link_next = game_get_link(game, id_west);
      printf("   %2d|         %2d|%2d\n", (int)id_west, (int)id_spc_back, 
        (int)id_east);
      printf("%2d<--|           |-->%2d\n", (int)link_get_space2(link_next), 
        (int)link_get_space2(link_back));
      space_print_gdesc(space_back);
    } else if(id_east != NO_ID && id_west == NO_ID){
     	  link_back = game_get_link(game, id_east);
        printf("     |         %2d|%2d\n", (int)id_spc_back, (int)id_east);
        printf("     |           |-->%2d\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_back);
		} else if(id_west != NO_ID){
		    link_back = game_get_link(game, id_west);
        printf("   %2d|         %2d|\n", (int)id_west, (int)id_back);
				printf("%2d<--|           |\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_back);
		} else{
        printf("     |         %2d|\n", (int) id_back);
				printf("     |           |\n");
				space_print_gdesc(space_back);
		}
		game_print_objects(game, space_back);
		printf("     +-----------+\n");
		printf("            ^ %2d\n", (int)id_back);
  }
  
  /* Print the actual space if it is different from NO_ID */
  if(id_act != NO_ID){
    printf("     +-----------+\n");
    id_east = space_get_east(space_act);
    id_west = space_get_west(space_act);
    if(id_east != NO_ID && id_west != NO_ID){
      link_back = game_get_link(game, id_east);
      link_next = game_get_link(game, id_west);
      printf("   %2d| >8D     %2d|%2d\n", (int)id_west, (int)id_act, 
        (int)id_east);
      printf("%2d<--|           |-->%2d\n", (int)link_get_space2(link_next), 
        (int)link_get_space2(link_back));
      space_print_gdesc(space_act);
    } else if(id_east != NO_ID && id_west == NO_ID){
     	  link_back = game_get_link(game, id_east);
        printf("     | >8D     %2d|%2d\n", (int)id_act, (int)id_east);
        printf("     |           |-->%2d\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_act);
		} else if(id_west != NO_ID){
		    link_back = game_get_link(game, id_west);
        printf("   %2d| >8D     %2d|\n", (int)id_west, (int)id_act);
				printf("%2d<--|           |\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_act);
		} else{
        printf("     | >8D     %2d|\n", (int) id_act);
				printf("     |           |\n");
        space_print_gdesc(space_act);
		}
		game_print_objects(game, space_act);
		printf("     +-----------+\n");
  }  
    
  /* Print the next space if it is different from NO_ID */ 
  if(id_next != NO_ID){
    printf("            v %2d\n", (int)id_next);
    printf("     +-----------+\n");
    id_east = space_get_east(space_next);
    id_west = space_get_west(space_next);
    if(id_east != NO_ID && id_west != NO_ID){
      link_next = game_get_link(game, id_east);
      link_back = game_get_link(game, id_west);
      printf("   %2d|         %2d|%2d\n", (int)id_west, (int)id_spc_next, 
        (int)id_east);
      printf("%2d<--|           |-->%2d\n", (int)link_get_space2(link_back), 
        (int)link_get_space2(link_next));
      space_print_gdesc(space_next);
    } else if(id_east != NO_ID && id_west == NO_ID){
     	  link_next = game_get_link(game, id_east);
        printf("     |         %2d|%2d\n", (int)id_spc_next, (int)id_east);
        printf("     |           |-->%2d\n", (int)link_get_space2(link_next));
        space_print_gdesc(space_next);
		} else if(id_west != NO_ID){
		    link_next = game_get_link(game, id_west);
        printf("   %2d|         %2d|\n", (int)id_west, (int)id_next);
				printf("%2d<--|           |\n", (int)link_get_space2(link_next));
        space_print_gdesc(space_next);
		} else{
        printf("     |         %2d|\n", (int) id_spc_next);
				printf("     |           |\n");
        space_print_gdesc(space_next);
		}
		game_print_objects(game, space_next);
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
  inv = player_get_inventory(player(game));
  count = inventory_get_count(inv);
  printf("\nPlayer objects: ");
  /* Get the different names of the objects and print them */
	for(i=0; i<count; i++){    
	  object = game_get_object(game, set_get_object_at_position(inventory_get_bag(inv), i));
    name = object_get_name(object);
    printf("%s, ",name);
  }

  /*Print the last die value*/
  printf("\nLast die value: %d", die_get_value(die(game)));
  /* Print the commands the user can type */
  printf("\n[commands: go <direction> or g <direction>, catch <obj_name> or c <obj_name>, leave ");
  printf("<obj_name> or l <obj_name>, inspect <spc_name/obj_name> or i <spc_name/obj_name>, quit or q, roll or r]");
  printf("\nprompt:> ");
}




/*!< Private functions definition */

/**
@date 04-10-2016 
@author Alejandro Sanchez

@brief game_get_space_id_at
Gives the information of the identifier of the space at the position
you want.

@param Game *game: the game where the space is.
@param int position: the position of the space you want the id.

@return Id: the identifier of the space you want or NO_ID on error.
*/
Id game_get_space_id_at(Game *game, int position){
  /* Check that the inputs are correct and not empty */
  if(!game || position < 0 || position >= MAX_SPACES){   
    return NO_ID;
  }

  return space_get_id(spaces(game)[position]);
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_get_object
Gives a specific object.

@param Game *game: the game where the object is.
@param Id id: the id of the object you want.

@return Object *: the object you want or NULL on error.
*/
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



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_set_player_location
Sets a location for a player.

@param Game *game: the game where the player is.
@param Id location: the location you want for the player.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_set_player_location(Game *game, Id location){
  /* Set location */
  if(player_set_location(player(game), location) == ERROR){
    return ERROR;
  }
  return OK;
}



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_get_player_location
Gives the location of the player.

@param Game *game: the game where the player is.

@return Id: the location of the player or NO_ID on error.
*/
Id game_get_player_location(Game *game){
  if(!game){  /* Check that the input is not empty */
    return NO_ID;
  }

  return player_get_location(player(game));
}
 


/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_set_object_location
Sets a location for an object.

@param Game *game: the game where the object is.
@param Id id: the location you want for the object.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
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



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_get_object_location
Gives the location of the object.

@param Game *game: the game where the object is.

@return Id: the location of the object or NO_ID on error.
*/
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


/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_get_link
Gives a specific link.

@param Game *game: the game where the link is.
@param Id id: the id of the link you want.

@return Link *: the link you want or NULL on error.
*/
Link * game_get_link(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the link you want */
  for(i=0; i < MAX_LINKS && links(game)[i] != NULL; i++){
    if(id == link_get_id(links(game)[i])){
      return links(game)[i];
    }
  }
    
  return NULL;
}


/**
@date 11-11-2016 
@author Alejandro Sanchez

@brief game_spaces_are_linked
Checks if there is a link between two spaces.

@param Game *game: the game where the link and spaces are.
@param Space *space1: one of the spaces you want to know if is linked.
@param Space *space2: the other space you want to know if is linked.
@return BOOL: TRUE if the spaces are linked and FALSE in other cases. 
*/
BOOL game_spaces_are_linked(Game *game, Space *space1, Space *space2){
  Id aux1, aux2, id_space1, id_space2;
  int i = 0, flag = 0;

  if(!game || !space1 || !space2){
    return FALSE;
  }

  id_space1 = space_get_id(space1);
  id_space2 = space_get_id(space2);

  while(1 < MAX_LINKS && flag == 0){
    aux1 = link_get_space1(links(game)[i]);
    if(aux1 == id_space1){
      aux2 = link_get_space2(links(game)[i]);
        if(aux2 == id_space2){
          flag = 1;
        } 
    } else if(aux1 == id_space2){
        aux2 = link_get_space2(links(game)[i]);
        if(aux2 == id_space1){
          flag = 1;
        }  
    }
    i++;
  }

  if(flag == 0){
    return FALSE;
  }

  return TRUE;
}

/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_is_link_open
Checks if a link of the game is open or not.

@param Game *game: the game where the link is.
@param Id link: the identifier of the link to check.
             
@return BOOL: TRUE is the link is open or FALSE if not.
*/
BOOL game_is_link_open(Game *game, Id link){
  Link *lnk = NULL;

  if(!game || link == NO_ID){
    return FALSE;
  }

  /* Get the link */
  lnk = game_get_link(game, link);

  /* Check if the link is open or not */
  return link_is_open(lnk);
}



/*!< Callbacks implementation for each action */

/**
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_UNKNOWN
No actions. It is used when the command is UNKOWN.

@param Game *game: the game.

@return STATUS: ERROR, because this command can't be typed.
*/
STATUS callback_UNKNOWN(Game *game){
  return ERROR;
}



/** 
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_QUIT
No actions. It is used when the command is QUIT.

@param Game *game: the game.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS callback_QUIT(Game *game){
  if(!game){
    return ERROR;
  }
  
  return OK;
}



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_CATCH
Catches an object from a space. It is used when the command is CATCH.

@param Game *game: the game.
@param char *arg: the name of the object to catch.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
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



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_LEAVE
Leaves an object on a space. It is used when the command is LEAVE.

@param Game *game: the game.
@param char *arg: the name of the object to leave.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS callback_LEAVE(Game *game, char *arg){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Inventory *inv = NULL;
  Object *object = NULL;
 
  /* Check that the inputs are not empty */
  if(!game || !arg){ 
    return ERROR;
  } 

  /* Get the objects that the player have */
  inv = player_get_inventory(player(game));
  if(!inv){ /* Check that the player has at least one object */
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
  count = inventory_get_count(inv);

  /* Look for the object to leave */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(inventory_get_bag(inv), i);
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



/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief callback_GO
Moves the player to a new space. It is used when the command 
is GO.

@param Game *game: the game.
@param char *arg: the direction you want to move the player.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS callback_GO(Game *game, char *arg){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, auxl = NO_ID, i = 0, flag = 0;
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
  	link_id = space_get_north(spaces(game)[aux]);
  } else if(!strcmp(arg, "south") || !strcmp(arg, "s")){
  	 link_id = space_get_south(spaces(game)[aux]);  
  } else if(!strcmp(arg, "west") || !strcmp(arg, "w")){
  	 link_id = space_get_west(spaces(game)[aux]);  
  } else if(!strcmp(arg, "east") || !strcmp(arg, "e")){
  	 link_id = space_get_east(spaces(game)[aux]);  
  } else if(!strcmp(arg, "up") || !strcmp(arg, "u")){
  	 link_id = space_get_up(spaces(game)[aux]);  
  } else if(!strcmp(arg, "down") || !strcmp(arg, "d")){
  	 link_id = space_get_down(spaces(game)[aux]);  
  } else{
      return ERROR;
  }

  /* If there is not link connection */
  if(link_id == NO_ID){
  	return ERROR; 
  }

  /* Find the space with the same link*/
  i = 0;
  flag = 0;
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
  
  space_id2 = link_get_space2(links(game)[auxl]);

  /* Check that the link is open */
  if(link_is_open(links(game)[auxl]) == TRUE){
  	game_set_player_location(game, space_id2);
  	return OK; 
  }

  return ERROR; 
}



/**
@date 04-11-2016 
@author Guillermo Rodriguez

@brief callback_ROLL
Rolls a die of the game. It is used when the command is ROLL.

@param Game *game: the game.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS callback_ROLL(Game *game){
  /* Check that the input is not empty and the die exists */
  if(!game || !die(game)){  
		return ERROR;
	 }
    
  /* Roll the die */  
  die_roll(die(game));

  return OK;
}



/**
@date 04-11-2016 
@author Ricardo Riol

@brief callback_INSPECT
This function tells the space's or object's information

@param Game *game: the game.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS callback_INSPECT(Game *game, char *arg){
  Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL, *set_spc = NULL;
  Id id_space = NO_ID;
  int flag, i;
  char *description = NULL;
	/* Check that the inputs are not empty */
  if (!game || !arg){
    return ERROR;
  }
  
  id_space = game_get_player_location(game);
  space = game_get_space(game, id_space);
  set_spc = space_get_object(space);

  inv = player_get_inventory(player(game));
  set_inv = inventory_get_bag(inv);

	/* Check if you want a space description or an object description */
  if(!strcmp (arg, "s") || !strcmp (arg, "space")){	/* space */
    description = space_get_desc(space);
    fprintf(stdout,"%s\n", description);
    return OK;
  } else {	/* object */
    	for(i=0, flag=0;i < set_get_count(set_inv) && flag == 0; i++){
        obj = game_get_object(game, set_get_object_at_position(set_inv, i));
      	if(!strcmp(object_get_name(obj), arg)){
        	flag = 1;
      	}
    	}
      if(flag == 0){
        for(i=0, flag=0;i < set_get_count(set_spc) && flag == 0; i++){
        obj = game_get_object(game, set_get_object_at_position(set_spc, i));
        if(!strcmp(object_get_name(obj), arg)){
            flag = 1;
          }
        }
      }
  }

  if (flag == 1){
    fprintf(stdout, "%s\n", object_get_desc(obj));
    return OK;
  } 
    
  fprintf(stdout, "Error, the object has not been found.\n");
  return ERROR;
}
