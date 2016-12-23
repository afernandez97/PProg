/**
	@file person_test.h
	@version 1.0
	@date 16-12-2016
	@author Guillermo Rodriguez

	@brief	Tests person's functions


	@version
	Dec. 16, 2016 Version 1.0 (initial release)
*/

#ifndef PERSON_TEST_H
#define PERSON_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "person.h"

#pragma GCC diagnostic ignored "-Wpedantic"

/**
@def Constant values description
*/
#define MAX_TEST_DIALOGUE 18

#define FUNCTION_IS_CORRECT(x)\
  				if(x){\
						fprintf(stdout,"%s %d %s OK_\n", __FILE__, __LINE__, __FUNCTION__);\
					} else{\
							(fprintf(stdout,"%s %d %s ERROR_\n", __FILE__, __LINE__, __FUNCTION__));\
					}

/*!< Public functions description */
 
/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_create
   Tests if you can successfully create a dialogue.

   @param
   @return
*/
void test1_dialogue_create();

/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_destroy
   Tests if you can successfully destroy a dialogue.

   @param
   @return
*/
void test1_dialogue_destroy();


/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_destroy
   Tests if you can successfully destroy an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_destroy();




/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_set_command_act
   Tests if you can successfully set the command act to a dialogue.

   @param
   @return
*/
void test1_dialogue_set_command_act();

/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test2_dialogue_set_command_act
   Tests if you can set the command act to an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_set_command_act();



/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test3_dialogue_set_command_act
   Tests if you can set an uninitialised command act to a dialogue.

   @param
   @return
*/
void test3_dialogue_set_command_act();




/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_get_command_act
   Tests if you can successfully get the command act to a dialogue.

   @param
   @return
*/
void test1_dialogue_get_command_act();


/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test2_dialogue_get_command_act
   Tests if you can successfully get the command act to an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_get_command_act();

/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_set_command_prev
   Tests if you can successfully prev the command act to a dialogue.

   @param
   @return
*/
void test1_dialogue_set_command_prev();
/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test2_dialogue_set_command_prev
   Tests if you can set the command prev to an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_set_command_prev();



/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test3_dialogue_set_command_prev
   Tests if you can set an uninitialised command prev to a dialogue.

   @param
   @return
*/
void test3_dialogue_set_command_prev();



/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_get_command_prev
   Tests if you can successfully get the command prev to a dialogue.

   @param
   @return
*/
void test1_dialogue_get_command_prev();


/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test2_dialogue_get_command_prev
   Tests if you can successfully get the command prev to an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_get_command_prev();


 /**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_set_text
   Tests if you can successfully set the text to a dialogue.

   @param
   @return
*/
void test1_dialogue_set_text();

/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test2_dialogue_set_text
   Tests if you can set the text to an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_set_text();



/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test3_dialogue_set_text
   Tests if you can set a NULL text to a dialogue.

   @param
   @return
*/
void test3_dialogue_set_text();

/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test1_dialogue_get_text
   Tests if you can successfully get the text to a dialogue.

   @param
   @return
*/
void test1_dialogue_get_text();


/**
   @author Guillermo Rodriguez
   @date 22-12-2016

   @brief test2_dialogue_get_text
   Tests if you can successfully get the text to an uninitialised dialogue.

   @param
   @return
*/
void test2_dialogue_get_text();
 

#endif
