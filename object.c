/**
   @file object.c
   @version 4.0
   @date 03-12-2016 
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
   @version Dec. 03, 2016  Version 4.0
   Added fields "price", "bought", "hidden", "open", "light" 
   and "on" to the structure "Object".
   Created functions to handle this fields and modified the 
   functions that were affected by these new fields.   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
 
/**
@def Constant values description 
*/ 
#define id(X) (X)->id
#define name(X) (X)->name
#define location(X) (X)->location
#define desc(X) (X)->desc
#define price(X) (X)->price
#define hidden(X) (X)->hidden
#define open(X) (X)->open
#define light(X) (X)->light
#define on(X) (X)->on


/**
@brief Object's structure
Contains the object's fields
*/

struct _Object{
	Id id; /*!< Identifier of the object */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
	Id location; /*!< Location of the object */
	char desc[WORD_SIZE + 1];	/*!< Description of the object */
	double price; /*!< Price of the object */
	_BOOL hidden; /*!< Hidden or not */
	Id open; /*!< Identifier of the link which can be opened with this object */
	_BOOL light; /*!< Light or not */
	_BOOL on; /*!< On / Off */
};


/*!< Public functions definition */

/**
@brief object_create
Creates an object.
@date 03-12-2016 
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
  open(object) = NO_ID;

  name(object)[0] = '\0';
  desc(object)[0] = '\0';

  price(object) = 0.00;
  hidden(object) = _FALSE;
  light(object) = _FALSE;
  on(object) = _FALSE;

  return object;
}



/**
@brief object_destroy
Destroys an object.
@date 02-10-2016 
@author Alejandro Sanchez 
@param Object *object: the object to destroy.
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/

_STATUS object_destroy(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return _ERROR;
  }

  free(object);    /* Eliminate the memory of the object */
 
  return _OK;
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
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_name(Object *object, char *name){
  if(!object || !name){			/* Check that the inputs are not empty */
    return _ERROR;
  }

  /* Set the name and check if it hasworked */
  if(!strcpy(name(object), name)){	
    return _ERROR;
  }

  return _OK;
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
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_location(Object *object, Id location){
  if(!object){			/* Check that the input is not empty */
    return _ERROR;
  }

  /* Set the location */
  location(object) = location;

  return _OK;
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
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_desc(Object *object, char *desc){
  if(!object || !desc){   /* Check if the inputs are not empty */
    return _ERROR;
  }

  /* Set the description and check if it has worked */
  if(!strcpy(desc(object), desc)){
    return _ERROR;
  }  
  
  return _OK;
}



/**
@brief object_get_desc
Gives the information of the description of the object.
@date 18-11-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know its description.
@return char *: the description of the object or NULL on error.
*/

char * object_get_desc(Object *object){
  if(!object){  /* Check that the input is not empty */
   return NULL;
  }

  return desc(object); 
} 


/**
@brief object_set_price
Sets a price for an object.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set the price.
@param double price: the new price you want for the object.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_price(Object *object, double price){
  if(!object){      /* Check that the input is not empty */
    return _ERROR;
  }

  /* Set the price */
  price(object) = price;

  return _OK;
}

/**
@brief object_get_price
Returns an object's price.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object which you want the price of.
@return double: the object's price or -1 on error.
*/

double object_get_price(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return -1;
  }

  return price(object);
}



/**
@brief object_set_hidden
Sets if an object is hidden or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its hidden's field.
@param _BOOL hidden: Choose if the object is hidden or not.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS object_set_hidden(Object *object, _BOOL hidden){
  if(!object){      /* Check that the input is not empty */
    return _ERROR;
  }

  /* Set the hidden */
  hidden(object) = hidden;

  return _OK;
}


/**
@brief object_is_hidden
Gets if an object is hidden or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return _BOOL: the hidden field of the object or _FALSE if the input is NULL.
*/

_BOOL object_is_hidden(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return _FALSE;
  }

  return hidden(object);
}



/**
@brief object_set_open
Sets if an object can open a link or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its open's field.
@param Id open: the identifier of the link that the object can open.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_open(Object *object, Id open){
  if(!object){      /* Check that the input is not empty */
    return _ERROR;
  }

  /* Set the open */
  open(object) = open;

  return _OK;
}


/**
@brief object_can_open
Gets if an object can open or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return Id: the id of the link that the object can open or NO_ID on error.
*/

Id object_can_open(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return open(object);
}


/**
@brief object_set_light
Sets if an object can light or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its light's field.
@param _BOOL light: Choose if the object can light or not.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_light(Object *object, _BOOL light){
  if(!object){      /* Check that the input is not empty */
    return _ERROR;
  }

  /* Set the light */
  light(object) = light;

  return _OK;
}


/**
@brief object_can_light
Gets if an object can light or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return _BOOL: the light field of the object or _FALSE if the input is NULL.
*/

_BOOL object_can_light(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return _FALSE;
  }

  return light(object);
}


/**
@brief object_set_on
Sets if an object is on or off.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its on's field.
@param _BOOL on: Choose if the object is on or off.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS object_set_on(Object *object, _BOOL on){
  if(!object){      /* Check that the input is not empty */
    return _ERROR;
  }

  /* Set the on */
  on(object) = on;

  return _OK;
}


/**
@brief object_is_on
Gets if an object is on or off.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return _BOOL: the on field of the object or _FALSE if the input is NULL.
*/

_BOOL object_is_on(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return _FALSE;
  }

  return on(object);
}



/**
@brief object_print
Prints the information of the object on the screen.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object the object you want to print.
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/

_STATUS object_print(Object *object){
  if(!object){        /* Check that the input is not empty */
    return _ERROR;
  }

  /* Print the object fields */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Location: %ld; \
    Description: %s; Price: %lf; Open: %ld", id(object), name(object), location(object),
    desc(object), price(object), open(object));


  if(hidden(object) == _TRUE){
    fprintf(stdout, "hidden: _TRUE;");
  } else{
    fprintf(stdout, "hidden: _FALSE;");
  }

  if(light(object) == _TRUE){
    fprintf(stdout, "light: _TRUE;");
  } else{
    fprintf(stdout, "light: _FALSE;");
  }

  if(on(object) == _TRUE){
    fprintf(stdout, "on: _TRUE)\n");
  } else{
    fprintf(stdout, "on: _FALSE)\n");
  }

  return _OK;
}




