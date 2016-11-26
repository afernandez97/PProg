/**
@file game_reader.c
@version 4.0
@date 11-11-2016
@authors Guillermo Rodriguez and Alejandro Sanchez

@brief
It implements the game reader.

@version
Sept. 30, 2016  Version 1.0 (initial release)
@version
Sept. 30, 2016  Version 2.0 
  Commented the file.
@version
Oct. 27,  2016  Version 3.0
  Created functions "game_load_objects" and "game_add_object".
  Modified function "game_load_spaces".
@version
Nov. 05, 2016   Version 4.0
  Modified functions after making "Game" structure private.
@version
Nov. 11, 2016   Version 4.1
  Created functions "game_load_links" and "game_add_link".  
@version
Nov. 26, 2016 Version 5.0
  Updated headers to use Doxygen.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"


/*** Constant values description ***/
#define spaces(X) (X)->spaces
#define objects(X) (X)->objects
#define links(X) (X)->links


/*** Public functions definition ***/

/**
@date 30-09-2016 
@author Alejandro Sanchez

@brief game_add_space
Add a space to a game.

@param Game *game: the game where you add the space.
@param Space *space: the space you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_space(Game *game, Space *space){
  int i = 0;  /*!< Initialize the counter */

  if(!game || !space){  /*!< Check that the inputs are not empty */
    return ERROR;
  }

  /*!< Increase the counter until finding an empty space */
  while(i < MAX_SPACES && game_get_space_at_position(game, i) != NULL){
    i++;
  }

  /*!< Check if every space is not empty */
  if(i >= MAX_SPACES){
    return ERROR;
  }

  /*!< Set the new space */
  if(game_set_space_at_position(game, space, i) == ERROR){
    return ERROR;
  }

  return OK;
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_spaces
Loads a space from a file.

@param Game *game: the game where you want to load the spaces.
@param char *filename: the file that contains the spaces.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_load_spaces(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
	char gdesc[WORD_SIZE] = "";
	char desc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  
  if(!game || !filename){ /*!< Check that the inputs are not empty */
    return ERROR;
  }
  
  strcat(filename,"_spaces.dat");
  
  file = fopen(filename, "r");   /*!< Open the file where the spaces are */
  if(!file){
    return ERROR;
  }
  
  /*!< Read each line of the file and get the id and the links of each space */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#s:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");      
      west = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
			toks = strtok(NULL, "|");
			if(toks != NULL){
      	strcpy(desc, toks);
			}
      toks = strtok(NULL, "\n");
      if(toks != NULL){
        strcpy(gdesc, toks);        
      }

#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s\n", id, name, north, east, south, west, desc, gdesc);
#endif
      space = space_create(id); /*!< Create the space */
      if(space != NULL){
        /*!< Set the name to the space */  
        space_set_name(space, name);

        /*!< Set the links to the space */  
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);

        /*!< Set the graphic description to the space */ 
				space_set_gdesc(space, gdesc);
        
				/*!< Set the description to the space */ 
				space_set_desc(space, desc);
        
        /*!< Add the space to the game */
        game_add_space(game, space);  
      }
    } /*!< if(strncmp("#s:", line, 3) == 0) */
  } /*!< while */
  
  if(ferror(file)){ /*!< Test the error indicator for the file */ 
    status = ERROR;
  }
  
  fclose(file); /*!< Close the file */
  
  return status;
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_add_object
Adds an object to a game.

