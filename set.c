/** =================================================================== 
   @file set.c
   @version 2.0
   @date 18-10-2016
   @autor Guillermo Rodriguez and Alejandro Sanchez
 
   
    @brief It implements a set.
 
   @date
    Oct. 18, 2016 Version 1.0 (initial release)
=================================================================== */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/*!< Constant values description */
#define id(X) (X)->id
#define count(X) (X)->count
 
/*** The Set structure stores information of the identifiers or the objects
that contains and the number of them ***/ 
struct _Set{
  Id id[MAX_ID]; /*!< Array of identifiers */
  int count;/*!< Number of identifiers in that moment */
};
 
/*** Public functions definition ***/
/** --------------------------------------------------------------------
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_create()
    Creates a set
  
   @param 
         
   @return 
    Set *: the set created or NULL on error.
   -------------------------------------------------------------------- */
Set * set_create(){
  Set *set = NULL;

  set = (Set *)malloc(sizeof(Set));
  if(!set){  /* Check if memory has been allocated */
    return NULL;
  }       
  
  /* Initialize structure field */
  count(set) = 0;
        
  return set;
}
 


/** --------------------------------------------------------------------
    
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_destroy() 
    Destroys a set.
  
   @param 
    Set *set: the set to destroy.
   @return 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS set_destroy(Set *set){
  if(!set){         /* Check that the input is not empty */
    return ERROR;
  }
   
  free(set);        /* Eliminate the memory of the set */     

  return OK;
}


 
/** --------------------------------------------------------------------
   
   @date 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_add()
    Adds an object to the set.
  
     
    @param Set *set: the set to change.
    @param Id id: the id of the object you want to add.
     
    @return STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS set_add(Set *set, Id id){
  /* Check that the input is not empty or the set is full */
  if(!set || set_is_full(set) == TRUE){
		return ERROR;
	} 

  /* Check if the set already contains that object */
  if(set_is_object(set, id) == TRUE){
    return ERROR;
  }

  /* Add the id of the object to the set */
	id(set)[count(set)] = id;

  /* Increase in 1 the number of objects in the set */
  count(set)++;

  return OK ;
}


 
/** --------------------------------------------------------------------
  
   @date: 18-10-2016 
   @author: Guillermo Rodriguez 
  
   @brief set_del()
    Deletes an object from the set.
  
    
   @param Set *set: the set to change.
   @param the id of the object you want to delete.
    
   @return STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS set_del(Set *set, Id id){
 	/* Initialize the counter and the flag */
  int i = 0, flag = 0;

  /* Check that the input is not empty or the set is empty */
  if(!set || set_is_empty(set) == TRUE){
		return ERROR;
	}

  /* Look for the object to delete in the set */
  while(flag == 0 && i < count(set)){ 
    if(id == id(set)[i]){
      flag = 1;
  	}
    i++;
	}
  
  /* Check that the object was found */   
	if(flag == 0){
  	return ERROR;
	}

  /* The order of the objects in the set doesn't matter, so the last
  object is set in the position of the object to delete (no holes) */
  id(set)[i-1] = id(set)[count(set)-1];    
  id(set)[count(set)-1] = NO_ID;

  /* Decrease in 1 the number of objects in the set */
  count(set)--;  
  
  return OK ;
}



/** --------------------------------------------------------------------
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_get_count
    Returns the number of objects in the set.
  
    
   @param Set *set: the set that you want to know its number of objects.
                 
    
   @return int: the number of objects in the set.
   -------------------------------------------------------------------- */
int set_get_count(Set *set){
	if(!set){
		return 0;
	}

	return count(set);
}



/** --------------------------------------------------------------------
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief  set_is_empty()
    Checks if the set is empty or not.
  
    
   @param Set *set: the set to check.
                 
    
   @return BOOL: TRUE is the set is empty or FALSE if not.
   -------------------------------------------------------------------- */
BOOL set_is_empty(Set *set){
  /* Check if the input is empty or the number of objects is 0 */
  if(!set || count(set) == 0){
	  return TRUE;
  } 

  return FALSE;
}



/** --------------------------------------------------------------------
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_is_full
    Checks if the set is full or not.
  
   
   @param Set *set: the set to check.
                 
    
   @return BOOL: TRUE is the set is full or FALSE if not.
   -------------------------------------------------------------------- */
BOOL set_is_full(Set *set){
  /* Check if the input is empty or the number of objects is lower 
  than the maximum number of objects that can contain the set */
  if(!set || count(set) < MAX_ID){
    return FALSE;
  } 

  return TRUE;
}



/** --------------------------------------------------------------------
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_get_object_at_position
    Returns the id of the object at the position i.
  
    
   @param Set *set: the set you want to know an especific object.
   @param int position: the position of the object in the set.
                 
    
   @return Id: the id of the object at the position i or NO_ID on error.
   -------------------------------------------------------------------- */
Id set_get_object_at_position(Set *set, int position){
  /* Check that the input is not empty or position is between 0 (included) 
  and the maximum number of objects that can contain the set */
	if(!set || position < 0 || position >= MAX_ID){
		return NO_ID;
	}

	return id(set)[position];
}



/** --------------------------------------------------------------------
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez 
  
   @brief set_is_object
    Checks if there is an especific object in the set.
  
    
   @param Set *set: the set where you want to find the object.
   @param Id object: the id of the object you want to know if it is in the set.
                  
    @return BOOL: TRUE if the object is in the set and FALSE in other cases. 
   -------------------------------------------------------------------- */
BOOL set_is_object(Set *set, Id object){
  int i, flag = 0;  /* Initialize the flag */

  /* Check that the inputs are not empty or the set is empty */
  if(!set || object == NO_ID || set_is_empty(set) == TRUE){
    return FALSE;
  }

  /* Look for the object in the set */
  for(i=0; i<count(set) && flag == 0; i++){
    if(object == id(set)[i]){
      flag = 1;
    }   
  }

  /* Check if the object was found */
  if(flag == 1){
    return TRUE;
  }  
  
  return FALSE;
}



/** --------------------------------------------------------------------
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_print
    Prints a set.
  
    
   @param Set *set: the set to print.
                 
    
   @return STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS set_print(Set *set){
  int i;

  if(!set){   /* Check that the input is not empty */
    return ERROR;
  }
  
  /* Print the set fields */
  for(i=0; i<count(set); i++){ 
    fprintf(stdout, "--> Object_id: %ld \n", id(set)[i]);
  }
  
  return OK;
}


