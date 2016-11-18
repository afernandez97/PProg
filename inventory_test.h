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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "set.h"    
/* Constant values description */

#define MAX_TEST 27

#define FUNCTION_IS_CORRECT(x)\
          if(x){\
            fprintf(stdout,"%s %d %s CORRECT\n", __FILE__, __LINE__, __FUNCTION__);\
          } else{\
              (fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
          }
    

/*** Data structures definition ***/


/* Public functions description */

/* --------------------------------------------------------------------
   Function: test1_inventory_destroy
   Date: 11-11-2011
   Author: Ricard Riol
   
   Description:
    Tests if destroys an inventory.

   Input:
    

   Output:
    
------------------------------------------------------------------- */
void test1_inventory_destroy();          

/* --------------------------------------------------------------------
   Function: test1_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
   Tests if adds an object to an inventory.

   Input: 
  
   Output: 
    
   -------------------------------------------------------------------- */
void test1_inventory_add_object();

/* --------------------------------------------------------------------
   Function: test1_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
  
   Output: 
    
   -------------------------------------------------------------------- */
void test1_inventory_del_object();

/* --------------------------------------------------------------------
   Function: test1_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_set_bag();

/* --------------------------------------------------------------------
   Function: test1_inventory_get_bag
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the bag of an inventory.

   Input:
   
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_bag();

/* --------------------------------------------------------------------
   Function: test1_inventory_get_count
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the number of objects of the inventory.

   Input:
    
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_count();

/* --------------------------------------------------------------------
   Function: test1_inventory_get_max
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    TEsts if the maximum number of objects that an inventory can contain.
   
   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_max();

/* --------------------------------------------------------------------
   Function: test1_inventory_is_object
   Date: 04-11-2016 
   Author: Ricardo Riol
  
   Description: 
    tests if checks if there is an especific object in the inventory.
  
   Input: 
                 
   Output: 
   -------------------------------------------------------------------- */
void tests1_inventory_is_object();

/* --------------------------------------------------------------------
   Function: test1_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test1_inventory_is_empty();

/* --------------------------------------------------------------------
   Function: test1_inventory_is_full
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Checks if the inventory is full or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test1_inventory_is_full();

/* --------------------------------------------------------------------
   Function: test1_inventory_print
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
    checks if prints the information of the inventory on the screen.

   Input: 
  
   Output: 

   -------------------------------------------------------------------- */
void test1_inventory_print();

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
   Function: test2_inventory_destroy
   Date: 11-11-2011
   Author: Ricard Riol
   
   Description:
    Tests if destroys an inventory.

   Input:

   Output:
    
------------------------------------------------------------------- */
void test2_inventory_destroy();


/* --------------------------------------------------------------------
   Function: test2_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
   Tests if adds an object to an inventory.

   Input: 

   Output: 
    
   -------------------------------------------------------------------- */

void test2_inventory_add_object();

/* --------------------------------------------------------------------
   Function: test3_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
   Tests if adds an object to an inventory.

   Input: 
 
   Output: 
    
   -------------------------------------------------------------------- */

void test3_inventory_add_object();


/* --------------------------------------------------------------------
   Function: test2_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
 
   Output: 
    
   -------------------------------------------------------------------- */

void test2_inventory_del_object();

/* --------------------------------------------------------------------
   Function: test3_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
  
   
   Output: 
    
   -------------------------------------------------------------------- */

void test3_inventory_del_object();

/* --------------------------------------------------------------------
   Function: test2_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:

   Output:
    
------------------------------------------------------------------- */

void test2_inventory_set_bag();

/* --------------------------------------------------------------------
   Function: test3_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:

   Output:
    
------------------------------------------------------------------- */

void test3_inventory_set_bag();

/* --------------------------------------------------------------------
   Function: test2_inventory_get_bag
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the bag of an inventory.

   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test2_inventory_get_bag();

/* --------------------------------------------------------------------
   Function: test2_inventory_get_count
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if return sthe number of obajects of the inventory.

   Input:

  
   Output:
    
------------------------------------------------------------------- */
void test2_inventory_get_count();

/* --------------------------------------------------------------------
   Function: test2_inventory_get_max
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    TEsts if the maximum number of objects that an inventory can contain.
   
   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test2_inventory_get_max();

/* --------------------------------------------------------------------
   Function: test2_inventory_is_object
   Date: 11-11-2016 
   Author: Ricardo Riol
  
   Description: 
    tests if checks if there is an especific object in the inventory.
  
   Input: 
                 
   Output: 
   -------------------------------------------------------------------- */
void tests2_inventory_is_object();

/* --------------------------------------------------------------------
   Function: test2_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test2_inventory_is_empty();

/* --------------------------------------------------------------------
   Function: test3_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test3_inventory_is_empty();


/* --------------------------------------------------------------------
   Function: test2_inventory_is_full
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Checks if the inventory is full or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test2_inventory_is_full();

/* --------------------------------------------------------------------
   Function: test2_inventory_print
   Date: 01-11-2011 
   Author: Ricardo Riol

   Description: 
    checks if prints the information of the inventory on the screen.

   Input: 

   Output: 

   -------------------------------------------------------------------- */
void test2_inventory_print();












#endif
