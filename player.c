/* ===================================================================
   File: player.c
   Version: 2.1
   Date: 28-10-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
    It implements a player.

   Revision history:
    Oct. 03, 2016  Version 1.0 (initial release)
    Oct. 25, 2016  Version 2.0
      Changed "objects" field to Set *.
      Modified the functions that were affected by this field.
    Oct. 28, 2016  Version 2.1
      Changed "player_set_object" to "player_add_object".
      Created function "player_del_object".
    Nov. 05, 2016 Version 3.0
      Changed "objects" field to Inventory *inv.
      Modified the functions that were affected by this field.
      Created function "player_has_object" and "player_set_object".
   =================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/*** Constant values description ***/
#define id(X) (X)->id
#define name(X) (X)->name
#define location(X) (X)->location
#define inv(X) (X)->inv

/*** The Player structure stores information of the different players that play the game ***/
struct _Player {
	Id id; /* Identifier of the player */
  char name[WORD_SIZE + 1]; /* Name of the player */
  Id location;  /* Identifier of the space where the player is */
  Inventory *inv;  /* Bag of objects that the player carries */
};


/*** Public functions definition ***/
/* --------------------------------------------------------------------
   Function: player_create
   Date: 25-10-2016 
   Author: Guillermo Rodriguez

   Description: 
	  Creates a player.

   Input: 
	  Id id: the id of the player that is created.
   Output: 
	  Player *: the player created or NULL on error.
   -------------------------------------------------------------------- */
Player * player_create(Id id){
  Player *player = NULL;

  if(id == NO_ID){ /* Check that the input is not empty */ 
    return NULL;
  }

  player = (Player *)malloc(sizeof(Player));
  if(!player){   /* Check if memory has been allocated */
    return NULL;
  }

  /* Initialize structure fields */
  id(player) = id;

  name(player)[0] = '\0';
    
  location(player) = NO_ID;

  inv(player) = inventory_create();
  if(!inv(player)){   /* Check if memory has been allocated */
	  free(player);
    return NULL;
	}
 

  return player;
}



/* --------------------------------------------------------------------
   Function: player_destroy
   Date: 25-10-2016 
   Author: Guillermo Rodriguez

   Description: 
	  Destroys a player.

   Input: 
	  Player *player: the player to destroy.
   Output: 
	  STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS player_destroy(Player *player){
  if(!player){	      /* Check that the input is not empty */ 
    return ERROR;
  }

  inventory_destroy(inv(player)); /* Destroy the bag of objects */
  free(player);   /* Eliminate the memory of the player */
 
  return OK;
}



/* --------------------------------------------------------------------
   Function: player_get_id
   Date: 03-10-2016 
   Author: Guillermo Rodriguez

   Description: 
	  Returns a player's id.

   Input: 
	  Player *player: the player which you want the id of.
   Output: 
	  Id: the player's id or NO_ID on error.
   -------------------------------------------------------------------- */
Id player_get_id(Player *player){
  if(!player){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return id(player);
}



/* --------------------------------------------------------------------
   Function: player_set_name
   Date: 03-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Sets a name for a player.

   Input: 
    Player *player: the player you want to rename.
    char *name: the new name you want for the player.
  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS player_set_name(Player *player, char *name){
  if(!player || !name){ 		/* Check that the inputs are not empty */
    return ERROR;
  }

  /* Set the name and check if it hasworked */
  if(!strcpy(name(player), name)){ 	
    return ERROR;
  }

  return OK;
}



/* --------------------------------------------------------------------
   Function: player_get_name
   Date: 03-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Gives the information of the name of the player.

   Input: 
    Player *player: the player that you want to know the name.

   Output: 
    const char *: the name of the player or NULL on error.
   -------------------------------------------------------------------- */
const char * player_get_name(Player *player){
  if(!player){               /* Check that the input is not empty */
    return NULL;
  }

  return name(player);                
}



/* --------------------------------------------------------------------
   Function: player_set_location
   Date: 03-10-2016 
   Author: Guillermo Rodriguez

   Description: 
	  Sets a location for a player.

   Input: 
	  Player *player: the player you want to change.
	  Id location: the new location you want for the player.
  
   Output: 
    Status: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS player_set_location(Player *player, Id location){
  if(!player){      /* Check that the inputs are not empty */
  	return ERROR;
  }

  location(player) = location;  /* Set the location */

  return OK;
}



