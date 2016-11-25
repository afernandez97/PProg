/**
@brief
Contains the implementation of the functions used to test the
functions implemented in space.c.

@file space_test.c
@author Adrián Fernández
@version 1.0
@date Nov. 23, 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space_test.h" 

int main(int argc, char **argv){
	int all, test;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\t", test);
		if (test < 1 || test > MAX_TEST_SPACE) {
			printf("Unknown test\t");
			return 1; 
		}
	}

	if (all || test == 1) test1_space_create();
	if (all || test == 2) test2_space_create();
	if (all || test == 3) test1_space_destroy();
	if (all || test == 4) test2_space_destroy();
	if (all || test == 5) test1_space_get_id();
	if (all || test == 6) test2_space_get_id();
	if (all || test == 7) test1_space_set_name();
	if (all || test == 8) test2_space_set_name();
	if (all || test == 9) test3_space_set_name();
	if (all || test == 10) test1_space_get_name();
	if (all || test == 11) test2_space_get_name();
	if (all || test == 12) test1_space_set_north();
	if (all || test == 13) test2_space_set_north();
	if (all || test == 14) test3_space_set_north();
	if (all || test == 15) test1_space_get_north();
	if (all || test == 16) test2_space_get_north();
	if (all || test == 17) test1_space_set_south();
	if (all || test == 18) test2_space_set_south();
	if (all || test == 19) test3_space_set_south();
	if (all || test == 20) test1_space_get_south();
	if (all || test == 21) test2_space_get_south();
	if (all || test == 22) test1_space_set_east();
	if (all || test == 23) test2_space_set_east();
	if (all || test == 24) test3_space_set_east();
	if (all || test == 25) test1_space_get_east();
	if (all || test == 26) test2_space_get_east();
	if (all || test == 27) test1_space_set_west();
	if (all || test == 28) test2_space_set_west();
	if (all || test == 29) test3_space_set_west();
	if (all || test == 30) test1_space_get_west();
	if (all || test == 31) test2_space_get_west();
	if (all || test == 32) test1_space_add_object();
	if (all || test == 33) test2_space_add_object();
	if (all || test == 34) test3_space_add_object();
	if (all || test == 35) test1_space_del_object();
	if (all || test == 36) test2_space_del_object();
	if (all || test == 37) test3_space_del_object();
	if (all || test == 38) test1_space_get_object();
	if (all || test == 39) test2_space_get_object();
	if (all || test == 40) test1_space_is_object();
	if (all || test == 41) test2_space_is_object();
	if (all || test == 42) test3_space_is_object();
	if (all || test == 43) test1_space_set_desc();
	if (all || test == 44) test2_space_set_desc();
	if (all || test == 45) test3_space_set_desc();
	if (all || test == 46) test1_space_get_desc();
	if (all || test == 47) test2_space_get_desc();
	if (all || test == 48) test1_space_set_gdesc();
	if (all || test == 49) test2_space_set_gdesc();
	if (all || test == 50) test3_space_set_gdesc();
	if (all || test == 51) test1_space_get_gdesc();
	if (all || test == 52) test2_space_get_gdesc();
	if (all || test == 53) test1_space_print();
	if (all || test == 54) test2_space_print();
	if (all || test == 55) test1_space_print_gdesc();
	if (all || test == 56) test2_space_print_gdesc();

	return 0;
}



/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_create
Tests if you can successfully create a space.

@param
@return
*/
void test1_space_create(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space != NULL);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_create
Tests if you can create a space if the id
is not valid.

