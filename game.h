/**
@file game.h
@version 6.0
@date 03-12-2016
@authors Guillermo Rodriguez and Alejandro Sanchez

@brief
It defines the game interface for each command.

@version
Jan. 13, 2015 Version 1.0 (initial release)
@version
Sept. 30, 2016  Version 2.0 
	Commented the file and extracted "game_load_spaces" to 
  "gamereader.c"
@version
Oct. 04, 2016 Version 2.1
  Added "idobject" and "idplayer".
  Added two inputs (player and object) to "game_init" and 
  "game_init_from_file" after creating ADT Player and ADT Object. 
@version
Oct. 20, 2016 Version 3.0
  Added "id_die" and deleted "idobject".
  Added field "die" to the structure "Game".
@version
Nov. 05, 2016 Version 4.0
  Made "Game" structure private.
  Modified some functions after this change.
  Added command GO and removed commands NEXT, BACK and JUMP.   
@version
Nov. 13, 2016 Version 4.1
  Created functions "game_spaces_are_linked" and "game_is_link_open"
  after creating ADT Link.  
@version
Nov. 26, 2016 Version 5.0
  Updated headers to use Doxygen.
@version
Dec. 3, 2016 Version 6.0
  Added field "text", players now can be loaded from a file.
*/

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "link.h"
#include "die.h"
#include "types.h"

/**
@def Constant values description 
*/
#define idplayer 1
#define id_die 2


/**
@brief
The Game structure stores information of the game and its elements.
*/
typedef struct _Game Game;


/*!< Public functions description */

/**
@date 05-10-2016 
@author Guillermo Rodriguez

@brief game_init
Initializes a game.

@param Id die: the identifier of the die of the game.

@return Game *game: the game initialized.
*/
Game* game_init(Id die);



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
Game * game_init_from_file(char *filename1,Id player, Id die);


/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief game_destroy
Destroys a game.

@param Game *game: the game to destroy.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_destroy(Game *game);



/**
@date 05-11-2016 
@author Ricardo Riol

@brief game_update
Updates a game.

@param Game *game: the game to update.
@param Command *cmd: the command typed by the user.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_update(Game *game, Command *cmd);



/**
@date 04-10-2016 
@author Alejandro Sanchez

@brief game_get_space
Gives a specific space.

@param Game *game: the game where the space is.
@param Id id: the id of the space you want.

@return Space *: the space you want or NULL on error.
*/
Space * game_get_space(Game *game, Id id);



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
STATUS game_set_space_at_position(Game *game, Space *space, int position);



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_get_space_at_position
Gets the space in a specific position.

@param Game *game: the game where the space is.
@param int position: the position of the space.

@return Space *space : the space in that position or NULL on error.
*/
Space * game_get_space_at_position(Game *game, int position);



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
STATUS game_set_object_at_position(Game *game, Object *object, int position);



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_get_object_at_position
Gets the object in a specific position.

@param Game *game: the game where the object is.
@param int position: the position of the object

@return Object *object : the object in that position or NULL on error.
*/
Object * game_get_object_at_position(Game *game, int position);



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
STATUS game_set_link_at_position(Game *game, Link *link, int position);



/**
@date 13-10-2016 
@author Alejandro Sanchez

@brief game_get_link_at_position
Gets the link in a specific position.

@param Game *game: the game where the link is.
@param int position: the position of the link.

@return Link *link : the link in that position or NULL on error.
*/
Link * game_get_link_at_position(Game *game, int position);



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_link_at_position
Sets a player in a specific position.

@param Game *game: the game where the player is.
@param Player *player: the player you want to set
@param int position: the position where you want to set the player.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_set_player_at_position(Game *game, Player *player, int position);



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_link_at_position
Gets the player in a specific position.

@param Game *game: the game where the player is.
@param int position: the position of the player.

@return Player *player : the player in that position or NULL on error.
*/
Player * game_get_player_at_position(Game *game, int position);



/**
@date 23-09-2016 
@author Alejandro Sanchez

@brief game_is_over
Ends the game.

@param Game *game: the game to end.

@return BOOL: FALSE.
*/
BOOL game_is_over(Game *game);



/**
@date 20-10-2016 
@author Alejandro Sanchez

@brief game_print_data
Prints the data of the game.

@param Game *game: the game to print its elements.

@return
*/
void game_print_data(Game *game);



/**
@date 02-11-2016 
@author Alejandro Sanchez

@brief game_print_objects
Prints the objects of the game (<name>:<location>).

@param Game *game: the game to print its objects.
@param Space *space: the space where you want to print the objects.

@return
*/
void game_print_objects(Game *game, Space *space);



/**
Function: 
@date 02-11-2016 
@author Alejandro Sanchez

@brief game_print_screen
Prints the screen of the game.

@param Game *game: the game to print its screen.

@return
*/
void game_print_screen(Game *game);



#endif
