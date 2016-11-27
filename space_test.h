/**
@file space_test.h
@version 1.0
@date 23-11-2016
@author Adrián Fernández

@brief
Contains the headers of the functions used to test the functions
implemented in space.c.

@version
	Nov. 23, 2016  Version 1.0 (initial release)
*/

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "space.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define MAX_TEST_SPACE 52

#define FUNCTION_IS_CORRECT(x)\
    if(x){\
        fprintf(stdout,"%s %d %s OK\n", __FILE__, __LINE__, __FUNCTION__);\
    } else{\
        (fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
    }


/*!< Public functions description */

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_create

Tests if you can successfully create a space.

@param
@return
*/
void test1_space_create();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_create

Tests if you can create a space if the id
is not valid.

@param
@return
*/
void test2_space_create();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_destroy

Tests if you can successfully destroy a space.

@param
@return
*/
void test1_space_destroy();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_destroy

Tests if you can destroy an uninitialised space.

@param
@return
*/
void test2_space_destroy();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_id

Tests if you can successfully get the id of a space.

@param
@return
*/
void test1_space_get_id();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_id

Tests if you can get the id of an uninitialised space.

@param
@return
*/
void test2_space_get_id();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_name

Tests if you can successfully set the name of a space.

@param
@return
*/
void test1_space_set_name();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_name

Tests if you can set the name of an uninitialised space.

@param
@return
*/
void test2_space_set_name();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test3_space_set_name

Tests if you can set the name of a space if the string inserted
is unassigned.

@param
@return
*/
void test3_space_set_name();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_name

Tests if you can successfully get the name of a space.

@param
@return
*/
void test1_space_get_name();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_name

Tests if you can get the name of an uninitialised space.

@param
@return
*/
void test2_space_get_name();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_north

Tests if you can successfully set the north of a space.

@param
@return
*/
void test1_space_set_north();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_north

Tests if you can set the north of an uninitialised space.

@param
@return
*/
void test2_space_set_north();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_north

Tests if you can successfully get the north of a space.

@param
@return
*/
void test1_space_get_north();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_north

Tests if you can get the north field of an uninitialised space.

@param
@return
*/
void test2_space_get_north();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_south

Tests if you can successfully set the south of a space.

@param
@return
*/
void test1_space_set_south();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_south

Tests if you can set the south of an uninitialised space.

@param
@return
*/
void test2_space_set_south();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_south

Tests if you can successfully get the south of a space.

@param
@return
*/
void test1_space_get_south();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_south

Tests if you can get the south field of an uninitialised space.

@param
@return
*/
void test2_space_get_south();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_east

Tests if you can successfully set the east of a space.

@param
@return
*/
void test1_space_set_east();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_east

Tests if you can set the east of an uninitialised space.

@param
@return
*/
void test2_space_set_east();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_east

Tests if you can successfully get the east of a space.

@param
@return
*/
void test1_space_get_east();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_east

Tests if you can get the east field of an uninitialised space.

@param
@return
*/
void test2_space_get_east();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_west

Tests if you can successfully set the west of a space.

@param
@return
*/
void test1_space_set_west();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_west

Tests if you can set the west of an uninitialised space.

@param
@return
*/
void test2_space_set_west();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_west

Tests if you can successfully get the west of a space.

@param
@return
*/
void test1_space_get_west();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_west

Tests if you can get the west field of an uninitialised space.

@param
@return
*/
void test2_space_get_west();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_add_object

Tests if you can successfully add an object to a space.

@param
@return
*/
void test1_space_add_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_add_object

Tests if you can add an object to a space if the id is not
valid.

@param
@return
*/
void test2_space_add_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test3_space_add_object

Tests if you can add an object to an uninitialised space.

@param
@return
*/
void test3_space_add_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_del_object

Tests if you can successfully delete an object from a space.

@param
@return
*/
void test1_space_del_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_del_object

Tests if you can delete an object from a space if the id is not
valid.

@param
@return
*/
void test2_space_del_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test3_space_del_object

Tests if you can delete an object from an uninitialised space.

@param
@return
*/
void test3_space_del_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_object

Tests if you can successfully get the object of a space.

@param
@return
*/
void test1_space_get_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_object

Tests if you can get the object of an uninitialised space.

@param
@return
*/
void test2_space_get_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_is_object

Tests if you can successfully find an object in a space.

@param
@return
*/
void test1_space_is_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_is_object

Tests if you can find an object in a space if the id is not
valid.

@param
@return
*/
void test2_space_is_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test3_space_is_object

Tests if you can find an object in an uninitialised space.

@param
@return
*/
void test3_space_is_object();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_desc

Tests if you can successfully set the desc of a space.

@param
@return
*/
void test1_space_set_desc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_desc

Tests if you can set the desc of a space if the string is 
unassigned.

@param
@return
*/
void test2_space_set_desc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test3_space_set_desc

Tests if you can set the desc of an uninitialised space.

@param
@return
*/
void test3_space_set_desc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_desc

Tests if you can successfully get the desc of a space.

@param
@return
*/
void test1_space_get_desc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_desc

Tests if you can get the desc field of an uninitialised space.

@param
@return
*/
void test2_space_get_desc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_set_gdesc

Tests if you can successfully set the gdesc of a space.

@param
@return
*/
void test1_space_set_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_set_gdesc

Tests if you can set the gdesc of a space if the string is 
unassigned.

@param
@return
*/
void test2_space_set_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test3_space_set_gdesc

Tests if you can set the gdesc of an uninitialised space.

@param
@return
*/
void test3_space_set_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_get_gdesc

Tests if you can successfully get the gdesc of a space.

@param
@return
*/
void test1_space_get_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_get_gdesc

Tests if you can get the gdesc field of an uninitialised space.

@param
@return
*/
void test2_space_get_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_print_gdesc

Tests if you can successfully print the gdesc of a space.

@param
@return
*/
void test1_space_print_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_print_gdesc

Tests if you can print the gdesc field of an uninitialised space.

@param
@return
*/
void test2_space_print_gdesc();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test1_space_print

Tests if you can successfully print a space.

@param
@return
*/
void test1_space_print();

/**
@author Adrián Fernández
@date: Nov. 23, 2016

@brief test2_space_print

Tests if you can print an uninitialised space.

@param
@return
*/
void test2_space_print();

#endif
