/* ===================================================================
   File: die.c
   Version: 1.0
   Date: 15-10-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
    It implements a die.

   Revision history:
    Oct. 15, 2016  Version 1.0 (initial release)
   =================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "die.h"

/*** Constant values description ***/
#define id(X) (X)->id
#define num(X) (X)->num
#define min(X) (X)->min
#define max(X) (X)->max

struct _Die{
  Id id;  /* Id of the die */
  int num;  /* Number of the last roll */
  int min;  /* Lowest number of the die */
  int max;  /* Highest number of the die */
};


/*** Public functions definition ***/
/* --------------------------------------------------------------------
   Function: die_create
   Date: 15-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Creates a die.
 
   Input: 
    Id id: the id of the die
   Output: 
    Die *: the die created or NULL on error.
   -------------------------------------------------------------------- */
Die * die_create(Id id){
  Die *die = NULL;

  if(id == NO_ID){    /* Check that the input is not empty */ 
    return NULL;
  }

  die = (Die *)malloc(sizeof(Die));
  if(!die){  /* Check if memory has been allocated */
    return NULL;
  }    
 
  /* Initialize structure fields */
  id(die) = id;

  num(die) = 0;   
  max(die) = 6;
  min(die) = 1; 

  return die;
}



/* --------------------------------------------------------------------
   Function: die_destroy
   Date: 15-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Destroys a die.
 
   Input: 
    Die *die: the die to destroy.
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS die_destroy(Die *die){
  if(!die){         /* Check that the input is not empty */
    return ERROR;
  }
    
  free(die);        /* Eliminate the memory of the die */      
  
  return OK;
}



/* --------------------------------------------------------------------
   Function: die_roll
   Date: 15-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Rolls a die.
        
   Input: 
    Die *die: the die to roll.

   Output: 
    STATUS: OK if you do the operation well and ERROR in other cases.
   -------------------------------------------------------------------- */
STATUS die_roll(Die *die){
  if(!die){         /* Check that the input is not empty */
     return ERROR;
  }

  /* Generate a pseudo-random number between max and min */
  num(die) = rand()%(max(die)-min(die)+1)+min(die);
  return OK;
}   



/* --------------------------------------------------------------------
   Function: die_get_value
   Date: 15-10-2016 
   Author: Guillermo Rodriguez 
 
   Description: 
    Returns the last die value.
 
   Input: 
    Die *die: the die you want to know the last value.
        
   Output: 
    int : the last die value or -1 on error.
   -------------------------------------------------------------------- */
int die_get_value(Die*die){
  if(!die){  /* Check that the input is not empty */
    return -1;
  }
  
  return num(die);
}
 


/* --------------------------------------------------------------------
   Function: die_print
   Date: 15-10-2016 
   Author: Guillermo Rodriguez 
 
   Description: 
    Prints a die.
 
   Input: 
    Die *die: the die to print.
				
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS die_print(Die *die){
	if(!die){  /* Check that the input is not empty */
		return ERROR;
	}
   
  /* Print the die fields */ 
	fprintf(stdout, "--> die id %ld die roll %d \n", id(die), num(die));
     
  return OK;

}



