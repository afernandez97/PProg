/* ===================================================================
   File: space.h
   Version: 4.1
   Date: 18-11-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
		It defines a space.

   Revision history:
		Sept. 23, 2016  Version 1.0 (initial release)
    Sept. 30, 2016  Version 2.0 
      Commented the file.
    Oct.  07, 2016   Version 2.1
      Changed "space_get_object" and "space_set_object" after creating 
      ADT Object.
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
		Nov. 18, 2016	 Version 4.1
			Added field "desc" to the structure "Space".
			Created "space_set_desc" and "space_get_desc".
   =================================================================== */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

/*** Data structures definition ***/
typedef struct _Space Space;

/*** Constant values description ***/
#define MAX_SPACES 100


/*** Public functions description ***/
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
Space * space_create(Id id);



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
STATUS space_destroy(Space *space);



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
Id space_get_id(Space *space);



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
STATUS space_set_name(Space *space, char *name);



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
const char* space_get_name(Space *space);



/* --------------------------------------------------------------------
   Function: space_set_north
   Date: 11-11-2016 
   Author: Guillermo Rodriguez

   Description:
		Sets the North link to a space.

   Input: 
		Space *space: the space where you want to change the North link.
		Id id: the new North link you want for the space.

   Output: 
		STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_north(Space *space, Id id);



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
Id space_get_north(Space *space);



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
STATUS space_set_south(Space *space, Id id);



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
Id space_get_south(Space *space);



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
STATUS space_set_east(Space *space, Id id);



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
Id space_get_east(Space *space);



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
STATUS space_set_west(Space *space, Id id);



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
Id space_get_west(Space *space);



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
STATUS space_add_object(Space *space, Id object);



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
STATUS space_del_object(Space *space, Id object);



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
Set* space_get_object(Space *space);



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
BOOL space_is_object(Space *space, Id object);



/* --------------------------------------------------------------------
   Function: space_set_desc
   Date: 18-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Sets the description of the space.

   Input: 
    Space *space: the space you want to change its description.
    char *desc: the new description of the space.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS space_set_desc(Space *space, char *desc);



/* --------------------------------------------------------------------
   Function: space_get_desc
   Date: 18-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the information of the description of the space.

   Input: 
    Space *space: the space you want to know its description.

   Output: 
    char *: the description of the space or NULL on error.
 -------------------------------------------------------------------- */
char *space_get_desc(Space *space);



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
STATUS space_set_gdesc(Space *space, char *gdesc);



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
char * space_get_gdesc(Space *space);



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
STATUS space_print_gdesc(Space *space);



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
STATUS space_print(Space *space);


#endif
