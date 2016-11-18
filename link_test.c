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
#include "player_test.h" 

#define MAX_TEST_LINK 24

int main(int argc, char** argv){

	int all, test, count;

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

	if (all || test == 1) count += test1_link_create();
	if (all || test == 2) count += test2_link_create();
	if (all || test == 3) count += test3_link_create();
	if (all || test == 4) count += test4_link_create();
	if (all || test == 5) count += test1_link_destroy();
	if (all || test == 6) count += test2_link_destroy();
	if (all || test == 7) count += test1_link_get_id();
	if (all || test == 8) count += test2_link_get_id();
	if (all || test == 9) count += test1_link_set_name();
	if (all || test == 10) count += test2_link_set_name();
	if (all || test == 11) count += test3_link_set_name();
	if (all || test == 12) count += test1_link_get_name();
	if (all || test == 13) count += test2_link_get_name();
	if (all || test == 14) count += test1_link_get_space1();
	if (all || test == 15) count += test2_link_get_space1();
	if (all || test == 16) count += test1_link_get_space2();
	if (all || test == 17) count += test2_link_get_space2();
	if (all || test == 18) count += test1_link_set_state();
	if (all || test == 19) count += test2_link_set_state();
	if (all || test == 20) count += test3_link_set_state();
	if (all || test == 21) count += test1_link_get_state();
	if (all || test == 22) count += test2_link_get_state();
	if (all || test == 23) count += test1_link_print();
	if (all || test == 24) count += test2_link_print();

	if (count == 0) {
		fprintf (stdout, "No errors detected\n");
	} else {
		fprintf (stdout, "%d errors detected\n", count);
	}

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
	int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test1_link_create(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link == NULL){
		FUNCTION_IS_CORRECT(0);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}


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
int test2_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(noId, id, id);

	if (link == NULL){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	link_destroy(link);
	return 1;
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
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test3_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id, noId, id);

	if (link == NULL){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	link_destroy(link);
	return 1;
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
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test4_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id, id, noId)

	if (link == NULL){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	link_destroy(link);
	return 1;
}

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
int test1_link_destroy(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_destroy(link) == ERROR){
		FUNCTION_IS_CORRECT(0);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	return 0;
}

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
int test2_link_destroy(){

	Link* link;

	if (link_destroy(link) == ERROR){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}

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
int test1_link_get_id(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_get_id(link) == NO_ID){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_get_id(){

	Link* link;

	if (link_get_id(link) == NO_ID){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}

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
int test1_link_set_name(){

	Link* link;
	Id id = 1;
	char name[MAX_CHAR] = "name";

	link = link_create(id, id, id);

	if (link_set_name(link, name) == ERROR){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_set_name(){

	Link* link;
	char name[MAX_CHAR] = "name";

	if (link_set_name(link, name) == ERROR){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
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
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test3_link_set_name(){

	Link* link;
	Id id = 1;
	char* noName = NULL;

	link = link_create(id, id, id);

	if (link_set_name(link, noName) == ERROR){
		FUNCTION_IS_CORRECT(1);
		link_destroy(link);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	link_destroy(link);
	return 1;
}

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
int test1_link_get_name(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_get_name(link) == NULL){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_get_name(){

	Link* link;

	if (link_get_name(link) == NULL){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}

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
int test1_link_get_space1(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_get_space1(link) == NO_ID){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_get_space1(){

	Link* link;

	if (link_get_space1(link) == NO_ID){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}

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
int test1_link_get_space2(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_get_space1(link) == NO_ID){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_get_space2(){

	Link* link;

	if (link_get_space1(link) == NO_ID){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}

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
int test1_link_set_state(){

	Link* link;
	Id id = 1;
	STATE state = OPEN;

	link = link_create(id, id, id);

	if (link_set_state(link, state) == ERROR){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_set_state(){

	Link* link;
	STATE state = OPEN;

	if (link_set_state(link, state) == ERROR){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
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
    int: Returns 0 if OK or 1 if ERROR.
-------------------------------------------------------------------- */
int test3_link_set_state(){

	Link* link;
	Id id = 1;
	STATE noState = NO_STATE;

	link = link_create(id, id, id);

	if (link_set_state(link, noState) == ERROR){
		FUNCTION_IS_CORRECT(1);
		link_destroy(link);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	link_destroy(link);
	return 1;
}

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
int test1_link_get_state(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_get_state(link) == NO_STATE){
		FUNCTION_IS_CORRECT(1);
		link_destroy(link);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	link_destroy(link);
	return 1;
}

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
int test2_link_get_state(){

	Link* link;

	if (link_get_state(link) == NO_STATE){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}

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
int test1_link_print(){

	Link* link;
	Id id = 1;

	link = link_create(id, id, id);

	if (link_print(link) == ERROR){
		FUNCTION_IS_CORRECT(0);
		link_destroy(link);
		return 1;
	}
	
	FUNCTION_IS_CORRECT(1);
	link_destroy(link);
	return 0;
}

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
int test2_link_print(){

	Link* link;

	if (link_print(link) == ERROR){
		FUNCTION_IS_CORRECT(1);
		return 0;
	}
	
	FUNCTION_IS_CORRECT(0);
	return 1;
}
