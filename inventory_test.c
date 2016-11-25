/* ===================================================================
File: inventory_test.c
Version: 1.0
Date: Nov. 4, 2016
Authors: Ricardo Riol 

Description:
	Tests inventory's functions
Revision history:
	Nov. 4, 2016: Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory_test.h"

int main(int argc, char **argv) {
	int test = 0, todas = 1;
	if(argc < 2){
  	printf("Pasando todas las pruebas al modulo inventory:\n");
  } else{
    	test = atoi(argv[1]);
      todas = 0;
      printf("Pasando prueba %d:\t", test);
      if(test < 1 || test > MAX_TEST){
  			printf("Error prueba no reconocida");
        exit(EXIT_SUCCESS);
      }
    }

  if (todas || test == 1)  test1_inventory_destroy();
  if (todas || test == 2)  test1_inventory_add_object();
  if (todas || test == 3)  test1_inventory_del_object();
  if (todas || test == 4)  test1_inventory_set_bag();
  if (todas || test == 5)  test1_inventory_get_bag();
  if (todas || test == 6)  test1_inventory_get_count();
  if (todas || test == 7)  test1_inventory_get_max();
  if (todas || test == 8)  test1_inventory_is_object();
  if (todas || test == 9)  test1_inventory_is_empty();
  if (todas || test == 10) test1_inventory_is_full();
  if (todas || test == 11) test1_inventory_print();
  if (todas || test == 12) test1_inventory_create();
  if (todas || test == 13) test2_inventory_destroy();
  if (todas || test == 14) test2_inventory_add_object();
  if (todas || test == 15) test3_inventory_add_object();
  if (todas || test == 16) test2_inventory_del_object();
  if (todas || test == 17) test3_inventory_del_object();
  if (todas || test == 18) test2_inventory_set_bag();
  if (todas || test == 18) test3_inventory_set_bag();
  if (todas || test == 19) test2_inventory_get_bag();
  if (todas || test == 20) test2_inventory_get_count();
  if (todas || test == 21) test2_inventory_get_max();
  if (todas || test == 22) test2_inventory_is_object();
  if (todas || test == 23) test2_inventory_is_empty();
  if (todas || test == 23) test3_inventory_is_empty();
  if (todas || test == 24) test2_inventory_is_full();
  if (todas || test == 25) test2_inventory_print();
  

  exit(EXIT_SUCCESS);
}

/* --------------------------------------------------------------------
   Function: test1_inventory_destroy
   Date: 11-11-2011
   Author: Ricard Riol
   
   Description:
    Tests if destroys an inventory.

   Input:
    

   Output:
    
------------------------------------------------------------------- */
void test1_inventory_destroy(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_destroy(inventory) == ERROR);
	return;
}          

/* --------------------------------------------------------------------
   Function: test1_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
   Tests if adds an object to an inventory.

   Input: 
  
   Output: 
    
   -------------------------------------------------------------------- */
void test1_inventory_add_object(){
	Inventory *inventory = NULL;
	Id object = 1;
	FUNCTION_IS_CORRECT(inventory_add_object(inventory,object) == ERROR);
}

/* --------------------------------------------------------------------
   Function: test1_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
  
   Output: 
    
   -------------------------------------------------------------------- */
