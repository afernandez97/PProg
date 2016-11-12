/* ===================================================================
File: link_test.h
Version: 2.0
Date: Nov. 12, 2016
Authors: Adrián Fernández

Description:
    Contains the headers of the functions used to test the functions
    implemented in link.c.

Revision history:
    Nov. 12, 2016: Version 2.0 (initial release)
=================================================================== */

#ifndef LINK_TEST_H
#define LINK_TEST_H

#include "link.h"

#define FUNCTION_IS_CORRECT(x)\
    if(x){\
        fprintf(stdout,"%s %d %s OK\n", __FILE__, __LINE__, __FUNCTION__);\
    } else{\
        (fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
    }


/*** Public functions description ***/

/* --------------------------------------------------------------------
Function: test1_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully create a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_create();

/* --------------------------------------------------------------------
Function: test2_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can create a Link without specifying it's id.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_create();

/* --------------------------------------------------------------------
Function: test3_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can create a Link without specifying it's first
    Space id.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test3_link_create();

/* --------------------------------------------------------------------
Function: test4_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can create a Link without specifying it's second
    Space id.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test4_link_create();

/* --------------------------------------------------------------------
Function: test1_link_destroy
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully destroy a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_destroy();

/* --------------------------------------------------------------------
Function: test2_link_destroy
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can destroy an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_destroy();

/* --------------------------------------------------------------------
Function: test1_link_get_id
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the id of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_get_id();

/* --------------------------------------------------------------------
Function: test2_link_get_id
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the id of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_get_id();

/* --------------------------------------------------------------------
Function: test1_link_set_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully set the name of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_set_name();

/* --------------------------------------------------------------------
Function: test2_link_set_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the name of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_set_name();

/* --------------------------------------------------------------------
Function: test3_link_set_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the name of a Link if the string inserted
    is unassigned.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test3_link_set_name();

/* --------------------------------------------------------------------
Function: test1_link_get_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the name of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_get_name();

/* --------------------------------------------------------------------
Function: test2_link_get_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the name of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_get_name();

/* --------------------------------------------------------------------
Function: test1_link_get_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the space1 of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_get_space1();

/* --------------------------------------------------------------------
Function: test2_link_get_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the space1 field of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_get_space1();

/* --------------------------------------------------------------------
Function: test1_link_get_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the space2 of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_get_space2();

/* --------------------------------------------------------------------
Function: test2_link_get_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the space2 field of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_get_space2();

/* --------------------------------------------------------------------
Function: test1_link_set_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully set the state of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_set_state();

/* --------------------------------------------------------------------
Function: test2_link_set_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the state of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_set_state();

/* --------------------------------------------------------------------
Function: test3_link_set_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the state of a Link if the state inserted
    is unassigned.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test3_link_set_state();

/* --------------------------------------------------------------------
Function: test1_link_get_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the state of a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_get_state();

/* --------------------------------------------------------------------
Function: test2_link_get_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the state of an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_get_state();

/* --------------------------------------------------------------------
Function: test1_link_print
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully print a Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_print();

/* --------------------------------------------------------------------
Function: test2_link_print
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can print an uninitialised Link.

Input:

Output:
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test2_link_print();

#endif
