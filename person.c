/**
   @file person.c
   @version 1.0
   @date 16-12-2016 
   @author Guillermo Rodriguez
   @brief It implements a person.
   @version Dec.16  , 2016  Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
 
/**
@def Constant values description 
*/ 
#define id(X) (X)->id
#define name(X) (X)->name
#define location(X) (X)->location
#define rule(X) (X)->rule



/**
@brief Person's structure
Contains the person's fields
*/
struct _Person{
	Id id; /*!< Identifier of the person */
  char name[WORD_SIZE + 1]; /*!< Name of the person */
	Id location; /*!< Location of the person */
	Id rule;	/*!< Question of the person */
};


/*!< Public functions definition */

/**
@brief person_create
Creates a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Id id: the id of the person that is created.
@return Person *: the person created or NULL on error.
*/

Person * person_create(Id id){
  Person * person = NULL;

  if(id == NO_ID){ 	/* Check that the input is not empty */ 
    return NULL;
  }

  person = (Person *)malloc(sizeof(Person));
  if(!person){	    /* Check if memory has been allocated */
    return NULL;
  }

  /* Initialize structure fields */
  id(person) = id;
	location(person) = NO_ID;
  rule(person) = NO_ID;

  name(person)[0] = '\0';

  return person;
}



/**
@brief person_destroy
Destroys a person.
@date 16-12-2016 
@author Guillermo Rodriguez 
@param Person *person: the person to destroy.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ person_destroy(Person * person){
  if(!person){      /* Check that the input is not empty */ 
    return ERROR_;
  }

  free(person);    /* Eliminate the memory of the person */
 
  return OK_;
}



/**
@brief person_get_id
Returns a person's id.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person which you want the id of.
@return Id: the person's id or NO_ID on error.
*/

Id person_get_id(Person *person){
  if(!person){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return id(person);
}



/**
@brief person_set_name
Sets a name for a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param person *person: the person you want to rename.
@param char *name: the new name you want for the person.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ person_set_name(Person *person, char *name){
  if(!person || !name){			/* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Set the name and check if it hasworked */
  if(!strcpy(name(person), name)){	
    return ERROR_;
  }

  return OK_;
}



/**
@brief person_get_name
Gives the information of the name of the person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person you want to know the name.
@return char *: the name of the person or NULL on error.
*/

char * person_get_name(Person *person){
  if(!person){            /* Check that the input is not empty */
    return NULL;
  }

  return name(person);                
}



/**
@brief person_set_location
Sets a location for a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person you want to set the location.
@param Id location: the new location you want for the person.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ person_set_location(Person *person, Id location){
  if(!person){			/* Check that the input is not empty */
    return ERROR_;
  }

  /* Set the location */
  location(person) = location;

  return OK_;
}

/**
@brief person_get_location
Returns an person's location.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person which you want the location of.
@return Id: the person's location or NO_ID on error.
*/

Id person_get_location(Person *person){
  if(!person){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return location(person);
}

/**
@brief person_set_rule
Sets a rule for a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person you want to set the rule.
@param Id rule: the new rule you want for the person.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ person_set_rule(Person *person, Id rule){
  if(!person){			/* Check that the input is not empty */
    return ERROR_;
  }

  /* Set the location */
  rule(person) = rule;

  return OK_;
}



/**
@brief person_get_rule
Returns a person's rule.
@date 16-12-2016 
@author Guillermo Rodriguez
@param person *person: the person which you want the rule of.
@return Id: the person's rule or NO_ID on error.
*/
Id person_get_rule(Person *person){
  if(!person){      /* Check that the input is not empty */ 
    return NO_ID;
  }

  return rule(person);
}




/**
@brief person_print
Prints the information of the person on the screen.
@date 03-12-2016 
@author Guillermo Rodriguez
@param Person *person the person you want to print.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/
STATUS_ person_print(Person *person){
  if(!person){        /* Check that the input is not empty */
    return ERROR_;
  }

  /* Print the person fields */
  fprintf(stdout, "--> Person (Id: %ld; Name: %s; Location: %ld; Rule: %ld)", id(person), name(person), location(person),rule(person));


  return OK_;
}




