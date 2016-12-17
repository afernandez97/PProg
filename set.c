/** 
   @file set.c
   @version 2.0
   @date 18-10-2016
   @autor Guillermo Rodriguez and Alejandro Sanchez
 
   
    @brief It implements a set.
 
   @version
    Oct. 18, 2016 Version 1.0 (initial release)
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/**
@def Constant values description 
*/
#define id(X) (X)->id
#define count(X) (X)->count
 
/**
@brief Set structure
Stores information of the identifiers or the objects
that contains and the number of them.
*/
struct _Set{
  Id id[MAX_ID]; /*!< Array of identifiers */
  int count;  /*!< Number of identifiers in that moment */
};
 
/*!< Public functions definition */
/**
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_create()
    Creates a set
  
   @param 
         
   @return 
    Set *: the set created or NULL on error.
   */
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
 


/**
    
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_destroy() 
    Destroys a set.
  
   @param 
    Set *set: the set to destroy.
   @return 
    _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS set_destroy(Set *set){
  if(!set){         /* Check that the input is not empty */
    return _ERROR;
  }
   
  free(set);        /* Eliminate the memory of the set */     

  return _OK;
}


 
/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_add()
    Adds an object to the set.
  
     
    @param Set *set: the set to change.
    @param Id id: the id of the object you want to add.
     
    @return _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS set_add(Set *set, Id id){
  /* Check that the input is not empty or the set is full */
  if(!set || set_is_full(set) == _TRUE){
		return _ERROR;
	} 

  /* Check if the set already contains that object */
  if(set_is_object(set, id) == _TRUE){
    return _ERROR;
  }

  /* Add the id of the object to the set */
	id(set)[count(set)] = id;

  /* Increase in 1 the number of objects in the set */
  count(set)++;

  return _OK ;
}


 
/**
  
   @date 18-10-2016 
   @author Guillermo Rodriguez 
  
   @brief set_del()
    Deletes an object from the set.
  
    
   @param Set *set: the set to change.
   @param the id of the object you want to delete.
    
   @return _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS set_del(Set *set, Id id){
 	/* Initialize the counter and the flag */
  int i = 0, flag = 0, pos;
  Id buff;

  /* Check that the input is not empty or the set is empty */
  if(!set || set_is_empty(set) == _TRUE){
		return _ERROR;
	}

  /* Look for the object to delete in the set */
  while(flag == 0 && i < count(set)){ 
    if(id == id(set)[i]){
      flag = 1;
      pos = i;
  	}
    i++;
	}
  
  /* Check that the object was found */   
	if(flag == 0){
  	return _ERROR;
	}

  /* Rearrange te set */
  id(set)[pos] = NO_ID;
  for (i = pos; i < count(set); i++) {
    buff = id(set)[i];
    id(set)[i] = id(set)[i + 1];
    id(set)[i + 1] = buff;
  }

  /* Decrease in 1 the number of objects in the set */
  count(set)--;  
  
  return _OK ;
}



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_get_count
    Returns the number of objects in the set.
  
    
   @param Set *set: the set that you want to know its number of objects.
                 
    
   @return int: the number of objects in the set.
   */
int set_get_count(Set *set){
	if(!set){
		return 0;
	}

	return count(set);
}



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief  set_is_empty()
    Checks if the set is empty or not.
  
    
   @param Set *set: the set to check.
                 
    
   @return _BOOL: _TRUE is the set is empty or _FALSE if not.
   */
_BOOL set_is_empty(Set *set){
  /* Check if the input is empty or the number of objects is 0 */
  if(!set || count(set) == 0){
	  return _TRUE;
  } 

  return _FALSE;
}



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_is_full
    Checks if the set is full or not.
  
   
   @param Set *set: the set to check.
                 
    
   @return _BOOL: _TRUE is the set is full or _FALSE if not.
   */
_BOOL set_is_full(Set *set){
  /* Check if the input is empty or the number of objects is lower 
  than the maximum number of objects that can contain the set */
  if(!set || count(set) < MAX_ID){
    return _FALSE;
  } 

  return _TRUE;
}



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_get_object_at_position
    Returns the id of the object at the position i.
  
    
   @param Set *set: the set you want to know an especific object.
   @param int position: the position of the object in the set.
                 
    
   @return Id: the id of the object at the position i or NO_ID on error.
   */
Id set_get_object_at_position(Set *set, int position){
  /* Check that the input is not empty or position is between 0 (included) 
  and the maximum number of objects that can contain the set */
	if(!set || position < 0 || position >= MAX_ID){
		return NO_ID;
	}

	return id(set)[position];
}



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez 
  
   @brief set_is_object
    Checks if there is an especific object in the set.
  
    
   @param Set *set: the set where you want to find the object.
   @param Id object: the id of the object you want to know if it is in the set.
                  
    @return _BOOL: _TRUE if the object is in the set and _FALSE in other cases. 
   */
_BOOL set_is_object(Set *set, Id object){
  int i, flag = 0;  /* Initialize the flag */

  /* Check that the inputs are not empty or the set is empty */
  if(!set || object == NO_ID || set_is_empty(set) == _TRUE){
    return _FALSE;
  }

  /* Look for the object in the set */
  for(i=0; i<count(set) && flag == 0; i++){
    if(object == id(set)[i]){
      flag = 1;
    }   
  }

  /* Check if the object was found */
  if(flag == 1){
    return _TRUE;
  }  
  
  return _FALSE;
}



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_print
    Prints a set.
  
    
   @param Set *set: the set to print.
                 
    
   @return _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS set_print(Set *set){
  int i;

  if(!set){   /* Check that the input is not empty */
    return _ERROR;
  }
  
  /* Print the set fields */
  for(i=0; i<count(set); i++){ 
    fprintf(stdout, "--> Object_id: %ld \n", id(set)[i]);
  }
  
  return _OK;
}


