/**
   @file die.h
   @Version 1.0
   @date 15-10-2016 
   @author Guillermo Rodriguez and Alejandro Sanchez

   @brief 
    It implements a die.

   
   @version Oct. 15, 2016  Version 1.0 (initial release)
	 @version Nov. 24, 2016  Version 2.0 
			Included <time.h> to use srand() in "die_create".
   */


#ifndef DIE_H
#define DIE_H

#include "types.h"

/*!< Data structures definition */
typedef struct _Die Die;



/*!< Public functions description */

/**
   
   @date 15-10-2016 
   @author Guillermo Rodriguez
 
   @brief die_create()
    Creates a die and creates a seed to generate pseudo-random numbers.
 
    
   @param Id id: the id of the die
    
   @return Die *: the die created or NULL on error.
   */
Die * die_create(Id id);




/**
 
   @date 15-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Destroys a die.die_destroy()
 
    
   @param Die *die: the die to destroy.
    
   @return _STATUS: ERROR if the input is NULL and OK otherwise.
   */
_STATUS die_destroy(Die *die);


/**
   
   @date 15-10-2016 
   @author Guillermo Rodriguez
 
   @brief die_roll()
    Rolls a die.
        
    
   @param Die *die: the die to roll.
    
   @return _STATUS: OK if you do the operation well and ERROR in other cases.
   */
_STATUS die_roll(Die *die);



/**
   
   @date 15-10-2016 
   @author Guillermo Rodriguez 
 
   @brief die_get_value()
    Returns the last die value.
 
   
   @param Die *die: the die you want to know the last value.
        
    
   @return int : the last die value or -1 on error.
   */
int die_get_value(Die*die);



/**
  
   @date 15-10-2016 
   @author Guillermo Rodriguez 
 
   @brief 
    Prints a die.  die_print()
 
    
   @param Die *die: the die to print.
				
    
   @return _STATUS: ERROR if the input is NULL and OK otherwise.
   */
_STATUS die_print(Die*die);


#endif


