/* ===================================================================
File: link_test.c
Version: 1.0
Date: Nov. 12, 2016
Authors: Adrián Fernández

Description:
	Contains the implementation of the functions used to test the
	functions implemented in link.c.

Revision history:
	Nov. 12, 2016: Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_test.h" 

#define MAX_TEST_LINK 24

int main(int argc, char** argv){

	int all, test;

	count = 0;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\t", test);
		if (test < 1 || test > MAX_TEST_LINK) {
			printf("Unknown test\t");
			return 1; 
		}
	}

	if (all || test == 1) test1_link_create();
	if (all || test == 2) test2_link_create();
	if (all || test == 3) test3_link_create();
	if (all || test == 4) test4_link_create();
	if (all || test == 5) test1_link_destroy();
	if (all || test == 6) test2_link_destroy();
	if (all || test == 7) test1_link_get_id();
	if (all || test == 8) test2_link_get_id();
	if (all || test == 9) test1_link_set_name();
	if (all || test == 10) test2_link_set_name();
	if (all || test == 11) test3_link_set_name();
	if (all || test == 12) test1_link_get_name();
	if (all || test == 13) test2_link_get_name();
	if (all || test == 14) test1_link_get_space1();
	if (all || test == 15) test2_link_get_space1();
	if (all || test == 16) test1_link_get_space2();
	if (all || test == 17) test2_link_get_space2();
	if (all || test == 18) test1_link_set_state();
	if (all || test == 19) test2_link_set_state();
	if (all || test == 20) test3_link_set_state();
	if (all || test == 21) test1_link_get_state();
	if (all || test == 22) test2_link_get_state();
	if (all || test == 23) test1_link_print();
	if (all || test == 24) test2_link_print();

	return 0;
}

/* --------------------------------------------------------------------
Function: test1_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully create a Link.

Input:

Output:
	
-------------------------------------------------------------------- */
void test1_link_create(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link != NULL);
	link_destroy(link);

	return;
}


/* --------------------------------------------------------------------
Function: test2_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can create a Link without specifying it's id.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(noId);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link == NULL);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test3_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can create a Link without specifying it's first
    Space id.

Input:

Output:
    
-------------------------------------------------------------------- */
void test3_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id);
	link_set_space1(link, noId);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link == NULL);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test4_link_create
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can create a Link without specifying it's second
    Space id.

Input:

Output:
    
-------------------------------------------------------------------- */
void test4_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, noId);
	FUNCTION_IS_CORRECT(link == NULL);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_destroy
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully destroy a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_destroy(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_destroy(link) != ERROR);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_destroy
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can destroy an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_destroy(){

	Link* link;

	FUNCTION_IS_CORRECT(link_destroy(link) == ERROR);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_get_id
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the id of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_get_id(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_get_id(link) != NO_ID);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_get_id
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the id of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_get_id(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_id(link) == NO_ID);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_set_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully set the name of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_set_name(){

	Link* link;
	Id id = 1;
	char name[MAX_CHAR] = "name";

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_set_name(link, name) != ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_set_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the name of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_set_name(){

	Link* link;
	char name[MAX_CHAR] = "name";

	FUNCTION_IS_CORRECT(link_set_name(link, name) == ERROR);

	return;
}

/* --------------------------------------------------------------------
Function: test3_link_set_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the name of a Link if the string inserted
    is unassigned.

Input:

Output:
    
-------------------------------------------------------------------- */
void test3_link_set_name(){

	Link* link;
	Id id = 1;
	char* noName = NULL;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_set_name(link, noName) == ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_get_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the name of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_get_name(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_get_name(link) != NULL);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_get_name
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the name of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_get_name(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_name(link) == NULL);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_set_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully set the space1 of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_set_space1(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space1(link, id) != ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_set_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the space1 of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_set_space1(){

	Link* link;
	Id id = 1;

	FUNCTION_IS_CORRECT(link_set_space1(link, id) == ERROR);

	return;
}

/* --------------------------------------------------------------------
Function: test3_link_set_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the space1 of a Link if the string Id is 
    not valid.

Input:

Output:
    
-------------------------------------------------------------------- */
void test3_link_set_space1(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space1(link, noId) == ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_get_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the space1 of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_get_space1(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_get_space1(link) != NO_ID);
	link_destroy(link);

	return;

}

/* --------------------------------------------------------------------
Function: test2_link_get_space1
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the space1 field of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_get_space1(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_space1(link) == NO_ID);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_set_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully set the space2 of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_set_space2(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space2(link, id) != ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_set_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the space2 of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_set_space2(){

	Link* link;
	Id id = 1;

	FUNCTION_IS_CORRECT(link_set_space2(link, id) == ERROR);

	return;
}

/* --------------------------------------------------------------------
Function: test3_link_set_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the space2 of a Link if the string Id is 
    not valid.

Input:

Output:
    
-------------------------------------------------------------------- */
void test3_link_set_space2(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space2(link, noId) == ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_get_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the space2 of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_get_space2(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT (link_get_space2(link) != NO_ID);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_get_space2
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the space2 field of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_get_space2(){

	Link* link;

	FUNCTION_IS_CORRECT (link_get_space2(link) == NO_ID);
	
	return;
}

/* --------------------------------------------------------------------
Function: test1_link_set_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully set the state of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_set_state(){

	Link* link;
	Id id = 1;
	STATE state = OPEN;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_set_state(link, state) != ERROR);
	link_destroy(link);
	
	return;
}

/* --------------------------------------------------------------------
Function: test2_link_set_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the state of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_set_state(){

	Link* link;
	STATE state = OPEN;

	FUNCTION_IS_CORRECT(link_set_state(link, state) == ERROR);

	return;
}

/* --------------------------------------------------------------------
Function: test3_link_set_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can set the state of a Link if the state inserted
    is unassigned.

Input:

Output:
    
-------------------------------------------------------------------- */
void test3_link_set_state(){

	Link* link;
	Id id = 1;
	STATE noState = NO_STATE;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_set_state(link, noState) == ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_get_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully get the state of a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_get_state(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_get_state(link) != NO_STATE);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_get_state
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can get the state of an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_get_state(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_state(link) == NO_STATE);

	return;
}

/* --------------------------------------------------------------------
Function: test1_link_print
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can successfully print a Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test1_link_print(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT(link_print(link) != ERROR);
	link_destroy(link);

	return;
}

/* --------------------------------------------------------------------
Function: test2_link_print
Date: Nov. 12, 2016
Author: Adrián Fernández

Description: 
    Tests if you can print an uninitialised Link.

Input:

Output:
    
-------------------------------------------------------------------- */
void test2_link_print(){

	Link* link;

	FUNCTION_IS_CORRECT(link_print(link) == ERROR):

	return;
}
