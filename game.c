/**
@file game.c
@version 6.0
@date 03-12-2016
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
@version
Dec. 3, 2016 Version 6.0
  Added field "text", players now can be loaded from a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_management.h"

#ifdef __WINDOWS_BUILD__
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/**
@def Constant values description
*/
#define players(X) (X)->players
#define spaces(X) (X)->spaces
#define objects(X) (X)->objects
#define die(X) (X)->die
#define links(X) (X)->links
#define text(X) (X)->text


/**
@brief
The Game structure stores information of the game and its elements.
*/
struct _Game{
  Player *players[MAX_PLAYERS];   /*!< Players of the game */
  Object *objects[MAX_OBJECTS];   /*!< Objects of the game */
  Space *spaces[MAX_SPACES];      /*!< Spaces of the game */
  Die *die;                       /*!< Die of the game*/ 
  Link *links[MAX_LINKS];         /*!< Links of the game */
  char text[WORD_SIZE];           /*!< Text shown on the screen */
};


/*!< List of callbacks for each command in the game */
/**
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_UNKNOWN
No actions. It is used when the command is UNKOWN.

@param Game *game: the game.

@return _STATUS: _ERROR, because this command can't be typed.
*/
_STATUS callback_UNKNOWN(Game *game);
/** 
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_QUIT
No actions. It is used when the command is QUIT.

@param Game *game: the game.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_QUIT(Game *game);
/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_CATCH
Catches an object from a space. It is used when the command is CATCH.

@param Game *game: the game.
@param char *arg: the name of the object to catch.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_CATCH(Game *game, char *arg, int player);
/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_LEAVE
Leaves an object on a space. It is used when the command is LEAVE.

@param Game *game: the game.
@param char *arg: the name of the object to leave.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_LEAVE(Game *game, char *arg, int player);
/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief callback_GO
Moves the player to a new space. It is used when the command 
is GO.

@param Game *game: the game.
@param char *arg: the direction you want to move the player.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_GO(Game *game, char *arg, int player);
/**
@date 04-11-2016 
@author Guillermo Rodriguez

@brief callback_ROLL
Rolls a die of the game. It is used when the command is ROLL.

@param Game *game: the game.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_ROLL(Game *game);
/**
@date 02-12-2016 
@author Ricardo Riol

@brief callback_INSPECT
Tells the space's or object's information

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_INSPECT(Game *game, char *arg, int player);
/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNON
Turns on an object

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_TURNON(Game *game, char *arg, int player);
/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNOFF
Turns on an object

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_TURNOFF(Game *game, char *arg, int player);
/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_open
Opens a link

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_OPEN(Game *game, char *arg, char *arg2, int player);



/*!< Private functions description */
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
Id game_get_space_id_at(Game *game, int position);

/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_get_object
Gives a specific object.

@param Game *game: the game where the object is.
@param Id id: the id of the object you want.

@return Object *: the object you want or NULL on error.
*/
Object * game_get_object(Game *game, Id id);
/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_get_link
Gives a specific link.

@param Game *game: the game where the link is.
@param Id id: the id of the link you want.

@return Link *: the link you want or NULL on error.
*/
Link * game_get_link(Game *game, Id id);
/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player
Gives a specific player.

@param Game *game: the game where the player is.
@param Id id: the id of the player you want.

@return Player *: the player you want or NULL on error.
*/
Player * game_get_player(Game *game, Id id);

/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_player_location
Sets a location of a player.

@param Game *game: the game where the player is.
@param Id player: the id of the player selected.
@param Id location: the location you want for the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_player_location(Game *game, Id player, Id location);
/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player_location
Gives the location of a player.

@param Game *game: the game where the player is.
@param Id player: the id of the player selected.

@return Id: the location of the player or NO_ID on error.
*/
Id game_get_player_location(Game *game, Id player);
/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_set_object_location
Sets a location for an object.

@param Game *game: the game where the object is.
@param Id id: the location you want for the object.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_object_location(Game *game, Id object, Id location);
/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_get_object_location
Gives the location of the object.

@param Game *game: the game where the object is.

@return Id: the location of the object or NO_ID on error.
*/
Id game_get_object_location(Game *game, Id object);

/**
@date 11-11-2016 
@author Alejandro Sanchez

@brief game_spaces_are_linked
Checks if there is a link between two spaces.

@param Game *game: the game where the link and spaces are.
@param Space *space1: one of the spaces you want to know if is linked.
@param Space *space2: the other space you want to know if is linked.
@return _BOOL: _TRUE if the spaces are linked and _FALSE in other cases. 
*/

