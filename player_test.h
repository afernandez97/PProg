/**
   @file player_test.h
   @version 1.0
   @date 05-11-2016 
   @author Guillermo Rodriguez 

   @brief 
    Tests player's functions

   
   @version Nov. 5, 2016  Version 1.0 (initial release)
   */




#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "player.h"

#pragma GCC diagnostic ignored "-Wpedantic"

/* Constant values description */
#define MAX_TEST 27

#define FUNCTION_IS_CORRECT(x)\
  				if(x){\
						fprintf(stdout,"%s %d %s CORRECT\n", __FILE__, __LINE__, __FUNCTION__);\
					} else{\
							(fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
					}

/*!< Public functions description */
/** 
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors you try to destroy an uninitialized player. test1_player_destroy ()
 
   @param 
    
 
   @return 
    
   */
void test1_player_destroy();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the player's id 
   from an uninitialized player.test1_player_get_id()
 
   @param 
    
 
   @return 
    
   */
void test1_player_get_id();
/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a name
   for an uninitialized player. test1_player_set_name()
   @param 
    
 
   @return 
    
   */
void test1_player_set_name();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the player's name 
   from an uninitialized player.test1_player_get_name()
   @param 
    
 
   @return 
    
   */
void test1_player_get_name();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a location 
   for an uninitialized player.test1_player_set_location()
   @param 
    
 
   @return 
    
   */
void test1_player_set_location();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the player's location 
   from an uninitialized player.test1_player_get_location()
   @param 
    
 
   @return 
    
   */
void test1_player_get_location();



/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you try to add an object to 
   an uninitialized player.test1_player_add_object()
   @param 
    
 
   @return 
    
   */
void test1_player_add_object();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you try to delete an object 
   from an uninitialized player.Function: test1_player_del_object()
   @param 
    
 
   @return 
    
   */
void test1_player_del_object();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you try to know if there is an 
   specific object in the bag of an uninitialized player.test1_player_has_object()
   @param 
    
 
   @return 
    
   */
void test1_player_has_object();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to print an uninitialized player
    test1_player_print()
   @param 
    
 
   @return 
    
   */
void test1_player_print();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you init a player.test1_player_create()
   @param 
    
 
   @return 
    
   */
void test1_player_create();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors you try to destroy a player.test2_player_destroy ()
 
   @param 
    
 
   @return 
    
   */
void test2_player_destroy();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the player's id 
   from a player.test2_player_get_id()
 
   @param 
    
 
   @return 
    
   */
void test2_player_get_id();



/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a name 
   for a player.test2_player_set_name()
   @param 
    
 
   @return 
    
   */
void test2_player_set_name();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the player's name.
   test2_player_get_name()
   @param
    
 
   @return 
    
   */
void test2_player_get_name();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a location 
   for  a player.test2_player_set_location()
   @param 
    
 
   @return 
    
   */
void test2_player_set_location();

/**
   Function: test3_player_set_location
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set an empty 
   location for a player
   for  a player
   @param 
    
 
   @return 
    
   */
void test3_player_set_location();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the player's location 
   from  a player.test2_player_get_location()
   @param 
    
 
   @return 
    
   */
void test2_player_get_location();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you try to add an object to 
   a player.test2_player_add_object()
   @param 
    
 
   @return 
    
   */
void test2_player_add_object();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to add an empty object.
   test3_player_add_object()
   @param 
    
 
   @return 
    
   */
void test3_player_add_object();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to delete an object.
   test2_player_del_object()
   @param 
    
 
   @return 
    
   */
void test2_player_del_object();



/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you try to delete an empty object.
   test3_player_del_object()
   @param 
    
 
   @return 
    
   */
void test3_player_del_object();



/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to delete an object 
   and there aren't objects in the player.test4_player_del_object()
   @param 
    
 
   @return 
    
   */
void test4_player_del_object();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to add an object that 
   is already in the bag of the player.test4_player_add_object()
   @param 
    
 
   @return 
    
   */
void test4_player_add_object();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors  when you print a player
   is already in the bag of the player. test2_player_print()
   @param 
    
 
   @return 
    
   */
void test2_player_print();


/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to know if there 
   is an specific object in the bag of the player.test2_player_has_object()
   @param 
    
 
   @return 
    
   */
void test2_player_has_object();

/**
   @date 05-10-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to know if there is 
   an specific object in the bag of the player.test3_player_has_object()
   @param 
    
 
   @return 
    
   */

void test3_player_has_object();

#endif
