/**
  @file inventory.c
  @version 1.1
  @date 04-11-2016
  @author Adrian Fernandez, Alejandro Sanchez

  @brief
    It implements an inventory.

  @version Nov. 03, 2016 Version 1.0 (initial release)
  @version  Nov. 4, 2016 Version 1.1
      Created the rest of the functions and commented the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

/**
@def Constant values description 
*/
#define bag(X) (X)->bag
#define max(X) (X)->max

/**
@brief Inventory structure
Stores information of the set of objects
that contains and the maximum number of objects that can contain
*/
struct _Inventory {
	Set* bag; /*!< Bag of the inventory */
	int max;  /*!< Maximum number of objects in the inventory */ 
};


/*!< Public functions definition */
/**
   @date 03-11-2016
   @author Adrian Fernández

   @brief 
   	Creates an inventory.inventory_create()

   @param 

   @return
  	Inventory *: the inventory created or NULL on error.
*/
Inventory *inventory_create(){
	Inventory *inv = NULL;
	
	inv = (Inventory *)malloc(sizeof(Inventory));
	if(!inv){   /* Check if memory has been allocated */
		return NULL;
	}

  /* Initialize structure fields */
	bag(inv) = set_create();
	if(!bag(inv)){
		free(inv);
		return NULL;
	}

	max(inv) = MAX_BAG;

	return inv;
}



/**
   @date 03-11-2016
   @author Adrian Fernández
   
   @brief
   	Destroys an inventory.inventory_destroy()

   @param
  	Inventory *: the inventory to destroy.

   @return
    _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/
_STATUS inventory_destroy(Inventory *inv){
	if(!inv){    /* Check that the input is not empty */
		return _ERROR;
	}

  /* Eliminate the memory of the bag of objects if it exists */
	if(bag(inv) != NULL){
		set_destroy(bag(inv));
	}
	free(inv);   /* Eliminate the memory of the inventory */   

	return _OK;
}



/**
   @date 04-11-2016 
   @author Alejandro Sanchez

   @brief 
	  Adds an object to an inventory.inventory_add_object()

 
   @param  Inventory *inventory: the inventory that you want to change.
   @param Id object: the new object you want for the inventory.
  
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS inventory_add_object(Inventory *inv, Id object){
	/* Check that the inputs are not empty */
  if(!inv || object == NO_ID || inventory_is_full(inv)){  
  	return _ERROR;
  }

  /* Add the object to the inventory */ 
  if(set_add(bag(inv), object) == _ERROR){
    return _ERROR;
  }

  return _OK;
}



/**
   @date 04-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Deletes an object of the inventory.inventory_del_object()
  
   @param Inventory *inv: the inventory you want to change.
   @param Id object: the identifier of the object you want to remove 
    from the inventory.
   
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS inventory_del_object(Inventory *inv, Id object){
  if(!inv || object == NO_ID || (inventory_is_empty(inv)==_TRUE)){  /* Check that the inputs are not empty */
    return _ERROR;
  }
 
  /* Removes the object from the inventory */
  if(set_del(bag(inv), object) == _ERROR){
    return _ERROR;
  }      

  return _OK;
}



/**
   @date 04-11-2016
   @author Adrian Fernandez

   @brief
  	Sets the bag of an inventory. inventory_set_bag()
   
 
   @param  Inventory *inv: the inventory whose bag you want to set.
   @param  Set *bag: the bag you want to set.
   
   @return
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS inventory_set_bag(Inventory *inv, Set *bag){
  /* Check that the inputs are not empty or the bag contains more 
  objects than the maximum of the inventory */
	if(!inv || !bag || set_get_count(bag) > max(inv)){
		return _ERROR;
	}


  /* Eliminate the memory of the bag of objects if it exists */
	if(bag(inv) != NULL){
		set_destroy(bag(inv));
	}

  /* Set the new bag to the inventory */
	bag(inv) = bag;
	
	return _OK;
}



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
Set * inventory_get_bag(Inventory *inv){
	if(!inv){    /* Check that the input is not empty */
		return NULL;
	}

	return bag(inv);
}



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
int inventory_get_count(Inventory *inv){
	if(!inv){   /* Check that the input is not empty */
		return 0;
	}

	return set_get_count(bag(inv));
}



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
int inventory_get_max(Inventory *inv){
	if(!inv){     /* Check that the input is not empty */
		return -1;
	}

	return max(inv);
}



/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief 
    Checks if there is an especific object in the inventory.inventory_is_object()
  
    
   @param Inventory *inv: the inventory where you want to find the object.
   @param Id object: the id of the object you want to know if it is in the inventory.
                 
   @return 
    _BOOL: _TRUE if the object is in the inventory and _FALSE in other cases. 
   */
_BOOL inventory_is_object(Inventory *inv, Id object){
	if(!inv || object == NO_ID){   /* Check that the inputs are not empty */
    	return _FALSE;
	}
  return set_is_object(bag(inv), object);	
}



/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief 
    Checks if the inventory is empty or not.inventory_is_empty()
  
   @param 
    Inventory *inv: the inventory to check.
                 
   @return 
    _BOOL: _TRUE is the inventory is empty or _FALSE if not.
   */
_BOOL inventory_is_empty(Inventory *inv){
  /* Check if the input is empty or the number of objects is 0 */
  if(!inv || set_is_empty(bag(inv)) == _TRUE){
	  return _TRUE;
  } 

  return _FALSE;
}



/**
   @date 04-11-2016 
   @author Alejandro Sanchez
  
   @brief 
    Checks if the inventory is full or not.inventory_is_full()
  
   @param 
    Inventory *inv: the inventory to check.
                 
   @return 
    _BOOL: _TRUE is the inventory is full or _FALSE if not.
   */
_BOOL inventory_is_full(Inventory *inv){
  /* Check if the input is empty or the number of objects is lower 
  than the maximum number of objects that can contain the inv */
  if(!inv || inventory_get_count(inv) < max(inv)){
    return _FALSE;
  } 

  return _TRUE;
}



/**
   @date 04-11-2016 
   @author Alejandro Sanchez

   @brief 
	  Prints the information of the inventory on the screen.inventory_print()

   @param 
	  Inventory *inv: the inventory you want to print.
   @return 
	  _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS inventory_print(Inventory *inv){
  if(!inv){      /* Check that the input is not empty */
    return _ERROR;
  }

  /* Print the inventory fields */
  fprintf(stdout, "Inventory -->  Max: %d; ", max(inv));
  if(set_print(bag(inv)) == _ERROR){
	 return _ERROR;
  }

  fprintf(stdout, ")\n");

  return _OK;
}


