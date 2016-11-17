/* =================================================================== 
   File: game_reader.h
   Version: 4.0
   Date: 11-11-2016
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description:
    It defines the game reader.

   Revision history:
    Sept. 30, 2016 Version 1.0 (initial release)
    Sept. 30, 2016  Version 2.0 
    	Commented the file.
		Oct.	27,	2016	Version 3.0
			Created functions "game_load_objects" and "game_add_object".
    Nov. 11, 2016   Version 4.0
      Created functions "game_load_links" and "game_add_link".
=================================================================== */
#ifndef GAME_READER_H
#define GAME_READER_H
#include "game.h"


/*** Public functions description ***/
/* ----------------------------------------------------------------------------
   Function: game_add_space
   Date: 30-09-2016 
   Author: Alejandro Sanchez

   Description: 
    Add a space to a game.

   Input: 
    Game *game: the game where you add the space.
    Space *space: the space you want to add to the game.  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_add_space(Game *game, Space *space);



/* ----------------------------------------------------------------------------
   Function: game_load_spaces
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Loads a space from a file.

   Input: 
    Game *game: the game where you want to load the spaces.
    char *filename: the file that contains the spaces.   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_load_spaces(Game* game, char* filename); 



/* ----------------------------------------------------------------------------
   Function: game_add_object
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Adds an object to a game.

   Input: 
    Game *game: the game where you add the object.
    Object *object: the object you want to add to the game.  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_add_object(Game *game, Object *object);



/* ----------------------------------------------------------------------------
   Function: game_load_objects
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Loads the objects from a file.

   Input: 
    Game *game: the game where you want to load the objects.
    char *filename: the file that contains the spaces.   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_load_objects(Game *game, char *filename);

/* ----------------------------------------------------------------------------
   Function: game_add_link
   Date: 13-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Adds an link to a game.

   Input: 
    Game *game: the game where you add the link.
    Link *link: the link you want to add to the game.  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_add_link(Game *game, Link *link);

/* --------------------------------------------------------------------
   Function: game_load_links
   Date: 10-11-2016
   Author: Ricardo Riol
 
   Description:
    Loads the links from a file.
  
   Input:
    Game *game: the game where you want to load the links.
    char *filename: the file that contains the links. 
   Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
 ------------------------------------------------------------------- */
STATUS game_load_links(Game *game, char *filename);

#endif