_BOOL game_spaces_are_linked(Game *game, Space *space1, Space *space2);
/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_is_link_open
Checks if a link of the game is open or not.

@param Game *game: the game where the link is.
@param Id link: the identifier of the link to check.
             
@return _BOOL: _TRUE is the link is open or _FALSE if not.
*/
_BOOL game_is_link_open(Game *game, Id link);



/*!< Public functions definition */

/**
@date 05-10-2016 
@author Guillermo Rodriguez

@brief game_init
Initializes a game.

@param Id die: the identifier of the die of the game.

@return Game *game: the game initialized.
*/
Game * game_init(Id die){
  int i;
  Game *game=NULL;

  /* Check that the inputs are not empty */ 
  if(!objects(game) || die == NO_ID){  
    return NULL;
  }

  game = (Game *)malloc(sizeof(Game));
  if(!game){    /* Check if memory has been allocated */
		return NULL;
  }
  for(i=0; i < MAX_SPACES; i++){  
    spaces(game)[i] = NULL;   /* Initialize to NULL each space */
  }
    
  for(i=0; i < MAX_PLAYERS; i++){  
    players(game)[i] = NULL;   /* Initialize to NULL each player */
  }

  for(i=0; i < MAX_OBJECTS; i++){  
    objects(game)[i] = NULL;   /* Initialize to NULL each object */
  }

  die(game) = die_create(die);  /* Create a die */
  if(!die(game)){   /* Check if memory has been allocated */
    free(game);
    return NULL;
  }

  text(game) = "";

  return game;
}



/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_init_from_file
Initializes a game from two files which contain the spaces and objects.

@param char *path: the path of the different files that contain the game.
@param Id die: the identifier of the die of the game.

@return Game *game: the game initialized.
*/
Game * game_init_from_file(char *path, Id die){
  Game *game = NULL;

  /* Check that the inputs are not empty */ 
  if(!path || die == NO_ID){  
    return NULL;
  }

  /* Initialize the elements of the game and check if it has worked */
  game = game_init(die);
  if(!game){
    game_destroy(game);
    return NULL; 
  }

  /* Load the game from the file and check if it has worked */
  if(game_load(game, path) == _ERROR){
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  } 
  
  return game;
}


/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief game_destroy
Destroys a game.

@param Game *game: the game to destroy.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_destroy(Game *game){
  int i;

  if(!game){  /* Check that the input is not empty */
    return _ERROR;
  }
  
  /* Destroy the die */
  die_destroy(die(game));

  /* Destroy the players */
  for(i=0; i < MAX_PLAYERS; i++){
    player_destroy(players(game)[i]);
  }
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

  return _OK;
}



