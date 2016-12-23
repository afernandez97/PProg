/**
   @file space.c
   @version 5.3
   @date 20-12-2016 
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
     @version  Dec. 12, 2016   Version 5.1
      Added field "rule" to the structure "Space".
      Created "space_set_rule" and "space_get_rule".
     @version  Dec. 16, 2016   Version 5.2
      Added fields "person" and "shop" to the structure "Space".
      Created "space_set_person", "space_get_person", "space_set_shop", "space_is_shop".
     @version  Dec. 20, 2016   Version 5.3
      Added field "exam" to the structure "Space".
      Created "space_set_exam", "space_get_exam".
	*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

/**
@def Constant values description 
*/
#define id(X) (X)->id
#define name(X) (X)->name
#define north(X) (X)->north
#define south(X) (X)->south
#define east(X) (X)->east
#define west(X) (X)->west
#define up(X) (X)->up
#define down(X) (X)->down
#define objects(X) (X)->objects
#define desc(X) (X)->desc
#define printdesc(X) (X)->printdesc
#define gdesc(X) (X)->gdesc
#define illuminated(X) (X)->illuminated
#define rule(X) (X)->rule
#define person(X) (X)->person
#define shop(X) (X)->shop 
#define exam(X) (X)->exam 

 
/** @brief The Space structure stores information of the different spaces that there are in the game */
struct _Space{
  Id id; /*!< Identifier of the space */
  char name[WORD_SIZE]; /* Name of the space */
  Id north; /*!< North link of the space */
  Id south; /*!< South link of the space */
  Id east;  /*!< East link of the space */
  Id west;  /*!< West link of the space */
	Id up;	/*!< Up link of the space */
	Id down;	/*!< Down link of the space */
	Id rule;     /*!< The rule of the space */
  Id person;     /*!< The person on the space */
  Set *objects; /*!<  Set of the objects,there are in the space */
	char desc[WORD_SIZE];	/*!< Description of the space */
  char gdesc[WORD_SIZE]; /*!< Graphic description of the space */
  BOOL_ illuminated; /*!< Illuminated or not */
  BOOL_ shop; /*!<If you can buy and sell objects in this space*/
  BOOL_ exam; /*!< Indicates if the exam is in that space or not */
  char printdesc[WORD_SIZE];
};
 
 
/*!< Public functions definition */
/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief Creates a space. space_create()
 
   @param 
    Id id: the id of the space that is created.
   @return 
    Space *: the space created or NULL on error.
  */
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
	up(space) = NO_ID;
  down(space) = NO_ID;
  rule(space) = NO_ID;  
  person(space) = NO_ID;

  objects(space) = set_create();
  if(!objects(space)){  /* Check if memory has been allocated */
	  free(space);
    return NULL;
	}

  strcpy(desc(space), "");
  strcpy(gdesc(space), "       |       |       |");
  illuminated(space) = FALSE_;
  shop(space) =FALSE_;
 
  return space;
}
 
 
 
/**
   @date 29-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Destroys a space. space_destroy()
 
   @param 
    Space *space: the space to destroy.
   @return 
    STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
   */
STATUS_ space_destroy(Space *space){
  if(!space){         /* Check that the input is not empty */
    return ERROR_;
  }

	if(objects(space) != NULL){
  	set_destroy(objects(space));  /* Destroy the set of objects */
	}  

	free(space);      /* Eliminate the memory of the space */      
  
  return OK_;
}
 
 
 
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
Id space_get_id(Space *space){
  if(!space){       /* Check that the input is not empty */
    return NO_ID;
  }
 
  return id(space);
}
 
 
 
/**
   @date 29-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Renames a space. space_set_name()
 
   @param Space *space: the space you want to rename.
   @param char *name: the new name you want for the space.
   
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_name(Space *space, char *name){
  if(!space || !name){          /* Check that the inputs are not empty */
    return ERROR_;
  }
 
  /* Set the name and check if it has worked */
  if(!strcpy(name(space), name)){   
    return ERROR_;
  }
 
  return OK_;
}
 
 
 
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
const char * space_get_name(Space *space){
  if(!space){                    /* Check that the input is not empty */
    return NULL;
  }
 
  return name(space);                
}
 
 

