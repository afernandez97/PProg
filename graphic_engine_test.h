/**
@file graphic_engine_test.h
@version 1.0
@date 09-12-2016
@author Adrián Fernández

@brief
Contains the declaration of the functions used to test the screen data type.

@version
Dec. 9, 2016 Version 1.0 (initial release)
@version
Dec. 10, 2016 Version 1.1
  Added tests for window_add_text.
*/

#ifndef GRAPHIC_ENGINE_TEST_H
#define GRAPHIC_ENGINE_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"

#pragma GCC diagnostic ignored "-Wpedantic"

/**
@def Constant values description 
*/
#define MAX_TEST_GE 41

#define FUNCTION_IS_CORRECT(x)\
    if(x){\
        fprintf(stdout,"%s %d %s _OK\n", __FILE__, __LINE__, __FUNCTION__);\
    } else{\
        (fprintf(stdout,"%s %d %s _ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
    }

/*!< Public functions declaration */

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_create
Tests if you can successfully create a screen.

@param
@return
*/
void test1_screen_create();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_destroy
Tests if you can successfully destroy a screen.

@param
@return
*/
void test1_screen_destroy();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_destroy
Tests if you can destroy an uninitialised screen.

@param
@return
*/
void test2_screen_destroy();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_refresh
Tests if you can successfully refresh a screen.

@param
@return
*/
void test1_screen_refresh();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_refresh
Tests if you can refresh an uninitialised screen.

@param
@return
*/
void test2_screen_refresh();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_print
Tests if you can successfully print a screen.

@param
@return
*/
void test1_screen_print();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_print
Tests if you can print an uninitialised screen.

@param
@return
*/
void test2_screen_print();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_add_window
Tests if you can successfully add a window to a screen.

@param
@return
*/
void test1_screen_add_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_add_window
Tests if you can add a window to an uninitialised screen.

@param
@return
*/
void test2_screen_add_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_screen_add_window
Tests if you can add an uninitialised window to a screen.

@param
@return
*/
void test3_screen_add_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_del_window
Tests if you can successfully delete the last window of a screen.

@param
@return
*/
void test1_screen_del_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_del_window
Tests if you can add delete the last window of an uninitialised screen.

@param
@return
*/
void test2_screen_del_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_get_window
Tests if you can successfully get the window in position n of a screen.

@param
@return
*/
void test1_screen_get_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_get_window
Tests if you can get the window in position n of an uninitialised screen.

@param
@return
*/
void test2_screen_get_window();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_create
Tests if you can successfully create a window.

@param
@return
*/
void test1_window_create();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_create
Tests if you can create a screen if nrows isn't valid.

@param
@return
*/
void test2_window_create();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_window_create
Tests if you can create a screen if ncols isn't valid.

@param
@return
*/
void test3_window_create();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test4_window_create
Tests if you can create a screen if begin_y isn't valid.

@param
@return
*/
void test4_window_create();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test5_window_create
Tests if you can create a screen if begin_x isn't valid.

@param
@return
*/
void test5_window_create();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_destroy
Tests if you can successfully destroy a window.

@param
@return
*/
void test1_window_destroy();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_destroy
Tests if you can destroy an uninitialised window.

@param
@return
*/
void test2_window_destroy();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_refresh
Tests if you can successfully refresh a window.

@param
@return
*/
void test1_window_refresh();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_refresh
Tests if you can refresh an uninitialised window.

@param
@return
*/
void test2_window_refresh();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_print
Tests if you can successfully print a window.

@param
@return
*/
void test1_window_print();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_print
Tests if you can print an uninitialised window.

@param
@return
*/
void test2_window_print();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_x
Tests if you can successfully get the begin_x field of a window.

@param
@return
*/
void test1_window_get_x();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_x
Tests if you can get the begin_x field of an uninitialised window.

@param
@return
*/
void test2_window_get_x();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_y
Tests if you can successfully get the begin_y field of a window.

@param
@return
*/
void test1_window_get_y();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_y
Tests if you can get the begin_y field of an uninitialised window.

@param
@return
*/
void test2_window_get_y();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_height
Tests if you can successfully get the nrows field of a window.

@param
@return
*/
void test1_window_get_height();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_height
Tests if you can get the nrows field of an uninitialised window.

@param
@return
*/
void test2_window_get_height();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_weight
Tests if you can successfully get the ncols field of a window.

@param
@return
*/
void test1_window_get_weight();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_weight
Tests if you can get the ncols field of an uninitialised window.

@param
@return
*/
void test2_window_get_weight();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_set_text
Tests if you can successfully set the text field of a window.

@param
@return
*/
void test1_window_set_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_set_text
Tests if you can set the text field of an uninitialised window.

@param
@return
*/
void test2_window_set_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_window_set_text
Tests if you can set the text field of a window if the string is not valid.

@param
@return
*/
void test3_window_set_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_add_text
Tests if you can successfully add a string to the text field of a window.

@param
@return
*/
void test1_window_add_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_addt_text
Tests if you can add a string to the text field of an uninitialised window.

@param
@return
*/
void test2_window_add_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_window_add_text
Tests if you can add a string to the text field of a window if the string is not valid.

@param
@return
*/
void test3_window_add_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_text
Tests if you can successfully get the text field of a window.

@param
@return
*/
void test1_window_get_text();

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_text
Tests if you can get the text field of an uninitialised window.

@param
@return
*/
void test2_window_get_text();

#endif
