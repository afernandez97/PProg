/* ===================================================================
   File: inventory_test.h
   Version: 2.0
   Date: 11-11-2011
   Author: Ricardo Riol

   Description: 
		It defines the iventory test function's

   Revision history:
		nov. 11, 2011  Version 2.0
   =================================================================== */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "set.h"

/* Constant values description */
#define MAX_BAG 10

#define bag(X) (X)->bag
#define max(X) (X)->max

/*** Data structures definition ***/


/* Public functions description */
/* --------------------------------------------------------------------
   Function: test1_inventory_create
   Date: 11-11-2011
   Author: Ricardo Riol

   Description: 
    Tests if an inventory is created.

   Input: 

   Output:
    
------------------------------------------------------------------- */
void test1_inventory_create();

/* --------------------------------------------------------------------
   Function: test2_inventory_create
   Date: 11-11-2011
   Author: Ricardo Riol

   Description: 
    Tests if an inventory is created.

   Input: 

   Output:
    
------------------------------------------------------------------- */
void test2_inventory_create();

/* --------------------------------------------------------------------
   Function: test1_inventory_destroy
   Date: 11-11-2011
   Author: Ricard Riol
   
   Description:
    Tests if destroys an inventory.

   Input:
    Inventory *: the inventory to destroy.

   Output:
    
------------------------------------------------------------------- */
void test1_inventory_destroy(Inventory *inv);

/* --------------------------------------------------------------------
   Function: test2_inventory_destroy
   Date: 11-11-2011
   Author: Ricard Riol
   
   Description:
    Tests if destroys an inventory.

   Input:
    Inventory *: the inventory to destroy.

   Output:
    
------------------------------------------------------------------- */
void test2_inventory_destroy(Inventory *inv);



/* --------------------------------------------------------------------
   Function: test1_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
	 Tests if adds an object to an inventory.

   Input: 
	  Inventory *inventory: the inventory that you want to change.
	  Id object: the new object you want for the inventory.
  
   Output: 
    
   -------------------------------------------------------------------- */
void test1_inventory_add_object(Inventory *inventory, Id object);

/* --------------------------------------------------------------------
   Function: test2_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
	 Tests if adds an object to an inventory.

   Input: 
	  Inventory *inventory: the inventory that you want to change.
	  Id object: the new object you want for the inventory.
  
   Output: 
    
   -------------------------------------------------------------------- */
void test2_inventory_add_object(Inventory *inventory, Id object);

/* --------------------------------------------------------------------
   Function: test3_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
	 Tests if adds an object to an inventory.

   Input: 
	  Inventory *inventory: the inventory that you want to change.
	  Id object: the new object you want for the inventory.
  
   Output: 
    
   -------------------------------------------------------------------- */
void test3_inventory_add_object(Inventory *inventory, Id object);

/* --------------------------------------------------------------------
   Function: test4_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
	 Tests if adds an object to an inventory.

   Input: 
	  Inventory *inventory: the inventory that you want to change.
	  Id object: the new object you want for the inventory.
  
   Output: 
    
   -------------------------------------------------------------------- */
void test4_inventory_add_object(Inventory *inventory, Id object);



/* --------------------------------------------------------------------
   Function: test1_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
    Inventory *inventory: the inventory you want to change.
    Id object: the identifier of the object you want to remove 
    from the inventory.
   
   Output: 
    
   -------------------------------------------------------------------- */
void test1_inventory_del_object(Inventory *inventory, Id object);

/* --------------------------------------------------------------------
   Function: test2_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
    Inventory *inventory: the inventory you want to change.
    Id object: the identifier of the object you want to remove 
    from the inventory.
   
   Output: 
    
   -------------------------------------------------------------------- */
void test2_inventory_del_object(Inventory *inventory, Id object);

/* --------------------------------------------------------------------
   Function: test3_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
    Inventory *inventory: the inventory you want to change.
    Id object: the identifier of the object you want to remove 
    from the inventory.
   
   Output: 
    
   -------------------------------------------------------------------- */
void test3_inventory_del_object(Inventory *inventory, Id object);

/* --------------------------------------------------------------------
   Function: test4_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
    Inventory *inventory: the inventory you want to change.
    Id object: the identifier of the object you want to remove 
    from the inventory.
   
   Output: 
    
   -------------------------------------------------------------------- */
void test4_inventory_del_object(Inventory *inventory, Id object);






/* --------------------------------------------------------------------
   Function: test1_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:
    Inventory *inv: the inventory whose bag you want to set.
    Set *bag: the bag you want to set.
   
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_set_bag(Inventory *inv, Set *bag);



/* --------------------------------------------------------------------
   Function: test1_inventory_get_bag
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the bag of an inventory.

   Input:
    Inventory *: the inventory whose bag you want to get.
  
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_bag(Inventory *inv);



/* --------------------------------------------------------------------
   Function: test1_inventory_get_count
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if return sthe number of obajects of the inventory.

   Input:
    Inventory *: the inventory whose bag you want to get.
  
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_count(Inventory *inv);



/* --------------------------------------------------------------------
   Function: test1_inventory_get_max
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    TEsts if the maximum number of objects that an inventory can contain.
   
   Input:
    Inventory *inv: the inventory whose maximum number of objects
    you want to get.
   
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_max(Inventory *inv);



/* --------------------------------------------------------------------
   Function: test1_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
    Inventory *inv: the inventory to check.
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test1_inventory_is_empty(Inventory *inv);



/* --------------------------------------------------------------------
   Function: test1_inventory_is_full
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Checks if the inventory is full or not.
  
   Input: 
    Inventory *inv: the inventory to check.
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test1_inventory_is_full(Inventory *inv);


/* --------------------------------------------------------------------
   Function: test1_inventory_print
   Date: 01-11-2011 
   Author: Ricardo Riol

   Description: 
	  checks if prints the information of the inventory on the screen.

   Input: 
	  Inventory *inv: the inventory you want to print.
   Output: 

   -------------------------------------------------------------------- */
void test1_inventory_print(Inventory *inv);

#endif

