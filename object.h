/**
   @file object.h
   @version 3.0
   @date 18-11-2016 
   @author Guillermo Rodriguez and Alejandro Sanchez
   @brief It implements an object.
   @version Oct. 02, 2016  Version 1.0 (initial release)
   @version Oct. 27, 2016  Version 2.0
   Added field "location" to the structure "Object".
   Modified the functions that are affected by this field.
   Created "object_set_location" and "object_get_location".
   @version Nov. 18, 2016  Version 3.0
   Added field "desc" to the structure "Object".
   Created "object_set_desc" and "object_get_desc".
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
@def Constant values description
*/
#define MAX_OBJECTS 100

/*!< Data structures definition */
typedef struct _Object Object;



/*!< Public functions description */

/**
@brief object_create
Creates an object.
@date 27-10-2016 
@author Alejandro Sanchez
@param Id id: the id of the object that is created.
@return Object *: the object created or NULL on error.
*/

Object * object_create(Id id);




/**
@brief object_destroy
Destroys an object.
@date 02-10-2016 
@author Alejandro Sanchez 
@param Object *object: the object to destroy.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/

STATUS object_destroy(Object *object);
   


/**
@brief object_get_id
Returns an object's id.
@date 02-10-2016 
@author Alejandro Sanchez
@param Object *object: the object which you want the id of.
@return Id: the object's id or NO_ID on error.
*/

Id object_get_id(Object *object);



/**
@brief object_set_name
Sets a name for an object.
@date 02-10-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to rename.
@param char *name: the new name you want for the object.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_name(Object *object, char *name);


/**
@brief object_get_name
Gives the information of the name of the object.
@date 02-10-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know the name.
@return char *: the name of the object or NULL on error.
*/

char * object_get_name(Object *object);


/**
@brief object_set_location
Sets a location for an object.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set the location.
@param Id location: the new location you want for the object.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_location(Object *object, Id location);



/**
@brief object_get_location
Returns an object's location.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object: the object which you want the location of.
@return Id: the object's location or NO_ID on error.
*/

Id object_get_location(Object *object);


/**
@brief object_set_desc
Sets the description of the object.
@date 18-11-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to change its description.
@param char *desc: the new description of the object.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_desc(Object *object, char *desc);


/**
@brief object_get_desc
Gives the information of the description of the object.
@date 18-11-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know its description.
@return char *: the description of the object or NULL on error.
*/

char *object_get_desc(Object *object);


/**
@brief object_print
Prints the information of the object on the screen.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object the object you want to print.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/

STATUS object_print(Object *object);


#endif

