/* ===================================================================
  File: inventory.h
  Version: 1.1
  Date: 04-11-2016
  Authors: Adrian Fernandez, Alejandro Sanchez

  Description:
    It defines an inventory.

  Revision history:
    Nov. 3, 2016 Version 1.0 (initial release)
    Nov. 4, 2016 Version 1.1
      Created the rest of the functions and commented the file.
=================================================================== */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "set.h"

/* Constant values description */
#define MAX_BAG 10

#define bag(X) (X)->bag
#define max(X) (X)->max

/*** Data structures definition ***/
typedef struct _Inventory Inventory;


/* Public functions description */
/* --------------------------------------------------------------------
   Function: inventory_create
   Date: 03-11-2016
   Author: Adrian Fernández

   Description: 
    Creates an inventory.

   Input: 

   Output:
    Inventory *: the inventory created or NULL on error.
------------------------------------------------------------------- */
Inventory *inventory_create();



/* --------------------------------------------------------------------
   Function: inventory_destroy
   Date: 03-11-2016
   Author: Adrian Fernández
   
   Description:
    Destroys an inventory.

   Input:
    Inventory *: the inventory to destroy.

   Output:
    STATUS: ERROR if the input is NULL and OK otherwise.
------------------------------------------------------------------- */
STATUS inventory_destroy(Inventory *inv);



/* --------------------------------------------------------------------
   Function: inventory_add_object
   Date: 04-11-2016 
   Author: Alejandro Sanchez

   Description: 
	  Adds an object to an inventory.

   Input: 
	  Inventory *inventory: the inventory that you want to change.
	  Id object: the new object you want for the inventory.
  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS inventory_add_object(Inventory *inventory, Id object);



/* --------------------------------------------------------------------
   Function: inventory_del_object
   Date: 04-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Deletes an object of the inventory.
 
   Input: 
    Inventory *inventory: the inventory you want to change.
    Id object: the identifier of the object you want to remove 
    from the inventory.
   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS inventory_del_object(Inventory *inventory, Id object);



/* --------------------------------------------------------------------
   Function: inventory_set_bag
   Date: 04-11-2016
   Author: Adrian Fernandez

   Description:
    Sets the bag of an inventory.
   
   Input:
    Inventory *inv: the inventory whose bag you want to set.
    Set *bag: the bag you want to set.
   
   Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
------------------------------------------------------------------- */
STATUS inventory_set_bag(Inventory *inv, Set *bag);



/* --------------------------------------------------------------------
   Function: inventory_get_bag
   Date: 04-11-2016
   Author: Adrian Fernandez

   Description:
    Returns the bag of an inventory.

   Input:
    Inventory *: the inventory whose bag you want to get.
  
   Output:
    Inventory *: the bag of the inventory.
------------------------------------------------------------------- */
Set* inventory_get_bag(Inventory *inv);



/* --------------------------------------------------------------------
   Function: inventory_get_count
   Date: 04-11-2016 
   Author: Alejandro Sanchez
  
   Description: 
    Returns the number of objects in the inventory.
  
   Input: 
    Inventory *inv: the inventory that you want to know its number 
    of objects.
                 
   Output: 
    int: the number of objects in the inventory.
   -------------------------------------------------------------------- */
int inventory_get_count(Inventory *inv);



/* --------------------------------------------------------------------
   Function: inventory_get_max
   Date: 04-11-2016
   Author: Adrian Fernandez

   Description:
    Returns the maximum number of objects that an inventory can contain.
   
   Input:
    Inventory *inv: the inventory whose maximum number of objects
    you want to get.
   
   Output:
    int: Maximum number of objects that the inventory can contain.
------------------------------------------------------------------- */
int inventory_get_max(Inventory *inv);



/* --------------------------------------------------------------------
   Function: inventory_is_empty
   Date: 04-11-2016 
   Author: Alejandro Sanchez
  
   Description: 
    Checks if the inventory is empty or not.
  
   Input: 
    Inventory *inv: the inventory to check.
                 
   Output: 
    BOOL: TRUE is the inventory is empty or FALSE if not.
   -------------------------------------------------------------------- */
BOOL inventory_is_empty(Inventory *inv);



/* --------------------------------------------------------------------
   Function: inventory_is_full
   Date: 04-11-2016 
   Author: Alejandro Sanchez
  
   Description: 
    Checks if the inventory is full or not.
  
   Input: 
    Inventory *inv: the inventory to check.
                 
   Output: 
    BOOL: TRUE is the inventory is full or FALSE if not.
   -------------------------------------------------------------------- */
BOOL inventory_is_full(Inventory *inv);


/* --------------------------------------------------------------------
   Function: inventory_print
   Date: 04-11-2016 
   Author: Alejandro Sanchez

   Description: 
	  Prints the information of the inventory on the screen.

   Input: 
	  Inventory *inv: the inventory you want to print.
   Output: 
	  STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS inventory_print(Inventory *inv);

#endif

