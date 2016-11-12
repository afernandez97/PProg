/* =================================================================== 
   File: set.h
   Version: 2.0
   Date: 18-10-2016
   Author: Guillermo Rodriguez and Alejandro Sanchez
 
   Description:
    It defines a set.
 
   Revision history:
    Oct. 18, 2016 Version 1.0 (initial release)
=================================================================== */


#ifndef SET_H
#define SET_H

#include "types.h"

/* Constant values description */
#define MAX_ID  50


/*** Data structures definition ***/
typedef struct _Set Set;


/* Public functions description */
/* --------------------------------------------------------------------
   Function: set_create
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Creates a set.
  
   Input: 
         
   Output: 
    Set *: the set created or NULL on error.
   -------------------------------------------------------------------- */
Set * set_create();


/* --------------------------------------------------------------------
   Function: set_destroy
   Date: 18-10-2016 
   Author: Guillermo Rodriguez 
 
   Description: 
    Destroys a set.
 
   Input: 
    Set *set: the set to destroy.
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS set_destroy(Set *set);



/* --------------------------------------------------------------------
   Function: set_add
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Adds an object to the set.
  
   Input: 
    Set *set: the set to change.
    Id id: the id of the object you want to add.
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS set_add(Set *set, Id id);



/* --------------------------------------------------------------------
   Function: set_del
   Date: 18-10-2016 
   Author: Guillermo Rodriguez 
  
   Description: 
    Deletes an object from the set.
  
   Input: 
    Set *set: the set to change.
    Id id: the id of the object you want to delete.
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS set_del(Set *set, Id id);



/* --------------------------------------------------------------------
   Function: set_get_count
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Returns the number of objects in the set.
  
   Input: 
    Set *set: the set that you want to know its number of objects.
                 
   Output: 
    int: the number of objects in the set.
   -------------------------------------------------------------------- */
int set_get_count(Set *set);



/* --------------------------------------------------------------------
   Function: set_is_empty
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Checks if the set is empty or not.
  
   Input: 
    Set *set: the set to check.
                 
   Output: 
    BOOL: TRUE is the set is empty or FALSE if not.
   -------------------------------------------------------------------- */
BOOL set_is_empty(Set *set);



/* --------------------------------------------------------------------
   Function: set_is_full
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Checks if the set is full or not.
  
   Input: 
    Set *set: the set to check.
                 
   Output: 
    BOOL: TRUE is the set is full or FALSE if not.
   -------------------------------------------------------------------- */
BOOL set_is_full(Set *set);
 


/* --------------------------------------------------------------------
   Function: set_get_object_at_position
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Returns the id of the object at the position i.
  
   Input: 
    Set *set: the set you want to know an especific object.
    int position: the position of the object in the set.
                 
   Output: 
    Id: the id of the object at the position i or NO_ID on error.
   -------------------------------------------------------------------- */
Id set_get_object_at_position(Set *set, int position);



/* --------------------------------------------------------------------
   Function: set_is_object
   Date: 18-10-2016 
   Author: Guillermo Rodriguez 
  
   Description: 
    Checks if there is an especific object in the set.
  
   Input: 
    Set *set: the set where you want to find the object.
    Id object: the id of the object you want to know if it is in the set.
                 
   Output: 
    BOOL: TRUE if the object is in the set and FALSE in other cases. 
   -------------------------------------------------------------------- */
BOOL set_is_object(Set *set, Id object);



/* --------------------------------------------------------------------
   Function: set_print
   Date: 18-10-2016 
   Author: Guillermo Rodriguez
  
   Description: 
    Prints a set.
  
   Input: 
    Set *set: the set to print.
                 
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS set_print(Set *set);


#endif

