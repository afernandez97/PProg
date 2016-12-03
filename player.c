/**
@file player.c
@version 2.1
@Date 28-10-2016 
@author Guillermo Rodriguez and Alejandro Sanchez

@brief 
It implements a player.


@version Oct. 03, 2016  Version 1.0 (initial release)
@version Oct. 25, 2016  Version 2.0
  Changed "objects" field to Set *.
  Modified the functions that were affected by this field.
@version Oct. 28, 2016  Version 2.1
  Changed "player_set_object" to "player_add_object".
  Created function "player_del_object".
@version Nov. 05, 2016 Version 3.0
  Changed "objects" field to Inventory *inv.
  Modified the functions that were affected by this field.
  Created function "player_has_object" and "player_set_object".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/*!< Constant values description */
#define id(X) (X)->id
#define name(X) (X)->name
#define location(X) (X)->location
#define inv(X) (X)->inv

/** @brief
The Player structure stores information of the different players that play the game.
*/
struct _Player {
	Id id; /*!< Identifier of the player */
  char name[WORD_SIZE]; /*!< Name of the player */
  Id location;  /*!< Identifier of the space where the player is */
  Inventory *inv;  /*!< Bag of objects that the player carries */
};


/*!< Public functions definition */

/**
   @date 25-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Creates a player.player_create()

   @param 
	  Id id: the id of the player that is created.
   @return 
	  Player *: the player created or NULL on error.
   */
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



/**
   @date 25-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Destroys a player.player_destroy()

   @param 
	  Player *player: the player to destroy.
   @return 
	  STATUS: ERROR if the input is NULL and OK otherwise.
   */
STATUS player_destroy(Player *player){
  if(!player){	      /* Check that the input is not empty */ 
    return ERROR;
  }

  inventory_destroy(inv(player)); /* Destroy the bag of objects */
  free(player);   /* Eliminate the memory of the player */
 
  return OK;
}



/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Returns a player's id.player_get_id()

   @param 
	  Player *player: the player which you want the id of.
   @return 
	  Id: the player's id or NO_ID on error.
   */
Id player_get_id(Player *player){
  if(!player){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return id(player);
}



/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets a name for a player.player_set_name()

   @param Player *player: the player you want to rename.
   @param char *name: the new name you want for the player.
  
   @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
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



/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the name of the player.player_get_name()

   @param 
    Player *player: the player that you want to know the name.

   @return 
    const char *: the name of the player or NULL on error.
   */
const char * player_get_name(Player *player){
  if(!player){               /* Check that the input is not empty */
    return NULL;
  }

  return name(player);                
}



/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Sets a location for a player.player_set_location()

   @param Player *player: the player you want to change.
   @param Id location: the new location you want for the player.
  
   @return 
    Status: OK if you do the operation well and ERROR in other cases.
   */
STATUS player_set_location(Player *player, Id location){
  if(!player || location == NO_ID){      /* Check that the inputs are not empty */
  	return ERROR;
  }

  location(player) = location;  /* Set the location */

  return OK;
}



/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the location of the player.player_get_location()

   @param 
    Player *player: the player that you want to know the location.

   @return 
    Id location: the location of the player or NO_ID on error.
   */
Id player_get_location(Player *player){
  if(!player){      /* Check that the input is not empty */
    return NO_ID;
  }

  return location(player); 
}



/**
   @date 05-11-2016
   @author Alejandro Sanchez

   @brief
    Sets the inventory of a player. player_set_inventory()
   
   
   @param Player *player: the player whose inventory you want to set.
   @param Inventory *inv: the inventory you want to set.
   
   @return
    STATUS: OK if you do the operation well and ERROR in other cases.
 */
STATUS player_set_inventory(Player *player, Inventory *inv){
  /* Check that the inputs are not empty */
  if(!player || !inv){
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



/**
   @date 28-10-2016 
   @author Alejandro Sanchez

   @brief 
	  Sets an object for a player.player_add_object()

  
  @param  Player *player: the player that you want to change.
  @param  Id object: the new object you want for the player.
  
  @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
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


/**
   @date 28-10-2016 
   @author Alejandro Sanchez
 
   @brief 
    Deletes an object of the player.player_del_object()
 
    
   @param Player *player: the player you want to change.
   @param Id object: the identifier of the object you want to remove 
    from the player.
   
   @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
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



/**
   @date 05-10-2016 
   @author Alejandro Sanchez

   @brief 
    Gives the information of the objects of the player.player_get_inventory()

   @param 
	  Player *player: the player that you want to know the object.

   @return 
    Inventory *: the inventory of objects of the player or NULL on error.
   */
Inventory * player_get_inventory(Player *player){
  if(!player){      /* Check that the input is not empty */
  	return NULL;
  }

  return inv(player); 
}



/**
   @date 05-11-2016 
   @author Guillermo Rodriguez 
  
   @brief 
    Checks if there is an especific object in the bag of the player.player_has_object()
  
   
   @param Player *player: the player you want to know if he brings an object.
   @parm Id object: the id of the object you want to know if it is in the bag 
    of the player.
                 
    @return 
    BOOL: TRUE if the object is in the bag of the player and FALSE in other cases. 
   */
BOOL player_has_object(Player *player, Id object){
  if(!player || object == NO_ID){
    return FALSE;
  }

  return inventory_is_object(inv(player), object);
}



/**
   @date 25-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Prints the information of the player on the screen.player_print()

   @param 
	  Player *player: the player you want to print.
   @return 
	  STATUS: ERROR if the input is NULL and OK otherwise.
   */
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






