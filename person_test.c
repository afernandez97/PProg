/**
	@file person_test.c
	@version 1.0
	@date 16-12-2016
	@author Guillermo Rodriguez

	@brief
	Contains the implementation of the functions used to test the
	functions implemented in person.c.

	@version
	Dec. 16, 2016 Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person_test.h" 

int main(int argc, char **argv){

	int all = 1, test;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\n", test);
		if (test < 1 || test > MAX_TEST_person) {
			printf("Unknown test\n");
			return 1; 
		}
	}

	if (all || test == 1) test1_person_create();
	if (all || test == 2) test2_person_create();
	if (all || test == 3) test1_person_destroy();
	if (all || test == 4) test2_person_destroy();
	if (all || test == 5) test1_person_get_id();
	if (all || test == 6) test2_person_get_id();
	if (all || test == 7) test1_person_set_name();
	if (all || test == 8) test2_person_set_name();
	if (all || test == 9) test3_person_set_name();
	if (all || test == 10) test1_person_get_name();
	if (all || test == 11) test2_person_get_name();
	if (all || test == 12) test1_person_set_location();
	if (all || test == 13) test2_person_set_location();
	if (all || test == 14) test3_person_set_location();
	if (all || test == 15) test1_person_get_location();
	if (all || test == 16) test2_person_get_location();
	if (all || test == 17) test1_person_set_rule();
	if (all || test == 18) test2_person_set_rule();
	if (all || test == 19) test3_person_set_rule();
	if (all || test == 20) test1_person_get_rule();
	if (all || test == 21) test2_person_get_rule();
	if (all || test == 22) test1_person_print();
	if (all || test == 23) test2_person_print();


	return 0;
}


/*!< Public functions implementation */

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_create
	Tests if you can successfully create a person.

	@param
	@return
