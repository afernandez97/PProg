/**
	@file inventory_test.c
	@version 1.0
	@date Nov. 4, 2016
	@author Ricardo Riol 
	@brief
	Tests inventory's functions
	@revision Nov. 4, 2016: Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory_test.h"

int main(int argc, char **argv) {
	int test = 0, all = 1;
	if(argc < 2){
  	printf("Testing all:\n");
  } else{
    	test = atoi(argv[1]);
      all = 0;
      printf("Testing %d:\t", test);
      if(test < 1 || test > MAX_TEST_INVENTORY){
  			printf("Unknown test\t");
        exit(EXIT_SUCCESS);
      }
    }

  if (all || test == 1)  test1_inventory_destroy();
  if (all || test == 2)  test1_inventory_add_object();
  if (all || test == 3)  test1_inventory_del_object();
  if (all || test == 4)  test1_inventory_set_bag();
  if (all || test == 5)  test1_inventory_get_bag();
  if (all || test == 6)  test1_inventory_get_count();
  if (all || test == 7)  test1_inventory_get_max();
  if (all || test == 8)  test1_inventory_is_object();
  if (all || test == 9)  test1_inventory_is_empty();
  if (all || test == 10) test1_inventory_is_full();
  if (all || test == 11) test1_inventory_print();
  if (all || test == 12) test1_inventory_create();
  if (all || test == 13) test2_inventory_destroy();
  if (all || test == 14) test2_inventory_add_object();
  if (all || test == 15) test3_inventory_add_object();
  if (all || test == 16) test2_inventory_del_object();
  if (all || test == 17) test3_inventory_del_object();
  if (all || test == 18) test2_inventory_set_bag();
  if (all || test == 18) test3_inventory_set_bag();
  if (all || test == 19) test2_inventory_get_bag();
  if (all || test == 20) test2_inventory_get_count();
  if (all || test == 21) test2_inventory_get_max();
  if (all || test == 22) test2_inventory_is_object();
  if (all || test == 23) test2_inventory_is_empty();
  if (all || test == 23) test3_inventory_is_empty();
  if (all || test == 24) test2_inventory_is_full();
  if (all || test == 25) test2_inventory_print();
  

  exit(EXIT_SUCCESS);
}

/**
   @date 11-11-2011
   @author Ricard Riol
   
   @brief
    Tests if destroys an inventory.test1_inventory_destroy()

   @param
    

   @return
    
*/
void test1_inventory_destroy(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_destroy(inventory) == ERROR);
	return;
}          

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
   Tests if adds an object to an inventory.test1_inventory_add_object()

   @param 
  
   @return 
    
   */
void test1_inventory_add_object(){
	Inventory *inventory = NULL;
	Id object = 1;
	FUNCTION_IS_CORRECT(inventory_add_object(inventory,object) == ERROR);
}

/**
   @date 11-11-2011 
   @author Ricardo Riol
 
   @brief 
    Tests if deletes an object of the inventory.test1_inventory_del_object()
 
   @param 
  
   @return 
    
   */
void test1_inventory_del_object(){
	Inventory *inventory = NULL;
	Id object = 1;
	FUNCTION_IS_CORRECT(inventory_del_object(inventory,object) == ERROR);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if sets the bag of an inventory.test1_inventory_set_bag()
   
   @param
  
   @return
    
*/
void test1_inventory_set_bag(){
	Inventory *inventory = NULL;
	Set* set = NULL;
	FUNCTION_IS_CORRECT(inventory_set_bag(inventory, set) == ERROR);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if returns the bag of an inventory.test1_inventory_get_bag()

   @param
   
   @return
    
*/
void test1_inventory_get_bag(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_get_bag(inventory)==NULL);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if returns the number of objects of the inventory.test1_inventory_get_count()

   @param
    
   @return
    
*/
void test1_inventory_get_count(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_get_count(inventory)==0);
	return;

}

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if the maximum number of objects that an inventory can contain.test1_inventory_get_max()
   
   @param
  
   @return
    
*/
void test1_inventory_get_max(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_get_max(inventory)==-1);
	return;
}

/**
   @date 04-11-2016 
   @author Ricardo Riol
  
   @brief 
    tests if checks if there is an especific object in the inventory.test1_inventory_is_object()
  
   @param 
                 
   @return 
   */
void test1_inventory_is_object(){
	Inventory *inventory = NULL;
	Id object = 1;
	FUNCTION_IS_CORRECT(inventory_is_object(inventory, object)==FALSE);
	return;
}

/**
   @date 11-11-2011 
   @author: Ricardo Riol
  
   @brief 
    Tests if the inventory is empty or not.test1_inventory_is_empty()
  
   @param 
                 
   @return 
   
   */
void test1_inventory_is_empty(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_is_empty(inventory)==TRUE);
	return;
}

/**
   @date 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Checks if the inventory is full or not.test1_inventory_is_full()
  
   @param 
                 
   @return 
   
   */
