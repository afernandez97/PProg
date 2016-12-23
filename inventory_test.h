/**
	@file inventory_test.h
	@version 1.0
	@date 11-11-2016
	@author Ricardo Riol 
	@brief
	Tests inventory's functions
	@version Nov. 11, 2016: Version 1.0 (initial release)
*/


#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "set.h"   

#pragma GCC diagnostic ignored "-Wpedantic"

/**
@def Constant values description 
*/
#define MAX_TEST_INVENTORY 25

#define FUNCTION_IS_CORRECT(x)\
          if(x){\
            fprintf(stdout,"%s %d %s OK_\n", __FILE__, __LINE__, __FUNCTION__);\
          } else{\
              (fprintf(stdout,"%s %d %s ERROR_\n", __FILE__, __LINE__, __FUNCTION__));\
          }
    

/*!< Public functions description */

/**
   @date 11-11-2011
   @author Ricard Riol
   
   @brief
    Tests if destroys an inventory.test1_inventory_destroy()

   @param
    

   @return
    
*/
void test1_inventory_destroy();          

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
   Tests if adds an object to an inventory.test1_inventory_add_object()

   @param 
  
   @return 
    
   */
void test1_inventory_add_object();

/**
   @date 11-11-2011 
   @author Ricardo Riol
 
   @brief 
    Tests if deletes an object of the inventory.test1_inventory_del_object()
 
   @param 
  
   @return 
    
   */
void test1_inventory_del_object();


/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if sets the bag of an inventory.test1_inventory_set_bag()
   
   @param
  
   @return
    
*/
void test1_inventory_set_bag();

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if returns the bag of an inventory.test1_inventory_get_bag()

   @param
   
   @return
    
*/
void test1_inventory_get_bag();

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if returns the number of objects of the inventory.test1_inventory_get_count()

   @param
    
   @return
    
*/
void test1_inventory_get_count();

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if the maximum number of objects that an inventory can contain.test1_inventory_get_max()
   
   @param
  
   @return
    
*/
void test1_inventory_get_max();


/**
   @date 04-11-2016 
   @author Ricardo Riol
  
   @brief 
    tests if checks if there is an especific object in the inventory.test1_inventory_is_object()
  
   @param 
                 
   @return 
   */
void test1_inventory_is_object();


/**
   @date 11-11-2011 
   @author: Ricardo Riol
  
   @brief 
    Tests if the inventory is empty or not.test1_inventory_is_empty()
  
   @param 
                 
   @return 
   
   */
void test1_inventory_is_empty();

/**
   @date 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Checks if the inventory is full or not.test1_inventory_is_full()
  
   @param 
                 
   @return 
   
   */
void test1_inventory_is_full();

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
    checks if prints the information of the inventory on the screen.test1_inventory_print()

   @param 
  
   @return 

   */
void test1_inventory_print();

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief 
    Tests if an inventory is created. test1_inventory_create()

   @oparam 

   @return
    
*/
void test1_inventory_create();

/**
   @date 11-11-2011
   @author Ricard Riol
   
   @brief
    Tests if destroys an inventory.test2_inventory_destroy()

   @param

   @return
    
*/
void test2_inventory_destroy();


/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
   Tests if adds an object to an inventory.test2_inventory_add_object()

   @param 

   @return 
    
 */
void test2_inventory_add_object();

/**
   @date 11-11-2011 
   @author Ricardo Riol

   @brief 
   Tests if adds an object to an inventory.test3_inventory_add_object()

   @param 
 
   @return 
    
   */
void test3_inventory_add_object();


/**
   @date 11-11-2011 
   @author Ricardo Riol
 
   @brief 
    Tests if deletes an object of the inventory.test2_inventory_del_object()
 
   @param 
 
   @return 
    
   */
void test2_inventory_del_object();

/**
   @date 11-11-2011 
   @author Ricardo Riol
 
   @brief 
    Tests if deletes an object of the inventory.test3_inventory_del_object()
 
   @param 
  
   @return 
    
   */
void test3_inventory_del_object();

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if sets the bag of an inventory.test2_inventory_set_bag()
   
   @param

   @return
    
*/
void test2_inventory_set_bag();

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if sets the bag of an inventory.test3_inventory_set_bag()
   
   @param

   @return
    
*/

void test3_inventory_set_bag();

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if returns the bag of an inventory.test2_inventory_get_bag()

   @param
  
   @return
    
*/
void test2_inventory_get_bag();

/**
   @date 11-11-2011
   @author Ricardo Riol
   @brief
    Tests if return sthe number of obajects of the inventory.test2_inventory_get_count()

   @param

  
   @return
    
*/
void test2_inventory_get_count();

/**
   @date 11-11-2011
   @author Ricardo Riol

   @brief
    Tests if the maximum number of objects that an inventory can contain.test2_inventory_get_max()
   
   @param
  
   @return
    
*/
void test2_inventory_get_max();


/**
   @date 11-11-2016 
   @author Ricardo Riol
  
   @brief 
    tests if checks if there is an especific object in the inventory.test2_inventory_is_object()
  
   @param 
                 
   @return 
   */
void test2_inventory_is_object();

/**
   @date: 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Tests if the inventory is empty or not.test2_inventory_is_empty()
  
   @param 
                 
   @return 
   
   */
void test2_inventory_is_empty();

/**
   @date 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Tests if the inventory is empty or not. test3_inventory_is_empty()
  
   @param 
                 
   @return 
   
   */
void test3_inventory_is_empty();


/**
   @date 11-11-2011 
   @author Ricardo Riol
  
   @brief 
    Checks if the inventory is full or not.test2_inventory_is_full()
  
   @param 
                 
   @return
   
   */
void test2_inventory_is_full();

/**
   @date 01-11-2011 
   @author Ricardo Riol

   @brief 
    checks if prints the information of the inventory on the screen. test2_inventory_print()

   @param

   @return 

   */
void test2_inventory_print();












#endif
