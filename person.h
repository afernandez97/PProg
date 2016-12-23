/**
   @file person.h
   @version 1.0
   @date 16-12-2016 
   @author Guillermo Rodriguez
   @brief It implements a person.
   @version Dec.16  , 2016  Version 1.0 (initial release)
*/

#ifndef PERSON_H
#define PERSON_H

#include "types.h"

/**
@def Constant values description
*/
#define MAX_PEOPLE 100

/*!< Data structures definition */
typedef struct _Person Person;



/*!< Public functions description */

/**
@brief person_create
Creates a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Id id: the id of the person that is created.
@return Person *: the person created or NULL on error.
*/

Person * person_create(Id id);



/**
@brief person_destroy
Destroys a person.
@date 16-12-2016 
@author Guillermo Rodriguez 
@param Person *person: the person to destroy.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ person_destroy(Person * person);



/**
@brief person_get_id
Returns a person's id.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person which you want the id of.
@return Id: the person's id or NO_ID on error.
*/

Id person_get_id(Person *person);



/**
@brief person_set_name
Sets a name for a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param person *person: the person you want to rename.
@param char *name: the new name you want for the person.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ person_set_name(Person *person, char *name);



/**
@brief person_get_name
Gives the information of the name of the person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person you want to know the name.
@return char *: the name of the person or NULL on error.
*/

char * person_get_name(Person *person);



/**
@brief person_set_location
Sets a location for a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person you want to set the location.
@param Id location: the new location you want for the person.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ person_set_location(Person *person, Id location);

/**
@brief person_get_location
Returns an person's location.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person which you want the location of.
@return Id: the person's location or NO_ID on error.
*/

Id person_get_location(Person *person);

/**
@brief person_set_rule
Sets a rule for a person.
@date 16-12-2016 
@author Guillermo Rodriguez
@param Person *person: the person you want to set the rule.
@param Id rule: the new rule you want for the person.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ person_set_rule(Person *person, Id rule);



/**
@brief person_get_rule
Returns a person's rule.
@date 16-12-2016 
@author Guillermo Rodriguez
@param person *person: the person which you want the rule of.
@return Id: the person's rule or NO_ID on error.
*/

Id person_get_rule(Person *person);



/**
@brief person_print
Prints the information of the person on the screen.
@date 03-12-2016 
@author Guillermo Rodriguez
@param Person *person the person you want to print.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ person_print(Person *person);





#endif