void test1_inventory_is_full(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_is_full(inventory)==FALSE);
	return;
}

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
    checks if prints the information of the inventory on the screen.test1_inventory_print()

   @param 
  
   @return 

   */
void test1_inventory_print(){
	Inventory *inventory = NULL;
	FUNCTION_IS_CORRECT(inventory_print(inventory)==ERROR);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief 
    Tests if an inventory is created. test1_inventory_create()

   @oparam 

   @return
    
*/
void test1_inventory_create(){
	Inventory *inventory = NULL;
	inventory = inventory_create();
	FUNCTION_IS_CORRECT(inventory != NULL);
	inventory_destroy (inventory);
	return;
}

/**
   @date 11-11-2011
   @author Ricard Riol
   
   @brief
    Tests if destroys an inventory.test2_inventory_destroy()

   @param

   @return
    
*/
void test2_inventory_destroy(){
	Inventory *inv = NULL;
	inv = inventory_create();
	if (!inv){
		return;
	}
	FUNCTION_IS_CORRECT(inventory_destroy(inv)==OK);
	return;
}

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
   Tests if adds an object to an inventory.test2_inventory_add_object()

   @param 

   @return 
    
 */

void test2_inventory_add_object(){
	Inventory *inv = NULL;
	Id idobject = NO_ID;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_add_object(inv, idobject)==ERROR);
	inventory_destroy (inv);
	return;
}

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
   Tests if adds an object to an inventory.test3_inventory_add_object()

   @param 
 
   @return 
    
   */

void test3_inventory_add_object(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_add_object(inv, idobject)==OK);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011 
   @author Ricardo Riol
 
   @brief 
    Tests if deletes an object of the inventory.test2_inventory_del_object()
 
   @param 
 
   @return 
    
   */

void test2_inventory_del_object(){
	Inventory *inv = NULL;
	Id idobject = NO_ID;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_del_object(inv, idobject)==ERROR);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011 
   @author Ricardo Riol
 
   @brief 
    Tests if deletes an object of the inventory.test3_inventory_del_object()
 
   @param 
  
   @return 
    
   */

void test3_inventory_del_object(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_del_object(inv, idobject)==OK);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if sets the bag of an inventory.test2_inventory_set_bag()
   
   @param

   @return
    
*/

void test2_inventory_set_bag(){
	Inventory *inv = NULL;
	Set *bag = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_set_bag(inv,bag)==ERROR);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if sets the bag of an inventory.test3_inventory_set_bag()
   
   @param

   @return
    
*/

void test3_inventory_set_bag(){
	Inventory *inv = NULL;
	Set *bag = NULL;
	inv = inventory_create();
	bag = set_create();
	FUNCTION_IS_CORRECT(inventory_set_bag(inv,bag)==OK);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if returns the bag of an inventory.test2_inventory_get_bag()

   @param
  
   @return
    
*/
void test2_inventory_get_bag(){
	Inventory *inv = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT (inventory_get_bag(inv)!=NULL);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if return sthe number of obajects of the inventory.test2_inventory_get_count()

   @param

  
   @return
    
*/
void test2_inventory_get_count(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT (inventory_get_count(inv)==1);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if the maximum number of objects that an inventory can contain.test2_inventory_get_max()
   
   @param
  
   @return
    
*/
void test2_inventory_get_max(){
	Inventory *inv = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT(inventory_get_max(inv)==MAX_BAG);
	inventory_destroy(inv);
	return;
}

/**
   @date 11-11-2016 
   @author Ricardo Riol
  
   @brief 
    tests if checks if there is an especific object in the inventory.test2_inventory_is_object()
  
   @param 
                 
   @return 
   */
void test2_inventory_is_object(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_is_object(inv, idobject)==TRUE);
	inventory_destroy(inv);
	return;
}

/**
   @date: 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Tests if the inventory is empty or not.test2_inventory_is_empty()
  
   @param 
                 
   @return 
   
   */
void test2_inventory_is_empty(){
	Inventory *inv = NULL;
	inv = inventory_create();
	FUNCTION_IS_CORRECT (inventory_is_empty(inv)==TRUE);
	inventory_destroy(inv);
}

/**
   @date 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Tests if the inventory is empty or not. test3_inventory_is_empty()
  
   @param 
                 
   @return 
   
   */
void test3_inventory_is_empty(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT (inventory_is_empty(inv)==FALSE);
	inventory_destroy(inv);
}
/**
   @date 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Checks if the inventory is full or not.test2_inventory_is_full()
  
   @param 
                 
   @return
   
   */
void test2_inventory_is_full(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT (inventory_is_full(inv)==FALSE);
	inventory_destroy(inv);
}

/**
   @date 01-11-2011 
   @author Ricardo Riol

   @brief 
    checks if prints the information of the inventory on the screen. test2_inventory_print()

   @param

   @return 

   */
void test2_inventory_print(){
	Inventory *inv = NULL;
	Id idobject = 1;
	inv = inventory_create();
	inventory_add_object (inv, idobject);
	FUNCTION_IS_CORRECT(inventory_print(inv)==OK);
	inventory_destroy(inv);
}




