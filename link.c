/* ===================================================================
File: link.c
Version: 1.0
Date: 04-11-2016
Authors: Adrian Fernández, Ricardo Riol

Description:
	It implements a link.
Revision history:
	Nov. 4, 2016: Version 1.0 (initial release)
=================================================================== */

#include "link.h"

#define id(X) X->id
#define name(X) X->name
#define space1(X) X->space1
#define space2(X) X->space2
#define state(X) X->state

struct _Link{
	Id id;
	char name[MAX_CHAR];
	Id space1;
	Id space2;
	STATE state;
};

/* --------------------------------------------------------------------
Function: link_create
Date: Nov. 4, 2016
Author: Adrian Fernández

Description: 
	This function creates a variable of type Link.
Input: 
	Id id: the id of the link.
Output:
	Link *: the link created or NULL on error.
------------------------------------------------------------------- */
Link * link_create(Id id){

	Link *link = NULL;

	if(id == NO_ID){
		return NULL;
	}

	link = (Link *)malloc(sizeof(Link));
	if(!link){
		return NULL;
	}

	id(link) = id;
	name(link) = "";
	space1(link) = NO_ID;
	space2(link) = NO_ID;
	state(link) = NO_STATE;

	return link;
}

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
STATUS link_destroy(Link* link){
	
	if(link==NULL){
		return ERROR;
	}

	free(link);

	return OK;
}

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
Id link_get_id(Link* link){
	
	if(link==NULL){
		return NO_ID;
	}

	return id(link);
}

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
STATUS link_set_name(Link* link, char* name){

	if(link==NULL || name==NULL){
		return ERROR;
	}

	if(strcpy(name(link), name)==NULL){
		return ERROR;
	}
	
	return OK;
}

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
char* link_get_name(Link* link){

	if(link==NULL){
		return NULL;
	}

	return name(link);
}

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
STATUS link_set_space1(Link *link, Id space1){
	if(!link || space1 == NO_ID){
		return ERROR;
	}
	
	space1(link) = space1;
	
	return OK;
}

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
Id link_get_space1(Link* link){

	if(link==NULL){
		return NO_ID;
	}

	return space1(link);
}


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
STATUS link_set_space2(Link *link, Id space2){
	if(!link || space2 == NO_ID){
		return ERROR;
	}
	
	space2(link) = space2;
	
	return OK;
}


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
Id link_get_space2(Link* link){

	if(link==NULL){
		return NO_ID;
	}

	return space2(link)
}

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
STATUS link_set_state(Link* link, STATE state){

	if(link==NULL){
		return ERROR;
	}

	state(link) = state;

	return OK;
}

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
STATE link_get_state(Link* link){

	if(link==NULL){
		return NO_STATE;
	}

	return state(link);	
}

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
STATUS link_print(Link* link){

	if (!link){
		return ERROR;
	}

	if(state(link)==NO_STATE){
		fprintf (stdout, "Link: %ld, %s, %ld, %ld, NO_STATE", id(link), name(link), space1(link), space2(link));
	}else if(state(link)==OPEN){
		fprintf (stdout, "Link: %ld, %s, %ld, %ld, OPEN", id(link), name(link), space1(link), space2(link));
	} else if(state(link)==CLOSED){
		fprintf (stdout, "Link: %ld, %s, %ld, %ld, CLOSED", id(link), name(link), space1(link), space2(link));
	}
	return OK;
}	
