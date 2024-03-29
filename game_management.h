/**
@file game_management.h
@version 6.2
@date 16-12-2016
@author Adrian Fernandez, Ricardo Riol, Guillermo Rodriguez and Alejandro Sanchez

@brief
It defines the game management.

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
  @version
Dec. 3, 2016 Version 6.0
  Added add_player and game_load_players.
@version
Dec. 11, 2016 Version 6.1
  Changed name of the file to game_management.h
  Created functions "game_load" and "game_save" (and game_save_X)
@version
Dec. 16, 2016 Version 6.2
  Added functions to load and save rules and people.
*/
#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game.h"	


/*!< Public functions description */

/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save
Saves the status of a game.

@param Game *game: the game you want to save its status.
@param char *path: the path of the different files that will contain the status of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save(Game *game, char *path); 


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_links
Saves the links of a game.

@param Game *game: the game you want to save its links.
@param char *filename: the filename that will contain the links of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_links(Game *game, char *filename);


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_spaces
Saves the spaces of a game.

@param Game *game: the game you want to save its spaces.
@param char *filename: the filename that will contain the spaces of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_spaces(Game *game, char *filename);


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_objects
Saves the objects of a game.

@param Game *game: the game you want to save its objects.
@param char *filename: the filename that will contain the objects of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_objects(Game *game, char *filename);


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_players
Saves the players of a game.

@param Game *game: the game you want to save its players.
@param char *filename: the filename that will contain the players of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_players(Game *game, char *filename);


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_save_rules
Saves the rules of a game.

@param Game *game: the game you want to save its rules.
@param char *filename: the filename that will contain the rules of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_rules(Game *game, char *filename);

/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_save_people
Saves the people of a game.

@param Game *game: the game you want to save its people.
@param char *filename: the filename that will contain the people of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_people(Game *game, char *filename);


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_load
Loads a previous save of a game.

@param Game *game: the game where you want to load the previous save of it.
@param char *path: the path of the different files that contain the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load(Game *game, char *path); 


/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_add_link
Adds an link to a game.

@param Game *game: the game where you add the link.
@param Link *link: the link you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_link(Game *game, Link *link);

/**
@date 10-11-2016
@author Ricardo Riol

@brief game_load_links
Loads the links from a file.

@param Game *game: the game where you want to load the links.
@param char *filename: the file that contains the links. 
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_links(Game *game, char *filename);


/**
@date 30-09-2016 
@author Alejandro Sanchez

@brief game_add_space
Add a space to a game.

@param Game *game: the game where you add the space.
@param Space *space: the space you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_space(Game *game, Space *space);



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_spaces
Loads a space from a file.

@param Game *game: the game where you want to load the spaces.
@param char *filename: the file that contains the spaces.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_spaces(Game *game, char *filename); 



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_add_object
Adds an object to a game.

@param Game *game: the game where you add the object.
@param Object *object: the object you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_object(Game *game, Object *object);



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_objects
Loads the objects from a file.

@param Game *game: the game where you want to load the objects.
@param char *filename: the file that contains the spaces.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_objects(Game *game, char *filename);


/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_add_link
Adds an player to a game.

@param Game *game: the game where you add the player.
@param Player *player: the player you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_player(Game *game, Player *player);

/**
@date 03-12-2016
@author Adrián Fernández

@brief game_load_links
Loads players from a file.

@param Game *game: the game where you want to load the players.
@param char *filename: the file that contains the players. 
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_players(Game *game, char *filename);


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_add_rule
Adds a rule to a game.

@param Game *game: the game where you add the rule.
@param Rule *rule: the rule you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_rule(Game *game, Rule *rule);


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_rules
Loads the rules from a file.

@param Game *game: the game where you want to load the rules .
@param char *filename: the file that contains the rules.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ game_load_rules(Game *game, char *filename);


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_add_person
Adds an person to a game.

@param Game *game: the game where you add the person.
@param Person *person: the person you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_person(Game *game, Person *person);



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_people
Loads the people from a file.

@param Game *game: the game where you want to load the people.
@param char *filename: the file that contains the people.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ game_load_people(Game *game, char *filename);




#endif
