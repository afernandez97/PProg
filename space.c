/* ===================================================================
   File: space.c
   Version: 4.0
   Date: 11-11-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez
 
   Description: 
    It implements a space.
 
   Revision history:
    Sept. 23, 2016  Version 1.0 (initial release)
    Sept. 30, 2016  Version 2.0 
      Commented the file and added macros for each structure field.
    Oct.  07, 2016  Version 2.1
      Changed structure field "object" after creating ADT Object.
    Oct. 25, 2016  Version 3.0
      Changed "objects" field to Set *.
      Modified the functions that were affected by this field. 
    Oct. 28, 2016  Version 3.1
      Changed "space_set_object" to "space_add_object".
      Created function "space_del_object".  
    Oct. 29, 2016   Version 3.2
      Added field "gdesc" to the structure "Space".
      Modified the functions that are affected by this field.
      Created "space_set_gdesc" and "space_get_gdesc". 
    Nov. 11, 2016   Version 4.0
      Changed the sense of some fields of the structure. The coordinates
      are changed to links. 
   =================================================================== */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

/*** Constant values description ***/
#define id(X) (X)->id
#define name(X) (X)->name
#define north(X) (X)->north
#define south(X) (X)->south
#define east(X) (X)->east
#define west(X) (X)->west
#define objects(X) (X)->objects
#define gdesc(X) (X)->gdesc

 
/*** The Space structure stores information of the different spaces that there are in the game ***/
struct _Space{
  Id id; /* Identifier of the space */
  char name[WORD_SIZE + 1]; /* Name of the space */
  Id north; /* North link of the space */
  Id south; /* South link of the space */
  Id east;  /* East link of the space */
  Id west;  /* West link of the space */
  Set *objects; /*  Set of the objects,there are in the space */
  char gdesc[WORD_SIZE +1]; /* Graphic description of the space */
};
 
 
/*** Public functions definition ***/
/* --------------------------------------------------------------------
   Function: space_create
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Creates a space.
 
   Input: 
    Id id: the id of the space that is created.
   Output: 
    Space *: the space created or NULL on error.
   -------------------------------------------------------------------- */
