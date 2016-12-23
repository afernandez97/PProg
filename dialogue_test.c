/**
	@file dialoggue_test.c
	@version 1.0
	@date 22-12-2016
	@author Guillermo Rodriguez

	@brief
	Contains the implementation of the functions used to test the
	functions implemented in dialogue.c.

	@version
	Dec. 22, 2016 Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dialogue_test.h" 

int main(int argc, char **argv){

	int all = 1, test;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\n", test);
		if (test < 1 || test > MAX_TEST_DIALOGUE) {
			printf("Unknown test\n");
			return 1; 
		}
	}

	if (all || test == 1) test1_dialogue_create();
	if (all || test == 2) test1_dialogue_destroy();
	if (all || test == 3) test1_dialogue_set_command_act();
	if (all || test == 4) test2_dialogue_set_command_act();
	if (all || test == 5) test3_dialogue_set_command_act();
	if (all || test == 6) test1_dialogue_get_command_act();
	if (all || test == 7) test2_dialogue_get_command_act();
	if (all || test == 8) test1_dialogue_set_command_prev();
	if (all || test == 9) test2_dialogue_set_command_prev();
	if (all || test == 10)test3_dialogue_set_command_prev();
	if (all || test == 11)test1_dialogue_get_command_act();
	if (all || test == 12)test2_dialogue_get_command_act();
	if (all || test == 13)test1_dialogue_set_text();
	if (all || test == 14)test2_dialogue_set_text();
	if (all || test == 15)test3_dialogue_set_text();
	if (all || test == 16)test1_dialogue_get_text();
	if (all || test == 17)test2_dialogue_get_text();
    if (all || test == 18) test2_dialogue_destroy();	


	return 0;
}


/*!< Public functions implementation */

/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_create
	Tests if you can successfully create a dialogue.

	@param
	@return
*/
void test1_dialogue_create(){
	Dialogue * dialogue = NULL;
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue != NULL);
	dialogue_destroy(dialogue);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_destroy
	Tests if you can successfully destroy a dialogue.

	@param
	@return
*/
void test1_dialogue_destroy(){
	Dialogue * dialogue = NULL;
	dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_destroy(dialogue) == OK_);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_destroy
	Tests if you can successfully destroy an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_destroy(){
	Dialogue * dialogue = NULL;
	FUNCTION_IS_CORRECT(dialogue_destroy(dialogue) == ERROR_);
	return;
}



/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_set_command_act
	Tests if you can successfully set the command act to a dialogue.

	@param
	@return
*/
void test1_dialogue_set_command_act(){
	Dialogue * dialogue = NULL;
	Command * command = command_create();
	command_set_cmd(command,ANSWER);
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_set_command_act(dialogue,command,OK_) == OK_);
    command_destroy(command);
    dialogue_destroy(dialogue);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test2_dialogue_set_command_act
	Tests if you can set the command act to an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_set_command_act(){
	Dialogue * dialogue = NULL;
	Command * command = command_create();
	command_set_cmd(command,ANSWER);
	FUNCTION_IS_CORRECT(dialogue_set_command_act(dialogue,command,OK_) == ERROR_);
	command_destroy(command);
	return;
}



/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test3_dialogue_set_command_act
	Tests if you can set an uninitialised command act to a dialogue.

	@param
	@return
*/
void test3_dialogue_set_command_act(){
	Dialogue * dialogue = NULL;
	Command * command =  NULL;
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_set_command_act(dialogue,command,OK_) == ERROR_);
	dialogue_destroy(dialogue);
	return;
}




/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_get_command_act
	Tests if you can successfully get the command act to a dialogue.

	@param
	@return
