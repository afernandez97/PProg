/* ===================================================================
   File: object.h
   Version: 2.0
   Date: 27-10-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
		It defines an object.

   Revision history:
		Oct. 02, 2016  Version 1.0 (initial release)
		Oct. 27, 2016	 Version 2.0
			Added field "location" to the structure "Object". 
      Modified the functions that are affected by this field.			
      Created "object_set_location" and "object_get_location".
   =================================================================== */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/*** Data structures definition ***/
typedef struct _Object Object;

/*** Constant values description ***/
#define MAX_OBJECTS 100


/*** Public functions description ***/
/* --------------------------------------------------------------------
   Function: object_create
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Creates an object.

   Input: 
		Id id: the id of the object that is created.
   Output: 
		Object *: the object created or NULL on error.
   -------------------------------------------------------------------- */
Object * object_create(Id id);



/* --------------------------------------------------------------------
   Function: object_destroy
   Date: 02-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Destroys an object.

   Input: 
		Object *object: the object to destroy.
   Output: 
		STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS object_destroy(Object *object);
   


/* --------------------------------------------------------------------
   Function: object_get_id
   Date: 02-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Returns an object's id.

   Input: 
		Object *object: the object which you want the id of.

   Output: 
		Id: the object's id or NO_ID on error.
   -------------------------------------------------------------------- */
Id object_get_id(Object *object);



/* --------------------------------------------------------------------
   Function: object_set_name
   Date: 02-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Sets a name for an object.

   Input: 
		Object *object: the object you want to rename.
		char *name: the new name you want for the object.
  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS object_set_name(Object *object, char *name);


/* --------------------------------------------------------------------
   Function: object_get_name
   Date: 02-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the information of the name of the object.

   Input: 
		Object *object: the object you want to know the name.

   Output: 
    char *: the name of the object or NULL on error.
   -------------------------------------------------------------------- */
char * object_get_name(Object *object);



/* --------------------------------------------------------------------
   Function: object_set_location
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Sets a location for an object.

   Input: 
		Object *object: the object you want to set the location.
		Id location: the new location you want for the object.
  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS object_set_location(Object *object, Id location);



/* --------------------------------------------------------------------
   Function: object_get_location
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Returns an object's location.

   Input: 
		Object *object: the object which you want the location of.

   Output: 
		Id: the object's location or NO_ID on error.
   -------------------------------------------------------------------- */
Id object_get_location(Object *object);



/* --------------------------------------------------------------------
   Function: object_print
   Date: 27-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Prints the information of the object on the screen.

   Input: 
		Object *object the object you want to print.
   Output: 
		STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS object_print(Object *object);


#endif

