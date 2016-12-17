/**
@file game_rules_test.c
@version 1.0
@date 13-12-2016
@author Guillermo Rodriguez

@brief
Contains the implementation of the functions used to test the
functions implemented in game_rules.c.

@version
	Dec. 13, 2016 Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_rules_test.h" 

int main(int argc, char **argv){

	int all = 1, test;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\n", test);
		if (test < 1 || test > MAX_TEST_RULE) {
			printf("Unknown test\n");
			return 1; 
		}
	}

	if (all || test == 1) test1_rule_create();
	if (all || test == 2) test2_rule_create();
	if (all || test == 3) test1_rule_destroy();
	if (all || test == 4) test2_rule_destroy();
	if (all || test == 5) test1_rule_get_id();
	if (all || test == 6) test2_rule_get_id();
	if (all || test == 7) test1_rule_set_ask();
	if (all || test == 8) test2_rule_set_ask();
	if (all || test == 9) test3_rule_set_ask();
	if (all || test == 10) test1_rule_get_ask();
	if (all || test == 11) test2_rule_get_ask();
	if (all || test == 12) test1_rule_set_choice1();
	if (all || test == 13) test2_rule_set_choice1();
	if (all || test == 14) test3_rule_set_choice1();
	if (all || test == 15) test1_rule_get_choice1();
	if (all || test == 16) test2_rule_get_choice1();
	if (all || test == 17) test1_rule_set_choice2();
	if (all || test == 18) test2_rule_set_choice2();
	if (all || test == 19) test3_rule_set_choice2();
	if (all || test == 20) test1_rule_get_choice2();
	if (all || test == 21) test2_rule_get_choice2();
	if (all || test == 22) test1_rule_print();
	if (all || test == 23)  test2_rule_print();


	return 0;
}


/*!< Public functions implementation */

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_create
Tests if you can successfully create a rule.

@param
@return
*/
void test1_rule_create(){
	Rule * rule = NULL;
	Id id = 1;

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule != NULL);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_create
Tests if you can create a rule if the id
is not valid.

@param
@return
*/
void test2_rule_create(){
	Rule * rule = NULL;
	Id noId = NO_ID;

	rule = rule_create(noId);
	FUNCTION_IS_CORRECT(rule == NULL);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_destroy
Tests if you can successfully destroy a rule.

@param
@return
*/
void test1_rule_destroy(){
	Rule * rule = NULL;
	Id id = 1;

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_destroy(rule) == _OK);
	return;
}


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_destroy
Tests if you can destroy an uninitialised rule.