@param
@return
*/
void test2_space_create(){
	Space *space = NULL;
	Id noId = NO_ID;

	space = space_create(noId);
	FUNCTION_IS_CORRECT(space == NULL);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_destroy
Tests if you can successfully destroy a space.

@param
@return
*/
void test1_space_destroy(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_destroy(space) == OK);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_destroy
Tests if you can destroy an uninitialised space.

@param
@return
*/
void test2_space_destroy(){
	Space *space = NULL;

	FUNCTION_IS_CORRECT(space_destroy(space) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_id
Tests if you can successfully get the id of a space.

@param
@return
*/
void test1_space_get_id(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_get_id(space) != NO_ID);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_id
Tests if you can get the id of an uninitialised space.

@param
@return
*/
void test2_space_get_id(){
	Space *space = NULL;

	FUNCTION_IS_CORRECT(space_get_id(space) == NO_ID);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_name
Tests if you can successfully set the name of a space.

@param
@return
*/
void test1_space_set_name(){
	Space *space = NULL;
	Id id = 1;
	char name[WORD_SIZE] = "name";

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_name(space, name) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_name
Tests if you can set the name of an uninitialised space.

@param
@return
*/

void test2_space_set_name(){
	Space *space = NULL;
	char name[WORD_SIZE] = "name";

	FUNCTION_IS_CORRECT(space_set_name(space, name) == ERROR);
	return;
}


/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_name
Tests if you can set the name of a space if the string inserted
is unassigned.

@param
@return
*/

void test3_space_set_name(){
	Space *space = NULL;
	Id id = 1;
	char *noName = NULL;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_name(space, noName) == ERROR);
	space_destroy(space);
	return;
}



/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_name
Tests if you can successfully get the name of a space.

@param
@return
*/
void test1_space_get_name(){
	Space *space = NULL;
	Id id = 1;
	char name[WORD_SIZE] = "name";

	space = space_create(id);
	space_set_name(space, name);
	FUNCTION_IS_CORRECT(space_get_name(space) != NULL);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_name
Tests if you can get the name of an uninitialised space.

@param
@return
*/
void test2_space_get_name(){
	Space *space = NULL;
	char name[WORD_SIZE] = "name";

	space_set_name(space, name);
	FUNCTION_IS_CORRECT(space_get_name(space) == NULL);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_north
Tests if you can successfully set the north of a space.

@param
@return
*/
void test1_space_set_north(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_north(space, id) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_north
Tests if you can set the north of an uninitialised space.

@param
@return
*/
void test2_space_set_north(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_north(space, id) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_north
Tests if you can set the north of a space if the id is 
not valid.

@param
@return
*/
void test3_space_set_north(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_north(space, noId) == ERROR);
	space_destroy(space);
	return;
}


/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_north
Tests if you can successfully get the north of a space.

@param
@return
*/
void test1_space_get_north(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_north(space, id);
	FUNCTION_IS_CORRECT(space_get_north(space) != NO_ID);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_north
Tests if you can get the north field of an uninitialised space.

@param
@return
*/
void test2_space_get_north(){
	Space *space = NULL;
	Id id = 1;

	space_set_north(space, id);
	FUNCTION_IS_CORRECT(space_get_north(space) == NO_ID);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_south
Tests if you can successfully set the south of a space.

@param
@return
*/
void test1_space_set_south(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_south(space, id) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_south
Tests if you can set the south of an uninitialised space.

@param
@return
*/
void test2_space_set_south(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_south(space, id) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_south
Tests if you can set the south of a space if the id is 
not valid.

@param
@return
*/
void test3_space_set_south(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_south(space, noId) == ERROR);
	space_destroy(space);
	return;
}


/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_south
Tests if you can successfully get the south of a space.

@param
@return
*/
void test1_space_get_south(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_south(space, id);
	FUNCTION_IS_CORRECT(space_get_south(space) != NO_ID);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_south
Tests if you can get the south field of an uninitialised space.

@param
@return
*/
void test2_space_get_south(){
	Space *space = NULL;
	Id id = 1;

	space_set_south(space, id);
	FUNCTION_IS_CORRECT(space_get_south(space) == NO_ID);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_east
Tests if you can successfully set the east of a space.

@param
@return
*/
void test1_space_set_east(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_east(space, id) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_east
Tests if you can set the east of an uninitialised space.

@param
@return
*/
void test2_space_set_east(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_east(space, id) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_east

Tests if you can set the east of a space if the id is 
not valid.

@param
@return
*/
void test3_space_set_east(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_east(space, noId) == ERROR);
	space_destroy(space);
	return;
}
/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_east
Tests if you can successfully get the east of a space.

@param
@return
*/
void test1_space_get_east(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_east(space, id);
	FUNCTION_IS_CORRECT(space_get_east(space) != NO_ID);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_east
Tests if you can get the east field of an uninitialised space.

@param
@return
*/
void test2_space_get_east(){
	Space *space = NULL;
	Id id = 1;

	space_set_east(space, id);
	FUNCTION_IS_CORRECT(space_get_east(space) == NO_ID);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_west
Tests if you can successfully set the west of a space.

@param
@return
*/
void test1_space_set_west(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_west(space, id) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_west
Tests if you can set the west of an uninitialised space.

@param
@return
*/
void test2_space_set_west(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_west(space, id) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_west
Tests if you can set the west of a space if the id is 
not valid.

@param
@return
*/
void test3_space_set_west(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_west(space, noId) == ERROR);
	space_destroy(space);
	return;
}


/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_west
Tests if you can successfully get the west of a space.

@param
@return
*/
void test1_space_get_west(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_west(space, id);
	FUNCTION_IS_CORRECT(space_get_west(space) != NO_ID);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_west
Tests if you can get the west field of an uninitialised space.

@param
@return
*/
void test2_space_get_west(){
	Space *space = NULL;
	Id id = 1;

	space_set_west(space, id);
	FUNCTION_IS_CORRECT(space_get_west(space) == NO_ID);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_add_object
Tests if you can successfully add an object to a space.

@param
@return
*/
void test1_space_add_object(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_add_object(space, id) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_add_object
Tests if you can add an object to a space if the id is not
valid.

@param
@return
*/
void test2_space_add_object(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_add_object(space, noId) == ERROR);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_add_object
Tests if you can add an object to an uninitialised space.

@param
@return
*/
void test3_space_add_object(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_add_object(space, id) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_del_object
Tests if you can successfully delete an object from a space.

@param
@return
*/
void test1_space_del_object(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_del_object(space, id) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_del_object
Tests if you can delete an object from a space if the id is not
valid.

@param
@return
*/
void test2_space_del_object(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_del_object(space, noId) == ERROR);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_del_object
Tests if you can delete an object from an uninitialised space.

@param
@return
*/
void test3_space_del_object(){
	Space *space = NULL;
	Id id = 1;

	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_del_object(space, id) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_object
Tests if you can successfully get the object of a space.

@param
@return
*/
void test1_space_get_object(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_get_object(space) != NULL);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_object
Tests if you can get the object of an uninitialised space.

@param
@return
*/
void test2_space_get_object(){
	Space *space = NULL;
	Id id = 1;

	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_get_object(space) == NULL);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_is_object
Tests if you can successfully find an object in a space.

@param
@return
*/
void test1_space_is_object(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_is_object(space, id) == TRUE);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_is_object
Tests if you can find an object in a space if the id is not
valid.

@param
@return
*/
void test2_space_is_object(){
	Space *space = NULL;
	Id id = 1;
	Id noId = NO_ID;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_is_object(space, noId) == FALSE);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_is_object
Tests if you can find an object in an uninitialised space.

@param
@return
*/
void test3_space_is_object(){
	Space *space = NULL;
	Id id = 1;

	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_is_object(space, id) == FALSE);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_desc
Tests if you can successfully set the desc of a space.

@param
@return
*/
void test1_space_set_desc(){
	Space* space = NULL;
	Id id = 1;
	char desc[WORD_SIZE] = "desc";

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_desc(space, desc) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_desc
Tests if you can set the desc of a space if the string is 
unassigned.

@param
@return
*/
void test2_space_set_desc(){
	Space *space = NULL;
	Id id = 1;
	char *noDesc = NULL;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_desc(space, noDesc) == ERROR);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_desc
Tests if you can set the desc of an uninitialised space.

@param
@return
*/
void test3_space_set_desc(){
	Space *space = NULL;

	char desc[WORD_SIZE] = "desc";

	FUNCTION_IS_CORRECT(space_set_desc(space, desc) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_desc
Tests if you can successfully get the desc of a space.

@param
@return
*/
void test1_space_get_desc(){
	Space *space = NULL;
	Id id = 1;
	char desc[WORD_SIZE] = "desc";

	space = space_create(id);
	space_set_desc(space, desc);
	FUNCTION_IS_CORRECT(space_get_desc(space) != NULL);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_desc
Tests if you can get the desc field of an uninitialised space.

@param
@return
*/
void test2_space_get_desc(){
	Space *space = NULL;
	char desc[WORD_SIZE] = "desc";

	space_set_desc(space, desc);
	FUNCTION_IS_CORRECT(space_get_desc(space) == NULL);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_set_gdesc
Tests if you can successfully set the gdesc of a space.

@param
@return
*/
void test1_space_set_gdesc(){
	Space* space = NULL;
	Id id = 1;
	char gdesc[WORD_SIZE] = "gdesc";

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_gdesc(space, gdesc) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_set_gdesc
Tests if you can set the gdesc of a space if the string is 
unassigned.

@param
@return
*/
void test2_space_set_gdesc(){
	Space *space = NULL;
	Id id = 1;
	char *noGdesc = NULL;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_gdesc(space, noGdesc) == ERROR);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test3_space_set_gdesc
Tests if you can set the gdesc of an uninitialised space.

@param
@return
*/
void test3_space_set_gdesc(){
	Space *space = NULL;

	char gdesc[WORD_SIZE] = "gdesc";

	FUNCTION_IS_CORRECT(space_set_gdesc(space, gdesc) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_get_gdesc
Tests if you can successfully get the gdesc of a space.

@param
@return
*/
void test1_space_get_gdesc(){
	Space *space = NULL;
	Id id = 1;
	char gdesc[WORD_SIZE] = "gdesc";

	space = space_create(id);
	space_set_gdesc(space, gdesc);
	FUNCTION_IS_CORRECT(space_get_gdesc(space) != NULL);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_get_gdesc
Tests if you can get the gdesc field of an uninitialised space.

@param
@return
*/
void test2_space_get_gdesc(){
	Space *space = NULL;
	char gdesc[WORD_SIZE] = "gdesc";

	space_set_desc(space, gdesc);
	FUNCTION_IS_CORRECT(space_get_gdesc(space) == NULL);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_print_gdesc
Tests if you can successfully print the gdesc of a space.

@param
@return
*/
void test1_space_print_gdesc(){
	Space *space = NULL;
	Id id = 1;
	char gdesc[WORD_SIZE] = "gdesc";

	space = space_create(id);
	space_set_gdesc(space, gdesc);
	FUNCTION_IS_CORRECT(space_print_gdesc(space) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_print_gdesc
Tests if you can print the gdesc field of an uninitialised space.

@param
@return
*/
void test2_space_print_gdesc(){
	Space *space = NULL;

	FUNCTION_IS_CORRECT(space_print_gdesc(space) == ERROR);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test1_space_print
Tests if you can successfully print a space.

@param
@return
*/

void test1_space_print(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_print(space) == OK);
	space_destroy(space);
	return;
}

/**
@author Adrián Fernández
@date Nov. 23, 2016

@brief test2_space_print
Tests if you can print an uninitialised space.

@param
@return
*/
void test2_space_print(){
	Space *space = NULL;

	FUNCTION_IS_CORRECT(space_print(space) == ERROR);
	return;
}
