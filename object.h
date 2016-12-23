/**
   @file object.h
   @version 4.0
   @date 03-12-2016 
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
   @version Dec. 03, 2016  Version 4.0
     Added fields "price", "hidden", "open", "light" 
     and "on" to the structure "Object".
     Created functions to handle this fields and modified the 
     functions that were affected by these new fields.  
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
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ object_destroy(Object *object);
   


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
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_name(Object *object, char *name);


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
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_location(Object *object, Id location);



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
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_desc(Object *object, char *desc);
STATUS_ object_set_printdesc(Object *object, char *printdesc);


/**
@brief object_get_desc
Gives the information of the description of the object.
@date 18-11-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know its description.
@return char *: the description of the object or NULL on error.
*/

char * object_get_desc(Object *object);
char * object_get_printdesc(Object *object);


/**
@brief object_set_price
Sets a price for an object.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set the price.
@param double price: the new price you want for the object.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_price(Object *object, double price);


/**
@brief object_get_price
Returns an object's price.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object which you want the price of.
@return double: the object's price or -1 on error.
*/

double object_get_price(Object *object);


/**
@brief object_set_hidden
Sets if an object is hidden or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its hidden's field.
@param BOOL_ hidden: Choose if the object is hidden or not.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ object_set_hidden(Object *object, BOOL_ hidden);


/**
@brief object_is_hidden
Gets if an object is hidden or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL_: the hidden field of the object or FALSE_ if the input is NULL.
*/

BOOL_ object_is_hidden(Object *object);


/**
@brief object_set_open
Sets if an object can open a link or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its open's field.
@param Id open: the identifier of the link that the object can open.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_open(Object *object, Id open);


/**
@brief object_can_open
Gets if an object can open or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return Id: the id of the link that the object can open or NO_ID on error.
*/

Id object_can_open(Object *object);


/**
@brief object_set_light
Sets if an object can light or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its light's field.
@param BOOL_ light: Choose if the object can light or not.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_light(Object *object, BOOL_ light);


/**
@brief object_can_light
Gets if an object can light or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL_: the light field of the object or FALSE_ if the input is NULL.
*/

BOOL_ object_can_light(Object *object);


/**
@brief object_set_on
Sets if an object is on or off.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its on's field.
@param BOOL_ on: Choose if the object is on or off.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ object_set_on(Object *object, BOOL_ on);


/**
@brief object_is_on
Gets if an object is on or off.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL_: the on field of the object or FALSE_ if the input is NULL.
*/

BOOL_ object_is_on(Object *object);


/**
@brief object_print
Prints the information of the object on the screen.
@date 27-10-2016 
@author Alejandro Sanchez
@param Object *object the object you want to print.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ object_print(Object *object);


#endif

