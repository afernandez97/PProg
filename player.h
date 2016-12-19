/**
@file player.h
@version 4.0
@Date 16-12-2016 
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
@version Dec. 16, 2016 Version 4.0
  Added field "money".
  Created functions "player_set_money" and "player_get_money".
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"
#include "types.h"

/**
@def Constant values description
*/
#define MAX_PLAYERS 12

/*!< Data structures definition */
typedef struct _Player Player;



/*!< Public functions description */

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
Player * player_create(Id id);


/**
   @date 25-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Destroys a player.player_destroy()

   @param 
	  Player *player: the player to destroy.
   @return 
	  _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS player_destroy(Player *player);



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
Id player_get_id(Player *player);




/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets a name for a player.player_set_name()

   @param Player *player: the player you want to rename.
   @param char *name: the new name you want for the player.
  
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS player_set_name(Player *player, char *name);




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
const char * player_get_name(Player *player);




/**
   @date 03-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Sets a location for a player.player_set_location()

   @param Player *player: the player you want to change.
   @param Id location: the new location you want for the player.
  
   @return 
    Status: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS player_set_location(Player *player, Id location);



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
Id player_get_location(Player *player);



/**
   @date 05-11-2016
   @author Alejandro Sanchez

   @brief
    Sets the inventory of a player. player_set_inventory()
   
   
   @param Player *player: the player whose inventory you want to set.
   @param Inventory *inv: the inventory you want to set.
   
   @return
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
 */
_STATUS player_set_inventory(Player *player, Inventory *inv);



/**
   @date 28-10-2016 
   @author Alejandro Sanchez

   @brief 
	  Sets an object for a player.player_add_object()

  
  @param  Player *player: the player that you want to change.
  @param  Id object: the new object you want for the player.
  
  @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS player_add_object(Player *player, Id object);



/**
   @date 28-10-2016 
   @author Alejandro Sanchez
 
   @brief 
    Deletes an object of the player.player_del_object()
 
    
   @param Player *player: the player you want to change.
   @param Id object: the identifier of the object you want to remove 
    from the player.
   
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS player_del_object(Player *player, Id object);



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
Inventory * player_get_inventory(Player *player);



/**
   @date 05-11-2016 
   @author Guillermo Rodriguez 
  
   @brief 
    Checks if there is an especific object in the bag of the player.player_has_object()
  
   
   @param Player *player: the player you want to know if he brings an object.
   @parm Id object: the id of the object you want to know if it is in the bag 
    of the player.
                 
    @return 
    _BOOL: _TRUE if the object is in the bag of the player and _FALSE in other cases. 
   */
_BOOL player_has_object(Player *player, Id object);


/**
   @date 18-12-2016 
   @author Guillermo Rodriguez

   @brief 
	  Sets money for a player.player_set_money()

   @param Player *player: the player you want to change.
   @param double money: the money you want to add or quit for a player.
  
   @return 
    Status: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS player_set_money(Player *player, double money);



/**
   @date 18-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the money of the player.player_get_money()

   @param 
    Player *player: the player that you want to know the money.

   @return 
    double money: the money of the player or NO_ID on error.
   */
double player_get_money(Player *player);



/**
   @date 25-10-2016 
   @author Guillermo Rodriguez

   @brief 
	  Prints the information of the player on the screen.player_print()

   @param 
	  Player *player: the player you want to print.
   @return 
	  _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS player_print(Player *player);


#endif