/* --------------------------------------------------------------------
   Function: player_get_location
   Date: 03-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Gives the location of the player.

   Input: 
    Player *player: the player that you want to know the location.

   Output: 
    Id location: the location of the player or NO_ID on error.
   -------------------------------------------------------------------- */
Id player_get_location(Player *player){
  if(!player){      /* Check that the input is not empty */
    return NO_ID;
  }

  return location(player); 
}



/* --------------------------------------------------------------------
   Function: player_set_inventory
   Date: 05-11-2016
   Author: Alejandro Sanchez

   Description:
    Sets the inventory of a player.
   
   Input:
    Player *player: the player whose inventory you want to set.
    Inventory *inv: the inventory you want to set.
   
   Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
------------------------------------------------------------------- */
STATUS player_set_inventory(Player *player, Inventory *inv){
  /* Check that the inputs are not empty */
  if(!inv || !inventory){
    return ERROR;
  }

  /* Eliminate the memory of the inventory of objects if it exists */
  if(inv(player) != NULL){
    inventory_destroy(inv(player));
  }

  /* Set the new inventory to the player */
  inv(player) = inv;
  
  return OK;
}



/* --------------------------------------------------------------------
   Function: player_add_object
   Date: 28-10-2016 
   Author: Alejandro Sanchez

   Description: 
	  Sets an object for a player.

   Input: 
	  Player *player: the player that you want to change.
	  Id object: the new object you want for the player.
  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS player_add_object(Player *player, Id object){
  if(!player || object == NO_ID){    /* Check that the inputs are not empty */
  	return ERROR;
  }

  /* Add the object to the player */ 
  if(inventory_add_object(inv(player), object) == ERROR){
    return ERROR;
  }

  return OK;
}


/* --------------------------------------------------------------------
   Function: player_del_object
   Date: 28-10-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Deletes an object of the player.
 
   Input: 
    Player *player: the player you want to change.
    Id object: the identifier of the object you want to remove 
    from the player.
   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS player_del_object(Player *player, Id object){
  if(!player || object == NO_ID){  /* Check that the inputs are not empty */
    return ERROR;
  }
 
  /* Removes the object from the player */
  if(inventory_del_object(inv(player), object) == ERROR){
    return ERROR;
  }      

  return OK;
}



/* --------------------------------------------------------------------
   Function: player_get_inventory
   Date: 05-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the information of the objects of the player.

   Input: 
	  Player *player: the player that you want to know the object.

   Output: 
    Inventory *: the inventory of objects of the player or NULL on error.
   -------------------------------------------------------------------- */
Inventory * player_get_inventory(Player *player){
  if(!player){      /* Check that the input is not empty */
  	return NULL;
  }

  return inv(player); 
}



/* --------------------------------------------------------------------
   Function: player_has_object
   Date: 05-11-2016 
   Author: Guillermo Rodriguez 
  
   Description: 
    Checks if there is an especific object in the bag of the player.
  
   Input: 
    Player *player: the player you want to know if he brings an object.
    Id object: the id of the object you want to know if it is in the bag 
    of the player.
                 
   Output: 
    BOOL: TRUE if the object is in the bag of the player and FALSE in other cases. 
   -------------------------------------------------------------------- */
BOOL player_has_object(Player *player, Id object){
  if(!player || object == NO_ID){
    return FALSE;
  }

  return inventory_is_object(inv(player), object);
}



/* --------------------------------------------------------------------
   Function: player_print
   Date: 25-10-2016 
   Author: Guillermo Rodriguez

   Description: 
	  Prints the information of the player on the screen.

   Input: 
	  Player *player: the player you want to print.
   Output: 
	  STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS player_print(Player *player){
  if(!player){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Print the player fields */
  fprintf(stdout, "Player -->  (Id: %ld; Name: %s; Location:%ld; ", 
    id(player), name(player), location(player));
  if(inventory_print(inv(player)) == ERROR){
	 return ERROR;
  }

  fprintf(stdout, ")\n");

  return OK;
}






