/**
@brief
Contains the implementation of the functions used to test the
functions implemented in link.c.

@file link_test.c
@author Adrián Fernández
@version 1.0
@date Nov. 12, 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_test.h" 

#define MAX_TEST_LINK 22

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
	if (all || test == 3) test1_link_destroy();
	if (all || test == 4) test2_link_destroy();
	if (all || test == 5) test1_link_get_id();
	if (all || test == 6) test2_link_get_id();
	if (all || test == 7) test1_link_set_name();
	if (all || test == 8) test2_link_set_name();
	if (all || test == 9) test3_link_set_name();
	if (all || test == 10) test1_link_get_name();
	if (all || test == 11) test2_link_get_name();
	if (all || test == 12) test1_link_get_space1();
	if (all || test == 13) test2_link_get_space1();
	if (all || test == 14) test1_link_get_space2();
	if (all || test == 15) test2_link_get_space2();
	if (all || test == 16) test1_link_set_state();
	if (all || test == 17) test2_link_set_state();
	if (all || test == 18) test3_link_set_state();
	if (all || test == 19) test1_link_get_state();
	if (all || test == 20) test2_link_get_state();
	if (all || test == 21) test1_link_print();
	if (all || test == 22) test2_link_print();

	return 0;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_create

Tests if you can successfully create a Link.

@param
@return
*/
void test1_link_create(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link != NULL);
	link_destroy(link);

	return;
}


/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_create

Tests if you can create a Link if the Id
is not valid.

@param
@return
*/
void test2_link_create(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(noId);
	FUNCTION_IS_CORRECT(link == NULL);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_destroy

Tests if you can successfully destroy a Link.

@param
@return
*/
void test1_link_destroy(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_destroy(link) != ERROR);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_destroy

Tests if you can destroy an uninitialised Link.

@param
@return
*/
void test2_link_destroy(){

	Link* link;

	FUNCTION_IS_CORRECT(link_destroy(link) == ERROR);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_get_id

Tests if you can successfully get the id of a Link.

@param
@return
*/
void test1_link_get_id(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_get_id(link) != NO_ID);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_get_id

Tests if you can get the id of an uninitialised Link.

@param
@return
*/
void test2_link_get_id(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_id(link) == NO_ID);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_set_name

Tests if you can successfully set the name of a Link.

@param
@return
*/
void test1_link_set_name(){

	Link* link;
	Id id = 1;
	char name[MAX_CHAR] = "name";

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_name(link, name) != ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_set_name

Tests if you can set the name of an uninitialised Link.

@param
@return
*/
void test2_link_set_name(){

	Link* link;
	char name[MAX_CHAR] = "name";

	FUNCTION_IS_CORRECT(link_set_name(link, name) == ERROR);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test3_link_set_name

Tests if you can set the name of a Link if the string inserted
is unassigned.

@param
@return
*/
void test3_link_set_name(){

	Link* link;
	Id id = 1;
	char* noName = NULL;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_name(link, noName) == ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_get_name

Tests if you can successfully get the name of a Link.

@param
@return
*/
void test1_link_get_name(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_get_name(link) != NULL);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_get_name

Tests if you can get the name of an uninitialised Link.

@param
@return
*/
void test2_link_get_name(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_name(link) == NULL);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_set_space1

Tests if you can successfully set the space1 of a Link.

@param
@return
*/
void test1_link_set_space1(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space1(link, id) != ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_set_space1

Tests if you can set the space1 of an uninitialised Link.

@param
@return
*/
void test2_link_set_space1(){

	Link* link;
	Id id = 1;

	FUNCTION_IS_CORRECT(link_set_space1(link, id) == ERROR);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test3_link_set_space1

Tests if you can set the space1 of a Link if the Id is 
not valid.

@param
@return
*/
void test3_link_set_space1(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space1(link, noId) == ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_get_space1

Tests if you can successfully get the space1 of a Link.

@param
@return
*/
void test1_link_get_space1(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space1(link, id);
	FUNCTION_IS_CORRECT(link_get_space1(link) != NO_ID);
	link_destroy(link);

	return;

}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_get_space1

Tests if you can get the space1 field of an uninitialised Link.

@param
@return
*/
void test2_link_get_space1(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_space1(link) == NO_ID);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_set_space2

Tests if you can successfully set the space2 of a Link.

@param
@return
*/
void test1_link_set_space2(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space2(link, id) != ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_set_space2

Tests if you can set the space2 of an uninitialised Link.

@param
@return
*/
void test2_link_set_space2(){

	Link* link;
	Id id = 1;

	FUNCTION_IS_CORRECT(link_set_space2(link, id) == ERROR);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test3_link_set_space2

Tests if you can set the space2 of a Link if the Id is 
not valid.

@param
@return
*/
void test3_link_set_space2(){

	Link* link;
	Id id = 1;
	Id noId = NO_ID;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_space2(link, noId) == ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_get_space2

Tests if you can successfully get the space2 of a Link.

@param
@return
*/
void test1_link_get_space2(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	link_set_space2(link, id);
	FUNCTION_IS_CORRECT (link_get_space2(link) != NO_ID);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_get_space2

Tests if you can get the space2 field of an uninitialised Link.

@param
@return
*/
void test2_link_get_space2(){

	Link* link;

	FUNCTION_IS_CORRECT (link_get_space2(link) == NO_ID);
	
	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_set_state

Tests if you can successfully set the state of a Link.

@param
@return
*/
void test1_link_set_state(){

	Link* link;
	Id id = 1;
	STATE state = OPEN;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_state(link, state) != ERROR);
	link_destroy(link);
	
	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_set_state

Tests if you can set the state of an uninitialised Link.

@param
@return
*/
void test2_link_set_state(){

	Link* link;
	STATE state = OPEN;

	FUNCTION_IS_CORRECT(link_set_state(link, state) == ERROR);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test3_link_set_state

Tests if you can set the state of a Link if the state inserted
is unassigned.

@param
@return
*/
void test3_link_set_state(){

	Link* link;
	Id id = 1;
	STATE noState = NO_STATE;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_set_state(link, noState) == ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_get_state

Tests if you can successfully get the state of a Link.

@param
@return
*/
void test1_link_get_state(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_get_state(link) != NO_STATE);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_get_state

Tests if you can get the state of an uninitialised Link.

@param
@return
*/
void test2_link_get_state(){

	Link* link;

	FUNCTION_IS_CORRECT(link_get_state(link) == NO_STATE);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test1_link_print

Tests if you can successfully print a Link.

@param
@return
*/
void test1_link_print(){

	Link* link;
	Id id = 1;

	link = link_create(id);
	FUNCTION_IS_CORRECT(link_print(link) != ERROR);
	link_destroy(link);

	return;
}

/**
@author Adrián Fernández
@date: Nov. 12, 2016

@brief test2_link_print

Tests if you can print an uninitialised Link.

@param
@return
*/
void test2_link_print(){

	Link* link;

	FUNCTION_IS_CORRECT(link_print(link) == ERROR):

	return;
}