/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Sets the North link to a space.space_set_north()
 
   @param Space *space: the space where you want to change the North link.
   @param Id id: the new North link you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_north(Space *space, Id id){
  if(!space){       /* Check that the input is not empty */
    return ERROR_;
  }
 
  north(space) = id;          /* Set the North link to the space */
  return OK_;
}
 
 
 
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
Id space_get_north(Space *space){
  if(!space){                   /* Check that the input is not empty */
    return NO_ID;
  }
 
  return north(space);
}
 
 
 
/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the South link to a space. space_set_south()
 
   @param Space *space: the space where you want to change the South link.
   @param Id id: the new South link you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_south(Space *space, Id id){
  if(!space){     /* Check that the input is not empty */
    return ERROR_;
  }
 
  south(space) = id;        /* Set the South link to the space */
  return OK_;
}
 
 
 
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
Id space_get_south(Space *space){
  if(!space){                   /* Check that the input is not empty */
    return NO_ID;
  }
 
  return south(space);
}
 
 
 
/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the East link to a space. space_set_east()
 
   @param Space *space: the space where you want to change the East link.
   @param Id id: the new East link you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_east(Space *space, Id id){
  if(!space){             /* Check that the input is not empty */
    return ERROR_;
  }
 
  east(space) = id;          /* Set the East link to the space */
  return OK_;
}
 
 
 
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
Id space_get_east(Space *space){
  if(!space){                    /* Check that the input is not empty */
    return NO_ID;
  }
 
  return east(space);
}
 
 
 
/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the West link to a space.  space_set_west()
 
   @param Space *space: the space where you want to change the West link.
   @param Id id: the new West link you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_west(Space *space, Id id){
  if(!space){             /* Check that the input is not empty */
    return ERROR_;
  }
 
  west(space) = id;          /* Set the West link to the space */
  return OK_;
}
 
 
 
/**
   @date 11-11-2016 
   @author Alejandro Sanchez
 
   @brief 
    Gives the information of the West link of the space.space_get_west()
 
   @param 
    Space *space: the space you want to know the West link.
 
   @return 
    Id: the West link of the space or NO_ID on error.
   */
Id space_get_west(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return west(space);
}
 
/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the Up link to a space. space_set_up()
 
   @param Space *space: the space where you want to change the Up link.
   @param Id id: the new Up link you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_up(Space *space, Id id){
  if(!space){             /* Check that the input is not empty */
    return ERROR_;
  }
 
  up(space) = id;          /* Set the Up link to the space */
  return OK_;
}
 
 
 
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
Id space_get_up(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return up(space);
}
 
 
/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief
    Set the Down link to a space. space_set_down()
 
   @param Space *space: the space where you want to change the Down link.
   @param Id id: the new Down link you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_down(Space *space, Id id){
  if(!space){             /* Check that the input is not empty */
    return ERROR_;
  }
 
  down(space) = id;          /* Set the Down link to the space */
  return OK_;
}
 
 
 
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
Id space_get_down(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return down(space);
}

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief
    Set the rule to a space. space_set_rule()
 
   @param Space *space: the space where you want to change the rule.
   @param Id id: the new rule you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_rule(Space *space, Id id){
  if(!space){             /* Check that the input is not empty */
    return ERROR_;
  }
 
  rule(space) = id;          /* Set the rule to the space */
  return OK_;
}
 
 
 
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
Id space_get_rule(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return rule(space);
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief
    Set the person to a space. space_set_person()
 
   @param Space *space: the space where you want to change the person.
   @param Id id: the new person you want for the space.
 
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_person(Space *space, Id id){
  if(!space){             /* Check that the input is not empty */
    return ERROR_;
  }
 
  person(space) = id;          /* Set the rule to the space */
  return OK_;
}
 
 
 
/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Gives the information of the person of the space.space_get_person()
 
   @param 
    Space *space: the space you want to know the person.
 
   @return 
    Id: the person of the space or NO_ID on error.
   */
Id space_get_person(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return person(space);
}

/**
   @date 25-10-2016 
   @author Alejandro Sanchez
 
   @brief 
    Adds an object to the space. space_add_object()
 
   @param Space *space: the space you want to change.
   @param Id object: the identifier of the object you want to put 
      into the space.
   
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_add_object(Space *space, Id object){
  if(!space || object == NO_ID){  /* Check that the inputs are not empty */
    return ERROR_;
  }
 
  /* Add the object into the space */ 
  if(set_add(objects(space), object) == ERROR_){
	  return ERROR_;
  }      

  return OK_;
}
 


