/* ===================================================================
  File: inventory.c
  Version: 1.1
  Date: 04-11-2016
  Authors: Adrian Fernandez, Alejandro Sanchez

  Description:
    It implements an inventory.

  Revision history:
  	Nov. 03, 2016 Version 1.0 (initial release)
    Nov. 4, 2016 Version 1.1
      Created the rest of the functions and commented the file.
=================================================================== */

#include "inventory.h"

/* Constant values description */
#define bag(X) (X)->bag
#define max(X) (X)->max


/*** The Inventory structure stores information of the set of objects
that contains and the maximum number of objects that can contain ***/ 
struct _Inventory {
	Set* bag;
	int max;
};


/* Public functions definition */
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
STATUS inventory_destroy(Inventory *inv){
	if(!inv){    /* Check that the input is not empty */
		return ERROR;
	}

  /* Eliminate the memory of the bag of objects if it exists */
	if(bag(inv) != NULL){
		set_destroy(bag(inv));
	}
	free(inv);   /* Eliminate the memory of the inventory */   

	return OK;
}



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
STATUS inventory_add_object(Inventory *inv, Id object){
	/* Check that the inputs are not empty */
  if(!inv || object == NO_ID || inventory_is_full(inv)){  
  	return ERROR;
  }

  /* Add the object to the inventory */ 
  if(set_add(bag(inv), object) == ERROR){
    return ERROR;
  }

  return OK;
}



/* --------------------------------------------------------------------
   Function: inventory_del_object
   Date: 04-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Deletes an object of the inventory.
 
   Input: 
    Inventory *inv: the inventory you want to change.
    Id object: the identifier of the object you want to remove 
    from the inventory.
   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS inventory_del_object(Inventory *inv, Id object){
  if(!inv || object == NO_ID || (inventory_is_empty(inv)==TRUE){  /* Check that the inputs are not empty */
    return ERROR;
  }
 
  /* Removes the object from the inventory */
  if(set_del(bag(inv), object) == ERROR){
    return ERROR;
  }      

  return OK;
}



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
STATUS inventory_set_bag(Inventory *inv, Set *bag){
  /* Check that the inputs are not empty or the bag contains more 
  objects than the maximum of the inventory */
	if(!inv || !bag || set_get_count(bag) > max(inv)){
		return ERROR;
	}


  /* Eliminate the memory of the bag of objects if it exists */
	if(bag(inv) != NULL){
		set_destroy(bag(inv));
	}

  /* Set the new bag to the inventory */
	bag(inv) = bag;
	
	return OK;
}



/* --------------------------------------------------------------------
   Function: inventory_get_bag
   Date: 04-11-2016
   Author: Adrian Fernandez

   Description:
  	Returns the bag of an inventory.

   Input:
  	Inventory *inv: the inventory whose bag you want to get.
  
   Output:
  	Inventory *: the bag of the inventory.
------------------------------------------------------------------- */
Inventory *inventory_get_bag(Inventory *inv){
	if(!inv){    /* Check that the input is not empty */
		return NULL;
	}

	return bag(inv);
}



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
int inventory_get_count(Inventory *inv){
	if(!inv){   /* Check that the input is not empty */
		return 0;
	}

	return set_get_count(bag(inv));
}



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
int inventory_get_max(Inventory *inv){
	if(!inv){     /* Check that the input is not empty */
		return -1;
	}

	return max(inv);
}



/* --------------------------------------------------------------------
   Function: inventory_is_object
   Date: 04-11-2016 
   Author: Alejandro Sanchez
  
   Description: 
    Checks if there is an especific object in the inventory.
  
   Input: 
    Inventory *inv: the inventory where you want to find the object.
    Id object: the id of the object you want to know if it is in the inventory.
                 
   Output: 
    BOOL: TRUE if the object is in the inventory and FALSE in other cases. 
   -------------------------------------------------------------------- */
BOOL inventory_is_object(Inventory *inv, Id object){
	if(!inv || object == NO_ID){   /* Check that the inputs are not empty */
    	return FALSE;
	}
  return set_is_object(bag(inv), object);	
}



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
BOOL inventory_is_empty(Inventory *inv){
  /* Check if the input is empty or the number of objects is 0 */
  if(!inv || set_is_empty(bag(inv)) == TRUE){
	  return TRUE;
  } 

  return FALSE;
}



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
BOOL inventory_is_full(Inventory *inv){
  /* Check if the input is empty or the number of objects is lower 
  than the maximum number of objects that can contain the inv */
  if(!inv || inventory_get_count(inv) < max(inv)){
    return FALSE;
  } 

  return TRUE;
}



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
STATUS inventory_print(Inventory *inv){
  if(!inv){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Print the inventory fields */
  fprintf(stdout, "Inventory -->  Max: %d; ", max(inv));
  if(set_print(bag(inv)) == ERROR){
	 return ERROR;
  }

  fprintf(stdout, ")\n");

  return OK;
}


