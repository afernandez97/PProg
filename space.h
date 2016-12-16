/**
   @file space.h
   @version 5.0
   @date 01-12-2016 
   @author Guillermo Rodriguez and Alejandro Sanchez
 
   @brief 
    It implements a space.
 
   @version
    Sept. 23, 2016  Version 1.0 (initial release)
    @version Sept. 30, 2016  Version 2.0 
      Commented the file and added macros for each structure field.
    @version Oct.  07, 2016  Version 2.1
      Changed structure field "object" after creating ADT Object.
    @version Oct. 25, 2016  Version 3.0
      Changed "objects" field to Set *.
      Modified the functions that were affected by this field. 
    @version Oct. 28, 2016  Version 3.1
      Changed "space_set_object" to "space_add_object".
      Created function "space_del_object".  
    @version Oct. 29, 2016   Version 3.2
      Added field "gdesc" to the structure "Space".
      Modified the functions that are affected by this field.
      Created "space_set_gdesc" and "space_get_gdesc". 
    @version Nov. 11, 2016   Version 4.0
      Changed the sense of some fields of the structure. The coordinates
      are changed to links. 
     @version  Nov. 18, 2016	 Version 4.1
			Added field "desc" to the structure "Space".
			Created "space_set_desc" and "space_get_desc".
     @version  Dec. 01, 2016	 Version 5.0
			Added fields "illuminated", "up" and "down" to the structure "Space".
			Created "space_set_up", "space_get_up", "space_set_down", "space_get_down",
			"space_set_illumination" and "space_is_illuminated" and modified the 
			functions affected by this changes.
   */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"
#include "game_rules.h"

/**
@def Constant values description
*/
#define MAX_SPACES 100

/*!< Data structures definition */
typedef struct _Space Space;



/*!< Public functions description */

/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief Creates a space. space_create()
 
   @param 
    Id id: the id of the space that is created.
   @return 
    Space *: the space created or NULL on error.
  */
Space * space_create(Id id);



/**
   @date 29-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Destroys a space. space_destroy()
 
   @param 
    Space *space: the space to destroy.
   @return 
    _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS space_destroy(Space *space);


/**
   @date 29-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Returns a space's id. space_get_id()
 
   @param 
    Space *space: the space which you want the id of.
   @return 
    Id: the space's id or NO_ID on error.
   */
Id space_get_id(Space *space);


/**
   @date 29-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Renames a space. space_set_name()
 
   @param Space *space: the space you want to rename.
   @param char *name: the new name you want for the space.
   
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_name(Space *space, char *name);



/**
   @date 29-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Gives the information of the name of the space. space_get_name()
 
   @param 
    Space *space: the space you want to know the name.
 
   @return 
    const char *: the name of the space or NULL on error.
   */
const char* space_get_name(Space *space);



/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Sets the North link to a space.space_set_north()
 
   @param Space *space: the space where you want to change the North link.
   @param Id id: the new North link you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_north(Space *space, Id id);



/**
   @date 11-11-2016  
   @author Alejandro Sanchez
 
   @brief 
    Gives the information of the North link of the space. space_get_north()
 
   @param 
    Space *space: the space you want to know the North link.
 
   @return 
    Id: the North link of the space or NO_ID on error. 
   */
Id space_get_north(Space *space);


/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the South link to a space. space_set_south()
 
   @param Space *space: the space where you want to change the South link.
   @param Id id: the new South link you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_south(Space *space, Id id);



/**
   @date 11-11-2016  
   @author Alejandro Sanchez
 
   @brief
    Gives the information of the South link of the space. space_get_south()
 
   @param 
    Space *space: the space you want to know the South link.
 
   @return 
    Id: the South link of the space or NO_ID on error.
   */
Id space_get_south(Space *space);



/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the East link to a space. space_set_east()
 
   @param Space *space: the space where you want to change the East link.
   @param Id id: the new East link you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_east(Space *space, Id id);



 
/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief 
    Gives the information of the East link of the space. space_get_east()
 
   @param 
    Space *space: the space you want to know the East link.
 
   @return 
    Id: the East link of the space or NO_ID on error.
   */
Id space_get_east(Space *space);



/*
   Function: space_set_west
   Date: 11-11-2016 
   Author: Alejandro Sanchez

   Description:
		Set the West link to a space.

   Input: 
		Space *space: the space where you want to change the West link.
		Id id: the new West link you want for the space.

   Output: 
		_STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_west(Space *space, Id id);



/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the West link to a space.  space_set_west()
 
   @param Space *space: the space where you want to change the West link.
   @param Id id: the new West link you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
Id space_get_west(Space *space);


/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the Up link to a space. space_set_up()
 
   @param Space *space: the space where you want to change the Up link.
   @param Id id: the new Up link you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_up(Space *space, Id id);
 
 
 
/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief 
    Gives the information of the Up link of the space.space_get_up()
 
   @param 
    Space *space: the space you want to know the Up link.
 
   @return 
    Id: the Up link of the space or NO_ID on error.
   */