void test1_inventory_del_object(){
	Inventory *inventory = NULL;
	Id object = 1;
	FUNCTION_IS_CORRECT(inventory_del_object(inventory,object) == ERROR);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_set_bag(){
	Inventory *inventory = NULL;
	Set* set = NULL;
	FUNCTION_IS_CORRECT(inventory_set_bag(inventory, set) == ERROR);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_get_bag
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the bag of an inventory.

   Input:
   
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_bag(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_get_bag(inventory)==NULL);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_get_count
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the number of objects of the inventory.

   Input:
    
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_count(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_get_count(inventory)==0);
	return;

}

/* --------------------------------------------------------------------
   Function: test1_inventory_get_max
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    TEsts if the maximum number of objects that an inventory can contain.
   
   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test1_inventory_get_max(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_get_max(inventory)==-1);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_is_object
   Date: 04-11-2016 
   Author: Ricardo Riol
  
   Description: 
    tests if checks if there is an especific object in the inventory.
  
   Input: 
                 
   Output: 
   -------------------------------------------------------------------- */
void tests1_inventory_is_object(){
	Inventory *inventory = NULL;
	Id object = 1;
	FUNCTION_IS_CORRECT(inventory_is_object(inventory, object)==FALSE);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test1_inventory_is_empty(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_is_empty(inventory)==TRUE);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_is_full
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Checks if the inventory is full or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test1_inventory_is_full(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_is_full(inventory)==FALSE);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_print
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
    checks if prints the information of the inventory on the screen.

   Input: 
  
   Output: 

   -------------------------------------------------------------------- */
void test1_inventory_print(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_print(inventory)==ERROR);
	return;
}

/* --------------------------------------------------------------------
   Function: test1_inventory_create
   Date: 11-11-2011
   Author: Ricardo Riol

   Description: 
    Tests if an inventory is created.

   Input: 

   Output:
    
------------------------------------------------------------------- */
void test1_inventory_create(){
	Inventory *inventory = NULL;
	inventory = inventory_create();
	FUNCTION_IS_CORRECT(inventory != NULL);
	inventory_destroy (inventory);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_destroy
   Date: 11-11-2011
   Author: Ricard Riol
   
   Description:
    Tests if destroys an inventory.

   Input:

   Output:
    
------------------------------------------------------------------- */
void test2_inventory_destroy(){
	Inventory *inv = NULL;
	inv = inventory_create();
	if (!inv){
		return;
	}
	FUNCTION_IS_CORRECT(inventory_destroy(inv)==OK);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
   Tests if adds an object to an inventory.

   Input: 

   Output: 
    
 -------------------------------------------------------------------- */

void test2_inventory_add_object(){
	Inventory *inv = NULL;
	Id idobject = NO_ID;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_add_object(inv, idobject)==ERROR);
	inventory_destroy (inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test3_inventory_add_object
   Date: 11-11-2011 
   Author: Ricardo Riol

   Description: 
   Tests if adds an object to an inventory.

   Input: 
 
   Output: 
    
   -------------------------------------------------------------------- */

void test3_inventory_add_object(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_add_object(inv, idobject)==OK);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
 
   Output: 
    
   -------------------------------------------------------------------- */

void test2_inventory_del_object(){
	Inventory *inv = NULL;
	Id idobject = NO_ID;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_del_object(inv, idobject)==ERROR);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test3_inventory_del_object
   Date: 11-11-2011 
   Author: Ricardo Riol
 
   Description: 
    Tests if deletes an object of the inventory.
 
   Input: 
  
   Output: 
    
   -------------------------------------------------------------------- */

void test3_inventory_del_object(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_del_object(inv, idobject)==OK);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:

   Output:
    
------------------------------------------------------------------- */

void test2_inventory_set_bag(){
	Inventory *inv = NULL;
	Set *bag = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_set_bag(inv,bag)==ERROR);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test3_inventory_set_bag
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    Tests if sets the bag of an inventory.
   
   Input:

   Output:
    
------------------------------------------------------------------- */

void test3_inventory_set_bag(){
	Inventory *inv = NULL;
	Set *bag = NULL;
	inv = inventory_create();
	bag = set_create();
	FUNCTION_IS_CORRECT(inventory_set_bag(inv,bag)==OK);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_get_bag
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if returns the bag of an inventory.

   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test2_inventory_get_bag(){
	Inventory *inv = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT (inventory_get_bag(inv)!=NULL);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_get_count
   Date: 11-11-2011
   Author:Ricardo Riol
   Description:
    Tests if return sthe number of obajects of the inventory.

   Input:

  
   Output:
    
------------------------------------------------------------------- */
void test2_inventory_get_count(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT (inventory_get_count(inv)==1);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_get_max
   Date: 11-11-2011
   Author: Ricardo Riol

   Description:
    TEsts if the maximum number of objects that an inventory can contain.
   
   Input:
  
   Output:
    
------------------------------------------------------------------- */
void test2_inventory_get_max(){
	Inventory *inv = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_get_max(inv)==MAX_BAG);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_is_object
   Date: 11-11-2016 
   Author: Ricardo Riol
  
   Description: 
    tests if checks if there is an especific object in the inventory.
  
   Input: 
                 
   Output: 
   -------------------------------------------------------------------- */
void tests2_inventory_is_object(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_is_object(inv, idobject)==TRUE);
	inventory_destroy(inv);
	return;
}

/* --------------------------------------------------------------------
   Function: test2_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test2_inventory_is_empty(){
	Inventory *inv = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT (inventory_is_empty(inv)==TRUE);
	inventory_destroy(inv);
}

/* --------------------------------------------------------------------
   Function: test3_inventory_is_empty
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Tests if the inventory is empty or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test3_inventory_is_empty(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT (inventory_is_empty(inv)==FALSE);
	inventory_destroy(inv);
}
/* --------------------------------------------------------------------
   Function: test2_inventory_is_full
   Date: 11-11-2011 
   Author: Ricardo Riol
  
   Description: 
    Checks if the inventory is full or not.
  
   Input: 
                 
   Output: 
   
   -------------------------------------------------------------------- */
void test2_inventory_is_full(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT (inventory_is_full(inv)==FALSE);
	inventory_destroy(inv);
}

/* --------------------------------------------------------------------
   Function: test2_inventory_print
   Date: 01-11-2011 
   Author: Ricardo Riol

   Description: 
    checks if prints the information of the inventory on the screen.

   Input: 

   Output: 

   -------------------------------------------------------------------- */
void test2_inventory_print(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_print(inv)==OK);
	inventory_destroy(inv);
}




