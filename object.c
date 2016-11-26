/**
   @file object.c
   @version 3.0
   @date 18-11-2016 
   @author Guillermo Rodriguez and Alejandro Sanchez
   @brief It implements an object.
   @version Oct. 02, 2016  Version 1.0 (initial release)
	 @version Oct. 27, 2016	 Version 2.0
	 Added field "location" to the structure "Object".
   Modified the functions that are affected by this field.
	 Created "object_set_location" and "object_get_location".
	 @version Nov. 18, 2016	 Version 3.0
	 Added field "desc" to the structure "Object".
	 Created "object_set_desc" and "object_get_desc".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
 
/*** Constant values description ***/ 
#define id(X) (X)->id
#define name(X) (X)->name
#define location(X) (X)->location
#define desc(X) (X)->desc


/**
@brief Object's structure
Contains the object's fields
*/

struct _Object{
	Id id; /*!< Identifier of the object */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
	Id location; /*!< Location of the object */
	char desc[WORD_SIZE + 1];	/*!< Description of the object */
};


/*** Public functions definition ***/

/**
@brief object_create
Creates an object.
@date 27-10-2016 
@author Alejandro Sanchez
@param Id id: the id of the object that is created.
@return Object *: the object created or NULL on error.
*/

Object * object_create(Id id){
  Object *object = NULL;

  if(id == NO_ID){ 	/* Check that the input is not empty */ 
    return NULL;
  }

  object = (Object *)malloc(sizeof(Object));
  if(!object){	    /* Check if memory has been allocated */
    return NULL;
  }

  /* Initialize structure fields */
  id(object) = id;
	location(object) = NO_ID;

  name(object)[0] = '\0';

  return object;
}



/**
@brief object_destroy
Destroys an object.
@date 02-10-2016 
@author Alejandro Sanchez 
@param Object *object: the object to destroy.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/

STATUS object_destroy(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return ERROR;
  }

  free(object);    /* Eliminate the memory of the object */
 
  return OK;
}



/**
@brief object_get_id
Returns an object's id.
@date 02-10-2016 
@author Alejandro Sanchez
@param Object *object: the object which you want the id of.
@return Id: the object's id or NO_ID on error.
*/

Id object_get_id(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return id(object);
}



/**
@brief object_set_name
Sets a name for an object.
@date 02-10-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to rename.
@param char *name: the new name you want for the object.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_name(Object *object, char *name){
  if(!object || !name){			/* Check that the inputs are not empty */
    return ERROR;
  }

  /* Set the name and check if it hasworked */
  if(!strcpy(name(object), name)){	
    return ERROR;
  }

  return OK;
}



/**
@brief object_get_name
Gives the information of the name of the object.
@date 02-10-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know the name.
@return char *: the name of the object or NULL on error.
*/

char * object_get_name(Object *object){
  if(!object){            /* Check that the input is not empty */
    return NULL;
  }

  return name(object);                
}



/**
@brief object_set_location
Sets a location for an object.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set the location.
@param Id location: the new location you want for the object.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_location(Object *object, Id location){
  if(!object){			/* Check that the input is not empty */
    return ERROR;
  }

  /* Set the location */
  location(object) = location;

  return OK;
}



/**
@brief object_get_location
Returns an object's location.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object: the object which you want the location of.
@return Id: the object's location or NO_ID on error.
*/

Id object_get_location(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return location(object);
}



/**
@brief object_set_desc
Sets the description of the object.
@date 18-11-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to change its description.
@param char *desc: the new description of the object.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_desc(Object *object, char *desc){
  if(!object || !desc){   /* Check if the inputs are not empty */
    return ERROR;
  }

  /* Set the description and check if it has worked */
  if(!strcpy(desc(object), desc)){
    return ERROR;
  }  
  
  return OK;
}



/**
@brief object_get_desc
Gives the information of the description of the object.
@date 18-11-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know its description.
@return char *: the description of the object or NULL on error.
*/

char *object_get_desc(Object *object){
  if(!object){  /* Check that the input is not empty */
   return NULL;
  }

  return desc(object); 
} 


/**
@brief object_print
Prints the information of the object on the screen.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object the object you want to print.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/

STATUS object_print(Object *object){
  if(!object){        /* Check that the input is not empty */
    return ERROR;
  }

  /* Print the object fields */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Location: %ld)\n", id(object), 
    name(object), location(object));

  return OK;
}