/**
 
   @date 28-10-2016 
   @author Alejandro Sanchez
 
   @brief 
    Deletes an object to the space.space_del_object()
 
   @param Space *space: the space you want to change. space_del_object()
   @param Id object: the identifier of the object you want to remove 
      from the space.
   
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_del_object(Space *space, Id object){
  if(!space || object == NO_ID){  /* Check that the inputs are not empty */
    return ERROR_;
  }
 
  /* Removes the object from the space */
  if(set_del(objects(space), object) == ERROR_){
    return ERROR_;
  }      

  return OK_;
}

 
 
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
Set * space_get_object(Space *space){
  if(!space){              /* Check that the input is not empty */
    return NULL;
  }
 
  return objects(space);
}
 


/**
   @date 25-10-2016 
   @author Guillermo Rodriguez 
  
   @brief 
    Checks if there is an especific object in the space.space_is_object()
  
   @param 
    Space *space: the space where you want to find the object.
    Id object: the id of the object you want to know if it is in the space.
                 
   @return 
    BOOL_: TRUE_ if the object is in the space and FALSE_ in other cases. 
   */
BOOL_ space_is_object(Space *space, Id object){
	if(!space || object == NO_ID){ /* Check if the inputs are not empty */
    	return FALSE_;
	}
  return set_is_object(objects(space), object);	
}


/**
   @date 18-11-2016 
   @author Alejandro Sanchez

   @brief 
    Sets the description of the space.space_set_desc()

   @param Space *space: the space you want to change its description.
   @param char *desc: the new description of the space.

   Output: 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_desc(Space *space, char *desc){
  if(!space || !desc){   /* Check if the inputs are not empty */
    return ERROR_;
  }

  /* Set the description and check if it has worked */
  if(!strcpy(desc(space), desc)){
    return ERROR_;
  }  
  
  return OK_;
}


STATUS_ space_set_printdesc(Space *space, char *printdesc){
  if(!space || !printdesc){   /* Check if the inputs are not empty */
    return ERROR_;
  }

  /* Set the description and check if it has worked */
  if(!strcpy(printdesc(space), printdesc)){
    return ERROR_;
  }  
  
  return OK_;
}



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
char *space_get_desc(Space *space){
  if(!space){  /* Check that the input is not empty */
   return NULL;
  }

  return desc(space); 
}


char *space_get_printdesc(Space *space){
  if(!space){  /* Check that the input is not empty */
   return NULL;
  }

  return printdesc(space); 
} 



/**
   @date 29-10-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the graphic description of the space. space_set_gdesc()

   @param Space *space: the space you want to change its graphic description.
    char *gdesc: the new graphic description of the space.
  
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_set_gdesc(Space *space, char *gdesc){
  if(!space || !gdesc){   /* Check if the inputs are not empty */
    return ERROR_;
  }

  /* Set the graphic description and check if it has worked */
  if(!strcpy(gdesc(space), gdesc)){
    return ERROR_;
  }  
  
  return OK_;
}



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
char *space_get_gdesc(Space *space){
  if(!space){  /* Check that the input is not empty */
   return NULL;
  }

  return gdesc(space); 
}   



/**
   @date 21-12-2016 
   @author Adrián Fernández

   @brief 
   Prints the graphic description of the space in a string. space_print_gdesc1()

   @param 
    Space *space: the space you want to print its graphic description.
    char *output: string in which the gdesc is printed.
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_print_gdesc1(Space *space, char *output){
  char gdesc[WORD_SIZE] = "", aux[WORD_SIZE] = "", *toks = NULL;
 
  /* Check if the input is empty or the graphic description is empty */
  if(!space || !strcmp(gdesc(space), "\0") || !output){
  	return ERROR_;
  }

  /* Copy the graphic description in an auxiliar array */
  if(!strcpy(gdesc, gdesc(space))){
  	return ERROR_;
  }

  /* Deletes the content of output */
  if(!strcpy(output, "")){
    return ERROR_;
  }

  /* "Tokenize" the graphic description and print it */
	toks = strtok(gdesc, "|");

	sprintf(aux, "| %s   |", toks);
  strcat(output, aux);
	
  return OK_;
}


