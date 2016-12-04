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
#define bought(X) (X)->bought
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
	BOOL bought; /*!< Bought or not */
	BOOL hidden; /*!< Hidden or not */
	Id open; /*!< Identifier of the link which can be opened with this object */
	BOOL light; /*!< Light or not */
	BOOL on; /*!< On / Off */
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
  bought(object) = FALSE;
  hidden(object) = FALSE;
  light(object) = FALSE;
  on(object) = FALSE;

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
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_price(Object *object, double price){
  if(!object){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Set the price */
  price(object) = price;

  return OK;
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
@brief object_set_bought
Sets if an object has been bought or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its bought's field.
@param BOOL bought: Choose if the object is bought or not.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_bought(Object *object, BOOL bought){
  if(!object){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Set the bought */
  bought(object) = bought;

  return OK;
}


/**
@brief object_is_bought
Gets if an object is bought or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL: the bought field of the object or FALSE if the input is NULL.
*/

BOOL object_is_bought(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return FALSE;
  }

  return bought(object);
}


/**
@brief object_set_hidden
Sets if an object is hidden or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its hidden's field.
@param BOOL hidden: Choose if the object is hidden or not.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS object_set_hidden(Object *object, BOOL hidden){
  if(!object){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Set the hidden */
  hidden(object) = hidden;

  return OK;
}


/**
@brief object_is_hidden
Gets if an object is hidden or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL: the hidden field of the object or FALSE if the input is NULL.
*/

BOOL object_is_hidden(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return FALSE;
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
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_open(Object *object, Id open){
  if(!object){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Set the open */
  open(object) = open;

  return OK;
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
@param BOOL light: Choose if the object can light or not.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_light(Object *object, BOOL light){
  if(!object){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Set the light */
  light(object) = light;

  return OK;
}


/**
@brief object_can_light
Gets if an object can light or not.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL: the light field of the object or FALSE if the input is NULL.
*/

BOOL object_can_light(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return FALSE;
  }

  return light(object);
}


/**
@brief object_set_on
Sets if an object is on or off.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to set its on's field.
@param BOOL on: Choose if the object is on or off.
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS object_set_on(Object *object, BOOL on){
  if(!object){      /* Check that the input is not empty */
    return ERROR;
  }

  /* Set the on */
  on(object) = on;

  return OK;
}


/**
@brief object_is_on
Gets if an object is on or off.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object: the object you want to know that.
@return BOOL: the on field of the object or FALSE if the input is NULL.
*/

BOOL object_is_on(Object *object){
  if(!object){      /* Check that the input is not empty */ 
    return FALSE;
  }

  return on(object);
}



/**
@brief object_print
Prints the information of the object on the screen.
@date 03-12-2016 
@author Alejandro Sanchez
@param Object *object the object you want to print.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/

STATUS object_print(Object *object){
  if(!object){        /* Check that the input is not empty */
    return ERROR;
  }

  /* Print the object fields */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Location: %ld; \
    Description: %s; Price: %lf; Open: %ld", id(object), name(object), location(object),
    desc(object), price(object), open(object));

  if(bought(object) == TRUE){
    fprintf(stdout, "bought: TRUE;");
  } else{
    fprintf(stdout, "bought: FALSE;");
  }

  if(hidden(object) == TRUE){
    fprintf(stdout, "hidden: TRUE;");
  } else{
    fprintf(stdout, "hidden: FALSE;");
  }

  if(light(object) == TRUE){
    fprintf(stdout, "light: TRUE;");
  } else{
    fprintf(stdout, "light: FALSE;");
  }

  if(on(object) == TRUE){
    fprintf(stdout, "on: TRUE)\n");
  } else{
    fprintf(stdout, "on: FALSE)\n");
  }

  return OK;
}