@param
@return
*/
void test2_rule_destroy(){
	Rule * rule = NULL;

	FUNCTION_IS_CORRECT(rule_destroy(rule) == _ERROR);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_id
Tests if you can successfully get the id of a space.

@param
@return
*/
void test1_rule_get_id(){
	Rule * rule = NULL;
	Id id = 1;

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_get_id(rule) != NO_ID);
	rule_destroy(space);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_id
Tests if you can get the id of an uninitialised rule.

@param
@return
*/
void test2_rule_get_id(){
	Rule * rule = NULL;

	FUNCTION_IS_CORRECT(rule_get_id(rule) == NO_ID);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_set_question
Tests if you can successfully set the question of a space.

@param
@return
*/
void test1_rule_set_question(){
	Rule * rule = NULL;
	Id id = 1;
	char question[WORD_SIZE] = "question";

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_set_question(rule, question) == _OK);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_set_question
Tests if you can set the question of an uninitialised rule.

@param
@return
*/

void test2_rule_set_question(){
	Rule * rule = NULL;
	char question[WORD_SIZE] = "question";

	FUNCTION_IS_CORRECT(rule_set_question(rule, question) == _ERROR);
	return;
}


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test3_rule_set_question
Tests if you can set the question of a rule if the string inserted
is unassigned.

@param
@return
*/

void test3_rule_set_question(){
	Rule * rule = NULL;
	Id id = 1;
	char *noName = NULL;

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_set_question(rule, noName) == _ERROR);
	rule_destroy(rule);
	return;
}



/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_question
Tests if you can successfully get the question of a rule.

@param
@return
*/
void test1_rule_get_question(){
	Rule * rule = NULL;
	Id id = 1;
	char question[WORD_SIZE] = "question";

	rule = rule_create(id);
	rule_set_question(rule, question);
	FUNCTION_IS_CORRECT(rule_get_question(rule) != NULL);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_question
Tests if you can get the question of an uninitialised rule.

@param
@return
*/
void test2_rule_get_question(){
	Rule * rule = NULL;
	char question[WORD_SIZE] = "question";

	rule_set_question(rule, question);
	FUNCTION_IS_CORRECT(rule_get_question(rule) == NULL);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_set_choice1
Tests if you can successfully set the first choice of a rule.

@param
@return
*/
void test1_rule_set_choice1(){
	Rule * rule = NULL;
	Id id = 1;
	char choice1[WORD_SIZE] = "choice1";

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_set_choice1(rule, choice1) == _OK);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_set_choice1
Tests if you can set the first choice of an uninitialised rule.

@param
@return
*/

void test2_rule_set_choice1(){
	Rule * rule = NULL;
	char choice1[WORD_SIZE] = "choice1";

	FUNCTION_IS_CORRECT(rule_set_choice1(rule, choice1) == _ERROR);
	return;
}


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test3_rule_set_choice1
Tests if you can set the first choice of a rule if the string inserted
is unassigned.

@param
@return
*/

void test3_rule_set_choice1(){
	Rule * rule = NULL;
	Id id = 1;
	char *noName = NULL;

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_set_choice1(rule, noName) == _ERROR);
	rule_destroy(rule);
	return;
}



/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_choice1
Tests if you can successfully get the first choice of a rule.

@param
@return
*/
void test1_rule_get_choice1(){
	Rule * rule = NULL;
	Id id = 1;
	char choice1[WORD_SIZE] = "choice1";

	rule = rule_create(id);
	rule_set_choice1(rule, choice1);
	FUNCTION_IS_CORRECT(rule_get_choice1(rule) != NULL);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_choice1
Tests if you can get the first choice of an uninitialised rule.

@param
@return
*/
void test2_rule_get_choice1(){
	Rule * rule = NULL;
	char choice1[WORD_SIZE] = "choice1";

	rule_set_choice1(rule, choice1);
	FUNCTION_IS_CORRECT(rule_get_choice1(rule) == NULL);
	return;
}


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_set_choice2
Tests if you can successfully set the second choice of a rule.

@param
@return
*/
void test1_rule_set_choice2(){
	Rule * rule = NULL;
	Id id = 1;
	char choice2[WORD_SIZE] = "choice2";

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_set_choice2(rule, choice2) == _OK);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_set_choice2
Tests if you can set the second choice of an uninitialised rule.

@param
@return
*/

void test2_rule_set_choice2(){
	Rule * rule = NULL;
	char choice2[WORD_SIZE] = "choice2";

	FUNCTION_IS_CORRECT(rule_set_choice2(rule, choice2) == _ERROR);
	return;
}


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test3_rule_set_choice2
Tests if you can set the second choice of a rule if the string inserted
is unassigned.

@param
@return
*/

void test3_rule_set_choice1(){
	Rule * rule = NULL;
	Id id = 1;
	char *noName = NULL;

	rule = rule_create(id);
	FUNCTION_IS_CORRECT(rule_set_choice2(rule, noName) == _ERROR);
	rule_destroy(rule);
	return;
}



/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_get_choice2
Tests if you can successfully get the second choice of a rule.

@param
@return
*/
void test1_rule_get_choice2(){
	Rule * rule = NULL;
	Id id = 1;
	char choice2[WORD_SIZE] = "choice2";

	rule = rule_create(id);
	rule_set_choice2(rule, choice2);
	FUNCTION_IS_CORRECT(rule_get_choice2(rule) != NULL);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_get_choice2
Tests if you can get the second choice of an uninitialised rule.

@param
@return
*/
void test2_rule_get_choice2(){
	Rule * rule = NULL;
	char choice2[WORD_SIZE] = "choice2";

	rule_set_choice2(rule, choice2);
	FUNCTION_IS_CORRECT(rule_get_choice2(rule) == NULL);
	return;
}


/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test1_rule_print
Tests if you can successfully print a rule.

@param
@return
*/

void test1_rule_print(){
	Rule * rule = NULL;
	Id id = 1;
	char question[WORD_SIZE] = "question";
	char choice1[WORD_SIZE] = "choice1";
	char choice2[WORD_SIZE] = "choice2";
	

	rule = rule_create(id);
	rule_set_question(rule, question);
	rule_set_choice1(rule, choice1);
	FUNCTION_IS_CORRECT(rule_print(rule) == _OK);
	rule_destroy(rule);
	return;
}

/**
@author Guillermo Rodriguez
@date 12-12-2016

@brief test2_rule_print
Tests if you can print an uninitialised rule.

@param
@return
*/
void test2_rule_print(){
	Rule * rule = NULL;

	FUNCTION_IS_CORRECT(rule_print(rule) == _ERROR);
	return;
}



