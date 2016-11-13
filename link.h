/* ===================================================================
File: link.h
Version: 1.0
Date: Nov. 4, 2016
Authors: Adrián Fernández, Ricardo Riol

Description:
	Contains the implementation of the functions associated to the
	Link data type.
Revision history:
	Nov. 4, 2016: Version 1.0 (initial release)
=================================================================== */

#ifndef LINK_H
#define LINK_H

#include "space.h"

typedef _Link Link;

typedef enum {	
  NO_STATE=-1, OPEN, CLOSED
} STATE;

/* --------------------------------------------------------------------
Function: link_create
Date: Nov. 4, 2016
Author: Alejandro Sanchez

Description: 
	This function creates a variable of type Link.
Input: 
	Id id: the id of the link.
Output:
	Link *: the link created or NULL on error.
------------------------------------------------------------------- */
Link * link_create(Id id);

/* --------------------------------------------------------------------
Function: link_destroy
Date: Nov. 4, 2016
Author: Adrián Fernández
 
Description:
	This function destroys a variable of type Link.
Input:
	Link* link: Pointer to the variable that is going to destroy.
Output:
	STATUS: Returns OK if the function has done his job correctly.
------------------------------------------------------------------- */
STATUS link_destroy(Link* link);

/* --------------------------------------------------------------------
Function: link_get_id
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function gets the id field of a Link.
Input:
	Link* link: Pointer to the Link whose id we want to get.
Output:
	Id: The id of the Link.
------------------------------------------------------------------- */
Id link_get_id(Link* link);

/* --------------------------------------------------------------------
Function: link_set_name
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function sets the name field of a Link.
Input:
	Link* link: Pointer to the Link whose name we want to set.
	char* name: The name we want to set.
Output:
	STATUS: Returns OK if the function has done his job correctly.
------------------------------------------------------------------- */
STATUS link_set_name(Link* link, char* name);

/* --------------------------------------------------------------------
Function: link_get_name
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function gets the name field of a Link.
Input:
	Link* link: Pointer to the Link whose name we want to get.
Output:
	char*: The name of the Link.
------------------------------------------------------------------- */
char* link_get_name(Link* link);

/* --------------------------------------------------------------------
Function: link_set_space1
Date: Nov. 4, 2016
Author: Alejandro Sanchez

Description:
	Sets the Id of a Link's first Space. 
Input:
	Link *link: the link whose first space you want to set.
	Id space1: the id of the space you want to be link's first space.
Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
------------------------------------------------------------------- */
STATUS link_set_space1(Link *link, Id space1);

/* --------------------------------------------------------------------
Function: link_get_space1
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function gets the Id of a Link's first Space. 
Input:
	Link* link: Pointer to the Link whose first Space we want to get.
Output:
	Id: The Id of the first Space.
------------------------------------------------------------------- */
Id link_get_space1(Link* link);

/* --------------------------------------------------------------------
Function: link_set_space2
Date: Nov. 4, 2016
Author: Alejandro Sanchez

Description:
	Sets the Id of a Link's second Space. 
Input:
	Link *link: the link whose second space you want to set.
	Id space2: the id of the space you want to be link's second space.
Output:
    STATUS: OK if you do the operation well and ERROR in other cases.
------------------------------------------------------------------- */
STATUS link_set_space2(Link *link, Id space2);

/* --------------------------------------------------------------------
Function: link_get_space2
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function gets the Id of a Link's second Space. 
Input:
	Link* link: Pointer to the Link whose second Space we want to get.
Output:
	Id: The Id of the second Space.
------------------------------------------------------------------- */
Id link_get_space2(Link* link);

/* --------------------------------------------------------------------
Function: link_set_state
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function sets the state field of a Link.
Input:
	Link* link: Pointer to the Link whose state we want to set.
	STATE state: The state we want to set.
Output:
	STATUS: Returns OK if the function has done his job correctly.
------------------------------------------------------------------- */
STATUS link_set_state(Link* link, STATE state);

/* --------------------------------------------------------------------
Function: link_get_state
Date: Nov. 4, 2016
Author: Adrián Fernández

Description:
	This function gets the state field of a Link.
Input:
	Link* link: Pointer to the Link whose state we want to get.
Output:
	STATE: The state of the Link.
------------------------------------------------------------------- */
STATE link_get_state(Link* link);

/* --------------------------------------------------------------------
   Function: link_is_open
   Date: 13-11-2016 
   Author: Alejandro Sanchez
  
   Description: 
    Checks if the link is open or not.
  
   Input: 
    Link *link: the link to check.
                 
   Output: 
    BOOL: TRUE is the link is open or FALSE if not.
   -------------------------------------------------------------------- */
BOOL link_is_open(Link *link);

/* --------------------------------------------------------------------
Function: link_print
Date: Nov. 4, 2016
Author: Ricardo Riol

Description:
	This function prints Links.
Input:
	Link* link: Pointer to the Link whose state we want to get.
Output:
	STATUS
------------------------------------------------------------------- */
STATUS link_print(Link* link);

#endif
