/** 
   @file set.h
   @version 2.0
   @date 18-10-2016
   @autor Guillermo Rodriguez and Alejandro Sanchez
 
   
    @brief It implements a set.
 
   @date
    Oct. 18, 2016 Version 1.0 (initial release)
*/


#ifndef SET_H
#define SET_H

#include "types.h"

/* Constant values description */
#define MAX_ID  50


/*** Data structures definition ***/
typedef struct _Set Set;


/* Public functions description */
/**
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_create()
    Creates a set
  
   @param 
         
   @return 
    Set *: the set created or NULL on error.
   */
Set * set_create();


/**
    
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_destroy() 
    Destroys a set.
  
   @param 
    Set *set: the set to destroy.
   @return 
    STATUS: ERROR if the input is NULL and OK otherwise.
   */
STATUS set_destroy(Set *set);


 
/**
   
   @date 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_add()
    Adds an object to the set.
  
     
    @param Set *set: the set to change.
    @param Id id: the id of the object you want to add.
     
    @return STATUS: OK if you do the operation well and ERROR in other cases.
   */
STATUS set_add(Set *set, Id id);


 
/**
  
   @date: 18-10-2016 
   @author: Guillermo Rodriguez 
  
   @brief set_del()
    Deletes an object from the set.
  
    
   @param Set *set: the set to change.
   @param the id of the object you want to delete.
    
   @return STATUS: OK if you do the operation well and ERROR in other cases.
   */
STATUS set_del(Set *set, Id id);



/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief set_get_count
    Returns the number of objects in the set.
  
    
   @param Set *set: the set that you want to know its number of objects.
                 
    
   @return int: the number of objects in the set.
   */
int set_get_count(Set *set);




/**
   
   @date 18-10-2016 
   @author Guillermo Rodriguez
  
   @brief  set_is_empty()
    Checks if the set is empty or not.
  
    
   @param Set *set: the set to check.
                 
    
   @return BOOL: TRUE is the set is empty or FALSE if not.
   */
BOOL set_is_empty(Set *set);



/**
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_is_full
    Checks if the set is full or not.
  
   
   @param Set *set: the set to check.
                 
    
   @return BOOL: TRUE is the set is full or FALSE if not.
   */
BOOL set_is_full(Set *set);
 



/**
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_get_object_at_position
    Returns the id of the object at the position i.
  
    
   @param Set *set: the set you want to know an especific object.
   @param int position: the position of the object in the set.
                 
    
   @return Id: the id of the object at the position i or NO_ID on error.
   */
Id set_get_object_at_position(Set *set, int position);



/**
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez 
  
   @brief set_is_object
    Checks if there is an especific object in the set.
  
    
   @param Set *set: the set where you want to find the object.
   @param Id object: the id of the object you want to know if it is in the set.
                  
    @return BOOL: TRUE if the object is in the set and FALSE in other cases. 
   */
BOOL set_is_object(Set *set, Id object);



/**
   
   @date: 18-10-2016 
   @author: Guillermo Rodriguez
  
   @brief set_print
    Prints a set.
  
    
   @param Set *set: the set to print.
                 
    
   @return STATUS: ERROR if the input is NULL and OK otherwise.
   */
STATUS set_print(Set *set);


#endif