@param Game *game: the game where you add the object.
@param Object *object: the object you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_object(Game *game, Object *object){
  int i = 0;  /*!< Initialize the counter */

  if(!game || !object){  /*!< Check that the inputs are not empty */
    return ERROR;
  }

  /*!< Increase the counter until finding an empty object */
  while(i < MAX_OBJECTS && game_get_object_at_position(game, i) != NULL){
    i++;
  }

  /*!< Check if every object is not empty */
  if(i >= MAX_OBJECTS){
    return ERROR;
  }

  /*!< Set the new object */
  if(game_set_object_at_position(game, object, i) == ERROR){
    return ERROR;
	}

  return OK;
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_objects
Loads the objects from a file.

@param Game *game: the game where you want to load the objects.
@param char *filename: the file that contains the spaces.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_load_objects(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
	char desc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL;
  Space *space = NULL;
  STATUS status = OK;
  
  if(!game || !filename){ /*!< Check that the inputs are not empty */
    return ERROR;
  }
  
  strcat(filename,"_objects.dat");
  
  file = fopen(filename, "r");   /*!< Open the file where the objects are */
  if(!file){
    return ERROR;
  }
  
  /*!< Read each line of the file and get the id, the name and the location of the objects */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#o:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
			toks = strtok(NULL, "|");
			if(toks !=NULL){
      	strcpy(desc, toks);
			}
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%s\n", id, name, location, desc);
#endif
      object = object_create(id); /*!< Create the object */
      if(object != NULL){
        /*!< Set the name to the object */  
        object_set_name(object, name);

        /*!< Set the location to the object */  
				object_set_location(object, location);
				
				/*!< Set the description to the object */ 
				object_set_desc(object, desc);
        		

        /*!< Add the object to the game */
        game_add_object(game, object);  


        /*!< Add the object to the set of objects of its location */
        space = game_get_space(game, location);
        if(space != NULL){
          space_add_object(space, id);
				}

        
      }
    } /*!< if(strncmp("#o:", line, 3) == 0) */
  } /*!< while */
  
  if(ferror(file)){ /*!< Test the error indicator for the file */ 
    status = ERROR;
  }
  
  fclose(file); /*!< Close the file */
  
  return status;
}



/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_add_link
Adds an link to a game.

@param Game *game: the game where you add the link.
@param Link *link: the link you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_link(Game *game, Link *link){
  int i = 0;  /*!< Initialize the counter */

  if(!game || !link){  /*!< Check that the inputs are not empty */
    return ERROR;
  }

  /*!< Increase the counter until finding an empty link */
  while(i < MAX_LINKS && game_get_link_at_position(game, i) != NULL){
    i++;
  }

  /*!< Check if every link is not empty */
  if(i >= MAX_LINKS){
    return ERROR;
  }

  /*!< Set the new link */
  if(game_set_link_at_position(game, link, i) == ERROR){
    return ERROR;
  }

  return OK;
}



/**
@date 10-11-2016
@author Ricardo Riol

@brief game_load_links
Loads the links from a file.

@param Game *game: the game where you want to load the links.
@param char *filename: the file that contains the links. 
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_load_links(Game *game, char *filename){
	FILE *file = NULL;
	char line[WORD_SIZE] = "";
	char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID;
	Id space_id1 = NO_ID;
	Id space_id2 = NO_ID;
	STATE link_state = NO_STATE;
	Link *link = NULL;
  STATUS status = OK;


	if(!game || !filename){    /*!< Check that the inputs are not empty */
		return ERROR;
	}
        strcat(filename,"_links.dat");
	
        file = fopen(filename, "r");	/*!< Open the file where the links are */
	if(!file){				
		return ERROR;
	}

  /*!< Read each line of the file and get the id, the name, the spaces and the state of the links */
	while(fgets(line, WORD_SIZE, file)){
		if(strncmp("#l:", line, 3) == 0){
			toks = strtok(line + 3, "|");
			id = atol(toks);
			toks = strtok(NULL, "|");	
			strcpy(name, toks);
			toks = strtok(NULL, "|");
			space_id1 = atol(toks);
			toks = strtok(NULL, "|");
			space_id2 = atol(toks);
			toks = strtok(NULL, "|");
			link_state = atoi(toks);

#ifdef DEBUG 
	printf("Leido: %ld|%s|%ld|%ld|%d\n", id, name, space_id1, space_id2, link_state);
#endif
	
     	link = link_create(id);	/*!< Create the link */
   		if(link != NULL){
        /*!< Set the name to the link */			
  			link_set_name(link, name);

        /*!< Set the first space to the link */
        link_set_space1(link, space_id1);

        /*!< Set the second space to the link */
        link_set_space2(link, space_id2);

        /*!< Set the state to the link */
	   		link_set_state(link, link_state);

        /*!< Add the link to the game */
        game_add_link(game, link);  
      }
    } /*!< if(strncmp("#l:", line, 3) == 0) */
  } /*!< while */
  
  if(ferror(file)){
  	status = ERROR;
	}
  
	fclose(file);
  
	return status;
}
