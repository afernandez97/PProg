/* ===================================================================
File: space_test.c
Version: 1.0
Date: Nov. 12, 2016
Authors: Adrián Fernández

Description:
	Contains the implementation of the functions used to test the
	functions implemented in space.c.

Revision history:
	Nov. 23, 2016: Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space_test.h" 

#define MAX_TEST_SPACE 56

int main(int argc, char **argv){

	int all, test;

	count = 0;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\t", test);
		if (test < 1 || test > MAX_TEST_SPACEK) {
			printf("Unknown test\t");
			return 1; 
		}
	}

	if (all || test == 1) space_create_test1();
	if (all || test == 2) space_create_test2();
	if (all || test == 3) space_destroy_test1();
	if (all || test == 4) space_destroy_test2();
	if (all || test == 5) space_get_id_test1();
	if (all || test == 6) space_get_id_test2();
	if (all || test == 7) space_set_name_test1();
	if (all || test == 8) space_set_name_test2();
	if (all || test == 9) space_set_name_test3();
	if (all || test == 10) space_get_name_test1();
	if (all || test == 11) space_get_name_test2();
	if (all || test == 12) space_set_north_test1();
	if (all || test == 13) space_set_north_test2();
	if (all || test == 14) space_set_north_test3();
	if (all || test == 15) space_get_north_test1();
	if (all || test == 16) space_get_north_test2();
	if (all || test == 17) space_set_south_test1();
	if (all || test == 18) space_set_south_test2();
	if (all || test == 19) space_set_south_test3();
	if (all || test == 20) space_get_south_test1();
	if (all || test == 21) space_get_south_test2();
	if (all || test == 22) space_set_east_test1();
	if (all || test == 23) space_set_east_test2();
	if (all || test == 24) space_set_east_test3();
	if (all || test == 25) space_get_east_test1();
	if (all || test == 26) space_get_east_test2();
	if (all || test == 27) space_set_west_test1();
	if (all || test == 28) space_set_west_test2();
	if (all || test == 29) space_set_west_test3();
	if (all || test == 30) space_get_west_test1();
	if (all || test == 31) space_get_west_test2();
	if (all || test == 32) space_add_object_test1();
	if (all || test == 33) space_add_object_test2();
	if (all || test == 34) space_add_object_test3();
	if (all || test == 35) space_del_object_test1();
	if (all || test == 36) space_del_object_test2();
	if (all || test == 37) space_del_object_test3();
	if (all || test == 38) space_get_object_test1();
	if (all || test == 39) space_get_object_test2();
	if (all || test == 40) space_is_object_test1();
	if (all || test == 41) space_is_object_test2();
	if (all || test == 42) space_is_object_test3();
	if (all || test == 43) space_set_desc_test1();
	if (all || test == 44) space_set_desc_test2();
	if (all || test == 45) space_set_desc_test3();
	if (all || test == 46) space_get_desc_test1();
	if (all || test == 47) space_get_desc_test2();
	if (all || test == 48) space_set_gdesc_test1();
	if (all || test == 49) space_set_gdesc_test2();
	if (all || test == 50) space_set_gdesc_test3();
	if (all || test == 51) space_get_gdesc_test1();
	if (all || test == 52) space_get_gdesc_test2();
	if (all || test == 53) space_print_test1();
	if (all || test == 54) space_print_test2();
	if (all || test == 55) space_print_gdesc_test1();
	if (all || test == 56) space_print_gdesc_test2();

	return 0;
}

void space_create_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space != NULL);
	space_free(space);
	return;
}

void space_create_test2(){
	Space *space = NULL;
	Id noId = -1;

	space = space_create(noId);
	FUNCTION_IS_CORRECT(space == NULL);
	space_free(space);
	return;
}

void space_destroy_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(free(space) == OK);
	return;
}

void space_destroy_test2(){
	Space *space = NULL;

	FUNCTION_IS_CORRECT(free(space) == ERROR);
	return;
}

void space_get_id_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_get_id(space) != NO_ID);
	space_free(space);
	return;
}

void space_get_id_test2(){
	Space *space = NULL;

	FUNCTION_IS_CORRECT(space_get_id(space) == NO_ID);
	return;
}

void space_set_name_test1(){
	Space *space = NULL;
	Id id = 1;
	char name[MAX_CHAR] = "name";

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_name(space, name) == OK);
	space_free(space);
	return;
}

void space_set_name_test2(){
	Space *space = NULL;
	Id id = 1;
	char *noName = NULL;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_name(space, noName) == ERROR);
	space_free(space);
	return;
}

void space_set_name_test3(){
	Space *space = NULL;
	Id id = 1;
	char name[MAX_CHAR] = "name";

	FUNCTION_IS_CORRECT(space_set_name(space, name) == ERROR);
	return;
}

void space_get_name_test1(){
	Space *space = NULL;
	Id id = 1;
	char name[MAX_CHAR] = "name";

	space = space_create(id);
	space_set_name(space, name);
	FUNCTION_IS_CORRECT(space_get_name(space) != NULL);
	space_free(space);
	return;
}

void space_get_name_test2(){
	Space *space = NULL;
	char name[MAX_CHAR] = "name";

	space_set_name(space, name);
	FUNCTION_IS_CORRECT(space_get_name(space) == NULL);
	return;
}

void space_set_north_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_north(space, id) == OK);
	space_free(space);
	return;
}

void space_set_north_test2(){
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_north(space, noId) == ERROR);
	space_free(space);
	return;
}

void space_set_north_test3(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_north(space, id) == ERROR);
	return;
}

void space_get_north_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_north(space, id);
	FUNCTION_IS_CORRECT(space_get_north(space) != NO_ID);
	space_free(space);
	return;
}

void space_get_north_test2(){
	Space *space = NULL;
	Id id = 1;

	space_set_north(space, id);
	FUNCTION_IS_CORRECT(space_get_north(space) == NO_ID);
	return;
}

void space_set_south_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_south(space, id) == OK);
	space_free(space);
	return;
}

void space_set_south_test2(){
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_south(space, noId) == ERROR);
	space_free(space);
	return;
}

void space_set_south_test3(Id id){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_south(space, id) == ERROR);
	return;
}

void space_get_south_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_south(space, id);
	FUNCTION_IS_CORRECT(space_get_south(space) != NO_ID);
	space_free(space);
	return;
}

void space_get_south_test2(){
	Space *space = NULL;
	Id id = 1;

	space_set_south(space, id);
	FUNCTION_IS_CORRECT(space_get_south(space) == NO_ID);
	return;
}

void space_set_east_test1(Space *space, Id id){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_east(space, id) == OK);
	space_free(space);
	return;
}

void space_set_east_test2(){
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_east(space, noId) == ERROR);
	space_free(space);
	return;
}

void space_set_east_test3(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_east(space, id) == ERROR);
	return;
}

void space_get_east_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_east(space, id);
	FUNCTION_IS_CORRECT(space_get_east(space) != NO_ID);
	space_free(space);
	return;
}

void space_get_east_test2(){
	Space *space = NULL;
	Id id = 1;

	space_set_east(space, id);
	FUNCTION_IS_CORRECT(space_get_east(space) == NO_ID);
	return;
}

void space_set_west_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_west(space, id) == OK);
	space_free(space);
	return;
}

void space_set_west_test2(){
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_west(space, noId) == ERROR);
	space_free(space);
	return;
}

void space_set_west_test3(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_set_west(space, id) == ERROR);
	return;
}

void space_get_west_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_set_west(space, id);
	FUNCTION_IS_CORRECT(space_get_west(space) != NO_ID);
	space_free(space);
	return;
}

void space_get_west_test2(){
	Space *space = NULL;
	Id id = 1;

	space_set_west(space, id);
	FUNCTION_IS_CORRECT(space_get_west(space) == NO_ID);
	return;
}

void space_add_object_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_add_object(space, id) == OK);
	space_free(space);
	return;
}

void space_add_object_test2(){
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_add_object(space, noId) == ERROR);
	space_free(space);
	return;
}

void space_add_object_test3(){
	Space *space = NULL;
	Id id = 1;

	FUNCTION_IS_CORRECT(space_add_object(space, id) == ERROR);
	return;
}

void space_del_object_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_del_object(space, id) == OK);
	space_free(space);
	return;
}

void space_del_object_test2(){
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_del_object(space, noId) == ERROR);
	space_free(space);
	return;
}

void space_del_object_test3(){
	Space *space = NULL;
	Id id = 1;

	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_del_object(space, id) == ERROR);
	return;
}

void space_get_object_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_get_object(space) != NO_ID);
	space_free(space);
	return;
}

void space_get_object_test2(){
	Space *space = NULL;
	Id id = 1;

	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_get_object(space) == NO_ID);
	return;
}

void space_is_object_test1(){
	Space *space = NULL;
	Id id = 1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_is_object(space, id) == TRUE);
	space_free(space);
	return;
}

void space_is_object_test2();{
	Space *space = NULL;
	Id id = 1;
	Id noId = -1;

	space = space_create(id);
	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_is_object(space, noId) == FALSE);
	space_free(space);
	return;
}

void space_is_object_test3(){
	Space *space = NULL;
	Id id = 1;

	space_add_object(space, id);
	FUNCTION_IS_CORRECT(space_is_object(space, id) == FALSE);
	return;
}

void space_set_desc_test1(){
	Space* space = NULL;
	Id id = 1;
	char desc[MAX_CHAR] = "desc";

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_desc(space, desc) == OK);
	space_free(space);
	return;
}

void space_set_desc_test2(Space *space){
	Space *space = NULL;
	Id id = 1;
	char *noDesc = NULL;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_desc(space, noDesc) == ERROR);
	space_free(space);
	return;
}

void space_set_desc_test3(char *desc){
	Space *space = NULL;
	Id id = 1;
	char desc[MAX_CHAR] = "desc";

	FUNCTION_IS_CORRECT(space_set_desc(space, desc) == ERROR);
	return;
}

void space_get_desc_test1(){
	Space *space = NULL;
	Id id = 1;
	char desc[MAX_CHAR] = "desc";

	space = space_create(id);
	space_set_desc(space, desc);
	FUNCTION_IS_CORRECT(space_get_desc(space) != NULL);
	space_free(space);
	return;
}

void space_get_desc_test2(){
	Space *space = NULL;
	char desc[MAX_CHAR] = "desc";

	space_set_desc(space, desc);
	FUNCTION_IS_CORRECT(space_get_desc(space) == NULL);
	return;
}

void space_set_gdesc_test1(){
	Space* space = NULL;
	Id id = 1;
	char gdesc[MAX_CHAR] = "gdesc";

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_gdesc(space, gdesc) == OK);
	space_free(space);
	return;
}

void space_set_gdesc_test2(Space *space){
	Space *space = NULL;
	Id id = 1;
	char *noGdesc = NULL;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_set_gdesc(space, noGdesc) == ERROR);
	space_free(space);
	return;
}

void space_set_gdesc_test3(char *gdesc){
	Space *space = NULL;
	Id id = 1;
	char gdesc[MAX_CHAR] = "gdesc";

	FUNCTION_IS_CORRECT(space_set_gdesc(space, gdesc) == ERROR);
	return;
}

void space_get_gdesc_test1(){
	Space *space = NULL;
	Id id = 1;
	char gdesc[MAX_CHAR] = "gdesc";

	space = space_create(id);
	space_set_gdesc(space, gdesc);
	FUNCTION_IS_CORRECT(space_get_gdesc(space) != NULL);
	space_free(space);
	return;
}

void space_get_gdesc_test2(){
	Space *space = NULL;
	char gdesc[MAX_CHAR] = "gdesc";

	space_set_desc(space, gdesc);
	FUNCTION_IS_CORRECT(space_get_gdesc(space) == NULL);
	return;
}

void space_print_gdesc_test1(Space *space){
	Space *space;
	Id id = 1;
	char gdesc[MAX_CHAR] = "gdesc";

	space = space_create(id);
	space_set_gdesc(space, gdesc);
	FUNCTION_IS_CORRECT(space_print_gdesc(space) == OK);
	space_free(space);
	return;
}

void space_print_gdesc_test2(){
	Space *space;
	char gdesc[MAX_CHAR] = "gdesc";

	space_set_gdesc(space, gdesc);
	FUNCTION_IS_CORRECT(space_print_gedesc(space) == ERROR);
	return;
}

void space_print_test1(){
	Space *space;
	Id id = 1;

	space = space_create(id);
	FUNCTION_IS_CORRECT(space_print(space) == OK);
	space_free(space);
	return;
}

void space_print_test2(){
	Space *space;

	FUNCTION_IS_CORRECT(space_print(space) == ERROR);
	return;
}
