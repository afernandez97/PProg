/**
@file link_test.h
@version 1.0
@date 12-11-2016
@author Adrián Fernández

@brief
Contains the headers of the functions used to test the functions
implemented in link.c.

@version
	Nov. 12, 2016 Version 1.0 (initial release)
*/

#ifndef LINK_TEST_H
#define LINK_TEST_H

#include "link.h"

#pragma GCC diagnostic ignored "-Wpedantic"

/* Constant values description */
#define MAX_TEST_LINK 22

#define FUNCTION_IS_CORRECT(x)\
    if(x){\
        fprintf(stdout,"%s %d %s OK\n", __FILE__, __LINE__, __FUNCTION__);\
    } else{\
        (fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
    }


/*!< Public functions description */

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_create
Tests if you can successfully create a Link.

@param
@return
*/
void test1_link_create();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_create
Tests if you can create a Link if the Id
is not valid.

@param
@return
*/
void test2_link_create();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_destroy
Tests if you can successfully destroy a Link.

@param
@return
*/
void test1_link_destroy();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_destroy
Tests if you can destroy an uninitialised Link.

@param
@return
*/
void test2_link_destroy();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_get_id
Tests if you can successfully get the id of a Link.

@param
@return
*/
void test1_link_get_id();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_get_id
Tests if you can get the id of an uninitialised Link.

@param
@return
*/
void test2_link_get_id();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_set_name
Tests if you can successfully set the name of a Link.

@param
@return
*/
void test1_link_set_name();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_set_name
Tests if you can set the name of an uninitialised Link.

@param
@return
*/
void test2_link_set_name();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test3_link_set_name
Tests if you can set the name of a Link if the string inserted
is unassigned.

@param
@return
*/
void test3_link_set_name();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_get_name
Tests if you can successfully get the name of a Link.

@param
@return
*/
void test1_link_get_name();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_get_name
Tests if you can get the name of an uninitialised Link.

@param
@return
*/
void test2_link_get_name();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_set_space1
Tests if you can successfully set the space1 of a Link.

@param
@return
*/
void test1_link_set_space1();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_set_space1
Tests if you can set the space1 of an uninitialised Link.

@param
@return
*/
void test2_link_set_space1();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test3_link_set_space1
Tests if you can set the space1 of a Link if the Id is 
not valid.

@param
@return
*/
void test3_link_set_space1();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_get_space1
Tests if you can successfully get the space1 of a Link.

@param
@return
*/
void test1_link_get_space1();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_get_space1
Tests if you can get the space1 field of an uninitialised Link.

@param
@return
*/
void test2_link_get_space1();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_set_space2
Tests if you can successfully set the space2 of a Link.

@param
@return
*/
void test1_link_set_space2();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_set_space2
Tests if you can set the space2 of an uninitialised Link.

@param
@return
*/
void test2_link_set_space2();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test3_link_set_space2
Tests if you can set the space2 of a Link if the Id is 
not valid.

@param
@return
*/
void test3_link_set_space2();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_get_space2
Tests if you can successfully get the space2 of a Link.

@param
@return
*/
void test1_link_get_space2();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_get_space2
Tests if you can get the space2 field of an uninitialised Link.

@param
@return
*/
void test2_link_get_space2();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_set_state
Tests if you can successfully set the state of a Link.

@param
@return
*/
void test1_link_set_state();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_set_state
Tests if you can set the state of an uninitialised Link.

@param
@return
*/
void test2_link_set_state();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test3_link_set_state
Tests if you can set the state of a Link if the state inserted
is unassigned.

@param
@return
*/
void test3_link_set_state();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_get_state
Tests if you can successfully get the state of a Link.

@param
@return
*/
void test1_link_get_state();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_get_state
Tests if you can get the state of an uninitialised Link.

@param
@return
*/
void test2_link_get_state();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test1_link_print
Tests if you can successfully print a Link.

@param
@return
*/
void test1_link_print();

/**
@author Adrián Fernández
@date: 12-11-2016

@brief test2_link_print
Tests if you can print an uninitialised Link.

@param
@return
*/
void test2_link_print();

#endif