*/
void test1_person_create(){
	Person * person = NULL;
	Id id = 1;

	person = person_create(id);
	FUNCTION_IS_CORRECT(person != NULL);
	person_destroy(person);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_create
	Tests if you can create a person if the id
	is not valid.

@param
@return
*/
void test2_person_create(){
	Person * person = NULL;
	Id noId = NO_ID;

	person = person_create(noId);
	FUNCTION_IS_CORRECT(person == NULL);
	person_destroy(person);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_destroy
	Tests if you can successfully destroy a person.

	@param
	@return
*/
void test1_person_destroy(){
	Person * person = NULL;
	Id id = 1;

	person = person_create(id);
	FUNCTION_IS_CORRECT(person_destroy(person) == OK);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_destroy
	Tests if you can destroy an uninitialised person.

	@param
	@return
*/
void test2_person_destroy(){
	Person * person = NULL;

	FUNCTION_IS_CORRECT(person_destroy(person) == ERROR);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_get_id
	Tests if you can successfully get the id of a person.

	@param
	@return
*/
void test1_person_get_id(){
	Person * person = NULL;
	Id id = 1;

	person = person_create(id);
	FUNCTION_IS_CORRECT(person_get_id(person) != NO_ID);
	person_destroy(space);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_get_id
	Tests if you can get the id of an uninitialised person.

	@param
	@return
*/
void test2_person_get_id(){
	person * person = NULL;

	FUNCTION_IS_CORRECT(person_get_id(person) == NO_ID);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_set_name
	Tests if you can successfully set the name of a person.

	@param
	@return
*/
void test1_person_set_name(){
	Person * person = NULL;
	Id id = 1;
	char name[WORD_SIZE] = "name";

	person = person_create(id);
	FUNCTION_IS_CORRECT(person_set_name(person,name) == OK);
	person_destroy(person);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_set_name
	Tests if you can set the name of an uninitialised person.

	@param
	@return
*/

void test2_person_set_name(){
	Person * person = NULL;
	char name[WORD_SIZE] = "name";

	FUNCTION_IS_CORRECT(person_set_name(person, name) == ERROR);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test3_person_set_name
	Tests if you can set the name of a person if the string inserted
	is unassigned.

	@param
	@return
*/

void test3_person_set_name(){
	Person * person = NULL;
	Id id = 1;
	char *noName = NULL;

	person = person_create(id);
	FUNCTION_IS_CORRECT(person_set_name(person, noName) == ERROR);
	person_destroy(person);
	return;
}



/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test1_person_get_name
	Tests if you can successfully get the name of a person.

	@param
	@return
*/
void test1_person_get_name(){
	Person * person = NULL;
	Id id = 1;
	char name[WORD_SIZE] = "name";

	person = person_create(id);
	person_set_name(person, name);
	FUNCTION_IS_CORRECT(person_get_name(person) != NULL);
	person_destroy(person);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 16-12-2016

	@brief test2_person_get_name
	Tests if you can get the name of an uninitialised person.

	@param
	@return
*/
void test2_person_get_name(){
	Person * person = NULL;
	char name[WORD_SIZE] = "name";

	person_set_name(person, name);
	FUNCTION_IS_CORRECT(person_get_name(person) == NULL);
	return;
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a location 
   for an uninitialized person.test1_person_set_location()
   @param 
    
 
   @return 
    
   */
void test1_person_set_location(){
	Person *person = NULL;
  Id idlocation = 345;
  FUNCTION_IS_CORRECT(person_set_location(person, idlocation) == ERROR);
  return;
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a location 
   for  a person.test2_person_set_location()
   @param 
    
 
   @return 
    
   */
void test2_person_set_location(){
	Person *person = NULL;
  Id idlocation = 345;
  Id idperson = 3;
  person = person_create(idperson);
  FUNCTION_IS_CORRECT(person_set_location(person, idlocation) == OK);
  person_destroy(person);
  return;
}

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set an empty 
   location for a person  test3_person_set_location()
   @param 
    
 
   @return 
    
   */
void test3_person_set_location(){
	Person *person = NULL;
  Id idlocation = NO_ID;
  Id idperson = 3;
  person = person_create(idperson);
  FUNCTION_IS_CORRECT(person_set_location(person, idlocation) == ERROR);
  person_destroy(person);
  return;
}

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's location 
   from an uninitialized person.test1_person_get_location()
   @param 
    
 
   @return 
    
   */
void test1_person_get_location(){
	Person *person = NULL;
  FUNCTION_IS_CORRECT(person_get_location(person) == NO_ID);
  return;
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's location 
   from  a person.test2_person_get_location()
   @param 
    
 
   @return 
    
   */
void test2_person_get_location(){
	Person * person = NULL;
  Id idlocation = 345;
  Id idperson = 3;
  person = person_create(idperson);
  person_set_location(person, idlocation);
  FUNCTION_IS_CORRECT(person_get_location(person) != NO_ID);
  person_destroy(person);
  return;
}

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a rule 
   for an uninitialized person.test1_person_set_rule()
   @param 
    
 
   @return 
    
   */
void test1_person_set_rule(){
	Person *person = NULL;
  Id idrule = 345;
  FUNCTION_IS_CORRECT(person_set_rule(person, idrule) == ERROR);
  return;
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to set a rule 
   for a person.test2_person_set_rule()
   @param 
    
 
   @return 
    
   */
void test2_person_set_rule(){
	Person *person = NULL;
  Id idrule = 345;
  Id idperson = 3;
  person = person_create(idperson);
  FUNCTION_IS_CORRECT(person_set_rule(person, idrule) == OK);
  person_destroy(person);
  return;
}

/**
   Function: test3_person_set_rule
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief  
   Check if there aren't any errors when you try to set an empty 
   rule for a person. test3_person_set_rule()
   @param 
    
 
   @return 
    
   */
void test3_person_set_rule(){
	Person *person = NULL;
  Id idrule = NO_ID;
  Id idperson = 3;
  person = person_create(idperson);
  FUNCTION_IS_CORRECT(person_set_rule(person, idrule) == ERROR);
  person_destroy(person);
  return;
}

/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's rule 
   from an uninitialized person.test1_person_get_rule()
   @param 
    
 
   @return 
    
   */
void test1_person_get_rule(){
	Person *person = NULL;
  FUNCTION_IS_CORRECT(person_get_rule(person) == NO_ID);
  return;
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
   Check if there aren't any errors when you try to get the person's rule 
   from  a person.test2_person_get_rule()
   @param 
    
 
   @return 
    
   */
void test2_person_get_rule(){
	Person * person = NULL;
  Id idrule = 345;
  Id idperson = 3;
  person = person_create(idperson);
  person_set_rule(person, idrule);
  FUNCTION_IS_CORRECT(person_get_rule(person) != NO_ID);
  person_destroy(person);
  return;
}

/**
@author Guillermo Rodriguez
@date 16-12-2016

@brief test1_person_print
Tests if you can successfully print a person.

@param
@return
*/

void test1_person_print(){
	Person * person = NULL;
	Id id = 1;
	char name[WORD_SIZE] = "name";
	Id location= 2;
	Id rule = 3;
	

	person = person_create(id);
	person_set_name(person, name);
  person_set_rule(person,rule);
	person_set_location(person,location);
	FUNCTION_IS_CORRECT(person_print(person) == OK);
	person_destroy(person);
	return;
}

/**
@author Guillermo Rodriguez
@date 16-12-2016

@brief test2_person_print
Tests if you can print an uninitialised person.

@param
@return
*/
void test2_person_print(){
	Person * person = NULL;

	FUNCTION_IS_CORRECT(person_print(person) == ERROR);
	return;
}



