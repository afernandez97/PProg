/* ===================================================================
   File: die.h
   Version: 1.0
   Date: 15-10-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
    It defines a die.

   Revision history:
    Oct. 15, 2016  Version 1.0 (initial release)
   =================================================================== */

#ifndef DIE_H
#define DIE_H

#include "types.h"


/*** Data structures definition ***/
typedef struct _Die Die;


/*** Public functions description ***/
/* --------------------------------------------------------------------
   Function: die_create
   Date: 15-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
    Creates a die.
 
   Input: 
    Id id: the id of the die.
   Output: 
    Die *: the die created or NULL on error.
   -------------------------------------------------------------------- */
Die * die_create(Id id);



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
STATUS die_destroy(Die *die);



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
STATUS die_roll(Die *die);



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
int die_get_value(Die*die);



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
STATUS die_print(Die*die);


#endif