/**
   @date 21-12-2016 
   @author Adrián Fernández

   @brief 
   Prints the graphic description of the space in a string. space_print_gdesc2()

   @param 
    Space *space: the space you want to print its graphic description.
    char *output: string in which the gdesc is printed.
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_print_gdesc2(Space *space, char *output){
  char gdesc[WORD_SIZE] = "", aux[WORD_SIZE] = "", *toks = NULL;
 
  /* Check if the input is empty or the graphic description is empty */
  if(!space || !strcmp(gdesc(space), "\0") || !output){
    return ERROR_;
  }

  /* Copy the graphic description in an auxiliar array */
  if(!strcpy(gdesc, gdesc(space))){
    return ERROR_;
  }

  /* Deletes the content of output */
  if(!strcpy(output, "")){
    return ERROR_;
  }

  /* "Tokenize" the graphic description and print it */
  toks = strtok(gdesc, "|");
  toks = strtok(NULL, "|");

  sprintf(aux, "| %s   |", toks);
  strcat(output, aux);
  
  return OK_;
}


/**
   @date 21-12-2016 
   @author Adrián Fernández

   @brief 
   Prints the graphic description of the space in a string. space_print_gdesc3()

   @param 
    Space *space: the space you want to print its graphic description.
    char *output: string in which the gdesc is printed.
   @return 
    STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ space_print_gdesc3(Space *space, char *output){
  char gdesc[WORD_SIZE] = "", aux[WORD_SIZE] = "", *toks = NULL;

  /* Check if the input is empty or the graphic description is empty */
  if(!space || !strcmp(gdesc(space), "\0") || !output){
    return ERROR_;
  }

  /* Copy the graphic description in an auxiliar array */
  if(!strcpy(gdesc, gdesc(space))){
    return ERROR_;
  }

  /* Deletes the content of output */
  if(!strcpy(output, "")){
    return ERROR_;
  }

  /* "Tokenize" the graphic description and print it */
  toks = strtok(gdesc, "|");
  toks = strtok(NULL, "|");
  toks = strtok(NULL, "|");

  sprintf(aux, "| %s   |", toks);
  strcat(output, aux);
  
  return OK_;
}


/**

   @date 01-12-2016 
   @author Guillermo Rodriguez 
 
   @brief 
    Sets if a space is illuminated or not.space_set_illumination()

   @param 
    Space *space: the space you want to change.
    BOOL_ illumination : Choose if the space is illuminated or not.
   @return 
    STATUS_: ERROR_ if the input is NULL and OK_ otherwise.

   */
STATUS_ space_set_illumination(Space *space, BOOL_ illumination){
	if(!space){
  	return ERROR_;
  }

  illuminated(space) = illumination;
  
	return OK_;
}

/**
   @date 01-12-2016 
   @author Guillermo Rodriguez 
 
   @brief 
    Gets if a space is illuminated or not.space_is_illuminated() 
 
   @param 
    Space *space: the space you want to know that.
   @return 
    BOOL_: the illumination of the space or FALSE_ if the input is NULL.
   */
BOOL_ space_is_illuminated(Space *space){
	if(!space){
  	return FALSE_;
  }
	return illuminated(space);
}


/**

   @date 16-12-2016 
   @author Guillermo Rodriguez 
 

   @brief 
    Sets if a space is a shop or not.space_set_shop()

   @param 
    Space *space: the space you want to change.
    BOOL_ shop : Choose if the space is a shop or not.

   @return 
    STATUS_: ERROR_ if the input is NULL and OK_ otherwise.

   */
STATUS_ space_set_shop(Space *space, BOOL_ shop){
	if(!space){
  	return ERROR_;
  }

  shop(space) = shop;
  
	return OK_;
}

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez 

 
   @brief 
    Gets if a space is a shop or not.space_is_shop() 
 
   @param 

    Space *space: the space you want to know that.
   @return 
    BOOL_: TRUE_ if the space is a shop or FALSE_ if the input is NULL.
   */
BOOL_ space_is_shop(Space *space){
	if(!space){
  	return FALSE_;
  }
	return shop(space);
}


