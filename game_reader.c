/* =================================================================== 
   File: game_reader.c
   Version: 4.1
   Date: 11-11-2016
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description:
    It implements the game reader.

   Revision history:
    Sept. 30, 2016  Version 1.0 (initial release)
    Sept. 30, 2016  Version 2.0 
      Commented the file.
		Oct. 27,	2016	Version 3.0
			Created functions "game_load_objects" and "game_add_object".
      Modified function "game_load_spaces".
    Nov. 05, 2016   Version 4.0
      Modified functions after making "Game" structure private.
    Nov. 11, 2016   Version 4.1
      Created functions "game_load_links" and "game_add_link".  
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"


/*** Constant values description ***/
#define spaces(X) (X)->spaces
#define objects(X) (X)->objects
#define links(X) (X)->links


/*** Public functions definition ***/
/* ----------------------------------------------------------------------------
   Function: game_add_space
   Date: 30-09-2016 
   Author: Alejandro Sanchez

   Description: 
    Adds a space to a game.

   Input: 
    Game *game: the game where you add the space.
    Space *space: the space you want to add to the game.  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_add_space(Game *game, Space *space){
  int i = 0;  /* Initialize the counter */

  if(!game || !space){  /* Check that the inputs are not empty */
    return ERROR;
  }

  /* Increase the counter until finding an empty space */
  while(i < MAX_SPACES && game_get_space_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every space is not empty */
  if(i >= MAX_SPACES){
    return ERROR;
  }

  /* Set the new space */
  if(game_set_space_at_position(game, space, i) == ERROR){
    return ERROR;
  }

  return OK;
}



/* ----------------------------------------------------------------------------
   Function: game_load_spaces
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Loads the spaes from a file.

   Input: 
    Game *game: the game where you want to load the spaces.
    char *filename: the file that contains the spaces.   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_load_spaces(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
	char gdesc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR;
  }
  
  file = fopen(filename, "r");   /* Open the file where the spaces are */
  if(!file){
    return ERROR;
  }
  
  /* Read each line of the file and get the id and the links of each space */
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
      toks = strtok(NULL, ".");
      if(toks != NULL){
        strcpy(gdesc, toks);        
      }

#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s\n", id, name, north, east, south, west, gdesc);
#endif
      space = space_create(id); /* Create the space */
      if(space != NULL){
        /* Set the name to the space */  
        space_set_name(space, name);

        /* Set the links to the space */  
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);

        /* Set the graphic description to the space */ 
        if(toks != NULL){
				  space_set_gdesc(space, gdesc);
        }
        /* Add the space to the game */
        game_add_space(game, space);  
      }
    } /* if(strncmp("#s:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}



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
STATUS game_add_object(Game *game, Object *object){
  int i = 0;  /* Initialize the counter */

  if(!game || !object){  /* Check that the inputs are not empty */
    return ERROR;
  }

  /* Increase the counter until finding an empty object */
  while(i < MAX_OBJECTS && game_get_object_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every object is not empty */
  if(i >= MAX_OBJECTS){
    return ERROR;
  }

  /* Set the new object */
  if(game_set_object_at_position(game, object, i) == ERROR){
    return ERROR;
	}

  return OK;
}



/* ----------------------------------------------------------------------------
   Function: game_load_objects
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Loads the objects from a file.

   Input: 
    Game *game: the game where you want to load the objects.
    char *filename: the file that contains the objects.   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   --------------------------------------------------------------------------- */
STATUS game_load_objects(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL;
  Space *space = NULL;
  STATUS status = OK;
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR;
  }
  
  file = fopen(filename, "r");   /* Open the file where the objects are */
  if(!file){
    return ERROR;
  }
  
  /* Read each line of the file and get the id, the name and the location of the objects */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#o:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif
      object = object_create(id); /* Create the object */
      if(object != NULL){
        /* Set the name to the object */  
        object_set_name(object, name);

        /* Set the location to the object */  
				object_set_location(object, location);

        /* Add the object to the game */
        game_add_object(game, object);  

        /* Add the object to the set of objects of its location */
        space = game_get_space(game, location);
        if(space != NULL){
          space_add_object(space, id);
        }
      }
    } /* if(strncmp("#o:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}



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
STATUS game_add_link(Game *game, Link *link){
  int i = 0;  /* Initialize the counter */

  if(!game || !link){  /* Check that the inputs are not empty */
    return ERROR;
  }

  /* Increase the counter until finding an empty link */
  while(i < MAX_LINKS && game_get_link_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every link is not empty */
  if(i >= MAX_LINKS){
    return ERROR;
  }

  /* Set the new link */
  if(game_set_link_at_position(game, link, i) == ERROR){
    return ERROR;
  }

  return OK;
}



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
STATUS game_load_links(Game *game, char *filename){
	FILE *file = NULL;
	char line[WORD_SIZE] = "";
	Id id = NO_ID;
	char name[WORD_SIZE] = "";
	Id space_id1 = NO_ID;
	Id space_id2 = NO_ID;
	STATE link_state = NO_STATE;
	Link *link = NULL;


	if(!game || !filename){    /* Check that the inputs are not empty */
		return ERROR;
	}

	file = fopen(filename, "r");	/* Open the file where the links are */
	if(!file){				
		return ERROR;
	}

  /* Read each line of the file and get the id, the name, the spaces and the state of the links */
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
	
     	link = link_create(id);	/* Create the link */
   		if(link != NULL){
        /* Set the name to the link */			
  			link_set_name(link, name);

        /* Set the first space to the link */
        link_set_space1(link, space_id1);

        /* Set the second space to the link */
        link_set_space2(link, space_id2);

        /* Set the state to the link */
	   		link_set_state(link, state);

        /* Add the link to the game */
        game_add_link(game, link);  
      }
    } /* if(strncmp("#l:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){
  	status = ERROR;
	}
  
	fclose(file);
  
	return status;
}
