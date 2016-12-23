/**
  @file inventory.h
  @version 1.1
  @date 04-11-2016
  @author Adrian Fernandez, Alejandro Sanchez

  @brief
    It implements an inventory.

  @version Nov. 03, 2016 Version 1.0 (initial release)
  @version  Nov. 4, 2016 Version 1.1
    Created the rest of the functions and commented the file.
*/


#ifndef INVENTORY_H
#define INVENTORY_H

#include "set.h"

/**
@def Constant values description
*/
#define MAX_BAG 10

#define bag(X) (X)->bag
#define max(X) (X)->max

/*!< Data structures definition */
typedef struct _Inventory Inventory;



/*!< Public functions description */

/**
   @date 03-11-2016
   @author Adrian Fernández

   @brief 
   	Creates an inventory.inventory_create()

   @param 

   @return
  	Inventory *: the inventory created or NULL on error.
*/
Inventory *inventory_create();



/**
   @date 03-11-2016
   @author Adrian Fernández
   
   @brief
   	Destroys an inventory.inventory_destroy()

   @param
  	Inventory *: the inventory to destroy.

   @return
    STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/
STATUS_ inventory_destroy(Inventory *inv);



/**
   @date 04-11-2016 
   @author Alejandro Sanchez

   @brief 
	  Adds an object to an inventory.inventory_add_object()

 
   @param  Inventory *inventory: the inventory that you want to change.
   @param Id object: the new object you want for the inventory.
  
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ inventory_add_object(Inventory *inventory, Id object);




/**
   @date 04-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Deletes an object of the inventory.inventory_del_object()
  
   @param Inventory *inv: the inventory you want to change.
   @param Id object: the identifier of the object you want to remove 
    from the inventory.
   
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ inventory_del_object(Inventory *inventory, Id object);



/**
   @date 04-11-2016
   @author Adrian Fernandez

   @brief
  	Sets the bag of an inventory. inventory_set_bag()
   
 
   @param  Inventory *inv: the inventory whose bag you want to set.
   @param  Set *bag: the bag you want to set.
   
   @return
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ inventory_set_bag(Inventory *inv, Set *bag);



/**
   @date 04-11-2016
   @author Adrian Fernandez

   @brief
  	Returns the bag of an inventory.inventory_get_bag()

   @param
  	Inventory *inv: the inventory whose bag you want to get.
  
   @return
  	Set *: the bag of the inventory.
*/
Set * inventory_get_bag(Inventory *inv);




/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief
    Returns the number of objects in the inventory.inventory_get_count()
  
   @param 
    Inventory *inv: the inventory that you want to know its number 
    of objects.
                 
   @return 
    int: the number of objects in the inventory.
   */
int inventory_get_count(Inventory *inv);




/**
   @date 04-11-2016
   @author Adrian Fernandez

   @brief
  	Returns the maximum number of objects that an inventory can contain.inventory_get_max()
   
   @param
  	Inventory *inv: the inventory whose maximum number of objects
    you want to get.
   
   @return
  	int: Maximum number of objects that the inventory can contain.
*/
int inventory_get_max(Inventory *inv);



/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief 
    Checks if there is an especific object in the inventory.inventory_is_object()
  
    
   @param Inventory *inv: the inventory where you want to find the object.
   @param Id object: the id of the object you want to know if it is in the inventory.
                 
   @return 
    BOOL_: TRUE_ if the object is in the inventory and FALSE_ in other cases. 
   */
BOOL_ inventory_is_object(Inventory *inv, Id object);



/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief 
    Checks if the inventory is empty or not.inventory_is_empty()
  
   @param 
    Inventory *inv: the inventory to check.
                 
   @return 
    BOOL_: TRUE_ is the inventory is empty or FALSE_ if not.
   */
BOOL_ inventory_is_empty(Inventory *inv);




/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief 
    Checks if the inventory is full or not.inventory_is_full()
  
   @param 
    Inventory *inv: the inventory to check.
                 
   @return 
    BOOL_: TRUE_ is the inventory is full or FALSE_ if not.
   */
BOOL_ inventory_is_full(Inventory *inv);


/**
   @date 04-11-2016 
   @author Alejandro Sanchez

   @brief 
	  Prints the information of the inventory on the screen.inventory_print()

   @param 
	  Inventory *inv: the inventory you want to print.
   @return 
	  STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
   */
STATUS_ inventory_print(Inventory *inv);

#endif

