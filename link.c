/**
@File link.c
@brief It implements a link.
@version 1.0
@date 04-11-2016
@Author Adrian Fernández, Ricardo Riol
@version Nov. 4, 2016: Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

#define id(X) X->id
#define name(X) X->name
#define space1(X) X->space1
#define space2(X) X->space2
#define state(X) X->state

/**
@brief Link structure
The Link structure stores information of the liks between spaces.
*/

struct _Link{
	Id id;	/*!< Link's id */
	char name[WORD_SIZE + 1]; /*!< Link's name */
	Id space1; /*!< One space's id that is linked with the link*/
	Id space2; /*!< The other space's id that is linked with the link*/
	STATE state; /*!< Link's state*/
};

/**
@brief link_create
This function creates a variable of type Link.
@date Nov. 4, 2016
@author Adrian Fernández
@param Id id: the id of the link.
@return Link *: the link created or NULL on error.
*/
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
	name(link)[0] = '\0';
	space1(link) = NO_ID;
	space2(link) = NO_ID;
	state(link) = NO_STATE;

	return link;
}

/**
@brief link_destroy
This function destroys a variable of type Link.
@date Nov. 4, 2016
@author Adrián Fernández
@param Link* link: Pointer to the variable that is going to destroy.
@return STATUS: Returns OK if the function has done his job correctly.
*/
STATUS link_destroy(Link* link){
	
	if(link==NULL){
		return ERROR;
	}

	free(link);

	return OK;
}

/**
@brief link_get_id
This function gets the id field of a Link.
@date Nov. 4, 2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose id we want to get.
@return Id: The id of the Link.
*/
Id link_get_id(Link* link){
	
	if(link==NULL){
		return NO_ID;
	}

	return id(link);
}

/**
@brief link_set_name
This function sets the name field of a Link.
@date Nov. 4, 2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose name we want to set.
@param char* name: The name we want to set.
@return STATUS: Returns OK if the function has done his job correctly.
*/
STATUS link_set_name(Link* link, char* name){

	if(link==NULL || name==NULL){
		return ERROR;
	}

	if(strcpy(name(link), name)==NULL){
		return ERROR;
	}
	
	return OK;
}

/**
@brief link_get_name
This function gets the name field of a Link.
@date Nov. 4, 2016
@author Adrián Fernández
@param Link* link: Pointer to the Link whose name we want to get.
@return char*: The name of the Link.
*/
char* link_get_name(Link* link){

	if(link==NULL){
		return NULL;
	}

	return name(link);
}

/**
@brief link_set_space1
@date Nov. 4, 2016
@author Alejandro Sanchez

Description:
	Sets the Id of a Link's first Space. 
@param
	Link *link: the link whose first space you want to set.
	Id space1: the id of the space you want to be link's first space.
@return
    STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS link_set_space1(Link *link, Id space1){
	if(!link || space1 == NO_ID){
		return ERROR;
	}
	
	space1(link) = space1;
	
	return OK;
}

/**
@brief link_get_space1
@date Nov. 4, 2016
@author Adrián Fernández

Description:
	This function gets the Id of a Link's first Space. 
@param
	Link* link: Pointer to the Link whose first Space we want to get.
@return
	Id: The Id of the first Space.
*/
Id link_get_space1(Link* link){

	if(link==NULL){
		return NO_ID;
	}

	return space1(link);
}


/**
@brief link_set_space2
@date Nov. 4, 2016
@author Alejandro Sanchez

Description:
	Sets the Id of a Link's second Space. 
@param
	Link *link: the link whose second space you want to set.
	Id space2: the id of the space you want to be link's second space.
@return
    STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS link_set_space2(Link *link, Id space2){
	if(!link || space2 == NO_ID){
		return ERROR;
	}
	
	space2(link) = space2;
	
	return OK;
}


/**
@brief link_get_space2
@date Nov. 4, 2016
@author Adrián Fernández

Description:
	This function gets the Id of a Link's second Space. 
@param
	Link* link: Pointer to the Link whose second Space we want to get.
@return
	Id: The Id of the second Space.
*/
Id link_get_space2(Link* link){

	if(link==NULL){
		return NO_ID;
	}

	return space2(link);
}

/**
@brief link_set_state
@date Nov. 4, 2016
@author Adrián Fernández

Description:
	This function sets the state field of a Link.
@param
	Link* link: Pointer to the Link whose state we want to set.
	STATE state: The state we want to set.
@return
	STATUS: Returns OK if the function has done his job correctly.
*/
STATUS link_set_state(Link* link, STATE state){

	if(link==NULL){
		return ERROR;
	}

	state(link) = state;

	return OK;
}

/**
@brief link_get_state
@date Nov. 4, 2016
@author Adrián Fernández

Description:
	This function gets the state field of a Link.
@param
	Link* link: Pointer to the Link whose state we want to get.
@return
	STATE: The state of the Link.
*/
STATE link_get_state(Link* link){

	if(link==NULL){
		return NO_STATE;
	}

	return state(link);	
}



/**
   @brief link_is_open
   @date 13-11-2016 
   @author Alejandro Sanchez
  
   Description: 
    Checks if the link is open or not.
  
   @param 
    Link *link: the link to check.
                 
   @return 
    BOOL: TRUE is the link is open or FALSE if not.
   -*/
BOOL link_is_open(Link *link){
	if(!link){
		return FALSE;
	}

	if(state(link) == OPEN){
		return TRUE;
	}

	return FALSE;
}



/**
@brief link_print
@date Nov. 4, 2016
@author Ricardo Riol

Description:
	This function prints Links.
@param
	Link* link: Pointer to the Link whose state we want to get.
@return
	STATUS
*/
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
