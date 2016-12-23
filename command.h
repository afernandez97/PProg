/**
@file command.h
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


#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
      
/**
@def Constant values description 
*/
#define CMD_LENGTH 100

/**
@brief Command enum

The Command enum contains the different commands that can be used in the game
*/

typedef enum{
  NO_CMD = -2,  /*!<  No Command */
  UNKNOWN,  /*!< Unknown Command */
  QUIT, /*!< Command to quit from the game */
  CATCH, /*!< Command to catch an object from a space */
  LEAVE, /*!< Command to leave an object on a space */
  GO,	   /*!< Command to go to another space */
  ROLL,	  /*!< Command to roll the die */	
  INSPECT, /*!< Command to get information about an object or space */
  TURNON,  /*!< Command to turn on an object */
  TURNOFF, /*!< Command to turn off an object*/
  OPENL, 		/*!< Command to open a link with an object */
  LOAD, /*!< Command to load a save of a previous game */
  SAVE, /*!< Command to save a game */
  BUY,  /*!< Command to buy an object from a shop */
  SELL,  /*!< Command to sell an object to a shop */
  ANSWER, /*!< Command to answer a question */
  TALK,  /*!< Command to talk with a person */
  NEXT  /*!< Command to change turn */
} T_Command;

/*!< Data structures definition */

/**
@brief Command structure.
The Command structure stores information of the different commands that can be used in the game
*/
typedef struct _Command Command;


/*!< Public functions description */

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
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/

STATUS_ command_destroy(Command *command);

/**
@brief command_set_cmd
Sets the type of the command.

@date 21-12-2016 
@author Alejandro Sanchez
@param Command *command: the command which you want to set its new type.
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ command_set_cmd(Command *command, T_Command cmd);

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
@brief command_set_arg
Sets the first argument for a command.
@date 21-12-2016 
@author Alejandro Sanchez
@param command *command: the command you want to change its first argument.
@param char *arg: the new argument you want for the command.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ command_set_arg(Command *command, char *arg);


/**
@brief command_get_arg
Gives the information of the argument of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command that you want to know the argument.

@return char *: the argument of the command or NULL on error.
*/
char * command_get_arg(Command *command);

/**
@brief command_set_arg2
Sets the second argument for a command.
@date 21-12-2016 
@author Alejandro Sanchez
@param command *command: the command you want to change its second argument.
@param char *arg: the new argument you want for the command.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ command_set_arg2(Command *command, char *arg2);

/**
@brief command_get_arg2
Gives the information of the second argument of the command.

@date 02-12-2016 
@author Guillermo Rodriguez
@param Command *command: the command that you want to know the second argument.

@return char *: the  second argument of the command or NULL on error.
*/
char * command_get_arg2(Command *command);




#endif
