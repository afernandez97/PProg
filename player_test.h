#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H
#include player.h
#define FUNCTION_IS_CORRECT(x)\
  				if(x){\
						fprintf(stdout,"%s %d %s Correct", __FILE__, __LINE__, __FUNCTION__);\
					} else{\
							(fprintf(stdout,"%s %d %s ERROR", __FILE__, __LINE__, __FUNCTION__));\
					}

/*** Public functions description ***/
/* --------------------------------------------------------------------
   Function: test1_player_destroy 
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors you try to destroy an uninitialized player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_destroy();

/* --------------------------------------------------------------------
   Function: test1_player_get_id
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's id 
   from an uninitialized player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_get_id();
/* --------------------------------------------------------------------
   Function: test1_player_set_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a name 
   for an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_set_name();


/* --------------------------------------------------------------------
   Function: test1_player_get_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's name 
   from an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_get_name();


/* --------------------------------------------------------------------
   Function: test1_player_set_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a location 
   for an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_set_location();

/* --------------------------------------------------------------------
   Function: test1_player_get_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's location 
   from an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_get_location();


/* --------------------------------------------------------------------
   Function: test1_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to add an object to 
   an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_add_object();

/* --------------------------------------------------------------------
   Function: test1_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to delete an object 
   from an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_del_object();

/* --------------------------------------------------------------------
   Function: test1_player_has_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to know if there is an 
   specific object in the bag of an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_has_object();

/* --------------------------------------------------------------------
   Function: test1_player_print
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to print an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_print();

/* --------------------------------------------------------------------
   Function: test1_player_create
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you init a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_create();

/* --------------------------------------------------------------------
   Function: test2_player_destroy 
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors you try to destroy a player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_destroy();

/* --------------------------------------------------------------------
   Function: test2_player_get_id
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's id 
   from a player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_get_id();



/* --------------------------------------------------------------------
   Function: test2_player_set_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a name 
   for a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_set_name();

/* --------------------------------------------------------------------
   Function: test2_player_get_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's name
   Input:
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_get_name();


/* --------------------------------------------------------------------
   Function: test2_player_set_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a location 
   for  a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_set_location();

/* --------------------------------------------------------------------
   Function: test3_player_set_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set an empty 
   location for a player
   for  a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test3_player_set_location();

/* --------------------------------------------------------------------
   Function: test2_player_get_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's location 
   from  a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_get_location();

/* --------------------------------------------------------------------
   Function: test2_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to add an object to 
   a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_add_object();


/* --------------------------------------------------------------------
   Function: test3_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to add an empty object
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test3_player_add_object();


/* --------------------------------------------------------------------
   Function: test2_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to delete an object
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_del_object();



/* --------------------------------------------------------------------
   Function: test3_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to delete an empty object
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test3_player_del_object();


/* --------------------------------------------------------------------
   Function: test4_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to delete an object 
   and there aren't objects in the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test4_player_del_object();

/* --------------------------------------------------------------------
   Function: test4_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to add an object that 
   is already in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test4_player_add_object();


/* --------------------------------------------------------------------
   Function: test2_player_print
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you print a player
   is already in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_print();


/* --------------------------------------------------------------------
   Function: test2_player_has_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to know if there 
   is an specific object in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_has_object();

/* --------------------------------------------------------------------
   Function: test3_player_has_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to know if there is 
   an specific object in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */

void test3_player_has_object();

#endif