/**

   @date 20-12-2016 
   @author Alejandro Sanchez 
 
   @brief 
    Sets if a space is where the exam will be done or not.space_set_exam()

   @param 
    Space *space: the space you want to change.
    BOOL_ exam: Choose if the space is where the exam will be or not.
   @return 
    STATUS_: ERROR_ if the input is NULL and OK_ otherwise.

   */
STATUS_ space_set_exam(Space *space, BOOL_ exam){
  if(!space){
    return ERROR_;
  }

  exam(space) = exam;
  
  return OK_;
}

/**
   @date 20-12-2016 
   @author Alejandro Sanchez 
 
   @brief 
    Gets if a space is where the exam will be done or not.space_is_exam() 
 
   @param 
    Space *space: the space you want to know that.
   @return 
    BOOL_: TRUE_ if the space will held the exam or FALSE_ if not or if the input is NULL.
   */
BOOL_ space_is_exam(Space *space){
  if(!space){
    return FALSE_;
  }
  return exam(space);
}

/**
   @date 20-12-2016 
   @author Alejandro Sanchez 
 
   @brief 
    Gets if a space is connected by a specific link or not.space_is_linked_by() 
 
   @param 
    Space *space: the space you want to know that.
   @return 
    BOOL_: TRUE_ if the space is linked by that link, FALSE_ if not or if the input is NULL.
   */
BOOL_ space_is_linked_by(Space *space, Id link){
  if(!space){
    return FALSE_;
  }

  if(link == north(space) || link == south(space) || link == east(space) 
    || link == west(space) || link == up(space) || link == down(space)){
    return TRUE_;
  }

  return FALSE_;
}

/**
   @date 01-12-2016 
   @author Alejandro Sanchez
 
   @brief 
    Prints a space on the screen.space_print()
 
   @param 
    Space *space: the space you want to print.
   @return 
    STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
   */
STATUS_ space_print(Space *space){
  Id idaux = NO_ID;
  char aux1[WORD_SIZE] = "";
  char aux2[WORD_SIZE] = "";
  char aux3[WORD_SIZE] = "";
   
  if(!space){                   /* Check that the input is not empty */
    return ERROR_;
  }
 
  /* Print each field of the Space structure, checking if it is empty */
	if(illuminated(space)==FALSE_){
		fprintf(stdout, "--> Space (Id: %ld; Name: %s; Description: %s; Illuminated: FALSE_)\n", 
    	id(space), name(space), desc(space));
	} else if(illuminated(space)==TRUE_){
		fprintf(stdout, "--> Space (Id: %ld; Name: %s; Description: %s; Illuminated: TRUE_)\n", 
    	id(space), name(space), desc(space));
	} 
  
  if(shop(space) == TRUE_){
    fprintf(stdout, "shop: TRUE_;");
  } else{
    fprintf(stdout, "shop: FALSE_;");
  }
   
  idaux = space_get_north(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No North link.\n");
  }
     
  idaux = space_get_south(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No South link.\n");
  }
     
  idaux = space_get_east(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No East link.\n");
  }
     
  idaux = space_get_west(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No West link.\n");
  }
	
  idaux = space_get_up(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> Up link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No Up link.\n");
  }
	
  idaux = space_get_down(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> Down link: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No Down link.\n");
  }
  idaux = space_get_rule(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> Rule: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No rule.\n");
  }

  idaux = space_get_person(space);
  if(NO_ID != idaux){
    fprintf(stdout, "---> Person: %ld.\n", idaux);
  } else{
      fprintf(stdout, "---> No person.\n");
  }

  if(set_is_empty(objects(space)) == TRUE_){
    fprintf(stdout, "---> No objects.\n");
  } else if(set_print(objects(space)) == ERROR_){
    return ERROR_;
  }

  if(space_print_gdesc1(space, aux1) == ERROR_){
    return ERROR_;
  }
  if(space_print_gdesc2(space, aux2) == ERROR_){
    return ERROR_;
  }
  if(space_print_gdesc3(space, aux3) == ERROR_){
    return ERROR_;
  }
 
  fprintf(stdout, "---> Graphic Description:\n%s\n%s\n%s\n", aux1, aux2, aux3);
  return OK_;
}

