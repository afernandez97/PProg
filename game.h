/**
@file game.h
@version 6.1
@date 19-12-2016
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
  @version
Dec. 19, 2016 Version 6.1
  Modified inspect to write the descriptions on the text field.
*/

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "person.h"
#include "dialogue.h"
#include "game_rules.h"
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
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_init_from_file
Initializes a game from two files which contain the spaces and objects.

@param char *path: the path of the different files that contain the game.
@param Id die: the identifier of the die of the game.

@return Game *game: the game initialized.
*/
Game * game_init_from_file(char *path, Id die);


/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief game_destroy
Destroys a game.

@param Game *game: the game to destroy.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_destroy(Game *game);



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
_STATUS game_update(Game *game, Command *command, int player);



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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_space_at_position(Game *game, Space *space, int position);



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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_object_at_position(Game *game, Object *object, int position);



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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_link_at_position(Game *game, Link *link, int position);



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

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_player_at_position(Game *game, Player *player, int position);



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
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_set_person_at_position
Sets a person in a specific position.

@param Game *game: the game where the person is.
@param Person * person : the person you want to set
@param int position: the position where you want to set the person.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_person_at_position(Game *game, Person *person, int position);



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_get_person_at_position
Gets the person in a specific position.

@param Game *game: the game where the person is.
@param int position: the position of the person

@return Person *person : the person in that position or NULL on error.
*/
Person * game_get_person_at_position(Game *game, int position);

/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_set_rule_at_position
Sets a rule in a specific position.

@param Game *game: the game where the rule is.
@param Rule * rule : the rule you want to set
@param int position: the position where you want to set the rule.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_rule_at_position(Game *game, Rule *rule, int position);



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_get_rule_at_position
Gets the rule in a specific position.

@param Game *game: the game where the rule is.
@param int position: the position of the rule

@return Rule *rule : the rule in that position or NULL on error.
*/
Rule * game_get_rule_at_position(Game *game, int position);

/**
@date 23-09-2016 
@author Alejandro Sanchez

@brief game_is_over
Ends the game.

@param Game *game: the game to end.

@return _BOOL: _FALSE.
*/
_BOOL game_is_over(Game *game);

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
@date 19-12-2016 
@author Adrián Fernández

@brief game_set_keyboard(Game* game, _BOOL keyboard)
Sets the keyboard field of a game.

@param Game *game: the game whose keyboard field you want to set.
@param _BOOL keyboard: the value you want to set.

@return 
_STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_keyboard(Game* game, _BOOL keyboard);

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_get_keyboard(Game* game)
Gets the keyboard field of a game.

@param Game *game: the game whose keyboard field you want to get.

@return 
_BOOL: value of the keyboard field
*/
_BOOL game_get_keyboard(Game *game);

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_set_answer(Game* game, char * answer)
Sets the answer field of a game.

@param Game *game: the game whose answer field you want to set.
@param char * answer: the value you want to set.

@return 
_STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_set_answer(Game* game, char * answer);

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_get_answer(Game* game)
Gets the answer field of a game.

@param Game *game: the game whose answer field you want to get.

@return 
char *: value of the answer field
*/
char * game_get_answer(Game *game);

#endif
