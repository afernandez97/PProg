/**
@file rule_test.h
@version 1.0
@date 12-12-2016
@author Guillermo Rodriguez

@brief
Contains the headers of the functions used to test the functions
implemented in rule.c.

@version
	Dec. 12, 2016 Version 1.0 (initial release)	
*/

#ifndef RULE_TEST_H
#define RULE_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "rule.h"

#pragma GCC diagnostic ignored "-Wpedantic"

/**
@def Constant values description 
*/
#define MAX_TEST_RULE 65

#define FUNCTION_IS_CORRECT(x)\
    if(x){\
        fprintf(stdout,"%s %d %s OK\n", __FILE__, __LINE__, __FUNCTION__);\
    } else{\
        (fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
    }


/*!< Public functions description */

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_create
Tests if you can successfully create a rule.

@param
@return
*/
void test1_rule_create();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_create
Tests if you can create a rule if the id
is not valid.

@param
@return
*/
void test2_rule_create();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_destroy
Tests if you can successfully destroy a rule.

@param
@return
*/
void test1_rule_destroy();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_destroy
Tests if you can destroy an uninitialised rule.

@param
@return
*/
void test2_rule_destroy();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_id
Tests if you can successfully get the id of a space.

@param
@return
*/
void test1_rule_get_id();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_id
Tests if you can get the id of an uninitialised rule.

@param
@return
*/
void test2_rule_get_id();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_set_ask
Tests if you can successfully set the ask of a space.

@param
@return
*/
void test1_rule_set_ask();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_set_ask
Tests if you can set the ask of an uninitialised rule.

@param
@return
*/

void test2_rule_set_ask();


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test3_rule_set_ask
Tests if you can set the ask of a rule if the string inserted
is unassigned.

@param
@return
*/

void test3_rule_set_ask();



/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_ask
Tests if you can successfully get the ask of a rule.

@param
@return
*/
void test1_rule_get_ask();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_ask
Tests if you can get the ask of an uninitialised rule.

@param
@return
*/
void test2_rule_get_ask();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_set_choice1
Tests if you can successfully set the first choice of a space.

@param
@return
*/
void test1_rule_set_choice1();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_set_choice1
Tests if you can set the first choice of an uninitialised rule.

@param
@return
*/

void test2_rule_set_choice1();


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test3_rule_set_choice1
Tests if you can set the first choice of a rule if the string inserted
is unassigned.

@param
@return
*/

void test3_rule_set_choice1();


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_choice1
Tests if you can successfully get the first choice of a rule.

@param
@return
*/
void test1_rule_get_choice1();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_choice1
Tests if you can get the first choice of an uninitialised rule.

@param
@return
*/
void test2_rule_get_choice1();


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_set_choice2
Tests if you can successfully set the second choice of a space.

@param
@return
*/
void test1_rule_set_choice2();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_set_choice2
Tests if you can set the second choice of an uninitialised rule.

@param
@return
*/

void test2_rule_set_choice2();


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test3_rule_set_choice2
Tests if you can set the second choice of a rule if the string inserted
is unassigned.

@param
@return
*/

void test3_rule_set_choice1();



/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_choice2
Tests if you can successfully get the second choice of a rule.

@param
@return
*/
void test1_rule_get_choice2();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_choice2
Tests if you can get the second choice of an uninitialised rule.

@param
@return
*/
void test2_rule_get_choice2();


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_print
Tests if you can successfully print a rule.

@param
@return
*/

void test1_rule_print();

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_print
Tests if you can print an uninitialised rule.

@param
@return
*/
void test2_rule_print();







#endif
