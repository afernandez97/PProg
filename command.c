/**
@file command.c
@version 5.1
@date 18-12-2016 
@author Guillermo Rodriguez and Alejandro Sanchez

@brief
It implements the command interpreter.
@version Sept. 23, 2016  Version 2.0 
	Commented the file.
@version Oct. 08, 2016 Version 2.1
	Added commands CATCH and LEAVE.	
@version Oct. 14, 2016 Version 2.2
	Added command JUMP.
@version Oct. 28, 2016 Version 3.0
	Created structure "Command".
	Added command ROLL.
@version Oct. 30, 2016 Version 3.1
	Created functions for ADT Command.
@version Nov. 04, 2016 Version 3.2
	Modified "get_user_input".
@version Nov. 05, 2016 Version 4.0
	Added command GO and removed commands NEXT, BACK and JUMP.
@version Dec. 8, 2016 Version 5.0
	Added commands TURNOFF, TURNON, OPENL, SAVE, LOAD.
@version Dec. 18, 2016 Version 5.1
	Added commands BUY, SELL, ANSWER.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"


/**
@def Constant values description 
*/
#define cmd(X) (X)->cmd
#define arg(X) (X)->arg
#define arg2(X) (X)->arg2

/**
@brief Command structure
Stores information of the different commands that can be used in the game
*/
struct _Command{
	T_Command cmd;	/*!< Type of command */
	char arg[CMD_LENGTH];	/*!< Input argument */
  char arg2[CMD_LENGTH]; /*!< Input argument for command open */
};


/*!< Public functions definition */

/**
@brief command_create
Creates a command.

@date 30-10-2016 
@author Alejandro Sanchez
@param 
@return Command *: the command created or NULL on error.
*/

Command * command_create(){
  Command *command = NULL;

  command = (Command *)malloc(sizeof(Command));
  if(!command){   /* Check if memory has been allocated */
    return NULL;
  }

  /* Initialize structure fields */
  cmd(command) = NO_CMD;
  arg(command)[0] = '\0';
  arg2(command)[0] = '\0';
  return command;
}



/**
@brief command_destroy
Destroys a command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command to destroy.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ command_destroy(Command *command){
  if(!command){   /* Check that the input is not empty */
    return ERROR_;
  }

  free(command);    /* Eliminate the memory of the command */

  return OK_;
}


/**
@brief command_set_cmd
Sets the type of the command.

@date 21-12-2016 
@author Alejandro Sanchez
@param Command *command: the command which you want to set its new type.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ command_set_cmd(Command *command, T_Command cmd){
  if(!command){   /* Check that the input is not empty */
    return ERROR_;
  }

  cmd(command) = cmd;

  return OK_;
}


/**
@brief command_get_cmd
Returns the type of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command which you want the type of.
@return T_Command: the command's type or NO_CMD on error.
*/
T_Command command_get_cmd(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NO_CMD;
  }

  return cmd(command);
}


/**
@brief command_set_arg
Sets the first argument for a command.
@date 21-12-2016 
@author Alejandro Sanchez
@param command *command: the command you want to change its first argument.
@param char *arg: the new argument you want for the command.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ command_set_arg(Command *command, char *arg){
  if(!command || !arg){     /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Set the argument and check if it has worked */
  if(!strcpy(arg(command), arg)){  
    return ERROR_;
  }

  return OK_;
}

/**
@brief command_get_arg
Gives the information of the argument of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command that you want to know the argument.

@return char *: the argument of the command or NULL on error.
*/
char * command_get_arg(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NULL;
  }

  return arg(command);
}


/**
@brief command_set_arg2
Sets the second argument for a command.
@date 21-12-2016 
@author Alejandro Sanchez
@param command *command: the command you want to change its second argument.
@param char *arg: the new argument you want for the command.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ command_set_arg2(Command *command, char *arg2){
  if(!command || !arg2){     /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Set the argument and check if it has worked */
  if(!strcpy(arg2(command), arg2)){  
    return ERROR_;
  }

  return OK_;
}

/**
@brief command_get_arg2
Gives the information of the second argument of the command.

@date 02-12-2016 
@author Guillermo Rodriguez
@param Command *command: the command that you want to know the second argument.

@return char *: the  second argument of the command or NULL on error.
*/
char * command_get_arg2(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NULL;
  }

  return arg2(command);
}
