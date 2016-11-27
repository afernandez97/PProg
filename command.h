/**
@file command.h
@version 4.0
@date 05-11-2016 
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
*/


#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
      
/*** Constant values description ***/
#define CMD_LENGTH 30

/**
@brief Command enum

The Command enum contains the different commands that can be used in the game
*/

typedef enum enum_Command{
  NO_CMD = -2,  /*!<  No Command */
  UNKNOWN,  /*!< Unknown Command */
  QUIT, /*!< Command to quit from the game */
  CATCH, /*!< Command to catch an object from a space */
  LEAVE, /*!< Command to leave an object on a space */
  GO,	   /*!< Command to go to another space */
  ROLL,	  /*!< Command to roll the die */	
  INSPECT /*!< Command to get information about an object or space*/ 
} T_Command;

/*** Data structures definition ***/

/**
@brief Command structure.
The Command structure stores information of the different commands that can be used in the game
*/
typedef struct _Command Command;


/*!< Public functions description */

/**
@brief get_user_input
Interprets the user's input. 
Input must be typed: 
 <command><blank space><argument> (space and argument only if needed)

@date 05-11-2016 
@author Ricardo Riol
@param 

@return Command *: interpretation of user's input or NULL on error.
*/

Command * get_user_input();

/**
@brief command_create
Creates a command.

@date 30-10-2016 
@author Alejandro Sanchez
@param 
@return Command *: the command created or NULL on error.
*/

Command * command_create();

/**
@brief command_destroy
Destroys a command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command to destroy.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/

STATUS command_destroy(Command *command);

/**
@brief command_get_cmd
Returns the type of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command which you want the type of.
@return T_Command: the command's type or NO_CMD on error.
*/

T_Command command_get_cmd(Command *command);

/**
@brief command_get_arg
Gives the information of the argument of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command that you want to know the argument.

@return char *: the argument of the command or NULL on error.
*/
char * command_get_arg(Command *command);

#endif