Space * space_create(Id id){
  Space *space = NULL;
 
  if(id == NO_ID){       /* Check that the input is not empty */
    return NULL;
  }
 
  space = (Space *)malloc(sizeof(Space));
  if(!space){  /* Check if memory has been allocated */
    return NULL;
  }    
     
 
  /* Initialize structure fields */
  id(space) = id;
 
  name(space)[0] = '\0';

  north(space) = NO_ID;
  south(space) = NO_ID;
  east(space) = NO_ID;
  west(space) = NO_ID;

  objects(space) = set_create();
  if(!objects(space)){  /* Check if memory has been allocated */
	  free(space);
    return NULL;
	}

  gdesc(space)[0] = '\0';
 
  return space;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_destroy
   Date: 29-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Destroys a space.
 
   Input: 
    Space *space: the space to destroy.
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS space_destroy(Space *space){
  if(!space){         /* Check that the input is not empty */
    return ERROR;
  }

	if(objects(space) != NULL){
  	set_destroy(objects(space));  /* Destroy the set of objects */
	}  

	free(space);      /* Eliminate the memory of the space */      
  
  return OK;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_get_id
   Date: 29-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Returns a space's id.
 
   Input: 
    Space *space: the space which you want the id of.
   Output: 
    Id: the space's id or NO_ID on error.
   -------------------------------------------------------------------- */
Id space_get_id(Space *space){
  if(!space){       /* Check that the input is not empty */
    return NO_ID;
  }
 
  return id(space);
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_set_name
   Date: 29-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Renames a space.
 
   Input: 
    Space *space: the space you want to rename.
    char *name: the new name you want for the space.
   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_name(Space *space, char *name){
  if(!space || !name){          /* Check that the inputs are not empty */
    return ERROR;
  }
 
  /* Set the name and check if it has worked */
  if(!strcpy(name(space), name)){   
    return ERROR;
  }
 
  return OK;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_get_name
   Date: 29-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Gives the information of the name of the space.
 
   Input: 
    Space *space: the space you want to know the name.
 
   Output: 
    const char *: the name of the space or NULL on error.
   -------------------------------------------------------------------- */
const char * space_get_name(Space *space){
  if(!space){                    /* Check that the input is not empty */
    return NULL;
  }
 
  return name(space);                
}
 
 

/* --------------------------------------------------------------------
   Function: space_set_north
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description:
    Sets the North link to a space.
 
   Input: 
    Space *space: the space where you want to change the North link.
    Id id: the new North link you want for the space.
 
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_north(Space *space, Id id){
  if(!space){       /* Check that the inputs are not empty */
    return ERROR;
  }
 
  north(space) = id;          /* Set the North link to the space */
  return OK;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_get_north
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Gives the information of the North link of the space.
 
   Input: 
    Space *space: the space you want to know the North link.
 
   Output: 
    Id: the North link of the space or NO_ID on error. 
   -------------------------------------------------------------------- */
Id space_get_north(Space *space){
  if(!space){                   /* Check that the input is not empty */
    return NO_ID;
  }
 
  return north(space);
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_set_south
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description:
    Set the South link to a space.
 
   Input: 
    Space *space: the space where you want to change the South link.
    Id id: the new South link you want for the space.
 
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_south(Space *space, Id id){
  if(!space){     /* Check that the inputs are not empty */
    return ERROR;
  }
 
  south(space) = id;        /* Set the South link to the space */
  return OK;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_get_south
   Date: 11-11-2016  
   Author: Alejandro Sanchez
 
   Description: 
    Gives the information of the South link of the space.
 
   Input: 
    Space *space: the space you want to know the South link.
 
   Output: 
    Id: the South link of the space or NO_ID on error.
   -------------------------------------------------------------------- */
Id space_get_south(Space *space){
  if(!space){                   /* Check that the input is not empty */
    return NO_ID;
  }
 
  return south(space);
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_set_east
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description:
    Set the East link to a space. 
 
   Input: 
    Space *space: the space where you want to change the East link.
    Id id: the new East link you want for the space.
 
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_east(Space *space, Id id){
  if(!space){             /* Check that the inputs are not empty */
    return ERROR;
  }
 
  east(space) = id;          /* Set the East link to the space */
  return OK;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_get_east
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Gives the information of the East link of the space.
 
   Input: 
    Space *space: the space you want to know the East link.
 
   Output: 
    Id: the East link of the space or NO_ID on error.
   -------------------------------------------------------------------- */
Id space_get_east(Space *space){
  if(!space){                    /* Check that the input is not empty */
    return NO_ID;
  }
 
  return east(space);
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_set_west
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description:
    Set the West link to a space.
 
   Input: 
    Space *space: the space where you want to change the West link.
    Id id: the new West link you want for the space.
 
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_west(Space *space, Id id){
  if(!space){             /* Check that the inputs are not empty */
    return ERROR;
  }
 
  west(space) = id;          /* Set the West link to the space */
  return OK;
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_get_west
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Gives the information of the West link of the space.
 
   Input: 
    Space *space: the space you want to know the West link.
 
   Output: 
    Id: the West link of the space or NO_ID on error.
   -------------------------------------------------------------------- */
Id space_get_west(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return west(space);
}
 
 
 
/* --------------------------------------------------------------------
   Function: space_add_object
   Date: 25-10-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Adds an object to the space.
 
   Input: 
    Space *space: the space you want to change.
    Id object: the identifier of the object you want to put 
      into the space.
   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_add_object(Space *space, Id object){
  if(!space || object == NO_ID){  /* Check that the inputs are not empty */
    return ERROR;
  }
 
  /* Add the object into the space */ 
  if(set_add(objects(space), object) == ERROR){
	  return ERROR;
  }      

  return OK;
}
 


/* --------------------------------------------------------------------
   Function: space_del_object
   Date: 28-10-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Deletes an object to the space.
 
   Input: 
    Space *space: the space you want to change.
    Id object: the identifier of the object you want to remove 
      from the space.
   
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_del_object(Space *space, Id object){
  if(!space || object == NO_ID){  /* Check that the inputs are not empty */
    return ERROR;
  }
 
  /* Removes the object from the space */
  if(set_del(objects(space), object) == ERROR){
    return ERROR;
  }      

  return OK;
}

 
 
/* --------------------------------------------------------------------
   Function: space_get_object
   Date: 25-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Gives the set of objects that is in the space.
 
   Input: 
    Space *space: the space where is the object you want to know its id.
   
   Output: 
    Set *: the set of objects there are in the space or NULL 
      on error.
   -------------------------------------------------------------------- */
Set * space_get_object(Space *space){
  if(!space){              /* Check that the input is not empty */
    return NULL;
  }
 
  return objects(space);
}
 


/* --------------------------------------------------------------------
   Function: space_is_object
   Date: 25-10-2016 
   Author: Guillermo Rodriguez 
  
   Description: 
    Checks if there is an especific object in the space.
  
   Input: 
    Space *space: the space where you want to find the object.
    Id object: the id of the object you want to know if it is in the space.
                 
   Output: 
    BOOL: TRUE if the object is in the space and FALSE in other cases. 
   -------------------------------------------------------------------- */
BOOL space_is_object(Space *space, Id object){
	if(!space || object == NO_ID){
    	return FALSE;
	}
  return set_is_object(objects(space), object);	
}



/* --------------------------------------------------------------------
   Function: space_set_gdesc
   Date: 29-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Sets de graphic description of the space.

   Input: 
    Space *space: the space you want to change its graphic description.
    char *gdesc: the new graphic description of the space.
  
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_gdesc(Space *space, char *gdesc){
  if(!space || !gdesc){   /* Check if the inputs are not empty */
    return ERROR;
  }

  /* Set the graphic description and check if it has worked */
  if(!strcpy(gdesc(space), gdesc)){
    return ERROR;
  }  
  
  return OK;
}



/* --------------------------------------------------------------------
   Function: space_get_gdesc
   Date: 29-10-2016 
   Author: Guillermo Rodriguez

   Description: 
    Gives the information of the graphic description of the space.

   Input: 
    Space *space: the space you want to know its graphic description.

   Output: 
    char *: the graphic description of the space or NULL on error.
 -------------------------------------------------------------------- */
char *space_get_gdesc(Space *space){
  if(!space){  /* Check that the input is not empty */
   return NULL;
  }

  return gdesc(space); 
}   



/* --------------------------------------------------------------------
   Function: space_print_gdesc
   Date: 29-10-2016 
   Author: Alejandro Sanchez

   Description: 
		Prints the graphic description of the space.

   Input: 
		Space *space: the space you want to print its graphic description.
   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_print_gdesc(Space *space){
  char gdesc[WORD_SIZE] = "", *toks = NULL;
 
  /* Check if the input is empty or the graphic description is empty */
  if(!space || strcmp(gdesc(space), "\0") == 0){
  	return ERROR;
  }

  /* Copy the graphic description in an auxiliar array */
  if(!strcpy(gdesc, gdesc(space))){
  	return ERROR;
  }

  /* "Tokenize" the graphic description and print it */
	toks = strtok(gdesc, "|");
  while(toks != NULL){
		fprintf(stdout, " | %s   |\n", toks);
		toks = strtok(NULL, "|");
  }

  return OK;
}



/* --------------------------------------------------------------------
   Function: space_print
   Date: 11-11-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Prints a space on the screen.
 
   Input: 
    Space *space: the space you want to print.
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS space_print(Space *space){
  Id idaux = NO_ID;
   
  if(!space){                   /* Check that the input is not empty */
    return ERROR;
  }
 
  /* Print each field of the Space structure, checking if it is empty */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", 
    id(space), name(space));
     
  idaux = space_get_north(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No north link.\n");
  }
     
  idaux = space_get_south(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No south link.\n");
  }
     
  idaux = space_get_east(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No east link.\n");
  }
     
  idaux = space_get_west(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No west link.\n");
      fprintf(stdout, "---> No west link.\n");
  }

  if(set_is_empty(objects(space)) == TRUE){
    fprintf(stdout, "---> No objects.\n");
  }   
  if(set_print(objects(space)) == ERROR){
    return ERROR;
  }

  if(space_print_gdesc(space) == ERROR){
    return ERROR;
  }
 
  return OK;
}