/**
@date 16-12-2016 
@author Alejandro Sanchez

@brief game_update
Updates a game.

@param Game *game: the game to update.
@param Command *cmd: the command typed by the user.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_update(Game *game, Command *command, int player){
  T_Command cmd;
  char arg[CMD_LENGTH] = "";
  _STATUS status = _ERROR;

  if(!game || !command || player < 0){ /* Check that the inputs are not empty */
    return _ERROR;
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
      status = callback_CATCH(game, arg, player);
      break;
    case LEAVE:
      status = callback_LEAVE(game, arg, player);
      break;
    case GO:
      status = callback_GO(game, arg, player);
      break;
    case INSPECT:
      status = callback_INSPECT(game, arg, player);
      break;  			  
    case ROLL:
      status = callback_ROLL(game);
      break;
    case TURON:
      status = callback_TURNON(game ,arg, player);
      break;
    case TUROFF:
      status = callback_TURNOFF(game,arg, player);
      break;
    case OPEN:
      status = callback_OPEN(game, arg, arg2, player);
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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_space_at_position(Game *game, Space *space, int position){
  if(!game || !space || position < 0){  /* Check that the inputs are not empty */
    return _ERROR;
  }

  if(spaces(game)[position] != NULL){
    space_destroy(spaces(game)[position]);
  }

  spaces(game)[position] = space;

  return _OK;
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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_object_at_position(Game *game, Object *object, int position){
  if(!game || !object || position < 0){  /* Check that the inputs are not empty */
    return _ERROR;
  }

  if(objects(game)[position] != NULL){
    object_destroy(objects(game)[position]);
  }

  objects(game)[position] = object;

  return _OK;
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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_link_at_position(Game *game, Link *link, int position){
  if(!game || !link || position < 0){  /* Check that the inputs are not empty */
    return _ERROR;
  }

  if(links(game)[position] != NULL){
    link_destroy(links(game)[position]);
  }

  links(game)[position] = link;

  return _OK;
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
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_link_at_position
Sets a player in a specific position.

@param Game *game: the game where the player is.
@param Player *player: the player you want to set
@param int position: the position where you want to set the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_player_at_position(Game *game, Player *player, int position){
  if(!game || !player || position < 0){  /* Check that the inputs are not empty */
    return _ERROR;
  }

  if(players(game)[position] != NULL){
    player_destroy(players(game)[position]);
  }

  players(game)[position] = player;

  return _OK;
}



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_link_at_position
Gets the player in a specific position.

@param Game *game: the game where the player is.
@param int position: the position of the player.

@return Player *player : the player in that position or NULL on error.
*/
Player * game_get_player_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return players(game)[position];
}



/**
@date 23-09-2016 
@author Alejandro Sanchez

@brief game_is_over
Ends the game.

@param Game *game: the game to end.

@return _BOOL: _FALSE.
*/
_BOOL game_is_over(Game *game){
    return _FALSE;
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
  
  /* Print the links */
  printf("=> Links: \n");
  for(i=0; i < MAX_LINKS && links(game)[i] != NULL; i++){
    link_print(links(game)[i]);
  }

  /* Print the players */
  printf("=> Players: \n");
  for(i=0; i < MAX_PLAYERS && players(game)[i] != NULL; i++){
    player_print(players(game)[i]);
  }

  /* Print the die information */  
  die_print(die(game));

  return;
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
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player
Gives a specific player.

@param Game *game: the game where the player is.
@param Id id: the id of the player you want.

@return Player *: the player you want or NULL on error.
*/
Player * game_get_player(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the player you want */
  for(i=0; i < MAX_PLAYERS && players(game)[i] != NULL; i++){
    if(id == player_get_id(players(game)[i])){
      return players(game)[i];
    }
  }
    
  return NULL;
}



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_player_location
Sets a location of a player.

@param Game *game: the game where the player is.
@param int player: number of the player.
@param Id location: the location you want for the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_player_location(Game *game, int player, Id location){
  Object *ply = NULL;

  if(!game || player < 0 || location == NO_ID){  /* Check that the inputs are not empty */
    return _ERROR;
  }

  /* Get the player */
  ply = game_get_player_at_position(game, player);
  
  /* Set its location */
  return player_set_location(ply, location);
}



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player_location
Gives the location of a player.

@param Game *game: the game where the player is.
@param int player: number of the player.

@return Id: the location of the player or NO_ID on error.
*/
Id game_get_player_location(Game *game, int player){
  Player *ply = NULL;

  if(!game || player < 0){  /* Check that the inputs are not empty */
    return NO_ID;
  }

	
  /* Get the player */
  ply = game_get_player_at_position(game, player);

  /* Get its location */
  return player_get_location(ply);
}
 


/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_set_object_location
Sets a location for an object.

@param Game *game: the game where the object is.
@param Id id: the location you want for the object.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_object_location(Game *game, Id object, Id location){
  Object *obj = NULL;

  if(!game || player == NO_ID || location == NO_ID){  /* Check that the inputs are not empty */
    return _ERROR;
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
@return _BOOL: _TRUE if the spaces are linked and _FALSE in other cases. 
*/
_BOOL game_spaces_are_linked(Game *game, Space *space1, Space *space2){
  Id aux1, aux2, id_space1, id_space2;
  int i = 0, flag = 0;

  if(!game || !space1 || !space2){
    return _FALSE;
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
    return _FALSE;
  }

  return _TRUE;
}

/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_is_link_open
Checks if a link of the game is open or not.

@param Game *game: the game where the link is.
@param Id link: the identifier of the link to check.
             
@return _BOOL: _TRUE is the link is open or _FALSE if not.
*/
_BOOL game_is_link_open(Game *game, Id link){
  Link *lnk = NULL;

  if(!game || link == NO_ID){
    return _FALSE;
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

@return _STATUS: _ERROR, because this command can't be typed.
*/
_STATUS callback_UNKNOWN(Game *game){
  return _ERROR;
}



/** 
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_QUIT
No actions. It is used when the command is QUIT.

@param Game *game: the game.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_QUIT(Game *game){
  if(!game){
    return _ERROR;
  }
  
  return _OK;
}



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_CATCH
Catches an object from a space. It is used when the command is CATCH.

@param Game *game: the game.
@param char *arg: the name of the object to catch.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_CATCH(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
  
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
  	return _ERROR;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
  	if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
    	flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
  }

  /* Get the set of objects from that space */
  set = space_get_object(spaces(game)[aux]);
  if(!set){ /* Check that there is at least one object on that space */
    return _ERROR;
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
    return _ERROR;
  }

  /* Set to the player the object with name "arg" which is on that space */
  if(player_add_object(players(game)[player], object_id) == _ERROR){
    return _ERROR;
  }

  /* Delete that object from that space */
  if(space_del_object(spaces(game)[aux], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the object is held by a player */
  game_set_object_location(game, object_id, NO_ID);

  return _OK; 
}



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_LEAVE
Leaves an object on a space. It is used when the command is LEAVE.

@param Game *game: the game.
@param char *arg: the name of the object to leave.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_LEAVE(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Inventory *inv = NULL;
  Object *object = NULL;
 
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return _ERROR;
  } 

  /* Get the objects that the player have */
  inv = player_get_inventory(players(game)[player]);
  if(!inv){ /* Check that the player has at least one object */
    return _ERROR;
  }

  /* Get player location */
  space_id = game_get_player_location(game, player); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
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
    return _ERROR;
  }

  /* Set the object to the space */
  if(space_add_object(spaces(game)[aux], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the player does not have that object */
  if(player_del_object(players(game)[player], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the object is on that space */
  game_set_object_location(game, object_id, space_id);

  return _OK;
}



/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief callback_GO
Moves the player to a new space. It is used when the command 
is GO.

@param Game *game: the game.
@param char *arg: the direction you want to move the player.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_GO(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, auxl = NO_ID, i = 0, flag = 0;
  Id space_id, space_id2, link_id;

  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
  	return _ERROR;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player); 
	if(space_id == NO_ID){  /* Check if it has worked */
    return _ERROR;
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
    return _ERROR;
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
      return _ERROR;
  }

  /* If there is not link connection */
  if(link_id == NO_ID){
  	return _ERROR; 
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
  	return _ERROR;
  }
  
  space_id2 = link_get_space2(links(game)[auxl]);

  /* Check that the link is open */
  if(link_is_open(links(game)[auxl]) == _TRUE){
  	game_set_player_location(game, player, space_id2);
  	return _OK; 
  }

  return _ERROR; 
}



/**
@date 04-11-2016 
@author Guillermo Rodriguez

@brief callback_ROLL
Rolls a die of the game. It is used when the command is ROLL.

@param Game *game: the game.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_ROLL(Game *game){
  /* Check that the input is not empty and the die exists */
  if(!game || !die(game)){  
		return _ERROR;
	 }
    
  /* Roll the die */  
  die_roll(die(game));

  return _OK;
}



/**
@date 02-12-2016 
@author Ricardo Riol

@brief callback_INSPECT
Tells the space's or object's information. It is used when the command is INSPECT.

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_INSPECT(Game *game, char *arg, int player){
  Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL, *set_spc = NULL;
  Id id_space = NO_ID;
  int flag, i, illuminated = 0, bought = 0;
  char *description = NULL;

	/* Check that the inputs are not empty */
  if (!game || !arg || player < 0){
    return _ERROR;
  }
  
  id_space = game_get_player_location(game, player);
  space = game_get_space(game, id_space);
  set_spc = space_get_object(space);

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);

  if (space_is_illuminated (space) == _TRUE){
      illuminated = 1;
  } 

	/* Check if you want a space description or an object description */
  if(!strcmp (arg, "s") || !strcmp (arg, "space")){	/* space */
    description = space_get_desc(space);

    if (illuminated == 1){
	    fprintf(stdout,"%s. The space is illuminated.\n", description);
    } else{
	      fprintf (stdout, "%s.\n", description);
    }
    return _OK;
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

  if (object_is_bought(obj) == _TRUE){
    bought = 1;
  }

  if (iluminated == 0){
    fprintf(stdout, "Error, the space is not iluminated.\n");
    return _OK;
  }

  if (flag == 1 && bought == 1 && illuminated == 1){
    fprintf(stdout, "%s. The object has been bought.\n", object_get_desc(obj));
    return _OK;
  } 

  if (flag == 1 && bought == 0 && illuminated == 1){
    fprintf(stdout, "%s.\n", object_get_desc(obj));
    return _OK;
  }

  fprintf(stdout, "Error, the object has not been found.\n");

  return _ERROR;
}


/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNON
Turns on an object. It is used when the command is TURNON.

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_TURNON(Game *game, char *arg, int player){
	Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL, *set_spc = NULL;
  Id id_space = NO_ID;
  int flag, i;
  char *description = NULL;

	/* Check that the inputs are not empty */
  if (!game || !arg || player < 0){
    return _ERROR;
  }
  
  id_space = game_get_player_location(game, player);
  space = game_get_space(game, id_space);
  set_spc = space_get_object(space);

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);
  for(i=0, flag=0; i < set_get_count(set_inv) && flag == 0; i++){
  	obj = game_get_object(game, set_get_object_at_position(set_inv, i));
  	if(!strcmp(object_get_name(obj), arg)){
    	flag = 1;
    }
  }

  if (flag == 1){
    if(object_can_light(obj)){
    	object_set_on(obj, _TRUE);
    }
    return _OK;
  } 
    
  fprintf(stdout, "Error when you try to turn on an object.\n");
  return _ERROR;
}


/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNOFF
Turns on an object. It is used when the command is TURNOFF.

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_TURNOFF(Game *game, char *arg, int player){
	Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL, *set_spc = NULL;
  Id id_space = NO_ID;
  int flag, i;
  char *description = NULL;

	/* Check that the inputs are not empty */
  if (!game || !arg || player < 0){
    return _ERROR;
  }
  
  id_space = game_get_player_location(game, player);
  space = game_get_space(game, id_space);
  set_spc = space_get_object(space);

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);
  for(i=0, flag=0; i < set_get_count(set_inv) && flag == 0; i++){
  	obj = game_get_object(game, set_get_object_at_position(set_inv, i));
  	if(!strcmp(object_get_name(obj), arg)){
    	flag = 1;
    }
  }

  if (flag == 1){
    if(object_can_light(obj)){
    	object_set_on(obj, _FALSE);
    }
    return _OK;
  } 
    
  fprintf(stdout, "Error when you try to turn off an object.\n");
  return _ERROR;
}

/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_OPENL
Opens a link. It is used when the command is OPENL.

@param Game *game: the game.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_OPENL(Game *game, char *arg, char *arg2, int player){
	Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL, *set_spc = NULL;
  Id id_space = NO_ID;
  int flag, i;
  char *description = NULL;

	/* Check that the inputs are not empty */
  if (!game || !arg || !arg2 || player < 0){
    return _ERROR;
  }
  
  id_space = game_get_player_location(game, player);
  space = game_get_space(game, id_space);
 
  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);
  for(i=0, flag=0; i < set_get_count(set_inv) && flag == 0; i++){
  	obj = game_get_object(game, set_get_object_at_position(set_inv, i));
  	if(!strcmp(object_get_name(obj), arg2)){
    	flag = 1;
    }
  }
  

  if (flag == 1 && object_can_open(obj) != NO_ID){
		for(i=0, flag=0; i < MAX_LINKS && links(game)[i] != NULL && flag == 0; i++){
				if(!strcmp(link_get_name(links(game)[i]), arg2)){
						flag = 1;
				}
		}
  }

  if(flag == 1){ 
  	if(link_set_state(links(game)[i], OPEN) == _OK){
			return _OK;
    }
  }

  fprintf(stdout, "Error when you try to open a link.\n");
  return _ERROR;
} 


/**
@date 16-12-2016 
@author Alejandro Sanchez
@brief callback_SAVE
Makes a save of the game. It is used when the command is SAVE.
@param Game *game: the game.
@param char *path: the path of the file to make the save of the game.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_SAVE(Game *game, char *path){
  /* Check that the inputs are not empty */
  if(!game || !path){  
    return _ERROR;
   }
    
  /* Save the game */  
  game_save(game, path);

  return _OK;
}


/**
@date 16-12-2016 
@author Alejandro Sanchez
@brief callback_LOAD
Loads a save of the game. It is used when the command is LOAD.
@param Game *game: the game.
@param char *path: the path of the file to load the save of the game.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_LOAD(Game *game, char *path){
  /* Check that the inputs are not empty */
  if(!game || !path){  
    return _ERROR;
   }
    
  /* Save the game */  
  game_load(game, path);

  return _OK;
}