Id space_get_up(Space *space);
 
 
/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the Down link to a space. space_set_down()
 
   @param Space *space: the space where you want to change the Down link.
   @param Id id: the new Down link you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_down(Space *space, Id id);
 
 
 
/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief 
    Gives the information of the Down link of the space.space_get_down()
 
   @param 
    Space *space: the space you want to know the Down link.
 
   @return 
    Id: the Down link of the space or NO_ID on error.
   */
Id space_get_down(Space *space);

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief
    Set the rule to a space. space_set_rule()
 
   @param Space *space: the space where you want to change the rule.
   @param Id id: the new rule you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_rule(Space *space, Id id);
 
 
 
/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Gives the information of the rule of the space.space_get_rule()
 
   @param 
    Space *space: the space you want to know the rule.
 
   @return 
    Id: the rule of the space or NO_ID on error.
   */
Id space_get_rule(Space *space);
 
/**
   @date 25-10-2016 
   @author Alejandro Sanchez
 
   @brief 
    Adds an object to the space. space_add_object()
 
   @param Space *space: the space you want to change.
   @param Id object: the identifier of the object you want to put 
      into the space.
   
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS space_add_object(Space *space, Id object);

   

/**
 
   @date 28-10-2016 
   @author Alejandro Sanchez
 
   @brief 
    Deletes an object to the space.space_del_object()
 
   @param Space *space: the space you want to change. space_del_object()
   @param Id object: the identifier of the object you want to remove 
      from the space.
   
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_del_object(Space *space, Id object);


/**
   @date 25-10-2016 
   @author Guillermo Rodriguez
 
   @brief
    Gives the set of objects that is in the space.space_get_object()
 
   @param 
    Space *space: the space where is the object you want to know its id.
   
   @return 
    Set *: the set of objects there are in the space or NULL 
      on error.
   */
Set* space_get_object(Space *space);




/**
   @date 25-10-2016 
   @author Guillermo Rodriguez 
  
   @brief 
    Checks if there is an especific object in the space.space_is_object()
  
   @param 
    Space *space: the space where you want to find the object.
    Id object: the id of the object you want to know if it is in the space.
                 
   @return 
    _BOOL: _TRUE if the object is in the space and _FALSE in other cases. 
   */
_BOOL space_is_object(Space *space, Id object);



/**
   @date 18-11-2016 
   @author Alejandro Sanchez

   @brief 
    Sets the description of the space.space_set_desc()

   @param Space *space: the space you want to change its description.
   @param char *desc: the new description of the space.

   Output: 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_desc(Space *space, char *desc);



/**
   @date 18-11-2016 
   @author Alejandro Sanchez

   @brief 
    Gives the information of the description of the space. space_get_desc()

   @param 
    Space *space: the space you want to know its description.

   @return 
    char *: the description of the space or NULL on error.
 */
char *space_get_desc(Space *space);



/**
   @date 29-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the graphic description of the space. space_set_gdesc()

   @param Space *space: the space you want to change its graphic description.
    char *gdesc: the new graphic description of the space.
  
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_gdesc(Space *space, char *gdesc);




/**
   @date 29-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the graphic description of the space.space_get_gdesc()

   @param
    Space *space: the space you want to know its graphic description.

   @return 
    char *: the graphic description of the space or NULL on error.
 */
char * space_get_gdesc(Space *space);


/**
   @date 29-10-2016 
   @author Alejandro Sanchez

   @brief 
   Prints the graphic description of the space in a string. space_print_gdesc()

   @param 
    Space *space: the space you want to print its graphic description.
    char *output: string in which the gdesc is printed.
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_print_gdesc(Space *space, char *output);


/**

   @date 01-12-2016 
   @author Guillermo Rodriguez 
 
   @brief 
    Sets if a space is illuminated or not.space_set_illumination()

   @param 
    Space *space: the space you want to change.
    _BOOL illumination : Choose if the space is illuminated or not.
   @return 
    _STATUS: _ERROR if the input is NULL and _OK otherwise.

   */
_STATUS space_set_illumination(Space *space, _BOOL illumination);


/**
   @date 01-12-2016 
   @author Guillermo Rodriguez 
 
   @brief 
    Gets if a space is illuminated or not.space_is_illuminated() 
 
   @param 
    Space *space: the space you want to know that.
   @return 
    _BOOL: the illumination of the space or _FALSE if the input is NULL.
   */
_BOOL space_is_illuminated(Space *space);


/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief 
    Prints a space on the screen.space_print()
 
   @param 
    Space *space: the space you want to print.
   @return 
    _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS space_print(Space *space);


#endif
