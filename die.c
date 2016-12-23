/**
   @file die.c
   @Version 1.0
   @date 15-10-2016 
   @author Guillermo Rodriguez and Alejandro Sanchez

   @brief 
    It implements a die.

   
   @version Oct. 15, 2016  Version 1.0 (initial release)
	 @version Nov. 24, 2016  Version 2.0 
			Included <time.h> to use srand() in "die_create".
   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "die.h"

/**
@def Constant values description 
*/
#define id(X) (X)->id
#define num(X) (X)->num
#define min(X) (X)->min
#define max(X) (X)->max

/**
@brief Die structure 
Stores information of the identifier of the die, the number of the last roll and the lowest and 
highest number of the die
*/
struct _Die{
  Id id;  /*!< Id of the die */
  int num;  /*!< Number of the last roll */
  int min;  /*!< Lowest number of the die */
  int max;  /*!< Highest number of the die */
};


/*!< Public functions definition */
/**
   
   @date: 15-10-2016 
   @author Guillermo Rodriguez
 
   @brief die_create()
    Creates a die and creates a seed to generate pseudo-random numbers.
 
    
   @param Id id: the id of the die
    
   @return Die *: the die created or NULL on error.
   */
Die * die_create(Id id){
  Die *die = NULL;

  if(id == NO_ID){    /* Check that the input is not empty */ 
    return NULL;
  }

  die = (Die *)malloc(sizeof(Die));
  if(!die){  /* Check if memory has been allocated */
    return NULL;
  }    
 
  /* Create a seed to generate a pseudo-random number later */
  srand(time(NULL));

  /* Initialize structure fields */
  id(die) = id;

  num(die) = 0;   
  max(die) = 6;
  min(die) = 1; 

  return die;
}



/**
 
   @date: 15-10-2016 
   @author: Guillermo Rodriguez
 
   @brief 
    Destroys a die.die_destroy()
 
    
   @param Die *die: the die to destroy.
    
   @return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
   */
STATUS_ die_destroy(Die *die){
  if(!die){         /* Check that the input is not empty */
    return ERROR_;
  }
    
  free(die);        /* Eliminate the memory of the die */      
  
  return OK_;
}



/**
   
   @date: 15-10-2016 
   @author: Guillermo Rodriguez
 
   @brief die_roll()
    Rolls a die.
        
    
   @param Die *die: the die to roll.
    
   @return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
   */
STATUS_ die_roll(Die *die){
  if(!die){         /* Check that the input is not empty */
     return ERROR_;
  }

  /* Generate a pseudo-random number between max and min */
  num(die) = rand()%(max(die)-min(die)+1)+min(die);
  return OK_;
}   



/**
   
   @date 15-10-2016 
   @author Guillermo Rodriguez 
 
   @brief die_get_value()
    Returns the last die value.
 
   
   @param Die *die: the die you want to know the last value.
        
    
   @return int : the last die value or -1 on error.
   */
int die_get_value(Die*die){
  if(!die){  /* Check that the input is not empty */
    return -1;
  }
  
  return num(die);
}
 


/**
  
   @date: 15-10-2016 
   @author Guillermo Rodriguez 
 
   @brief 
    Prints a die.  die_print()
 
    
   @param Die *die: the die to print.
				
    
   @return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
   */
STATUS_ die_print(Die *die){
	if(!die){  /* Check that the input is not empty */
		return ERROR_;
	}
   
  /* Print the die fields */ 
	fprintf(stdout, "--> die id %ld die roll %d \n", id(die), num(die));
     
  return OK_;

}



