/**
@file link.h
@brief It implements a link.
@version 1.0
@date 04-11-2016
@author Adrian Fernández, Ricardo Riol
@version Nov. 4, 2016 Version 1.0 (initial release)
*/


#ifndef LINK_H
#define LINK_H

#include "space.h"

/**
@def Constant values description
*/
#define MAX_LINKS 4*MAX_SPACES

/*!< Data structures definition */
typedef struct _Link Link;

/**
@brief Enum to set the link's state.
Open = 0
Closed = 1
No state = -1
*/
typedef enum {	
  NO_STATE = -1, OPEN, CLOSED
} STATE;



/*!< Public functions description */

/**
@brief link_create
This function creates a variable of type Link.
@date 04-11-2016
@author Adrian Fernández
@param Id id: the id of the link.
@return Link *: the link created or NULL on error.
*/

Link * link_create(Id id);

/**
@brief link_destroy
This function destroys a variable of type Link.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the variable that is going to destroy.
@return _STATUS: Returns _OK if the function has done his job correctly.
*/

_STATUS link_destroy(Link* link);

/**
@brief link_get_id
This function gets the id field of a Link.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose id we want to get.
@return Id: The id of the Link.
*/
Id link_get_id(Link* link);

/**
@brief link_set_name
This function sets the name field of a Link.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose name we want to set.
@param char* name: The name we want to set.
@return _STATUS: Returns _OK if the function has done his job correctly.
*/
_STATUS link_set_name(Link* link, char* name);

/**
@brief link_get_name
This function gets the name field of a Link.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose name we want to get.
@return char*: The name of the Link.
*/

char* link_get_name(Link* link);

/**
@brief link_set_space1
Sets the Id of a Link's first Space.
@date 04-11-2016
@author Alejandro Sanchez
@param Link *link: the link whose first space you want to set.
@param Id space1: the id of the space you want to be link's first space.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS link_set_space1(Link *link, Id space1);

/**
@brief link_get_space1
This function gets the Id of a Link's first Space. 
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose first Space we want to get.
@return Id: The Id of the first Space.
*/

Id link_get_space1(Link* link);

/**
@brief link_set_space2
Sets the Id of a Link's second Space. 
@date 04-11-2016
@author Alejandro Sanchez
@param Link *link: the link whose second space you want to set.
@param Id space2: the id of the space you want to be link's second space.
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS link_set_space2(Link *link, Id space2);

/**
@brief link_get_space2
This function gets the Id of a Link's second Space.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose second Space we want to get.
@return Id: The Id of the second Space.
*/

Id link_get_space2(Link* link);

/**
@brief link_set_state
This function sets the state field of a Link.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose state we want to set.
@param STATE state: The state we want to set.
@return _STATUS: Returns _OK if the function has done his job correctly.
*/

_STATUS link_set_state(Link* link, STATE state);

/**
@brief link_get_state
This function gets the state field of a Link.
@date 04-11-2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose state we want to get.
@return STATE: The state of the Link.
*/

STATE link_get_state(Link* link);

/**
@brief link_is_open
Checks if the link is open or not.
@date 13-11-2016 
@author Alejandro Sanchez
@param Link *link: the link to check.
@return _BOOL: _TRUE is the link is open or _FALSE if not.
*/

_BOOL link_is_open(Link *link);

/**
@brief link_print
This function prints Links.
@date 04-11-2016
@author Ricardo Riol
@param Link* link: Pointer to the Link whose state we want to get.
@return _STATUS
*/

_STATUS link_print(Link* link);

#endif
