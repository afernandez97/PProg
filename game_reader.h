/**
File: game_reader.h
@version 5.0
@date 11-11-2016
@authors Guillermo Rodriguez and Alejandro Sanchez

@brief
It defines the game reader.

@version
Sept. 30, 2016 Version 1.0 (initial release)
@version
Sept. 30, 2016  Version 2.0 
  Commented the file.
@version
Oct.  27, 2016  Version 3.0
  Created functions "game_load_objects" and "game_add_object".
@version
Nov. 11, 2016   Version 4.0
  Created functions "game_load_links" and "game_add_link".
@version
Nov. 26, 2016 Version 5.0
  Updated headers to use Doxygen.
*/
#ifndef GAME_READER_H
#define GAME_READER_H
#include "game.h"


/*!< Public functions description */

/**
@date 30-09-2016 
@author Alejandro Sanchez

@brief game_add_space
Add a space to a game.

@param Game *game: the game where you add the space.
@param Space *space: the space you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_space(Game *game, Space *space);



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_spaces
Loads a space from a file.

@param Game *game: the game where you want to load the spaces.
@param char *filename: the file that contains the spaces.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_load_spaces(Game* game, char* filename); 



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_add_object
Adds an object to a game.

@param Game *game: the game where you add the object.
@param Object *object: the object you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_object(Game *game, Object *object);



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_objects
Loads the objects from a file.

@param Game *game: the game where you want to load the objects.
@param char *filename: the file that contains the spaces.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_load_objects(Game *game, char *filename);

/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_add_link
Adds an link to a game.

@param Game *game: the game where you add the link.
@param Link *link: the link you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_link(Game *game, Link *link);

/**
@date 10-11-2016
@author Ricardo Riol

@brief game_load_links
Loads the links from a file.

@param Game *game: the game where you want to load the links.
@param char *filename: the file that contains the links. 
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_load_links(Game *game, char *filename);

#endif
