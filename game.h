/* =================================================================== 
   File: game.h
   Version: 2.1
   Date: 04-10-2016
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description:
    It defines the game interface for each command.

   Revision history:
    Jan. 13, 2015 Version 1.0 (initial release)
    Sept. 30, 2016  Version 2.0 
    	Commented the file and extracted "game_load_spaces" to 
      "gamereader.c"
    Oct. 04, 2016 Version 2.1
      Added "idobject" and "idplayer".
      Added two inputs (player and object) to "game_init" and 
      "game_init_from_file" after creating ADT Player and ADT Object. 
    Oct. 20, 2016 Version 3.0
      Added "id_die" and deleted "idobject".
      Added field "die" to the structure "Game".
    Nov. 05, 2016 Version 4.0
      Made "Game" structure private.
      Modified some functions after this change.
      Added command GO and removed commands NEXT, BACK and JUMP.   
    Nov. 13, 2016 Version 4.1
      Created functions "game_spaces_are_linked" and "game_is_link_open"
      after creating ADT Link.  
=================================================================== */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "die.h"
#include "types.h"

/*** Constant values description ***/
#define idplayer 1
#define id_die 2

/* Data structure definition and description */
/*** The Game structure stores information of the game and its elements ***/
typedef struct _Game Game;


/*** Public functions description ***/
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
Game* game_init(Id player, Id die);



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
Game * game_init_from_file(char *filename1, char *filename2, Id player, Id die);



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
STATUS game_destroy(Game *game);



/* --------------------------------------------------------------------
   Function: game_update
   Date: 04-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Updates a game.

   Input: 
    Game *game: the game to update.
    Command *cmd: the command typed by the user.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_update(Game *game, Command *cmd);



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
Space * game_get_space(Game *game, Id id);



/* --------------------------------------------------------------------
   Function: game_set_space_at_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Sets a space in a specific position.

   Input: 
    Game *game: the game where the space is.
    Space *space : the space you want to set
    int position: the position where you want to set the space.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_space_at_position(Game *game, Space *space, int position);



/* --------------------------------------------------------------------
   Function: game_get_space_at_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Gets the space in a specific position.

   Input: 
    Game *game: the game where the space is.
    int position: the position of the space.

   Output: 
    Space *space : the space in that position or NULL on error.
   -------------------------------------------------------------------- */
Space * game_get_space_at_position(Game *game, int position);



/* --------------------------------------------------------------------
   Function: game_set_object_at_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Sets an object in a specific position.

   Input: 
    Game *game: the game where the object is.
    Object *object : the object you want to set
    int position: the position where you want to set the object.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_object_at_position(Game *game, Object *object, int position);



/* --------------------------------------------------------------------
   Function: game_get_object_at_position
   Date: 30-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Gets the object in a specific position.

   Input: 
    Game *game: the game where the object is.
    int position: the position of the object

   Output: 
    Object *object : the object in that position or NULL on error.
   -------------------------------------------------------------------- */
Object * game_get_object_at_position(Game *game, int position);



/* --------------------------------------------------------------------
   Function: game_set_link_at_position
   Date: 13-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Sets a link in a specific position.

   Input: 
    Game *game: the game where the link is.
    Link *link : the link you want to set
    int position: the position where you want to set the link.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS game_set_link_at_position(Game *game, Link *link, int position);



/* --------------------------------------------------------------------
   Function: game_get_link_at_position
   Date: 13-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gets the link in a specific position.

   Input: 
    Game *game: the game where the link is.
    int position: the position of the link.

   Output: 
    Link *link : the link in that position or NULL on error.
   -------------------------------------------------------------------- */
Link * game_get_link_at_position(Game *game, int position);



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
BOOL game_is_over(Game *game);



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
void game_print_data(Game *game);



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
void game_print_objects(Game *game, Space *space);



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
void game_print_screen(Game *game);




#endif