*/
void test1_dialogue_get_command_act(){
	Dialogue * dialogue = NULL;
	Command * command = command_create();
	command_set_cmd(command,ANSWER);
    dialogue = dialogue_create();
    dialogue_set_command_act(dialogue,command,OK_);
	FUNCTION_IS_CORRECT(dialogue_get_command_act(dialogue) != NULL);
    command_destroy(command);
    dialogue_destroy(dialogue);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test2_dialogue_get_command_act
	Tests if you can successfully get the command act to an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_get_command_act(){
	Dialogue * dialogue = NULL;
	FUNCTION_IS_CORRECT(dialogue_get_command_act(dialogue) == NULL);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_set_command_prev
	Tests if you can successfully prev the command act to a dialogue.

	@param
	@return
*/
void test1_dialogue_set_command_prev(){
	Dialogue * dialogue = NULL;
	Command * command = command_create();
	command_set_cmd(command,ANSWER);
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_set_command_prev(dialogue,command,OK_) == OK_);
    command_destroy(command);
    dialogue_destroy(dialogue);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test2_dialogue_set_command_prev
	Tests if you can set the command prev to an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_set_command_prev(){
	Dialogue * dialogue = NULL;
	Command * command = command_create();
	command_set_cmd(command,ANSWER);
	FUNCTION_IS_CORRECT(dialogue_set_command_prev(dialogue,command,OK_) == ERROR_);
	command_destroy(command);
	return;
}



/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test3_dialogue_set_command_prev
	Tests if you can set an uninitialised command prev to a dialogue.

	@param
	@return
*/
void test3_dialogue_set_command_prev(){
	Dialogue * dialogue = NULL;
	Command * command =  NULL;
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_set_command_prev(dialogue,command,OK_) == ERROR_);
	dialogue_destroy(dialogue);
	return;
}




/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_get_command_prev
	Tests if you can successfully get the command prev to a dialogue.

	@param
	@return
*/
void test1_dialogue_get_command_prev(){
	Dialogue * dialogue = NULL;
	Command * command = command_create();
	command_set_cmd(command,ANSWER);
    dialogue = dialogue_create();
    dialogue_set_command_prev(dialogue,command,OK_);
	FUNCTION_IS_CORRECT(dialogue_get_command_prev(dialogue) != NULL);
    command_destroy(command);
    dialogue_destroy(dialogue);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test2_dialogue_get_command_prev
	Tests if you can successfully get the command prev to an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_get_command_prev(){
	Dialogue * dialogue = NULL;
	FUNCTION_IS_CORRECT(dialogue_get_command_prev(dialogue) == NULL);
	return;
}


 /**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_set_text
	Tests if you can successfully set the text to a dialogue.

	@param
	@return
*/
void test1_dialogue_set_text(){
	Dialogue * dialogue = NULL;
	char text[20] = "text";
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_set_text(dialogue,text) == OK_);
    dialogue_destroy(dialogue);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test2_dialogue_set_text
	Tests if you can set the text to an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_set_text(){
	Dialogue * dialogue = NULL;
	char text[20] = "text";
	FUNCTION_IS_CORRECT(dialogue_set_text(dialogue,text) == ERROR_);
	return;
}



/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test3_dialogue_set_text
	Tests if you can set a NULL text to a dialogue.

	@param
	@return
*/
void test3_dialogue_set_text(){
	Dialogue * dialogue = NULL;
	char * text = NULL;
    dialogue = dialogue_create();
	FUNCTION_IS_CORRECT(dialogue_set_text(dialogue,text) == ERROR_);
	dialogue_destroy(dialogue);
	return;
}

/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test1_dialogue_get_text
	Tests if you can successfully get the text to a dialogue.

	@param
	@return
*/
void test1_dialogue_get_text(){
	Dialogue * dialogue = NULL;
	char text[2] = "text";
    dialogue = dialogue_create();
    dialogue_set_text(dialogue,text);
	FUNCTION_IS_CORRECT(dialogue_get_text(dialogue) != NULL);
    dialogue_destroy(dialogue);
	return;
}


/**
	@author Guillermo Rodriguez
	@date 22-12-2016

	@brief test2_dialogue_get_text
	Tests if you can successfully get the text to an uninitialised dialogue.

	@param
	@return
*/
void test2_dialogue_get_text(){
	Dialogue * dialogue = NULL;
	FUNCTION_IS_CORRECT(dialogue_get_text(dialogue) == NULL);
	return;
}
