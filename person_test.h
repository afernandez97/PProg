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
#define MAX_TEST_PERSON 23

#define FUNCTION_IS_CORRECT(x)\
  				if(x){\
						fprintf(stdout,"%s %d %s OK_\n", __FILE__, __LINE__, __FUNCTION__);\
					} else{\
							(fprintf(stdout,"%s %d %s ERROR_\n", __FILE__, __LINE__, __FUNCTION__));\
					}

/*!< Public functions description */
 
/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_create
	Tests if you can successfully create a person.

	@param
	@return
*/
void test1_person_create();
/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_create
	Tests if you can create a person if the id
	is not valid.

@param
@return
*/
void test2_person_create();

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_destroy
	Tests if you can successfully destroy a person.

	@param
	@return
*/
void test1_person_destroy();

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_destroy
	Tests if you can destroy an uninitialised person.

	@param
	@return
*/
void test2_person_destroy();
/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_get_id
	Tests if you can successfully get the id of a person.

	@param
	@return
*/
void test1_person_get_id();

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_get_id
	Tests if you can get the id of an uninitialised person.

	@param
	@return
*/
void test2_person_get_id();

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_set_name
	Tests if you can successfully set the name of a person.

	@param
	@return
*/
void test1_person_set_name();
/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_set_name
	Tests if you can set the name of an uninitialised person.

	@param
	@return
*/

void test2_person_set_name();


/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test3_person_set_name
	Tests if you can set the name of a person if the string inserted
	is unassigned.

	@param
	@return
*/

void test3_person_set_name();



/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_get_name
	Tests if you can successfully get the name of a person.

	@param
	@return
*/
void test1_person_get_name();
/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_get_name
	Tests if you can get the name of an uninitialised person.

	@param
	@return
*/
void test2_person_get_name();


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a location 
   for an uninitialized person.test1_person_set_location()
   @param 
    
 
   @return 
    
   */
void test1_person_set_location();


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a location 
   for  a person.test2_person_set_location()
   @param 
    
 
   @return 
    
   */
void test2_person_set_location();

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set an empty 
   location for a person  test3_person_set_location()
   @param 
    
 
   @return 
    
   */
void test3_person_set_location();

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's location 
   from an uninitialized person.test1_person_get_location()
   @param 
    
 
   @return 
    
   */
void test1_person_get_location();


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's location 
   from  a person.test2_person_get_location()
   @param 
    
 
   @return 
    
   */
void test2_person_get_location();

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a rule 
   for an uninitialized person.test1_person_set_rule()
   @param 
    
 
   @return 
    
   */
void test1_person_set_rule();


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a rule 
   for a person.test2_person_set_rule()
   @param 
    
 
   @return 
    
   */
void test2_person_set_rule();

/**
   Function: test3_person_set_rule
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief  
   Check if there aren't any errors when you try to set an empty 
   rule for a person. test3_person_set_rule()
   @param 
    
 
   @return 
    
   */
void test3_person_set_rule();

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's rule 
   from an uninitialized person.test1_person_get_rule()
   @param 
    
 
   @return 
    
   */
void test1_person_get_rule();


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's rule 
   from  a person.test2_person_get_rule()
   @param 
    
 
   @return 
    
   */
void test2_person_get_rule();
/**
@author Guillermo Rodriguez
@date 16-12-2016

@brief test1_person_print
Tests if you can successfully print a person.

@param
@return
*/

void test1_person_print();

/**
@author Guillermo Rodriguez
@date 16-12-2016

@brief test2_person_print
Tests if you can print an uninitialised person.

@param
@return
*/
void test2_person_print();


  

#endif
